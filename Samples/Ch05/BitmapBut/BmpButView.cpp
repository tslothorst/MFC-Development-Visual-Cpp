// BmpBut.cpp : implementation of the CBmpButView class
//

#include "stdafx.h"
#include "BmpBut.h"

#include "BmpButDoc.h"
#include "BmpButView.h"
#include "resource.h"

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
// CBmpButView

IMPLEMENT_DYNCREATE(CBmpButView, CView)

BEGIN_MESSAGE_MAP(CBmpButView, CView)
	//{{AFX_MSG_MAP(CBmpButView)
	ON_COMMAND_RANGE(ID_COLORS_RED, ID_COLORS_BLUE, OnColors)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpButView construction/destruction
CBmpButView::CBmpButView()
{
}

CBmpButView::~CBmpButView()
{
}

BOOL CBmpButView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBmpButView drawing

void CBmpButView::OnDraw(CDC* pDC)
{
	CBmpButDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CBmpButView diagnostics

#ifdef _DEBUG
void CBmpButView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpButView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpButDoc* CBmpButView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpButDoc)));
	return (CBmpButDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBmpButView message handlers

void CBmpButView::OnColors(UINT nID)
{
	CBmpButDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	Invalidate();
}

// This function converts one of the 7 Command IDs to a COLORREF value.
COLORREF CBmpButView::IDtoColorRef(int nID)
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
