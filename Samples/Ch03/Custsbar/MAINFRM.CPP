// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CustSBar.h"

#include "MyStatBa.h"

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
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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
	
	if (FALSE == BuildStatusBar())
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::BuildStatusBar()
{
	CRect rcSB(0, 0, 0, 0);

	if (!m_wndStatusBar.Create(
		WS_VISIBLE | WS_CHILD | CCS_BOTTOM | SBARS_SIZEGRIP, 
		rcSB, this, AFX_IDW_STATUS_BAR))
	{
		TRACE0("Failed to create status bar\n");
		return FALSE;
	}

	// The actual work of determining the number of panes,
	// their types and contents is performed in the status
	// bar's own OnSize function. However, it's necessary
	// here to initialize the structure that is passed to
	// pane 3, which is an owner draw pane. See comments in
	// the status bar's DrawItem function, and the view
	// class's command handler which sets the text color.
	pt.bitmapID = IDM_BLACKBITMAP;

	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	
	// Force the status bar to move also, but only if its Create
	// function has been called, which instantiates its m_hWnd.
	if (m_wndStatusBar.m_hWnd)
		m_wndStatusBar.MoveWindow(0, cy, cx, cy, TRUE);	
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// This turns out to be, perhaps, the easiest way to integrate
	// the custom status bar into the application's command
	// routing scheme.
	m_wndStatusBar.DetermineKeyboardState();
	m_wndStatusBar.DetermineTextColor();
		
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
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
