// WebView.cpp : implementation of the CWebView class
//

#include "stdafx.h"
#include "Web.h"

#include "WebDoc.h"
#include "WebView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CWebView

IMPLEMENT_DYNCREATE(CWebView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebView, CHtmlView)
	//{{AFX_MSG_MAP(CWebView)
	ON_COMMAND(ID_GOBACK, OnGoback)
	ON_COMMAND(ID_GOFORWARD, OnGoforward)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CHtmlView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebView construction/destruction

CWebView::CWebView()
{
	// TODO: add construction code here

}

CWebView::~CWebView()
{
}

BOOL CWebView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWebView drawing

void CWebView::OnDraw(CDC* pDC)
{
	CWebDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

void CWebView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	Navigate2(_T("http://www.microsoft.com/visualc/"),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CWebView printing

BOOL CWebView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWebView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWebView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWebView diagnostics

#ifdef _DEBUG
void CWebView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebDoc* CWebView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebDoc)));
	return (CWebDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebView message handlers

void CWebView::OnGoback() 
{
	// TODO: Add your command handler code here
	CHtmlView::GoBack();
}

void CWebView::OnGoforward() 
{
	// TODO: Add your command handler code here
	CHtmlView::GoForward();
}
