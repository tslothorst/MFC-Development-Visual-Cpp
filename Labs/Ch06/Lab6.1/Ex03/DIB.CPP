// DIB.cpp : implementation file
//

#include "stdafx.h"
#include "DIB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DIB Helper Functions

BOOL IsWinDIB(BITMAPINFOHEADER* pBIH)
{
    ASSERT(pBIH);
    if (((BITMAPCOREHEADER*)pBIH)->bcSize == sizeof(BITMAPCOREHEADER)) 
	{
         return FALSE;
    }
    return TRUE;
}

int NumDIBColorBits(LPBITMAPINFO pBmpInfo) 
{
    BITMAPINFOHEADER* pBIH;
    BITMAPCOREHEADER* pBCH;
    int iBitCount;

    ASSERT(pBmpInfo);

    pBIH = &(pBmpInfo->bmiHeader);
    pBCH = (BITMAPCOREHEADER*) pBIH;

    // Start off by assuming the color table size from
    // the bit-per-pixel field.
    if (IsWinDIB(pBIH)) 
	{
        iBitCount = pBIH->biBitCount;
    } 
	else 
	{
        iBitCount = pBCH->bcBitCount;
    }
	return iBitCount;
}

int NumDIBColorEntries(LPBITMAPINFO pBmpInfo) 
{
    BITMAPINFOHEADER* pBIH;
    BITMAPCOREHEADER* pBCH;
    int iColors, iBitCount;

    ASSERT(pBmpInfo);

    pBIH = &(pBmpInfo->bmiHeader);
    pBCH = (BITMAPCOREHEADER*) pBIH;

    // Start off by assuming the color table size from
    // the bit-per-pixel field.
    if (IsWinDIB(pBIH)) 
	{
        iBitCount = pBIH->biBitCount;
    } 
	else 
	{
        iBitCount = pBCH->bcBitCount;
    }

    switch (iBitCount) 
	{
		case 1:
		    iColors = 2;
		    break;
		case 4:
		    iColors = 16;
		    break;
		case 8:
		    iColors = 256;
		    break;
			
		default:
		    iColors = 0;
		    break;
    }

    // If this is a Windows DIB, then the color table length
    // is determined by the biClrUsed field if the value in
    // the field is nonzero.
    if (IsWinDIB(pBIH) && (0 != pBIH->biClrUsed)) 
	{
        iColors = pBIH->biClrUsed;
    }

    return iColors;
}

/////////////////////////////////////////////////////////////////////////////
// CDIB Class Implementation

IMPLEMENT_SERIAL(CDIB, CObject, 0)

CDIB::CDIB()
{
    m_pBMI = 0;
    m_pBits = 0;
    Create(16, 16);
}

CDIB::~CDIB()
{
    // Free the memory.
    if (0 != m_pBMI)
    	free(m_pBMI);
    if (0 != m_pBits)
    	free(m_pBits);
}


BOOL CDIB::Create(int iWidth, int iHeight)
{
    // Delete any existing stuff.
    if (0 != m_pBMI)
    	free(m_pBMI);
    if (0 != m_pBits)
    	free(m_pBits);

    // Allocate memory for the header.
    m_pBMI = (BITMAPINFO*) malloc(sizeof(BITMAPINFOHEADER) +
                                  256 * sizeof(RGBQUAD));

    // Allocate memory for the bits (DWORD aligned).
    int iBitsSize = ((iWidth + 3) & ~3) * iHeight;
    m_pBits = (BYTE*)malloc(iBitsSize);

    // Fill in the header info.
    BITMAPINFOHEADER* pBI = (BITMAPINFOHEADER*) m_pBMI;
    pBI->biSize = sizeof(BITMAPINFOHEADER);
    pBI->biWidth = iWidth;
    pBI->biHeight = iHeight;
    pBI->biPlanes = 1;
    pBI->biBitCount = 8;
    pBI->biCompression = BI_RGB;
    pBI->biSizeImage = 0;
    pBI->biXPelsPerMeter = 0;
    pBI->biYPelsPerMeter = 0;
    pBI->biClrUsed = 0;
    pBI->biClrImportant = 0;

    // Create a gray scale color table.
    RGBQUAD* prgb = GetClrTabAddress();
    for (int i = 0; i < 256; i++) 
	{
        prgb->rgbBlue = prgb->rgbGreen = prgb->rgbRed = (BYTE) i;
        prgb->rgbReserved = 0;
        prgb++;
    }

    // Set all the bits to a known state (black).
    memset(m_pBits, iBitsSize, 0);

    return TRUE;
}

// Get the number of color table entries.
int CDIB::GetNumClrEntries()
{
    return NumDIBColorEntries(m_pBMI);
}

LONG CDIB::ScanLineWidth() const
{
	//	For easier reading
	#define	DWORD_PADDED(x) (((x)+3)&~3)
	
	return DWORD_PADDED((m_pBMI->bmiHeader.biBitCount * DibWidth() + 7)/8);
}

BOOL CDIB::Load(CFile* fp)
{
    BOOL bIsPM = FALSE;
    BITMAPINFO* pBmpInfo = 0;
    BYTE* pBits = 0;

    // Get the current file position.
    DWORD dwFileStart = fp->GetPosition();

    // Read the file header to get the file size and to
    // find out where the bits start in the file.
    BITMAPFILEHEADER BmpFileHdr;
    int iBytes;
    iBytes = fp->Read(&BmpFileHdr, sizeof(BmpFileHdr));

    // Check that we have the magic 'BM' at the start.
    if (BmpFileHdr.bfType != 0x4D42) 
	{
        TRACE("Not a bitmap file");
        goto $abort;
    }

    // Make a wild guess that the file is in Windows DIB
    // format and read the BITMAPINFOHEADER. If the file turns
    // out to be a PM DIB file, we'll convert it later.
    BITMAPINFOHEADER BmpInfoHdr;
    iBytes = fp->Read(&BmpInfoHdr, sizeof(BmpInfoHdr)); 

    // Check that we got a real Windows DIB file.
    if (BmpInfoHdr.biSize != sizeof(BITMAPINFOHEADER)) 
	{
        // Set a flag to convert PM file to Win format later.
        bIsPM = TRUE;

        // Back up the file pointer and read the BITMAPCOREHEADER
        // and create the BITMAPINFOHEADER from it.
        fp->Seek(dwFileStart + sizeof(BITMAPFILEHEADER), CFile::begin);
        BITMAPCOREHEADER BmpCoreHdr;
        iBytes = fp->Read(&BmpCoreHdr, sizeof(BmpCoreHdr)); 

        BmpInfoHdr.biSize = sizeof(BITMAPINFOHEADER);
        BmpInfoHdr.biWidth = (int) BmpCoreHdr.bcWidth;
        BmpInfoHdr.biHeight = (int) BmpCoreHdr.bcHeight;
        BmpInfoHdr.biPlanes = BmpCoreHdr.bcPlanes;
        BmpInfoHdr.biBitCount = BmpCoreHdr.bcBitCount;
        BmpInfoHdr.biCompression = BI_RGB;
        BmpInfoHdr.biSizeImage = 0;
        BmpInfoHdr.biXPelsPerMeter = 0;
        BmpInfoHdr.biYPelsPerMeter = 0;
        BmpInfoHdr.biClrUsed = 0;
        BmpInfoHdr.biClrImportant = 0;
    }

    // Allocate the memory blocks.
    // Copy the BmpInfoHdr we have so far,
    // and then read in the color table from the file.
    int iColors;
    int iColorTableSize;
    iColors = NumDIBColorEntries((LPBITMAPINFO) &BmpInfoHdr);
    iColorTableSize = 256 * sizeof(RGBQUAD);
    int iBitsSize;
    int iBISize;
    iBISize = sizeof(BITMAPINFOHEADER) + 
              iColorTableSize;
    iBitsSize = BmpFileHdr.bfSize - 
                BmpFileHdr.bfOffBits;

    // Allocate the memory for the header.
    pBmpInfo = (LPBITMAPINFO) malloc(iBISize);

    // Copy the header we already have.
    memcpy(pBmpInfo, &BmpInfoHdr, sizeof(BITMAPINFOHEADER));

    // Now read the color table in from the file.
    if (bIsPM == FALSE) 
	{
        // Read the color table from the file.
        iBytes = fp->Read(((LPBYTE) pBmpInfo) + 
                          sizeof(BITMAPINFOHEADER), iColorTableSize);
	} 
	else 
	{
        // Read each PM color table entry in turn and convert it
        // to Win DIB format as we go.
        LPRGBQUAD lpRGB;
        lpRGB = (LPRGBQUAD) ((LPBYTE) pBmpInfo + 
                                      sizeof(BITMAPINFOHEADER));
        int i;
        RGBTRIPLE rgbt;
        for (i=0; i<iColors; i++) 
		{
            iBytes = fp->Read(&rgbt, sizeof(RGBTRIPLE));
            lpRGB->rgbBlue = rgbt.rgbtBlue;
            lpRGB->rgbGreen = rgbt.rgbtGreen;
            lpRGB->rgbRed = rgbt.rgbtRed;
            lpRGB->rgbReserved = 0;
            lpRGB++;
        }
    }

    // Allocate the memory for the bits
    // and read the bits from the file.
    pBits = (BYTE*) malloc(iBitsSize);
    if (!pBits) 
	{
        TRACE("Out of memory for DIB bits");
        goto $abort;
    }

    // Seek to the bits in the file.
    fp->Seek(dwFileStart + BmpFileHdr.bfOffBits, CFile::begin);

    // Read the bits.
    iBytes = fp->Read(pBits, iBitsSize);

    // Everything went OK.
    if (0 != m_pBMI)
    	free(m_pBMI);
    m_pBMI = pBmpInfo; 
    if (0 != m_pBits)
    	free(m_pBits);
    m_pBits = pBits;
    return TRUE;
                
$abort: // Something went wrong.
    if (pBmpInfo) free(pBmpInfo);
    if (pBits) free(pBits);
    return FALSE;    
}

BOOL CDIB::Save(CFile* fp)
{
    BITMAPFILEHEADER bfh;

    // Construct the file header.
    bfh.bfType = 0x4D42; // 'BM'
    bfh.bfSize = 
		sizeof(BITMAPFILEHEADER) +
        sizeof(BITMAPINFOHEADER) +
        256 * sizeof(RGBQUAD) +
        ScanLineWidth() * DibHeight();
	
    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bfh.bfOffBits =
        sizeof(BITMAPFILEHEADER) +
        sizeof(BITMAPINFOHEADER) +
        256 * sizeof(RGBQUAD);

    // Write the file header.
    int iSize = sizeof(bfh);
    TRY 
	{
        fp->Write(&bfh, iSize);
    } 
	CATCH(CFileException, e) 
	{
        TRACE("Failed to write file header");
        return FALSE;
    } 
	END_CATCH

    // Write the BITMAPINFO structure.
    // Note: we assume that there are always 256 colors in the
    // color table.
    ASSERT(m_pBMI);
    iSize =	sizeof(BITMAPINFOHEADER) +
			256 * sizeof(RGBQUAD);
    TRY 
	{
        fp->Write(m_pBMI, iSize);
    } 
	CATCH(CFileException, e) 
	{
        TRACE("Failed to write BITMAPINFO");
        return FALSE;
    } 
	END_CATCH

    // Write the bits.
    iSize = ScanLineWidth() * DibHeight();
    TRY 
	{
        fp->Write(m_pBits, iSize);
    } 
	CATCH(CFileException, e) 
	{
        TRACE("Failed to write bits");
        return FALSE;
    } 
	END_CATCH

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// CDIB serialization

void CDIB::Serialize(CArchive& ar)
{
	ar.Flush();
    CFile* fp = ar.GetFile();

    if (ar.IsStoring()) 
	{
        Save(fp);
    } 
	else 
	{
        Load(fp);
    }
}

//////////////////////////////////////////////////////////////////
// CDDIB diagnostics

#ifdef _DEBUG
void CDIB::AssertValid() const
{
	CObject::AssertValid();
}

void CDIB::Dump(CDumpContext& dc) const
{
	CObject::Dump(dc);
}
#endif //_DEBUG
