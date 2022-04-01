// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "diff.h"

#include "progress.h"
#include "splitter.h"
#include "MainFrm.h"
#include "diffdoc.h"
#include "diffview.h"

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
	ON_COMMAND(ID_VIEW_DIALOGBAR, OnViewDialogbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DIALOGBAR, OnUpdateViewDialogbar)
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
	
	//Added for Dialog Bar Lab
	//Create a dialog bar object as a child of the main frame
	//This dialog bar is, in effect, a modeless dialog
	//The main frame will handle the messages for the dialog bar

	m_wndDialogBar.Create( this,	//Parent window is the main frame
					IDD_DIALOGBAR,	//The graphic resource
					CBRS_TOP,		//Align to the top of the frame
					ID_VIEW_DIALOGBAR);	//Control's ID
	
	m_wndDialogBar.EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndDialogBar);
	m_wndDialogBar.SetBarStyle(m_wndDialogBar.GetBarStyle() |
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
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CDiffView),size, pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CDiffView),size, pContext);
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

		((CDiffDoc *)GetActiveDocument())->
							RunComparison (File1, File2);

		::DragFinish(hDropInfo);
	}

}

void CMainFrame::OnViewDialogbar() 
{
	// TODO: Add your command handler code here
	//Dialog Bar lab
	ShowControlBar( & m_wndDialogBar,
		! m_wndDialogBar.IsWindowVisible( ),FALSE );
}

void CMainFrame::OnUpdateViewDialogbar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//Dialog Bar lab
	pCmdUI->SetCheck( m_wndDialogBar.IsWindowVisible( ) );
}

void CMainFrame::SetList( int nID, const CString & strFile )
{
	//Dialog Bar lab
	AddItem( nID, strFile );
	CComboBox * pCmb = 
		( CComboBox * ) m_wndDialogBar.GetDlgItem( nID );
	pCmb->SelectString( -1, strFile ); //Start search at top
}

void CMainFrame::AddItem( int nID, const CString & str )
{
	//Dialog Bar lab
	CComboBox * pCmb = 
		( CComboBox * ) m_wndDialogBar.GetDlgItem( nID );
	if ( CB_ERR == pCmb->FindString( -1, str ) )//Search from top
		pCmb->AddString( str );
}

void CMainFrame::ResetFile( int nID, const CString & str )
{
	//Dialog Bar lab
	if ( str.IsEmpty( ) )  //Nothing to do
		return;
	int pane = LEFT == nID ? 0 : 1; //pane 0 is left, pane 1 is right
	
	//Get the appropriate pane, Row 0, Column left or right
	CDiffView * pView = ( CDiffView * ) m_wndSplitter.GetPane( 0, pane );
	
	//Load the pane from the drive using the view's Serialize function
	if ( NULL != pView )
	{
		CFile file( str, CFile::modeRead );
		CArchive ar( & file, CArchive::load );
		pView->Serialize( ar );

		//Update the document data member (we're a friend)
		CDiffDoc * pDoc = pView->GetDocument( );
		if ( LEFT == nID )
			pDoc->m_File1 = str;
		else
			pDoc->m_File2 = str;
	}
}


