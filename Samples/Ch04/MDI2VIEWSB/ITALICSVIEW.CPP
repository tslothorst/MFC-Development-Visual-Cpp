// ItalicsView.cpp : implementation file
//

#include "stdafx.h"
#include "MDI2ViewsB.h"

#include "MDI2ViewsBDoc.h"
#include "ItalicsView.h"

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
	CMDI2ViewsBDoc* pDoc = GetDocument();
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

	CRect rect;
	GetClientRect(&rect);
	int x = rect.Width() / 2;
	int y = rect.Height() / 2;

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

void CItalicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDI2ViewsBDoc* CItalicsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI2ViewsBDoc)));
	return (CMDI2ViewsBDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CItalicsView message handlers
