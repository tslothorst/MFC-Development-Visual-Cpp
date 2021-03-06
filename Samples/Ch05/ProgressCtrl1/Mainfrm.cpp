// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PrgCtrl.h"

#include "splitter.h"
#include "MainFrm.h"
#include "PrgCdoc.h"
#include "PrgCview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
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
	// TODO: add member initialization code here
	
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

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}

BOOL CMainFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
		//
		//	For the difference application, we will create a
		//	static splitter window	with 2 side by side panes.
		//	
	if(!m_wndSplitter.CreateStatic(this,1,2,WS_CHILD))
	{
		return FALSE;
	}

	SIZE size;                                  
	CRect rect;     
	GetClientRect(&rect);   
		
		//
		//	Calculate the size of the splitter panes
		//
	size.cx = (rect.right - m_wndSplitter.GetSplitterWidth())/2;
	size.cy = rect.bottom;

		//
		//	Provide each pane with its own view, the same in this case
		//	but could be different	
		//
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CPrgCtrlView),size, pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CPrgCtrlView),size, pContext);
	//SetActiveView((CView *)m_wndSplitter.GetPane(0,1));
  
	m_wndSplitter.ShowWindow(SW_SHOWNORMAL);
	m_wndSplitter.UpdateWindow();

	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

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

void CMainFrame::OnDropFiles(HDROP hDropInfo) 
{
	UINT nFileCount = ::DragQueryFile (hDropInfo,
										0xFFFFFFFF,
										NULL, 0 );
	ASSERT (nFileCount !=0);

	// we must have at least two files for this function;
	// we will grab only the first two

	if (nFileCount >= 2)
	{
		CString File1;
		CString File2;

		::DragQueryFile (hDropInfo,
						0,
						File1.GetBufferSetLength (_MAX_PATH),
						_MAX_PATH);
		File1.ReleaseBuffer();

		::DragQueryFile (hDropInfo,
						1,
						File2.GetBufferSetLength (_MAX_PATH),
						_MAX_PATH);
		File2.ReleaseBuffer();

		((CPrgCtrlDoc *)GetActiveDocument())->
							RunComparison (File1, File2);

		::DragFinish(hDropInfo);
	}

}
