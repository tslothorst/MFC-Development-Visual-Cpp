// dibpal.h : header file
//
// CDIBPal class
//

#ifndef __DIBPAL__
#define __DIBPAL__

#include "dib.h"


class CDIBPal : public CPalette
{

// Constructor
public:
    CDIBPal();
    ~CDIBPal();
    BOOL		Create(CDIB *pDIB);     // Create from a DIB.
    int			GetNumColors();			// Get the number of colors
                                    // in the palette.
// Accessors
	int			GetSelectionIndex() const { return m_nSelectionIndex; }
	void		SetSelectionIndex(int nPaletteIndex);
	COLORREF	GetColorFromIndex(int nPaletteIndex);
	// void		SetColorAtIndex(int nPaletteIndex, COLORREF cr);
	BOOL		GetDraw3D() const { return m_bDraw3D; }
	void		SetDraw3D(BOOL bDraw3D = TRUE) { m_bDraw3D = bDraw3D; }


// Drawing function
    void		Draw(	CDC* pDC, 
						const CRect& rcRect, 
						BOOL bShowSelection = FALSE,
						BOOL bBkgnd = FALSE);
	int			HitTest(const CRect& rcRect, CPoint pt);

// Implementation
protected:
	int		m_nSelectionIndex;
	BOOL	m_bDraw3D;
};

#endif // __DIBPAL__
