// GrafView.cpp : implementation of the CTemperatureGraphView class
//

#include "stdafx.h"
#include "TmpGraph.h"
#include "TGrafDoc.h"
#include "GrafView.h"

#include <math.h>  // for fabs()

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphView

IMPLEMENT_DYNCREATE(CTemperatureGraphView, CView)

BEGIN_MESSAGE_MAP(CTemperatureGraphView, CView)
	//{{AFX_MSG_MAP(CTemperatureGraphView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphView construction/destruction

CTemperatureGraphView::CTemperatureGraphView()
{
}

CTemperatureGraphView::~CTemperatureGraphView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphView drawing

const int MAXTEMP = 40;
const int MINTEMP = -10;

const int PERCENTAGE = 85;
const int MARGIN = (100 - PERCENTAGE) / 2;

void CTemperatureGraphView::OnDraw(CDC* pDC)
{
	SetMappingMode(pDC);
	DrawAxes(pDC);

	CFont *	prevFont = (CFont*) pDC->SelectStockObject(ANSI_FIXED_FONT);
		DrawHorizontalDecorations(pDC);
		DrawVerticalDecorations(pDC);
	pDC->SelectObject(prevFont);
	
	DrawGraph(pDC);
}

void CTemperatureGraphView::DrawGraph(CDC* pDC)
{
	CTemperatureGraphDoc * pDoc = GetDocument();

	CPen redPen, *oldPen;
	redPen.CreatePen(PS_SOLID,0,RGB(255,0,0));
	oldPen = pDC->SelectObject(&redPen);

	pDC->Polyline(pDoc->temps.GetData(), pDoc->temps.GetSize());
	
	pDC->SelectObject(oldPen);
}

void CTemperatureGraphView::DrawVerticalDecorations(CDC* pDC)
{
	const int LINE_WIDTH = 1;
	int xpos, ypos;

	// Draw tics on the vertical axis every 10 degrees
    for (xpos = LINE_WIDTH, ypos = MAXTEMP; ypos >= MINTEMP; ypos -= 10)
	{
		pDC->MoveTo(-xpos, ypos);
		pDC->LineTo(0, ypos);
	}

	// Draw labels on the vertical axis.
	pDC->SetTextAlign(TA_RIGHT | TA_BASELINE);
    CString s;
	for (xpos = -2, ypos = MAXTEMP; ypos >= MINTEMP; ypos -= 10)
	{
		s.Format("%3d", ypos);
        pDC->TextOut(xpos, ypos, s);
	}
}	

void CTemperatureGraphView::DrawHorizontalDecorations(CDC* pDC)
{
	const int LINE_HEIGHT = 2;
	int xpos, ypos;
	
	// Draw tics on the horizontal axis.
    for (xpos = 1, ypos = LINE_HEIGHT; xpos <= 30; xpos ++)
	{
		pDC->MoveTo(xpos, ypos);
		pDC->LineTo(xpos, -ypos);
	}

	// Draw labels on the horizontal axis.
	pDC->SetTextAlign(TA_CENTER);
	int xval = 3;
	CString s;
    for (xpos = 1, ypos = -LINE_HEIGHT; xpos < 31; xval +=3, xpos += 3)
	{
		s.Format("%2d", xval);
        pDC->TextOut(xpos, ypos, s);
	}
}

void CTemperatureGraphView::SetMappingMode(CDC* pDC)
{
    // Establish a coordinate system that lets me map my own reality.
	pDC->SetMapMode(MM_ANISOTROPIC);
	
	// Set the size of my logical window. There are 31 days in the
	// month, and the temperature varies from MAXTEMP to MINTEMP.
	pDC->SetWindowExt(31, abs(MAXTEMP - MINTEMP));

	CRect me;
	GetClientRect(&me);
	// By default, the viewport considers 
	//		1 that the origin is at the upper left corner and
	//		2 that x increases to the right and y increases downwards
	// We need to alter both of these to make it appropriate for a
	// temperature graph, where the origin is at the left.

	// First, we make it so that Y increases in an upward direction.
	// This is done by making the 2nd argument negative.
	// X is OK as is. To allow a bit of room for some whitespace around
	// the graph, only PERCENTAGE % of the available area is used.
	pDC->SetViewportExt(PERCENTAGE * me.right / 100,
						-(PERCENTAGE * me.bottom / 100));

	// Next, we move the origin to the lower left side, but not all
	// the way to the bottom. X increases to the right of this 
	// point and decreases to the left. Y increases above this point
	// and decreases below it.
	
	// To get the x axis in the right place, we have to do some complicated
	// calculations to the y coordinate. The graph occupies PERCANTAGE
	// of the client area. y = 0 lies MARGIN + the positive amount
	// of the graph. 
	// thus is a fraction of PERCENTAGE.
	int y = MARGIN +
		(int) (fabs(MAXTEMP * 1.0 / (MAXTEMP - MINTEMP)) * PERCENTAGE);
	pDC->SetViewportOrg(2 * MARGIN * me.right / 100, y * me.bottom / 100);
}

void CTemperatureGraphView::DrawAxes(CDC* pDC)
{
	pDC->MoveTo(0, 0);
	pDC->LineTo(30, 0);
    pDC->MoveTo(0, MINTEMP);
	pDC->LineTo(0, MAXTEMP);
}

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphView diagnostics

#ifdef _DEBUG
void CTemperatureGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CTemperatureGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTemperatureGraphDoc* CTemperatureGraphView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTemperatureGraphDoc)));
	return (CTemperatureGraphDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphView message handlers
