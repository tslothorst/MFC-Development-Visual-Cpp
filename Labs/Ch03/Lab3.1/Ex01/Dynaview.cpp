// DynaView.cpp : implementation of the CMenusDynamicView class
//

#include "stdafx.h"
#include "DynaMenu.h"

#include "DynaMDoc.h"
#include "DynaView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

const COLORREF CYAN=RGB(0,255,255);
const COLORREF PURPLE=RGB(255,0,255);
const COLORREF YELLOW=RGB(255,255,0);

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView

IMPLEMENT_DYNCREATE(CMenusDynamicView, CView)

BEGIN_MESSAGE_MAP(CMenusDynamicView, CView)
	//{{AFX_MSG_MAP(CMenusDynamicView)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView construction/destruction
CMenusDynamicView::CMenusDynamicView()
{
}

CMenusDynamicView::~CMenusDynamicView()
{
}

BOOL CMenusDynamicView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView drawing

void CMenusDynamicView::OnDraw(CDC* pDC)
{
	CMenusDynamicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView diagnostics

#ifdef _DEBUG
void CMenusDynamicView::AssertValid() const
{
	CView::AssertValid();
}

void CMenusDynamicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenusDynamicDoc* CMenusDynamicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenusDynamicDoc)));
	return (CMenusDynamicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView message handlers


// This function converts one of the 7 Command IDs to a COLORREF value.
COLORREF CMenusDynamicView::IDtoColorRef(int nID)
{
	switch (nID)
	{
		case ID_COLORS_RED:
			return RED;
		case ID_COLORS_GREEN:
			return GREEN;		
		case ID_COLORS_BLUE:
			return BLUE;
		case ID_COLORS_CYAN:
			return CYAN;
		case ID_COLORS_PURPLE:
			return PURPLE;
		case ID_COLORS_YELLOW:
			return YELLOW;
		default:
			return BLACK;		
	}
}
