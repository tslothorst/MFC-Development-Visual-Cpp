// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "OwnDraw.h"

#include "ODrawMnu.h"
#include "BMapMenu.H"

#include "ODrawDoc.H"
#include "ODraView.H"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDR_COLOR_FIRST, IDR_COLOR_LAST, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(IDR_COLOR_FIRST, IDR_COLOR_LAST, OnUpdateColors)
END_MESSAGE_MAP()

void CMainFrame::OnUpdateColors(CCmdUI* pCmdUI)
{
	COwnerDrawMenusDoc * pDoc;
	pDoc = (COwnerDrawMenusDoc *) GetActiveDocument();
	
	// This will set a check mark on the bitmap menu.
	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

static UINT indicators[] =
{
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	AttachOwnerDrawMenu();
	AttachBitmapMenu();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::AttachBitmapMenu()
{
	// Append 4 menus to the empty menu object m_bitmapMenu
	// (which is an object of a custom class and is a member
	// of the frame class).  Each appended menu has its own bitmap.
	// For simplicity's sake, each bitmap menu item will use
	// the same ID as the corresponding owner draw menus.
	for (int iColor = 0; iColor <= (IDR_COLOR_LAST-IDR_COLOR_FIRST); iColor++)
	{
		// Skip Cyan, which is the 3rd color.
		if (3 == iColor) continue;
		m_bitmapMenu.AppendBitmapMenuItem(IDR_COLOR_FIRST + iColor);
	}

	// Replace the specified menu item with a color popup
	//  (note: will only work once)
	CMenu* pMenuBar = GetMenu();
	ASSERT(pMenuBar != NULL);
	
	TCHAR szString[256];
	// Colors is the 5th (4th from 0) menu. We want its string.
	pMenuBar->GetMenuString(4, szString, sizeof(szString),
							MF_BYPOSITION);

	// Make the newly created menu become the 5th menu's popup.
	pMenuBar = GetMenu();
	ASSERT(pMenuBar != NULL);
	pMenuBar->ModifyMenu(4, MF_BYPOSITION | MF_POPUP,
						(UINT)m_bitmapMenu.m_hMenu, szString);
}

void CMainFrame::AttachOwnerDrawMenu()
{
	// Append 4 menus to the empty menu object m_colorMenu
	// (which is an object of a custom class and is a member
	// of the frame class).  Each appended menu is owner drawn.
	for (int iColor = 0; iColor <= (IDR_COLOR_LAST-IDR_COLOR_FIRST); iColor++)
	{
		// Skip Cyan, which is the 3rd color.
		if (3 == iColor) continue;

		// 3 bit encoded RGB values
		BYTE red = (BYTE)(((iColor & 4) != 0) * 255);
		BYTE green = (BYTE)(((iColor & 2) != 0) * 255);
		BYTE blue = (BYTE)((iColor & 1) * 255);
	
		// Each appended menu has an RGB value associated with it
		// that will be passed to DrawItem in the itemData variable.
		// See DrawItem.
		m_ownerDrawMenu.AppendMenu(MF_ENABLED | MF_OWNERDRAW, 
				IDR_COLOR_FIRST + iColor, (LPCTSTR)RGB(red, green, blue));
	}

	// Replace the specified menu item with a color popup
	//  (note: will only work once)
	CMenu* pMenuBar = GetMenu();
	ASSERT(pMenuBar != NULL);
	
	TCHAR szString[256];
	// Colors is the 4th (3rd from 0) menu. We want its string.
	pMenuBar->GetMenuString(3, szString, sizeof(szString),
							MF_BYPOSITION);

	// Make the newly created menu become the 4th menu's popup.
	pMenuBar->ModifyMenu(3, MF_BYPOSITION | MF_POPUP,
						(UINT)m_ownerDrawMenu.m_hMenu, szString);
}

void CMainFrame::OnColors(UINT nID) 
{
	// Change the color, which is stored in the document.
	COwnerDrawMenusDoc * pDoc;
	pDoc = (COwnerDrawMenusDoc *) GetActiveDocument();
	pDoc->SetColor(IDtoColorRef(nID));

	// Invalidate the view to force a redraw.
	COwnerDrawMenusView * pView;
	pView = (COwnerDrawMenusView *) GetActiveView();
	pView->Invalidate();
}

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

// This function converts one of the 4 Command IDs
// to a COLORREF value.
COLORREF CMainFrame::IDtoColorRef(int nID)
{
	switch (nID)
	{
		case IDR_COLOR_RED:
			return RED;
		case IDR_COLOR_GREEN:
			return GREEN;		
		case IDR_COLOR_BLUE:
			return BLUE;
		default:
			return BLACK;		
	}
}
