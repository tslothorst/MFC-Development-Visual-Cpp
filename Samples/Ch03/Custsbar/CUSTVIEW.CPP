// CustView.cpp : implementation of the CCustomStatusBarView class
//

#include "stdafx.h"
#include "CustSBar.h"

#include "MyStatBa.h"
#include "MainFrm.h"

#include "CustSDoc.h"
#include "CustView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);
const COLORREF WHITE=RGB(255,255,255);

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarView

IMPLEMENT_DYNCREATE(CCustomStatusBarView, CView)

BEGIN_MESSAGE_MAP(CCustomStatusBarView, CView)
	//{{AFX_MSG_MAP(CCustomStatusBarView)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarView construction/destruction

CCustomStatusBarView::CCustomStatusBarView()
{
}

CCustomStatusBarView::~CCustomStatusBarView()
{
}

BOOL CCustomStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarView drawing

void CCustomStatusBarView::OnDraw(CDC* pDC)
{
	CCustomStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
	
	//Invalidate status bar to enable repainting
	CMainFrame * cmf = (CMainFrame *)GetParent();
	UINT mID;
	switch(pDoc->GetColor())
	{
		case RED:
			mID = IDM_REDBITMAP;
			break;
		case GREEN:
			mID = IDM_GREENBITMAP;
			break;
		case BLUE:
			mID = IDM_BLUEBITMAP;
			break;
		default:
			mID = IDM_BLACKBITMAP;
	}
	cmf->pt.bitmapID = mID;

	// Force the status bar to be redrawn.
	cmf->m_wndStatusBar.Invalidate();
	
}

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarView diagnostics

#ifdef _DEBUG
void CCustomStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CCustomStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCustomStatusBarDoc* CCustomStatusBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCustomStatusBarDoc)));
	return (CCustomStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarView message handlers

// This function converts one of the 4 Command IDs to a COLORREF value.
COLORREF CCustomStatusBarView::IDtoColorRef(int nID)
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

void CCustomStatusBarView::OnColors(UINT nID)
{
	CCustomStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Change the color (stored in the document class)
	// and invalidate the view.
	pDoc->SetColor(IDtoColorRef(nID));
	Invalidate();

}

void CCustomStatusBarView::OnUpdateColors(CCmdUI* pCmdUI)
{
	CCustomStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}


void CCustomStatusBarView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
}
