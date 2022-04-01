// BrowseView.cpp : implementation of the CBrowseView class
//

#include "stdafx.h"

#include "webbrowser2.h"
#include "Browse.h"

#include "BrowseDoc.h"
#include "BrowseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CBrowseView

IMPLEMENT_DYNCREATE(CBrowseView, CView)

BEGIN_MESSAGE_MAP(CBrowseView, CView)
	//{{AFX_MSG_MAP(CBrowseView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowseView construction/destruction

CBrowseView::CBrowseView()
{
	// TODO: add construction code here
	m_pBrowse = NULL;
}

CBrowseView::~CBrowseView()
{
}

BOOL CBrowseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBrowseView drawing

void CBrowseView::OnDraw(CDC* pDC)
{
	CBrowseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBrowseView printing

BOOL CBrowseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBrowseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBrowseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBrowseView diagnostics

#ifdef _DEBUG
void CBrowseView::AssertValid() const
{
	CView::AssertValid();
}

void CBrowseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBrowseDoc* CBrowseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBrowseDoc)));
	return (CBrowseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBrowseView message handlers

int CBrowseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect;
GetClientRect(&rect);
  
// Create the control. 
// IDC_WBC is a unique identifier for the control and was defined
// in Step 3 using a dummy menu item.
m_pBrowse = new CWebBrowser2;
ASSERT(m_pBrowse);
if (!m_pBrowse->Create(NULL,NULL,WS_VISIBLE,rect,this,IDC_WBC))
{
	TRACE("failed to create browser\n");
	delete m_pBrowse;
	m_pBrowse = NULL;
	return 0;
}
  
COleVariant noArg;
m_pBrowse->Navigate("www.microsoft.com", &noArg, &noArg, &noArg, 
					&noArg);

	return 0;
}

void CBrowseView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (m_pBrowse)
{
	m_pBrowse->SetWidth(cx);
	m_pBrowse->SetHeight(cy);
}

}

BOOL CBrowseView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	if(wParam == IDC_WBC)
		::AfxMessageBox("Hello");
	
	return CView::OnNotify(wParam, lParam, pResult);
}
