// SpltView.cpp : implementation of the CSplitterView class
//

#include "stdafx.h"
#include "splitter.h"

#include "SplitDoc.h"
#include "spltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterView

IMPLEMENT_DYNCREATE(CSplitterView, CScrollView)

BEGIN_MESSAGE_MAP(CSplitterView, CScrollView)
	//{{AFX_MSG_MAP(CSplitterView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterView construction/destruction

CSplitterView::CSplitterView()
{
}

CSplitterView::~CSplitterView()
{
}

BOOL CSplitterView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterView drawing

void CSplitterView::OnDraw(CDC* pDC)
{
	CSplitterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterView diagnostics

#ifdef _DEBUG
void CSplitterView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSplitterView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSplitterDoc* CSplitterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterDoc)));
	return (CSplitterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterView message handlers

void CSplitterView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	SetScrollSizes(MM_TEXT, CSize(640, 480));
}
