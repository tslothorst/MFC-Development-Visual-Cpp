// TbarView.cpp : implementation of the CAdditionalToolbarsView class
//

#include "stdafx.h"
#include "Toolbar.h"

#include "TBarDoc.h"
#include "TbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsView

IMPLEMENT_DYNCREATE(CAdditionalToolbarsView, CView)

BEGIN_MESSAGE_MAP(CAdditionalToolbarsView, CView)
	//{{AFX_MSG_MAP(CAdditionalToolbarsView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsView construction/destruction

CAdditionalToolbarsView::CAdditionalToolbarsView()
{
}

CAdditionalToolbarsView::~CAdditionalToolbarsView()
{
}

BOOL CAdditionalToolbarsView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsView drawing

void CAdditionalToolbarsView::OnDraw(CDC* pDC)
{
	CAdditionalToolbarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsView diagnostics

#ifdef _DEBUG
void CAdditionalToolbarsView::AssertValid() const
{
	CView::AssertValid();
}

void CAdditionalToolbarsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// non-debug version is inline
CAdditionalToolbarsDoc* CAdditionalToolbarsView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdditionalToolbarsDoc)));
	return (CAdditionalToolbarsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsView message handlers
void CAdditionalToolbarsView::OnColors(UINT nID)
{
	CAdditionalToolbarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	Invalidate();
}

void CAdditionalToolbarsView::OnUpdateColors(CCmdUI* pCmdUI)
{
	CAdditionalToolbarsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

// This function converts one of the 4 Command IDs to a COLORREF value.
COLORREF CAdditionalToolbarsView::IDtoColorRef(int nID)
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
