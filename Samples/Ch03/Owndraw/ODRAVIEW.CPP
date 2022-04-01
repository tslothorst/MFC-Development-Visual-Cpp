// ODraView.cpp : implementation of the COwnerDrawMenusView class
//

#include "stdafx.h"
#include "OwnDraw.h"

#include "ODrawDoc.h"
#include "ODraView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusView

IMPLEMENT_DYNCREATE(COwnerDrawMenusView, CView)

BEGIN_MESSAGE_MAP(COwnerDrawMenusView, CView)
	//{{AFX_MSG_MAP(COwnerDrawMenusView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusView construction/destruction

COwnerDrawMenusView::COwnerDrawMenusView()
{
}

COwnerDrawMenusView::~COwnerDrawMenusView()
{
}

BOOL COwnerDrawMenusView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusView drawing

void COwnerDrawMenusView::OnDraw(CDC* pDC)
{
	COwnerDrawMenusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusView diagnostics

#ifdef _DEBUG
void COwnerDrawMenusView::AssertValid() const
{
	CView::AssertValid();
}

void COwnerDrawMenusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COwnerDrawMenusDoc* COwnerDrawMenusView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COwnerDrawMenusDoc)));
	return (COwnerDrawMenusDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusView message handlers
