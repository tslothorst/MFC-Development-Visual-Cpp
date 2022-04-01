// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PrPrevue.h"

#include "MainFrm.h"

#include "printdoc.h"
#include "prinview.h"

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
	ON_UPDATE_COMMAND_UI(ID_DUMMY_PAGELENGTH, OnUpdatePagelength)
	ON_WM_WININICHANGE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_DUMMY_PAGELENGTH,
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
void CMainFrame::OnUpdatePagelength(CCmdUI* pCmdUI) 
{
	CPrintView * cpv;
	CString s;

	cpv = (CPrintView *)GetActiveView();

	// When Print Preview has been activated, a different
	// view is active, so we don't want to update the status bar.
	if (cpv->GetRuntimeClass() == RUNTIME_CLASS(CPrintView))
	{
		s.Format("Page Length: %d", cpv->GetPageLength());
		pCmdUI->SetText(s);
	}
}

void CMainFrame::OnWinIniChange(LPCTSTR lpszSection) 
{
	CFrameWnd::OnWinIniChange(lpszSection);

	if (0 == lstrcmp(lpszSection, "windows"))
	{
		CPrintApp * cpa = (CPrintApp *)::AfxGetApp();
		cpa->QueryPrinterAndSetMaxLines();

		CPrintView *cpv = (CPrintView *)GetActiveView();
		cpv->SetPageLength(cpa->GetMaxPageLength());
	}
}
