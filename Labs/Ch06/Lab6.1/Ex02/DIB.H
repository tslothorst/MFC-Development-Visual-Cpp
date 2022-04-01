// CDIB.h : header file
//

#ifndef __CDIB__
#define __CDIB__


BOOL IsWinDIB(BITMAPINFOHEADER* pBIH);
int NumDIBColorBits(LPBITMAPINFO pBmpInfo);
int NumDIBColorEntries(LPBITMAPINFO pBmpInfo);

/////////////////////////////////////////////////////////////////////////////
// CDIB Class

class CDIB : public CObject
{
// Construction
public:
	CDIB();
	DECLARE_SERIAL(CDIB)

// Attributes
public:
    BITMAPINFO* GetBitmapInfoAddress() const
			{return m_pBMI;}                        // Pointer to bitmap info
    BYTE* GetBitsAddress() const
		    {return m_pBits;}                       // Pointer to the bits
    RGBQUAD* GetClrTabAddress() const
			{return (LPRGBQUAD)(((BYTE*)(m_pBMI)) +
				     sizeof(BITMAPINFOHEADER));}    // Pointer to color table
    int	DibWidth() const 
			{return m_pBMI->bmiHeader.biWidth;}
    int	DibHeight() const 
			{return m_pBMI->bmiHeader.biHeight;}
    int GetNumClrEntries();					// Number of color table entries
	LONG ScanLineWidth() const;
	
											 
// Operations
public:
    virtual BOOL Create(int width, int height);		// Create a new DIB
    virtual BOOL Load(CFile* fp);					// Load from file
    virtual BOOL Save(CFile* fp);					// Save to file

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIB)
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDIB();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	BITMAPINFO*	m_pBMI;
	BYTE*		m_pBits;
};

/////////////////////////////////////////////////////////////////////////////

#endif
