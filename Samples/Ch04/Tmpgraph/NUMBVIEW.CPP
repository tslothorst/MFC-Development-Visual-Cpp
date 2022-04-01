// NumbView.cpp : implementation file
//

#include "stdafx.h"
#include "TmpGraph.h"
#include "TGrafDoc.h"
#include "NumbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemperatureNumbersView

IMPLEMENT_DYNCREATE(CTemperatureNumbersView, CView)

CTemperatureNumbersView::CTemperatureNumbersView()
{
}

CTemperatureNumbersView::~CTemperatureNumbersView()
{
}


BEGIN_MESSAGE_MAP(CTemperatureNumbersView, CView)
	//{{AFX_MSG_MAP(CTemperatureNumbersView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemperatureNumbersView drawing

void CTemperatureNumbersView::OnDraw(CDC* pDC)
{
	const int DAYS = 31;
	CTemperatureGraphDoc * pDoc = GetDocument();

	CFont *	prevFont = (CFont*)
		pDC->SelectStockObject(ANSI_FIXED_FONT);

	UINT oldAlignment = pDC->GetTextAlign();

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	CRect rect;
	GetClientRect(&rect);

	CString s;
	int i, x, y;

	// Display a header line, centered in the bottom pane.
	pDC->SetTextAlign(TA_CENTER);
	s.Format("Daily high temperatures (Celsius) for %s in %s, %d",
			(LPCTSTR) pDoc->m_city, (LPCTSTR) pDoc->m_month,
			pDoc->m_year);
	pDC->TextOut (rect.Width() / 2, 0, s);
	
	// Now that the heading line is displayed, move the origin
	// down 2 lines and display the numbers. This is slightly
	// easier than adjusting the y location in code.
	pDC->SetViewportOrg(0, 2 * tm.tmHeight);
	pDC->SetTextAlign(TA_LEFT);

	for(i = 0; i < pDoc->temps.GetSize(); i++)
	{
		s.Format("%2d: %2d", pDoc->temps[i].x + 1, pDoc->temps[i].y);
		if (i < DAYS)
		{
			x = i / 6 * 100;
			y = i % 6 * tm.tmHeight;
		}
		else
		// 31 is a special case to make it appear in last column.
		{
			x = 4 * 100;
			y = 6 * tm.tmHeight;
		}
		
		pDC->TextOut(x, y, s);
	}

	pDC->SelectObject(prevFont);
	pDC->SetTextAlign(oldAlignment);
}

/////////////////////////////////////////////////////////////////////////////
// CTemperatureNumbersView diagnostics
#ifdef _DEBUG

void CTemperatureNumbersView::AssertValid() const
{
	CView::AssertValid();
}

void CTemperatureNumbersView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTemperatureGraphDoc* CTemperatureNumbersView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTemperatureGraphDoc)));
	return (CTemperatureGraphDoc*)m_pDocument;
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTemperatureNumbersView message handlers
