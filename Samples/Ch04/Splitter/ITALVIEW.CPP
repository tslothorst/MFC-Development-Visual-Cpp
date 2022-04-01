// ItalView.cpp : implementation file
//

#include "stdafx.h"
#include "splitter.h"

#include "SplitDoc.h"
#include "ItalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CItalicsView

IMPLEMENT_DYNCREATE(CItalicsView, CView)

CItalicsView::CItalicsView()
{
}

CItalicsView::~CItalicsView()
{
}

BEGIN_MESSAGE_MAP(CItalicsView, CView)
	//{{AFX_MSG_MAP(CItalicsView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CItalicsView drawing

void CItalicsView::OnDraw(CDC* pDC)
{
	CSplitterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CFont * pOldFont, tempFont;
	LOGFONT lf;  

	// Obtain a pointer to the current font.
	pOldFont = pDC->GetCurrentFont();
	
	// Fill this function's LOGFONT object with the current font.
	pOldFont->GetLogFont(&lf);
	
	// Make the desired modification(s).
	lf.lfItalic = TRUE;

	// Fill this function's CFont object with the logfont.
	tempFont.CreateFontIndirect(&lf);

	// Select the new font object into the device context.
	pOldFont = (CFont *) pDC->SelectObject(&tempFont);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());

	// Restore the font that existed at the beginning of this function.
	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CItalicsView diagnostics

#ifdef _DEBUG
void CItalicsView::AssertValid() const
{
	CView::AssertValid();
}

CSplitterDoc* CItalicsView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitterDoc)));
	return (CSplitterDoc*)m_pDocument;
}

void CItalicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CItalicsView message handlers

void CItalicsView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
}
