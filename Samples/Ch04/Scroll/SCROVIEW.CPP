// ScroView.cpp : implementation of the CMyScrollView class
//

#include "stdafx.h"
#include "Scroll.h"

#include "ScrolDoc.h"
#include "ScroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView

IMPLEMENT_DYNCREATE(CMyScrollView, CScrollView)

BEGIN_MESSAGE_MAP(CMyScrollView, CScrollView)
	//{{AFX_MSG_MAP(CMyScrollView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView construction/destruction

CMyScrollView::CMyScrollView()
{
}

CMyScrollView::~CMyScrollView()
{
}

BOOL CMyScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView drawing

void CMyScrollView::OnDraw(CDC* pDC)
{
	CScrollDoc * pDoc = GetDocument();
	CPoint pt = pDoc->GetLocation();
	pDC->TextOut(pt.x, pt.y, pDoc->GetPhrase());
}

void CMyScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	
	sizeTotal.cx = sizeTotal.cy = 200;
	SetScrollSizes(MM_TEXT, sizeTotal);

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView diagnostics

#ifdef _DEBUG
void CMyScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMyScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CScrollDoc* CMyScrollView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollDoc)));
	return (CScrollDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView message handlers

// The CPoint argument represents the location of the mouse in
// device (physical) coordinates. OnDraw, which will be called
// as a result of the call to Invalidate at the end of this
// function, always draws to logical space. Therefore the CPoint
// argument must be converted to logical coordinates before storing
// the new location into the document object. To show the necessity
// of doing this, comment out the first 3 lines of this function,
// re-compile and execute.
void CMyScrollView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Create a client dc that points to the current view
	CClientDC dc(this);

	// Given that this is a scroll view, call OnPrepareDC to
	// adjust attributes of the device context appropriately.
	OnPrepareDC(&dc);

	dc.DPtoLP(&point);

	// Store the new location in the document and invalidate the view.
	CScrollDoc * pDoc = GetDocument();
	pDoc->SetLocation(point);
	
	Invalidate();
	
	CScrollView::OnLButtonDown(nFlags, point);
}
