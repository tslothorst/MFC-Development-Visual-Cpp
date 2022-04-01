// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MDI2ViewsB.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_ITALICS, OnWindowItalics)
	ON_COMMAND(ID_WINDOW_NEW, OnWindowItalics)
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
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
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
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CMDIFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnWindowItalics() 
{
	// We'll need a pointer to the active child...
	CMDIChildWnd* pChild = MDIGetActive();
	if (NULL == pChild)
	{
		TRACE0("Warning: No active child.\n");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
		return;     // command failed
	}
	
	// and to the active document...
	CDocument* pDoc = pChild->GetActiveDocument();
	if (NULL == pDoc)
	{
		TRACE0("Warning: No active document.\n");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
		return;     // command failed
	}

	// and to the application object.
	CMDI2ViewsBApp * pApp = (CMDI2ViewsBApp *)AfxGetApp();

	// Since both menu selections end up here (see message map)
	MSG const * pMsg = GetCurrentMessage();
	CMultiDocTemplate * pTemplate;

	// we need to know how we got here to figure out which template to use...
	if (LOWORD(pMsg->wParam) == ID_WINDOW_ITALICS)
		pTemplate = pApp->m_pItalicsTemplate;
	else
		pTemplate = pApp->m_pDefaultTemplate;

	// so that finally we can create a new frame...
	CFrameWnd* pFrame = pTemplate->CreateNewFrame(pDoc, pChild);
	if (NULL == pFrame)
	{
		TRACE0("Warning: failed to create new frame.\n");
		return;     // command failed
	}

	// which is then updated.
	pTemplate->InitialUpdateFrame(pFrame, pDoc);
}
