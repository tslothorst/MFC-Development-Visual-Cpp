// TextView.cpp : implementation of the CTextView class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextView

IMPLEMENT_DYNCREATE(CTextView, CScrollView)

BEGIN_MESSAGE_MAP(CTextView, CScrollView)
	//{{AFX_MSG_MAP(CTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextView construction/destruction

CTextView::CTextView()
		:	m_ViewCharSize(0,0),
			m_DocSize(0,0)

{
	m_pFont = NULL;
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTextView drawing

void CTextView::OnDraw(CDC* pDC)
{
	int nFirstLn, nLastLn;

	ComputeVisibleLines(pDC, nFirstLn, nLastLn);

	int nYPos = - nFirstLn * GetCharSize().cy;
	int nXPos = 4 * GetCharSize().cx;
	OnDraw(pDC, nFirstLn, nLastLn,nXPos,nYPos);
}

void CTextView::OnDraw(CDC* pDC, int nFirstLn, int nLastLn, 
						int nXPos /*= 0*/, int nYPos /*= 0*/)
{
	// 	Select specified font
	CFont* pPreviousFont = pDC->SelectObject(GetFont());

	//	Needed for height of each line
	CSize CharSize = GetCharSize();

	//	Get list of strings from the document
	//	and output them to the display context
	CStringList *pLineList = GetDocument()->GetLineList();

	CString 	strLine;
	POSITION 	pos;
	while (nFirstLn <= nLastLn)
	{
		if( ( pos = pLineList->FindIndex( nFirstLn )) != NULL )
		{
			strLine = pLineList->GetAt(pos); 
			pDC->TabbedTextOut(nXPos, nYPos, strLine, 0, NULL, 0);
			nYPos -= CharSize.cy;
			nFirstLn++;
		}
	}

	//	Cleanup and restore original GDI Objects
	if(pPreviousFont)
	{
		pDC->SelectObject(pPreviousFont);
	}
}

/*
void CTextView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}
*/

CFont *	CTextView::GetFont()
{
	if(m_pFont == NULL)
	{
		m_pFont = new CFont;
		if(m_pFont)
		{
			//	Default to 9 pt Arial
			m_pFont->CreatePointFont(90, "Arial");
		}
	}
	return m_pFont;
}

void CTextView::ComputeViewMetrics()
{
	// get a CDC* for the screen
	CDC* pDC = CDC::FromHandle(::GetDC(NULL));
	int nSaveDC = pDC->SaveDC();

	// select mapping mode
	pDC->SetMapMode(MM_LOENGLISH); 

	// select the font and get its metrics
	CFont* pPreviousFont = pDC->SelectObject(GetFont());
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	//	Calculate view character size
	m_ViewCharSize.cy = tm.tmHeight + tm.tmExternalLeading;
	m_ViewCharSize.cx = tm.tmAveCharWidth;

	// convert to device units to minimize round off error
	pDC->LPtoDP(&m_ViewCharSize);

	//	Calculate document size
	CTextDoc* pDoc = GetDocument();
	m_DocSize.cx = 0;
	m_DocSize.cy = m_ViewCharSize.cy * 
					pDoc->GetLineList()->GetCount();

	// loop through the document and find the longest line
	CString	Line;
	CSize size;
	POSITION pos = pDoc->GetLineList()->GetHeadPosition();
	while( pos != NULL )
	{
		Line = pDoc->GetLineList()->GetNext( pos );
		size = pDC->GetTextExtent(Line, Line.GetLength());
		m_DocSize.cx = max(size.cx, m_DocSize.cx);
	}

	//	Account for our simple margin
	m_DocSize.cx += 4 * m_ViewCharSize.cx;

	// clean up
	if(pPreviousFont)
	{
		pDC->SelectObject(pPreviousFont);
	}
	pDC->RestoreDC(nSaveDC);
	::ReleaseDC(NULL,pDC->GetSafeHdc());
}

void CTextView::ComputeVisibleLines(CDC* pDC, int& nFirst, int& nLast)
{
	int nLineCount = GetDocument()->GetLineList()->GetCount();

	// Get the viewport origin, convert to logical coordinates
	CPoint pt = pDC->GetViewportOrg();
	pDC->DPtoLP(&pt,1);

	// Get the clipping region, in logical coordinates
	CRect rc;
	pDC->GetClipBox(&rc);

	// Get the logical line height
	CSize CharSize = GetCharSize();

	// Compute the first visible line
	// The algorithm for the first visible line is
	//	· Calculate the distance from the top of the viewport to the top of clipping region
	//	· Divide this distance by the height of a line, giving the number of lines
	//	· Ensure that at least one line will be show

	nFirst = min(abs((rc.top - pt.y)/CharSize.cy),
				nLineCount-1);

	// compute the last visible line
	// The algorithm for the last visible line is
	//	· Calculate the number of lines that will fit into the clipping region
	//	· Add that to the starting line
	//	· Add one more line to make sure that partial lines are displayed
	//	· Make sure that this is less than the total number of lines

	nLast = min(abs(rc.Height())/CharSize.cy + nFirst + 1,
				nLineCount-1);
}


/////////////////////////////////////////////////////////////////////////////
// CTextView printing

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTextView diagnostics

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextView message handlers

void CTextView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	ComputeViewMetrics();

	SetScrollSizes(MM_LOENGLISH, GetDocSize());
	Invalidate();
}
