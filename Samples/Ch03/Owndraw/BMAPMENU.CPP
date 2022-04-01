// BMapMenu.cpp : implementation file
//

#include "stdafx.h"
#include "OwnDraw.h"
#include "BMapMenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenu
CBitmapMenu::CBitmapMenu()
{
	m_pBitmaps = new CBitmap[4];
	VERIFY(CreateMenu());
}

CBitmapMenu::~CBitmapMenu()
{
	//delete m_pBitmaps;
	Detach();
	ASSERT(m_hMenu == NULL);
}

void CBitmapMenu::AppendBitmapMenuItem(UINT nID)
{
	UINT bitmapID;
	int index;
	
	// Determine which bitmap to load.
	switch (nID)
	{
		case IDR_COLOR_RED:
			index = 0;
			bitmapID = IDB_RED;
			break;
		case IDR_COLOR_GREEN:
			index = 1;
			bitmapID = IDB_GREEN;
			break;
		case IDR_COLOR_BLUE:
			index = 2;
			bitmapID = IDB_BLUE;
			break;
		default:
			index = 3;
			bitmapID = IDB_BLACK;
	}
	
	// Load it into one of the CBitmap objects.
	m_pBitmaps[index].LoadBitmap(bitmapID);
	
	// Append it to the menu. Note that the bitmap MUST
	// be persistent.
	AppendMenu(MF_ENABLED, nID, &m_pBitmaps[index]);
}
