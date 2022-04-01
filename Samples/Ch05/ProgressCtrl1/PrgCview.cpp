// PrgCtrlView.cpp : implementation of the CPrgCtrlView class
//

#include "stdafx.h"
#include "PrgCtrl.h"

#include "PrgCDoc.h"
#include "PrgCView.h"
#include "splitter.h"
#include "mainfrm.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView

IMPLEMENT_DYNCREATE(CPrgCtrlView, CRichEditView)

BEGIN_MESSAGE_MAP(CPrgCtrlView, CRichEditView)
	//{{AFX_MSG_MAP(CPrgCtrlView)
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView construction/destruction

CPrgCtrlView::CPrgCtrlView()
{
	// TODO: add construction code here

}

CPrgCtrlView::~CPrgCtrlView()
{
}

BOOL CPrgCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView drawing

void CPrgCtrlView::OnDraw(CDC* pDC)
{
	CPrgCtrlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView printing

BOOL CPrgCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPrgCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPrgCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView diagnostics

#ifdef _DEBUG
void CPrgCtrlView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CPrgCtrlView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CPrgCtrlDoc* CPrgCtrlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrgCtrlDoc)));
	return (CPrgCtrlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlView message handlers

void CPrgCtrlView::OnInitialUpdate() 
{
	CRichEditView::OnInitialUpdate();
	
	GetRichEditCtrl().SetReadOnly();
	
}

void CPrgCtrlView::OnDropFiles(HDROP hDropInfo) 
{
	CPrgCtrlApp::GetApp()->GetMainFrame()->
		SendMessage ( WM_DROPFILES,
					  (WPARAM)hDropInfo);
	//Don't call the default -- we don't want OLE
	//embedding behavior	
	//CRichEditView::OnDropFiles(hDropInfo);
}
