// dibpal.cpp : implementation file
//

#include "stdafx.h"
#include "dibpal.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIBPal

CDIBPal::CDIBPal()
{
	m_nSelectionIndex = 0;
	m_bDraw3D = TRUE;
}

CDIBPal::~CDIBPal()
{
}

// Create a palette from the color table in a DIB.
BOOL CDIBPal::Create(CDIB* pDIB)
{
    DWORD dwColors = pDIB->GetNumClrEntries();
    // Check to see whether the DIB has a color table.
    if (!dwColors) 
	{
        TRACE("No color table");   
        return FALSE;
    }

    // Get a pointer to the RGB quads in the color table.
    RGBQUAD* pRGB = pDIB->GetClrTabAddress();

    // Allocate a logical palette and fill it with the color table info.
    LOGPALETTE* pPal = (LOGPALETTE*) malloc(sizeof(LOGPALETTE) 
                     + dwColors * sizeof(PALETTEENTRY));
    if (0 == pPal) 
	{
        TRACE("Out of memory for logical palette");
        return FALSE;
    }
    pPal->palVersion = 0x300;              // Windows 3.0
    pPal->palNumEntries = (WORD) dwColors; // Table size
    for (DWORD dw=0; dw<dwColors; dw++) 
	{
        pPal->palPalEntry[dw].peRed = pRGB[dw].rgbRed;
        pPal->palPalEntry[dw].peGreen = pRGB[dw].rgbGreen;
        pPal->palPalEntry[dw].peBlue = pRGB[dw].rgbBlue;
        pPal->palPalEntry[dw].peFlags = 0;
    }
    BOOL bResult = CreatePalette(pPal);
    free(pPal);
    return bResult;
}

/////////////////////////////////////////////////////////////////////////////
// CDIBPal commands

int CDIBPal::GetNumColors()
{
    int nColors = 0;
    if (!GetObject(sizeof(nColors), &nColors)) 
	{
        TRACE("Failed to get the number of colors in the palette");
        return 0;
    }
    return nColors;
}

void CDIBPal::SetSelectionIndex(int nPaletteIndex)
{
    int nColors = GetNumColors();
	ASSERT(nPaletteIndex >= 0 && nPaletteIndex < 256);

	m_nSelectionIndex = nPaletteIndex;
}

COLORREF CDIBPal::GetColorFromIndex(int nPaletteIndex)
{
    int nColors = GetNumColors();
	ASSERT(nPaletteIndex >= 0 && nPaletteIndex < nColors);

	PALETTEENTRY pe[256];

	GetPaletteEntries(0, nColors, pe);
	return RGB(pe[nPaletteIndex].peRed, pe[nPaletteIndex].peGreen,
				pe[nPaletteIndex].peBlue);
}

/************************************************************************
*	CDIBPal::Draw()
*
*	Draws the palette color table in a 16 x 16 grid
*	Conditionally draws 3D and/or selection indicator.
*
************************************************************************/
void CDIBPal::Draw(	CDC* pDC, 
					const CRect& rcRect, 
					BOOL bShowSelection /*= FALSE*/,
					BOOL bBkgnd /*= FALSE*/)
{
    int nColors = GetNumColors();
    CPalette* pOldPal = pDC->SelectPalette(this, bBkgnd);
    pDC->RealizePalette();

    int i, j, top, left, bottom, right;
    for (j=0, top=rcRect.top; j<16; j++, top=bottom) 
	{
        bottom = rcRect.top + ((j+1) * rcRect.Height() / 16 + 1);
        for (i=0, left=rcRect.left; i<16; i++, left=right) 
		{
            right = rcRect.left + ((i+1) * rcRect.Width() / 16 + 1);
			CBrush br;
			if(nColors >= 0)
			{
				br.CreateSolidBrush (PALETTEINDEX(j * 16 + i));
			}
			else
			{
				br.CreateStockObject(LTGRAY_BRUSH);
			}
			CBrush* pOldBrush = pDC->SelectObject(&br);
            
			
			//	Create a working rect
			CRect	rcFill(left-1, top-1, right, bottom);

			//	Fill with Color
			pDC->Rectangle(&rcFill);
				
			//	Draw a 3D Frame
			if(m_bDraw3D)
			{
				rcFill.InflateRect(-1, -1);
				pDC->Draw3dRect(&rcFill, RGB(96,96,96), RGB(255,255,255));

				rcFill.InflateRect(-1, -1);
				pDC->Draw3dRect(&rcFill, RGB(0,0,0), RGB(192,192,192));
			}

			//	and selection rect if needed
			if(bShowSelection && (m_nSelectionIndex == (j * 16 + i)))
			{
				rcFill.InflateRect(-1, -1);
				pDC->Draw3dRect(&rcFill, RGB(255,0,0), RGB(255,0,0));
			}

			if(pOldBrush)
			{
				pDC->SelectObject(pOldBrush);
			}
            nColors--;
        }
    }
    pDC->SelectPalette(pOldPal, FALSE);
}

/************************************************************************
*	CDIBPal::HitTest()
*
*	Determines which palette index whould be hit if a 16 x 16 grid
*	of colors were drawn in the provided rect
*
************************************************************************/
int	CDIBPal::HitTest(const CRect& rcRect, CPoint pt)
{
    int i, j, top, left, bottom, right;
    for (j=0, top=rcRect.top; j<16; j++, top=bottom) 
	{
        bottom = rcRect.top + ((j+1) * rcRect.Height() / 16 + 1);
        for (i=0, left=rcRect.left; i<16; i++, left=right) 
		{
            right = rcRect.left + ((i+1) * rcRect.Width() / 16 + 1);

			//	Create a working rect
			CRect	rcHit(left-1, top-1, right, bottom);

			if(rcHit.PtInRect(pt))
			{
				//	Return Index
				return (j * 16 + i);
			}
        }
    }
	//	No Hits
	return -1;
}
