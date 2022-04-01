// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DlgBars.h"

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
	ON_COMMAND(ID_VIEW_MYDIALOGBAR, OnViewDialogbar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MYDIALOGBAR, OnUpdateViewDialogbar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
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

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

// Everything from here to end of this function was added to 
// create and initialize the dialog bar.
	EnableDocking(CBRS_ALIGN_ANY);

 	// Programmer coded this to provide a Dialog Bar for the application.
	// The first 32 IDs for CMainFrame should not be used, hence the 33.
	// See comments in afxres.h and TN 31.
	if (! m_wndDialogBar.Create(this, IDD_DIALOG_BAR, 
					CBRS_TOP | CBRS_TOOLTIPS | CBRS_FLYBY,
					ID_VIEW_MYDIALOGBAR))
	{
		TRACE0("Failed to create dialog bar m_wndDialogBar\n");
		return -1; // fail to create
	}

	// Command buttons on a Dialog Bar work properly just by having the
	// same command ID as the corresponding menu item. 
	// In this way they behave like toolbar icons.

	// Icons, however, must also have their Notify properties set. 
	// Then they behave like ordinary toolbar icons.

	// Being a combo box, IDC_LIST_COLORS was populated at design time
	// The combo box has its command handler in the view class which
	// facilitates access to the document class. See the view class, and
	// in particular its message map, for details.
	CComboBox * p_lb = (CComboBox *)m_wndDialogBar.GetDlgItem(IDC_LIST_COLORS);
	p_lb->SetCurSel(0);

	// Also, an entry was added to the string table to so that tooltips
	// will be shown whenever the mouse cursor is over the list box.
	// See string table and entry IDC_LIST_COLORS.

	m_wndDialogBar.EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	DockControlBar(&m_wndDialogBar);

	return 0;
}

void CMainFrame::OnViewDialogbar() 
{
	OnBarCheck(ID_VIEW_MYDIALOGBAR);
}

void CMainFrame::OnUpdateViewDialogbar(CCmdUI* pCmdUI) 
{
	OnUpdateControlBarMenu(pCmdUI);
}


