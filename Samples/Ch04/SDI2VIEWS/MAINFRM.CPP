// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SDI2Views.h"

#include "SDI2ViewsDoc.h"
#include "ItalicsView.h"
#include "DefaultView.h"

#include "MainFrm.h"

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
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_DEFAULT, OnViewDefault)
	ON_COMMAND(ID_VIEW_ITALICS, OnViewItalics)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DEFAULT, OnUpdateViewDefault)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ITALICS, OnUpdateViewItalics)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// To give this SDI app 2 views, the main frame stores
	// pointers to them both. 
	m_pItalicsView = 0;
	m_pDefaultView = 0;
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

void CMainFrame::OnViewDefault() 
{
	CDocument* pDoc = GetActiveDocument();

	// The UI handler will prevent this function executing before
	// OnViewItalics, but just in case...
	ASSERT (m_pItalicsView != 0);
	ASSERT (m_pDefaultView != 0);

	pDoc->AddView(m_pDefaultView);

	// Show the default view and hide the italics view.
	m_pDefaultView->ShowWindow(SW_SHOW);
	m_pItalicsView->ShowWindow(SW_HIDE);

	// Swap IDs. See comment in next function.
	m_pDefaultView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	m_pItalicsView->SetDlgCtrlID(AFX_IDW_PANE_FIRST + 1);
	
	SetActiveView(m_pDefaultView);
	
	// The program will be a bit more efficient if the
	// unused view is removed. This way it won't receive
	// update messages whenever CDocument::UpdateAllViews is called.
	pDoc->RemoveView(m_pItalicsView);
	RecalcLayout();
}

void CMainFrame::OnViewItalics() 
{
	CDocument* pDoc = GetActiveDocument();
	
	// Only need to do this one time.
	if (0 == m_pItalicsView)
	{
		m_pDefaultView = (CDefaultView *)GetActiveView();
		// This object is destroyed in main frame's d'tor.
		m_pItalicsView = new CItalicsView(NULL);

		m_pItalicsView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
				rectDefault, this, AFX_IDW_PANE_FIRST + 1);
	}

	pDoc->AddView(m_pItalicsView);

	// Set the child i.d. of the italics view to AFX_IDW_PANE_FIRST,
	// so that CFrameWnd::RecalcLayout will allocate to this 
	// "first pane" that portion of the frame window's client area 
	// not allocated to control bars.  Set the child i.d. of the 
	// default view to AFX_IDW_PANE_FIRST + 1
	m_pItalicsView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	m_pDefaultView->SetDlgCtrlID(AFX_IDW_PANE_FIRST+1);
	
	// Show the italics view and hide the default view.
	m_pItalicsView->ShowWindow(SW_SHOW);
	m_pDefaultView->ShowWindow(SW_HIDE);
	
	SetActiveView(m_pItalicsView);

	// See comment in OnViewDefault.
	pDoc->RemoveView(m_pDefaultView);
	RecalcLayout();
}

void CMainFrame::OnUpdateViewDefault(CCmdUI* pCmdUI) 
{
	// Only enable the default view menu if the current view
	// is the italics view.
	pCmdUI->Enable(
		GetActiveView()->IsKindOf(RUNTIME_CLASS(CItalicsView)));
}

void CMainFrame::OnUpdateViewItalics(CCmdUI* pCmdUI) 
{
	// Only enable the italics view menu if the current view
	// is the default view.
	pCmdUI->Enable(
		GetActiveView()->IsKindOf(RUNTIME_CLASS(CDefaultView)));
}

void CMainFrame::OnColors(UINT nID)
{
	CSDI2ViewsDoc* pDoc = (CSDI2ViewsDoc*)GetActiveDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	Invalidate();
}

void CMainFrame::OnUpdateColors(CCmdUI* pCmdUI)
{
	CSDI2ViewsDoc* pDoc = (CSDI2ViewsDoc*)GetActiveDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

// This function converts one of the 4 Command IDs to a COLORREF value.
COLORREF CMainFrame::IDtoColorRef(int nID)
{
	switch (nID)
	{
		case ID_COLORS_RED:
			return RED;
		case ID_COLORS_GREEN:
			return GREEN;		
		case ID_COLORS_BLUE:
			return BLUE;
		default:
			return BLACK;		
	}
}
