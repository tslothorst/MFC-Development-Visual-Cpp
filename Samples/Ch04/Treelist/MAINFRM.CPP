// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "tree.h"

#include "AnmlData.h"

#include "treeDoc.h"
#include "TreeView.h"
#include "ListView.h"

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
	ON_COMMAND(ID_EDIT_ADDANIMAL, OnEditAddAnimal)
	ON_COMMAND(ID_EDIT_MODIFYANIMAL, OnEditModifyAnimal)
	ON_COMMAND(ID_EDIT_DELETEANIMAL, OnEditDeleteAnimal)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETEANIMAL, OnUpdateEditDeleteAnimal)
	ON_UPDATE_COMMAND_UI(ID_EDIT_MODIFYANIMAL, OnUpdateEditModifyAnimal)
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

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// This is the code for a static splitter.

	// Create a splitter window with 1 row, 2 columns.
	m_wndSplitter.CreateStatic(this, 1, 2);

	CRect cr;
	GetClientRect(&cr);

	// The left pane holds the tree view.
	int rc = m_wndSplitter.CreateView(0, 0,
								RUNTIME_CLASS(CSimpleTreeView),
								CSize(cr.Width() / 2, cr.Height()),
								pContext);
	if (FALSE == rc)
		return rc;

	// The right pane holds the list view.
	rc = m_wndSplitter.CreateView(0, 1,
								RUNTIME_CLASS(CSimpleListView),
								CSize(cr.Width() / 2, cr.Height()),
								pContext);
	return rc;
}

// These 3 command handlers (and UI functions for 2 of them) are placed
// in the frame class to make them available regardless of which view has
// focus. The actual code that does the work is placed in the tree view class.
void CMainFrame::OnEditAddAnimal() 
{
	CTreeDoc * pDoc = (CTreeDoc *) GetActiveDocument();
	pDoc->m_pTreeView->EditSelection();
}

void CMainFrame::OnEditModifyAnimal() 
{
	CTreeDoc * pDoc = (CTreeDoc *) GetActiveDocument();
	pDoc->m_pTreeView->ModifySelection();
}

void CMainFrame::OnEditDeleteAnimal() 
{
	CTreeDoc * pDoc = (CTreeDoc *) GetActiveDocument();
	pDoc->m_pTreeView->DeleteSelection();
}

// Only enable the delete menu if a specific animal is selected.
// Do not enable if node at level 0 or level 1 is selected.
void CMainFrame::OnUpdateEditDeleteAnimal(CCmdUI* pCmdUI) 
{
	CTreeDoc * pDoc = (CTreeDoc *) GetActiveDocument();
	CTreeCtrl & ctc = pDoc->m_pTreeView->GetTreeCtrl();

	HTREEITEM selectedNode = ctc.GetSelectedItem();
	if (selectedNode == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD itemData = ctc.GetItemData(selectedNode);
		if (0 == itemData || -1 == itemData)
			pCmdUI->Enable(FALSE);
		else
			pCmdUI->Enable(TRUE);
	}
}

// The modify menu is enabled if a level 1 node OR an animal is selected.
// Do not enable if node at level 0 is selected.
void CMainFrame::OnUpdateEditModifyAnimal(CCmdUI* pCmdUI) 
{
	CTreeDoc * pDoc = (CTreeDoc *) GetActiveDocument();
	CTreeCtrl & ctc = pDoc->m_pTreeView->GetTreeCtrl();

	HTREEITEM selectedNode = ctc.GetSelectedItem();
	if (selectedNode == NULL)
		pCmdUI->Enable(FALSE);
	else
	{
		DWORD itemData = ctc.GetItemData(selectedNode);
		if (0 == itemData)
			pCmdUI->Enable(FALSE);
		else
		{
			pCmdUI->Enable(TRUE);
			if (-1 == itemData)
				pCmdUI->SetText("&Modify Type");
			else
				pCmdUI->SetText("&Modify Animal");
		}
	}
}
