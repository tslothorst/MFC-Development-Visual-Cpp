// ODrawMnu.cpp : implementation file
//

#include "stdafx.h"
#include "owndraw.h"
#include "ODrawMnu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODmenus

CODmenus::CODmenus()
{
	VERIFY(CreateMenu());
}

CODmenus::~CODmenus()
{
	Detach();
	ASSERT(m_hMenu == NULL);
    // default CMenu::~CMenu will destroy
}

void CODmenus::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)
{
	// Just to show how this function can differentiate which
	// menu item it's drawing, we'll make each menu item be taller
	// than its predecessor
	switch (lpMIS->itemID)
	{
		case IDR_COLOR_BLUE:
			lpMIS->itemHeight = 2 * COLOR_BOX_HEIGHT;
			break;
		case IDR_COLOR_GREEN:
			lpMIS->itemHeight = 4 * COLOR_BOX_HEIGHT;
			break;
		case IDR_COLOR_RED:
			lpMIS->itemHeight = 8 * COLOR_BOX_HEIGHT;
			break;
		default:
			lpMIS->itemHeight = COLOR_BOX_HEIGHT;
	}
	lpMIS->itemWidth = COLOR_BOX_WIDTH;
}

void CODmenus::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	
	// RGB in item data
	COLORREF cr = (COLORREF)lpDIS->itemData;

	// For each menu item, there are possibly three things to
	// do. First, we have to determine if the entire item needs
	// to be drawn. This is simply a matter of selecting a brush
	// and filling the rectangle
	if (lpDIS->itemAction & ODA_DRAWENTIRE)
	{
		CBrush br(cr);
		pDC->FillRect(&lpDIS->rcItem, &br);
	}

	// Next, if an item's selection state has changed, we
	// determine if it has changed to selected and if it has
	// we need to hilite its frame. By also checking for
	// ODA_DRAWENTIRE, we force the first item in the menu to
	// be selected when it is drawn. 
	if ((lpDIS->itemAction & (ODA_SELECT | ODA_DRAWENTIRE))
		&& (lpDIS->itemState & ODS_SELECTED))
	{
		COLORREF crHilite = RGB(255-GetRValue(cr),
						255-GetGValue(cr), 255-GetBValue(cr));
		CBrush br(crHilite);
		pDC->FrameRect(&lpDIS->rcItem, &br);
	}

	// Finally, if an item's selection state has changed and
	// that change is to NOT selected, we need to remove the
	// hiliting frame.
	if ( (lpDIS->itemAction & ODA_SELECT) &&
		!(lpDIS->itemState & ODS_SELECTED))
	{
		CBrush br(cr);
		pDC->FrameRect(&lpDIS->rcItem, &br);
	}
}
