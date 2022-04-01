// TabbView.cpp : implementation of the CTabbedColorPhraseView class
//

#include "stdafx.h"
#include "Tabbed.h"

#include "ClrLstBx.H"
#include "ColorTab.H"
#include "PhrasTab.H"

#include "TabbeDoc.h"
#include "TabbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseView

IMPLEMENT_DYNCREATE(CTabbedColorPhraseView, CView)

BEGIN_MESSAGE_MAP(CTabbedColorPhraseView, CView)
	//{{AFX_MSG_MAP(CTabbedColorPhraseView)
	ON_COMMAND(ID_MODIFY_SHOWTABBEDDIALOGBOX, OnModifyShowtabbeddialogbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseView construction/destruction

CTabbedColorPhraseView::CTabbedColorPhraseView()
{
}

CTabbedColorPhraseView::~CTabbedColorPhraseView()
{
}

BOOL CTabbedColorPhraseView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseView drawing

void CTabbedColorPhraseView::OnDraw(CDC* pDC)
{
	CTabbedColorPhraseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseView diagnostics

#ifdef _DEBUG
void CTabbedColorPhraseView::AssertValid() const
{
	CView::AssertValid();
}

void CTabbedColorPhraseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabbedColorPhraseDoc* CTabbedColorPhraseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabbedColorPhraseDoc)));
	return (CTabbedColorPhraseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseView message handlers

void CTabbedColorPhraseView::OnModifyShowtabbeddialogbox() 
{
	CTabbedColorPhraseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Create each property page object and initialize
	// as appropriate.
	CPhraseTab phraseTab;
	phraseTab.m_phrase = pDoc->GetPhrase();
	
	CColorTab colorTab;
	colorTab.m_color = pDoc->GetColor();

	// Create the property sheet object and give it a title.
	CPropertySheet cps("Modify Phrase or Color");

	// Add the largest property page first.
	cps.AddPage(&phraseTab);
	cps.AddPage(&colorTab);
	
	// Since this is being displayed modally instead of
	// modelessly, remove the Apply button, which appears
	// by default on Property Sheets.
	cps.m_psh.dwFlags |= PSH_NOAPPLYNOW;
	
	// If the user clicks on OK and either color or phrase
	// has changed, update the document and invalidate the view.
	if (IDOK == cps.DoModal())
		if (pDoc->GetPhrase() != phraseTab.m_phrase ||
			 pDoc->GetColor() != colorTab.m_color)
		{
			pDoc->SetColor(colorTab.m_color);
			pDoc->SetPhrase(phraseTab.m_phrase);
			Invalidate();
		}
}
