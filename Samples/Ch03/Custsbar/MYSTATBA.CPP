// StatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "CustSBar.h"
#include "MyStatBa.h"

#include "CustSDoc.h"

#include "mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBar

CCustomStatusBar::CCustomStatusBar()
{
}

CCustomStatusBar::~CCustomStatusBar()
{
}

BEGIN_MESSAGE_MAP(CCustomStatusBar, CStatusBarCtrl)
	//{{AFX_MSG_MAP(CCustomStatusBar)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBar message handlers
void CCustomStatusBar::DrawItem(LPDRAWITEMSTRUCT lpdis)
{
	// Handle drawing of the ownerdraw pane(s) of the
	// CGraphicStatusBar object.

	CDC dc;
	dc.m_hDC = lpdis->hDC;

	// The parameter gives us a rectangle that needs to be drawn
	CRect rect(lpdis->rcItem);

	// itemData gives us a pointer to a structure that contains
	// the ID of the bitmap that is to be drawn in the current.
	// This structure was originally filled by CMainFrame, and
	// then changed by the View's event handler that modifies
	// the displayed color.
	CBitmap Bitmap;
	PaneTool *pt = (PaneTool *)lpdis->itemData;
	Bitmap.LoadBitmap(pt->bitmapID);

	CDC srcDC;
	srcDC.CreateCompatibleDC(NULL);
	srcDC.SelectObject(&Bitmap);
	dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),
				&srcDC, 0, 0, SRCCOPY);
}

void CCustomStatusBar::OnSize(UINT nType, int cx, int cy) 
{
	CStatusBarCtrl::OnSize(nType, cx, cy);

	int aWidths[5] = {cx / 2, cx / 2 + 30, cx / 2 + 100,
						cx / 2 + 130, -1};
	SetParts(5, aWidths);

	// Pane 0's text is written by the framework for menu and
	// toolbar status, so nothing needs to be done. The framework
	// will only do this if the custom status bar is given the ID
	// AFX_IDW_STATUS_BAR in the call to Create.

	// Pane 1 shows the status of the Caps Lock key. 
	// Also See CMainFrame::OnCmdMsg
	DetermineKeyboardState();

	// Pane 2 has static text.
	DetermineTextColor();

	// Pane 3 has a bitmap placed in it. Thus it has to have
	// owner draw. We pass it the address of a structure that
	// contains the bitmap's ID.
	CMainFrame * cmf = (CMainFrame *)GetParent();
	SetText((LPCTSTR) &cmf->pt, 3, SBT_OWNERDRAW);

	// Pane 4 will, width -1, takes over the rest of the
	// status bar and contains the sizing grip.
}

void CCustomStatusBar::DetermineTextColor()
{
	CMainFrame * cmf = (CMainFrame *)GetParent();
	CCustomStatusBarDoc * ccsbd = 
		(CCustomStatusBarDoc *)cmf->GetActiveDocument();

	CString color = "Black";
	
	// If the document doesn't exist yet, just set the color
	// to black.
	if (0 != ccsbd)
		// Convert an RGB value to a CString.
		switch (ccsbd->GetColor())
		{
			case RED:
				color = "Red";
				break;
			case GREEN:
				color = "Green";
				break;
			case BLUE:
				color = "Blue";
				break;
		}

	SetText(color, 2, 0);
}

void CCustomStatusBar::DetermineKeyboardState()
{
	// We completely take over writing the word CAP.
	BYTE ks[256];
	
	GetKeyboardState(ks);

	CRect rect;
	GetRect(1, &rect);
	rect.OffsetRect(3, 2);

	CClientDC dc(this);
	CFont * cf = GetFont();
	if (cf)
		dc.SelectObject(cf);
	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(GetSysColor(COLOR_MENU));
	
	if (ks[VK_CAPITAL] & 1)
		dc.SetTextColor(RGB(0, 0, 0));
	else
		dc.SetTextColor(RGB(127,127,127));

	dc.DrawText("CAP", rect, DT_LEFT);
}

