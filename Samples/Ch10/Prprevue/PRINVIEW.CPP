// PrinView.cpp : implementation of the CPrintView class
//

#include "stdafx.h"
#include "PrPrevue.h"
#include "PrintDoc.h"
#include "PrinView.h"
#include "Dialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintView

IMPLEMENT_DYNCREATE(CPrintView, CScrollView)

BEGIN_MESSAGE_MAP(CPrintView, CScrollView)
	//{{AFX_MSG_MAP(CPrintView)
	ON_COMMAND(ID_FILE_LINESPERPAGE, OnFileLinesperpage)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPrintView construction/destruction

CPrintView::CPrintView()
{
	CPrintApp * cpa = (CPrintApp *)::AfxGetApp();
	SetPageLength(cpa->GetMaxPageLength());
}

CPrintView::~CPrintView()
{
}

BOOL CPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView drawing
void CPrintView::OnDraw(CDC* pDC)
{
	int BeginningRow, EndingRow, i, x, y;
	TEXTMETRIC tm;
	CPoint pt;
	CRect rect;
	CString s;

	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDC->GetTextMetrics(&tm);
	pt = GetScrollPosition();
  
	// In the interest of efficiency, only display as many rows of the
	// simulated document as the view's height will allow. This requires
	// knowing 2 things: the current vertical scroll position...
	BeginningRow = pt.y / tm.tmHeight;

	// and the current height of the view window, which determines
	// how many 'rows' can be displayed.
	GetClientRect(&rect);
	EndingRow = BeginningRow + rect.Height() / tm.tmHeight;
	
	// However, don't attempt to display more lines than exist
	// in the document.
	if (EndingRow > pDoc->LinesOnDocument())
		EndingRow = pDoc->LinesOnDocument();
		
	x = 0;
	y = BeginningRow * tm.tmHeight;
	for (i = BeginningRow; i <= EndingRow; i++, y += tm.tmHeight)
		pDC->TextOut(x, y, pDoc->GetLine(i + 1));
}

void CPrintView::OnPaint() 
{
	// The first 3 lines exactly mimic CView::OnPaint
	CPaintDC dc(this);
	OnPrepareDC(&dc);
	OnDraw(&dc);

	// By placing this call, and hence the page break-showing code,
	// in OnPaint, we insure that page breaks won't show up in
	// Print Preview, which calls OnDraw via another method.
	ShowPageBreaks(&dc);
}

void CPrintView::ShowPageBreaks(CDC* pDC)
{
	int y, x2, h, interval, limit;
	CPen grayPen, *oldPen;
	CPrintDoc* pDoc;
	CRect rect;
	CPoint pt;
	TEXTMETRIC tm;

	pDoc = GetDocument();
	pDC->GetTextMetrics(&tm);
	interval = GetPageLength() * tm.tmHeight;
	limit = pDoc->LinesOnDocument() * tm.tmHeight;

	GetClientRect(&rect);
	x2 = rect.Width();
	h = rect.Height();

	pt = GetScrollPosition();	

	grayPen.CreatePen(PS_DOT, 0, RGB(128, 128, 128));
	oldPen = pDC->SelectObject(&grayPen);
	
	for (y = interval; y <= limit; y += interval)
	{
		// These 2 statement optimize the loop so drawing is
		// never even attempted outside the clipping region.
		if (y < pt.y) continue;
		if (y > pt.y + h) break;

		pDC->MoveTo(0, y);
		pDC->LineTo(x2, y);
	}
	
	pDC->SelectObject(oldPen);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView printing
BOOL CPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// In this function, we can modify the behavior of the printer
	// dialog box before it's displayed. It's best to determine the
	// number of pages in the print job AFTER the dialog box has been
	// displayed.
	pInfo->m_pPD->m_pd.Flags |= PD_DISABLEPRINTTOFILE;
	
	return DoPreparePrinting(pInfo);
}

void CPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int y = pDC->GetDeviceCaps(VERTRES);

	// Allow for 3 lines at the top and 2 at the bottom
	int lines = (y / tm.tmHeight) - 5;

	// It's possible that the user has changed the printer
	// such that the number of lines it supports is less than
	// what the user currently wants. If so, both the desired
	// lines per page (stored in the view object) and the maximum
	// number of lines the current printer mode supports 
	// (stored in the app object) will have to be changed.
	if (lines < GetPageLength())
	{
		SetPageLength(lines);
		CPrintApp * cpa = (CPrintApp *)::AfxGetApp();
		cpa->SetMaxPageLength(lines);
	}

	// The max page needs to be rounded up if the number of
	// lines to be printed isn't exactly divisible by
	// the lines per page.
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int pagecount = pDoc->LinesOnDocument() / GetPageLength();
	if ( 0 != (pDoc->LinesOnDocument() % GetPageLength()) )
		pagecount++;

	pInfo->SetMaxPage(pagecount);
	
	CScrollView::OnBeginPrinting(pDC, pInfo);
}

void CPrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CScrollView::OnPrepareDC(pDC, pInfo);
	
	// On a scroll view, if you want to modify the DC, do it AFTER
	// the call to the base class version.
	// Just for demo purposes, this program prints odd-numbered
	// pages shifted 500 printer units to the right.
	if (pDC->IsPrinting())
		if (0 == (pInfo->m_nCurPage & 1))
			pDC->SetViewportOrg(0, 0);
		else
			pDC->SetViewportOrg(500, 0);
}

void CPrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	int BeginningRow, EndingRow, i, x, y;
	TEXTMETRIC tm;
	CSize cs;
	CString s;
	
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDC->GetTextMetrics(&tm);
  
	// From the page currently being printed, determine the
	// starting row of this simulated text document.
	BeginningRow = (pInfo->m_nCurPage - 1) * GetPageLength();

	// From that determine the ending row, which can't be
	// greater than the number of lines in the document.
	EndingRow = BeginningRow + GetPageLength();
	if (EndingRow > pDoc->LinesOnDocument())
		EndingRow = pDoc->LinesOnDocument();

	// Load the page header from the string table, then print it
	// centered at the top of the page.
	s.LoadString(IDS_COMPANY_LOGO);
	cs = pDC->GetTextExtent(s);
	x = pDC->GetDeviceCaps(HORZRES);
	pDC->TextOut((x - cs.cx) / 2, 0, s);
	
	// Print the requested number of lines on the current page.
	y = 3 * tm.tmHeight;
	for (i = BeginningRow; i < EndingRow; i++, y += tm.tmHeight)
		pDC->TextOut(0, y, pDoc->GetLine(i + 1));

	// Print the page footer, centered on the bottom line.
	s.Format(IDS_PAGE, pInfo->m_nCurPage);
	cs = pDC->GetTextExtent(s);
	y = pDC->GetDeviceCaps(VERTRES);
	pDC->TextOut((x - cs.cx) / 2, y - cs.cy, s);

	// Since this isn't a WYSIWYG application, the base class's function should not
	// be called, since it would then call OnDraw, which in this application is
	// intended ONLY for screen display.
	//CScrollView::OnPrint(pDC, pInfo);
}

void CPrintView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// Since this app allocated no GDI resources in OnBeginPriting,
	// there's nothing to do in OnEndPrinting.
	CScrollView::OnEndPrinting(pDC, pInfo);
}

void CPrintView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView) 
{
	// We want to be able to scroll in the view to the page corresponding
	// to where the user scrolled during print preview.

	// The pDC argument points to a printer DC. We need a DC for the view.	
	CClientDC dc(this);
	
	// We'll need to know a character's height.
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	
	CPoint pt;
	// Simple multiplication determines the point.
	pt.y = (pInfo->m_nCurPage - 1) * tm.tmHeight * GetPageLength();
	pt.x = 0;
	ScrollToPosition(pt);

	CScrollView::OnEndPrintPreview(pDC, pInfo, point, pView);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView message handlers

void CPrintView::OnFileLinesperpage() 
{
	CLinesDLG dlg;

	dlg.m_linesPerPage = GetPageLength();
	CPrintApp * cpa = (CPrintApp *)::AfxGetApp();
	dlg.m_MaxPageLength = cpa->GetMaxPageLength();

	// If user selected OK and a change was made, re-do everything.
	if (IDOK == dlg.DoModal())
		if (GetPageLength() != dlg.m_linesPerPage)
		{
			SetPageLength(dlg.m_linesPerPage);
			SetScrollingAttributes();
		}
}

void CPrintView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	SetScrollingAttributes();
}

void CPrintView::SetScrollingAttributes()
{
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CSize sizeTotal, sizePage, sizeLine;

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	// Calculate the total size of this view
	sizeTotal.cx = 80 * tm.tmMaxCharWidth;
	// Note: this value cannot exceed 32767
	sizeTotal.cy = pDoc->LinesOnDocument() * tm.tmHeight;	 

	// Scroll one letter in either direction when
	// clicking on a scroll bar's arrows.
	// Current page length when clicking in the vertical shaft.
	// 5 characters when clicking in the horizontal shaft.
	sizeLine.cx = tm.tmAveCharWidth;
	sizeLine.cy = tm.tmHeight;
	sizePage.cx = 5 * tm.tmAveCharWidth;
	sizePage.cy = GetPageLength() * tm.tmHeight;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
	Invalidate();
}

BOOL CPrintView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// If we're scrolling in the vertical direction by use of the
	// thumbtack, we only want to scroll in units equal to a character's
	// height. nPos is adjusted so it's always equal to some multiple
	// of a character's height.
	if (SB_THUMBTRACK == HIBYTE(nScrollCode))
	{
		TEXTMETRIC tm;
		CClientDC dc(this);
		dc.GetTextMetrics(&tm);
		while ((nPos % tm.tmHeight) != 0)
			nPos--;
	}

	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintView diagnostics
#ifdef _DEBUG
void CPrintView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPrintView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPrintDoc* CPrintView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDoc)));
	return (CPrintDoc*)m_pDocument;
}
#endif //_DEBUG
