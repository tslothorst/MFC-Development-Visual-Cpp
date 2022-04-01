// DefaultView.cpp : implementation of the CDefaultView class
//

#include "stdafx.h"
#include "MDI2ViewsB.h"

#include "MDI2ViewsBDoc.h"
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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
	// TODO: add construction code here

}

CDefaultView::~CDefaultView()
{
}

BOOL CDefaultView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDefaultView drawing

void CDefaultView::OnDraw(CDC* pDC)
{
	CMDI2ViewsBDoc* pDoc = GetDocument();
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

CMDI2ViewsBDoc* CDefaultView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI2ViewsBDoc)));
	return (CMDI2ViewsBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDefaultView message handlers
