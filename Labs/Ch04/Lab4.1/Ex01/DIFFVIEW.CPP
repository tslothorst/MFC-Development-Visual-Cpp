// DiffView.cpp : implementation of the CDiffView class
//

#include "stdafx.h"
#include "Diff.h"

#include "DiffDoc.h"
#include "DiffView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiffView

IMPLEMENT_DYNCREATE(CDiffView, CView)

BEGIN_MESSAGE_MAP(CDiffView, CView)
	//{{AFX_MSG_MAP(CDiffView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiffView construction/destruction

CDiffView::CDiffView()
{
	// TODO: add construction code here

}

CDiffView::~CDiffView()
{
}

BOOL CDiffView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDiffView drawing

void CDiffView::OnDraw(CDC* pDC)
{
	CDiffDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDiffView printing

BOOL CDiffView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDiffView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDiffView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDiffView diagnostics

#ifdef _DEBUG
void CDiffView::AssertValid() const
{
	CView::AssertValid();
}

void CDiffView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDiffDoc* CDiffView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDiffDoc)));
	return (CDiffDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiffView message handlers
