// DlgBarsView.cpp : implementation of the CDlgBarsView class
//

#include "stdafx.h"
#include "DlgBars.h"

#include "DlgBarsDoc.h"
#include "DlgBarsView.h"

#include "mainfrm.h"

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
// CDlgBarsView

IMPLEMENT_DYNCREATE(CDlgBarsView, CView)

BEGIN_MESSAGE_MAP(CDlgBarsView, CView)
	//{{AFX_MSG_MAP(CDlgBarsView)
	ON_CBN_SELCHANGE(IDC_LIST_COLORS, OnSelchangeListColors)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsView construction/destruction

CDlgBarsView::CDlgBarsView()
{
}

CDlgBarsView::~CDlgBarsView()
{
}

BOOL CDlgBarsView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsView drawing

void CDlgBarsView::OnDraw(CDC* pDC)
{
	CDlgBarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsView diagnostics

#ifdef _DEBUG
void CDlgBarsView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgBarsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgBarsDoc* CDlgBarsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgBarsDoc)));
	return (CDlgBarsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsView message handlers
void CDlgBarsView::OnColors(UINT nID)
{
	CDlgBarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));

	// The view needs a pointer to the dialog bar's combo box.
	// since the dialog bar is a member of the main frame class,
	// we must first obtain a pointer to the main frame object.
	CMainFrame * cmf = (CMainFrame *)AfxGetMainWnd();
	CComboBox * p_cb = 
		(CComboBox *)cmf->m_wndDialogBar.GetDlgItem(IDC_LIST_COLORS);

	p_cb->SetCurSel(nID - ID_COLORS_BLACK);

	pDoc->UpdateAllViews(NULL);
}

void CDlgBarsView::OnUpdateColors(CCmdUI* pCmdUI)
{
	CDlgBarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->Enable(pDoc->GetColor() != IDtoColorRef(pCmdUI->m_nID));
}

// This function converts one of the 4 Command IDs to a COLORREF value.
COLORREF CDlgBarsView::IDtoColorRef(int nID)
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

// This function handles the combo box on the dialog bar. This function could 
// just as easily have been placed in the CMainFrame class. Placing this function
// in the view class places it close to all other command handlers, which generally
// need access to the document class.
void CDlgBarsView::OnSelchangeListColors() 
{
	CMainFrame * cmf = (CMainFrame *)AfxGetMainWnd();
	CComboBox * p_cb = (CComboBox *)cmf->m_wndDialogBar.GetDlgItem(IDC_LIST_COLORS);

	// Convert 0-3 to ID_COLORS_BLACK - ID_COLORS_BLUE, 
	// then call the color menu's command handler
	
	WPARAM wParam = p_cb->GetCurSel() + ID_COLORS_BLACK;
	this->SendMessage(WM_COMMAND, wParam);
}
