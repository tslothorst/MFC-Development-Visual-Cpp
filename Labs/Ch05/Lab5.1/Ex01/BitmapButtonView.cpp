// BitmapButtonView.cpp : implementation of the CBitmapButtonView class
//

#include "stdafx.h"
#include "BitmapButton.h"

#include "BitmapButtonDoc.h"
#include "BitmapButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonView

IMPLEMENT_DYNCREATE(CBitmapButtonView, CEditView)

BEGIN_MESSAGE_MAP(CBitmapButtonView, CEditView)
	//{{AFX_MSG_MAP(CBitmapButtonView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonView construction/destruction

CBitmapButtonView::CBitmapButtonView()
{
	// TODO: add construction code here

}

CBitmapButtonView::~CBitmapButtonView()
{
}

BOOL CBitmapButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonView drawing

void CBitmapButtonView::OnDraw(CDC* pDC)
{
	CBitmapButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonView diagnostics

#ifdef _DEBUG
void CBitmapButtonView::AssertValid() const
{
	CEditView::AssertValid();
}

void CBitmapButtonView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CBitmapButtonDoc* CBitmapButtonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapButtonDoc)));
	return (CBitmapButtonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonView message handlers
