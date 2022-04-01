// ClrLstBx.cpp : implementation file
//

#include "stdafx.h"
#include "Tabbed.h"
#include "ClrLstBx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorListBox

CColorListBox::CColorListBox()
{
}

CColorListBox::~CColorListBox()
{
}

void CColorListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{
	CRect rect;
	GetClientRect(&rect);

	// For this to work the original list box as drawn in
	// the resource editor must have the OwnerDraw property
	// set to variable, not fixed, even though we're drawing
	// them all the same height.
	lpMIS->itemHeight = rect.Height() / 4;
	lpMIS->itemWidth = rect.Width();
}

void CColorListBox::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	
	// Because this is an owner draw list box, the AddString
	// function has placed an RGB value in item data.
	COLORREF cr = (COLORREF)lpDIS->itemData;
	
	// There are 3 states this function accomodates.
	// 1) When the item is originally drawn.
	if (lpDIS->itemAction & ODA_DRAWENTIRE)
	{
		CBrush br(cr);
		pDC->FillRect(&lpDIS->rcItem, &br);
	}

	// 2) When its selection state is changing from non-selected
	//    to selected, so we hilite its frame.
	if ((lpDIS->itemState & ODS_SELECTED) &&
		(lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE)))
	{
		COLORREF crHilite = RGB(255-GetRValue(cr),
						255-GetGValue(cr), 255-GetBValue(cr));
		CBrush br(crHilite);
		pDC->FrameRect(&lpDIS->rcItem, &br);
	}

	// 3) When the item was selected and it's been de-selected.
	//    We need to remove its frame.
	if (!(lpDIS->itemState & ODS_SELECTED) &&
		(lpDIS->itemAction & ODA_SELECT))
	{
		CBrush br(cr);
		pDC->FrameRect(&lpDIS->rcItem, &br);
	}
}
