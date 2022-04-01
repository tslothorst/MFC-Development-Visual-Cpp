// MDIView.cpp : implementation of the CMDIAppView class
//

#include "stdafx.h"
#include "MDIApp.h"

#include "MDIDoc.h"
#include "MDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView

IMPLEMENT_DYNCREATE(CMDIAppView, CView)

BEGIN_MESSAGE_MAP(CMDIAppView, CView)
	//{{AFX_MSG_MAP(CMDIAppView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView construction/destruction

CMDIAppView::CMDIAppView()
{
}

CMDIAppView::~CMDIAppView()
{
}

BOOL CMDIAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView drawing

void CMDIAppView::OnDraw(CDC* pDC)
{
	CMDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView printing

BOOL CMDIAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDIAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDIAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView diagnostics

#ifdef _DEBUG
void CMDIAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIAppDoc* CMDIAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIAppDoc)));
	return (CMDIAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIAppView message handlers

void CMDIAppView::OnColors(UINT nID)
{
	CMDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	
	// If this were an SDI app then you'd call
		// Invalidate();
	// Since it's an MDI app, you have to call
	pDoc->UpdateAllViews(NULL);
}

void CMDIAppView::OnUpdateColors(CCmdUI* pCmdUI)
{
	CMDIAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

// This function converts one of the 4 Command IDs to a COLORREF value.
COLORREF CMDIAppView::IDtoColorRef(int nID)
{
	switch (nID)
	{
		case ID_COLORS_RED:
			return RED;
		case ID_COLORS_GREEN:
			return GREEN;		
		case ID_COLORS_BLUE:
			return BLUE;
		default:
			return BLACK;		
	}
}
