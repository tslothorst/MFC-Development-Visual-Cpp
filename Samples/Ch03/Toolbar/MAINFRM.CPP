// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Toolbar.h"

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
	ON_WM_CLOSE()
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_COLORTOOLBAR, OnViewColortoolbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLORTOOLBAR, OnUpdateViewColortoolbar)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
	:m_pColorToolbar(0)
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	WINDOWPLACEMENT wp;
	if (LoadWindowPlacement (&wp))
	{
		wp.showCmd = AfxGetApp()->m_nCmdShow;
		SetWindowPlacement (&wp);
	}
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	// or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't 
	// want the toolbar to be dockable
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

void CMainFrame::OnViewColortoolbar() 
{
	// The very first time, the toolbar needs to be created.
	// m_pColorToolbar is a pointer that is a member of
	// CMainFrame. See OnDestroy for the code that deletes
	// the object allocated here.
	if (0 == m_pColorToolbar)
	{
		m_pColorToolbar = new CToolBar;
		CString ErrMsg;
		if (0 == m_pColorToolbar->Create(this))
		{
			ErrMsg.LoadString(IDS_COLORTB_CREATE);
			::AfxMessageBox(ErrMsg);
			return;
		}
		if (0 == m_pColorToolbar->LoadToolBar(IDR_COLOR_TOOLBAR))
		{
			ErrMsg.LoadString(IDS_COLORTB_LOAD);
			::AfxMessageBox(ErrMsg);
			return;
		}
		m_pColorToolbar->EnableDocking(CBRS_ALIGN_ANY);
		
		DockControlBar(m_pColorToolbar);
	}
	else
		// If the window is visible, hide it.
		if(m_pColorToolbar->IsWindowVisible() == TRUE)
			ShowControlBar(m_pColorToolbar, FALSE, FALSE);
		else
			// Otherwise, show it.
			ShowControlBar(m_pColorToolbar, TRUE, FALSE);
}

void CMainFrame::OnUpdateViewColortoolbar(CCmdUI* pCmdUI) 
{
	// Initially, the color toolbar pointer is 0, so the UI
	// handler must not call IsWindowVisible unless the 
	// toolbar has been created.
	if (0 == m_pColorToolbar)
		pCmdUI->SetCheck(FALSE);
	else
		if(m_pColorToolbar->IsWindowVisible() == TRUE)
			pCmdUI->SetCheck(TRUE);
		else
			pCmdUI->SetCheck(FALSE);
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	
	// Since the color toolbar was dynamically created,
	// it must be destroyed when the frame is destroyed.
	if (0 != m_pColorToolbar)
	{
		delete m_pColorToolbar;
		m_pColorToolbar = 0;
	}
}

BOOL CMainFrame::LoadWindowPlacement (LPWINDOWPLACEMENT pwp)
{
	CString strBuffer = 
		AfxGetApp()->GetProfileString ("Settings", "WindowPos");

	if (strBuffer.IsEmpty ())
		return FALSE;

	int cRead = _stscanf (strBuffer, "%i:%i:%i:%i:%i:%i:%i:%i:%i:%i",
			&pwp->flags, &pwp->showCmd,
			&pwp->ptMinPosition.x, &pwp->ptMinPosition.y,
			&pwp->ptMaxPosition.x, &pwp->ptMaxPosition.y,
			&pwp->rcNormalPosition.left, &pwp->rcNormalPosition.top,
			&pwp->rcNormalPosition.right, &pwp->rcNormalPosition.bottom);

	if (cRead != 10)
		return FALSE;

	return TRUE;
}

VOID CMainFrame::SaveWindowPlacement (LPWINDOWPLACEMENT pwp)
{
	CString strBuffer;
	strBuffer.Format ("%i:%i:%i:%i:%i:%i:%i:%i:%i:%i",
		pwp->flags, pwp->showCmd,
		pwp->ptMinPosition.x, pwp->ptMinPosition.y,
		pwp->ptMaxPosition.x, pwp->ptMaxPosition.y,
		pwp->rcNormalPosition.left, pwp->rcNormalPosition.top,
		pwp->rcNormalPosition.right, pwp->rcNormalPosition.bottom);

	AfxGetApp()->WriteProfileString("Settings", "WindowPos", strBuffer);
}

void CMainFrame::OnClose()
{
	WINDOWPLACEMENT wp;
	if (GetWindowPlacement (&wp))
	{
		if (IsZoomed ())
			wp.flags |= WPF_RESTORETOMAXIMIZED;

		SaveWindowPlacement (&wp);
	}
	CFrameWnd::OnClose ();
}
