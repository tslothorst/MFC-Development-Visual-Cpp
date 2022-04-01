// ComboEx.cpp : implementation of the CComboExView class
//

#include "stdafx.h"
#include "ComboEx.h"

#include "ComboExDoc.h"
#include "ComboExView.h"
#include "resource.h"
#include "ComboExDlg.h"	

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CComboExView

IMPLEMENT_DYNCREATE(CComboExView, CView)

BEGIN_MESSAGE_MAP(CComboExView, CView)
	//{{AFX_MSG_MAP(CComboExView)
	ON_COMMAND(ID_COLORS, OnColors)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboExView construction/destruction
CComboExView::CComboExView()
{
}

CComboExView::~CComboExView()
{
}

BOOL CComboExView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CComboExView drawing

void CComboExView::OnDraw(CDC* pDC)
{
	CComboExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CComboExView diagnostics

#ifdef _DEBUG
void CComboExView::AssertValid() const
{
	CView::AssertValid();
}

void CComboExView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComboExDoc* CComboExView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComboExDoc)));
	return (CComboExDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CComboExView message handlers

void CComboExView::OnColors()
{
	CComboExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CComboExDlg comboExDlg;
	comboExDlg.DoModal();
	pDoc->SetColor(comboExDlg.m_Color);
	Invalidate();
}

