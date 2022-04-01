// diffView.cpp : implementation of the CDiffView class
//

#include "stdafx.h"
#include "diff.h"

#include "diffDoc.h"
#include "diffView.h"
#include "progress.h"
#include "splitter.h"
#include "mainfrm.h"
#include "resource.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiffView

IMPLEMENT_DYNCREATE(CDiffView, CRichEditView)

BEGIN_MESSAGE_MAP(CDiffView, CRichEditView)
	ON_WM_CONTEXTMENU()
	//{{AFX_MSG_MAP(CDiffView)
	ON_WM_DROPFILES()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EDIT_FONT, OnEditFont)
	ON_COMMAND(IDC_EDIT_COLOR_ADDITIONS, OnEditColorAdditions)
	ON_COMMAND(IDC_EDIT_COLOR_DELETIONS, OnEditColorDeletions)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
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

	return CRichEditView::PreCreateWindow(cs);
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
	CRichEditView::AssertValid();
}

void CDiffView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CDiffDoc* CDiffView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDiffDoc)));
	return (CDiffDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiffView message handlers

void CDiffView::OnInitialUpdate() 
{
	CRichEditView::OnInitialUpdate();
	
	GetRichEditCtrl().SetReadOnly();
	
}

void CDiffView::OnDropFiles(HDROP hDropInfo) 
{
	CDiffApp::GetApp()->GetMainFrame()->
		SendMessage ( WM_DROPFILES,
					  (WPARAM)hDropInfo);
	//Don't call the default -- we don't want OLE
	//embedding behavior	
	//CRichEditView::OnDropFiles(hDropInfo);
}

void CDiffView::OnContextMenu(CWnd *pWnd, CPoint point)
{
	UNUSED_ALWAYS (pWnd);	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_POPUP_DIFF_VIEW));

	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	if (pPopup != NULL)
		pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}

void CDiffView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	
	//CRichEditView::OnRButtonUp(nFlags, point);
	ClientToScreen (&point);
	OnContextMenu ((CWnd *)NULL, point);

}

void CDiffView::OnEditFont() 
{
	AfxMessageBox ("In OnEditFont()");
	
}


void CDiffView::OnEditColorAdditions() 
{
	AfxMessageBox ("In OnEditColorAdditions()");
	
}

void CDiffView::OnEditColorDeletions() 
{
	AfxMessageBox ("In OnEditColorDeletions()");
	
}
