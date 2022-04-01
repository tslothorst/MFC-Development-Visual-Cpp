// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MDI2Views.h"

#include "mdi2viewsdoc.h"
#include "italicsview.h"
#include "childfrm.h"

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
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_ITALICS, OnWindowItalics)
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
  	m_pItalicsTemplate = 0;
}

CMainFrame::~CMainFrame()
{
	if	(0 != m_pItalicsTemplate)
	{
		delete m_pItalicsTemplate;
	  	m_pItalicsTemplate = 0;
	}
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
	// The italics template is NOT added to the app's
	// list of templates. Whenever the app's list contains
	// more than 1 template, a list box is presented to the
	// user when the app starts asking which type of view
	// should be used.	By maintaining it myself, I easily
	// avoid that situation. This other template is destroyed
	// in the main frame's d'tor.
	
	// Don't create the second template until it's actually
	// needed, and then only do it once.
	if (0 == m_pItalicsTemplate)
	{
		m_pItalicsTemplate = new CMultiDocTemplate(
			IDR_MDI2VITYPE,
			RUNTIME_CLASS(CMDI2ViewsDoc),
			RUNTIME_CLASS(CChildFrame),
			RUNTIME_CLASS(CItalicsView));
	}

	ASSERT (m_pItalicsTemplate != 0);

	// To begin, we'll need a pointer to the active document.
	// This is obtained from the active child.
	CMDIChildWnd* pActiveChild = MDIGetActive();
	CDocument* pDocument;
	if (NULL == pActiveChild ||
	  (pDocument = pActiveChild->GetActiveDocument()) == NULL)
	{
		TRACE0("Warning: No active document for WindowNew command.\n");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE);
		return;     // command failed
	}

	CFrameWnd* pFrame = m_pItalicsTemplate->
					CreateNewFrame(pDocument, pActiveChild);
	if (NULL == pFrame)
	{
		TRACE0("Warning: failed to create new frame.\n");
		return;     // command failed
	}

	m_pItalicsTemplate->InitialUpdateFrame(pFrame, pDocument);
}
