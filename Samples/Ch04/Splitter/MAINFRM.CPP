// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "splitter.h"

#include "MainFrm.h"

#include "SplitDoc.h"
#include "SpltView.h"
#include "ItalView.h"

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
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

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

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
#if 0
	// This is the code for a dynamic splitter.
	CSize minWindow(10, 10);
	
	// These variables must both be 1 or 2 for dynamic splitters.
	int nRows = 2, nColumns = 2;
	
	return m_wndSplitter.Create(this, nRows, nColumns,
								minWindow, pContext);
#endif

#if 1
	// This is the code for a static splitter.
	CRect cr;
	GetClientRect(&cr);

	CSize paneSize(cr.Width(), cr.Height() / 2);

	int rc;
	m_wndSplitter.CreateStatic(this, 2, 1);

	rc = m_wndSplitter.CreateView(0, 0,
								RUNTIME_CLASS(CSplitterView),
								paneSize, pContext);

	// The view that is associated with the document when the template
	// is created can also be specified this way.
	// rc = m_wndSplitter.CreateView(0, 0,
	// 							pContext->m_pNewViewClass,
	// 							paneSize, pContext);

	if (FALSE == rc)
		return rc;
	
	rc = m_wndSplitter.CreateView(1, 0,
								RUNTIME_CLASS(CItalicsView),
								paneSize, pContext);
	return rc;
#endif
}

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);
const COLORREF WHITE=RGB(255,255,255);

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

// In an application with multiple views displayed, as in this app's
// 2 panes, it's necessary to place command handlers in the frame class
// so their associated menus are available regardless of which pane
// currently has the focus.
void CMainFrame::OnColors(UINT nID)
{
	CSplitterDoc* pDoc = (CSplitterDoc*) GetActiveDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	// When a single view is involved, we'd call
	//      Invalidate();
	// but when there's more than 1 view, call
	pDoc->UpdateAllViews(NULL);
}

void CMainFrame::OnUpdateColors(CCmdUI* pCmdUI)
{
	CSplitterDoc* pDoc = (CSplitterDoc*) GetActiveDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

