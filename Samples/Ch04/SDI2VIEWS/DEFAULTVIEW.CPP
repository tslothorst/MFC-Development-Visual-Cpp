// DefaultView.cpp : implementation of the CNormalView class
//

#include "stdafx.h"
#include "SDI2Views.h"

#include "SDI2ViewsDoc.h"
#include "DefaultView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDefaultView

IMPLEMENT_DYNCREATE(CDefaultView, CView)

BEGIN_MESSAGE_MAP(CDefaultView, CView)
	//{{AFX_MSG_MAP(CDefaultView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDefaultView construction/destruction

CDefaultView::CDefaultView()
{
}

CDefaultView::~CDefaultView()
{
}

BOOL CDefaultView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDefaultView drawing

void CDefaultView::OnDraw(CDC* pDC)
{
	CSDI2ViewsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rect;
	GetClientRect(&rect);
	int x = rect.Width() / 2;
	int y = rect.Height() / 2;

	pDC->SetTextAlign(TA_BASELINE | TA_CENTER);
	pDC->SetTextColor(pDoc->GetColor());

	pDC->TextOut(x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CDefaultView diagnostics

#ifdef _DEBUG
void CDefaultView::AssertValid() const
{
	CView::AssertValid();
}

void CDefaultView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDI2ViewsDoc* CDefaultView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDI2ViewsDoc)));
	return (CSDI2ViewsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDefaultView message handlers


