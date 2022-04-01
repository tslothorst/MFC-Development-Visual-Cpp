// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TmpGraph.h"

#include "TGrafDoc.h"
#include "GrafView.h"
#include "NumbView.h"
#include "Dialogs.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

UINT reg_msg = RegisterWindowMessage(MY_TEMP_MSG);

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_COMMAND(ID_CHANGE_SETDAILYTEMP, OnChangeSetdailytemp)
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(reg_msg, MyTemperatureHandler)
	ON_COMMAND_RANGE(ID_MONTH_JANUARY, ID_MONTH_LEAPFEBRUARY, OnMonth)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
void CMainFrame::OnMonth(UINT nID)
{
	CTemperatureGraphDoc * pDoc = (CTemperatureGraphDoc *)GetActiveDocument();
	int daycount, formersize;

	formersize = pDoc->temps.GetSize();

	switch (nID)
	{
		case ID_MONTH_JANUARY:
		case ID_MONTH_MARCH:
		case ID_MONTH_MAY:
		case ID_MONTH_JULY:
		case ID_MONTH_AUGUST:
		case ID_MONTH_OCTOBER:
		case ID_MONTH_DECEMBER:
			daycount = 31;
			break;
		case ID_MONTH_FEBRUARY:
			daycount = 28;
			break;
		case ID_MONTH_APRIL:
		case ID_MONTH_JUNE:
		case ID_MONTH_SEPTEMBER:
		case ID_MONTH_NOVEMBER:
			daycount = 30;
			break;
		default:	// Leap year February
			daycount = 29;
	}
	pDoc->temps.SetSize(daycount);

	// If the array has been extended, then the newly appended
	// elements will have to be initialized.
	if (formersize < daycount)
		while (formersize <= daycount)
		{
			pDoc->temps[formersize - 1].x = formersize - 1;
			pDoc->temps[formersize - 1].y = DEFAULT_TEMPERATURE;
			formersize++;
		}

	// convert nID to a subscript so as to load a string
	// from the string table, where the months have consecutive
	// IDs of IDS_JANUARY..IDS_LEAP_FEBRUARY
	CString s;
	s.LoadString(IDS_JANUARY + (nID-ID_MONTH_JANUARY));
	
	pDoc->m_month = s;
	pDoc->UpdateAllViews(NULL);
	pDoc->SetModifiedFlag(TRUE);
}

LRESULT CMainFrame::MyTemperatureHandler(WPARAM wParam, LPARAM lParam)
{
	CTemperatureGraphDoc * pDoc;
	pDoc = (CTemperatureGraphDoc *)GetActiveDocument();

	switch (wParam)
	{
		case ML_APPLY:
			// If the temperature for the given day has changed,
			// capture the variable and redraw the views.
			if (m_pDlg->m_temperature != pDoc->temps[m_pDlg->m_day-1].y)
			{
				 pDoc->temps[m_pDlg->m_day-1].y = m_pDlg->m_temperature;
				 pDoc->UpdateAllViews(NULL);
				 pDoc->SetModifiedFlag(TRUE);
			}
			break;
		case ML_CANCEL:
			m_pDlg = 0;
	}
	return TRUE;
}

CMainFrame::CMainFrame()
{
	m_pDlg = 0;
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// This is the code for a static splitter.
	CRect cr;
	GetClientRect(&cr);

	int rc;
	m_wndSplitter.CreateStatic(this, 2, 1);
	
	// The top pane gets the default view
	rc = m_wndSplitter.CreateView(0, 0,
								pContext->m_pNewViewClass,
								CSize(cr.Width(), cr.Height() / 2),
								pContext);
	if (FALSE == rc)
		return rc;

	// The bottom pane gets the additional view.
	rc = m_wndSplitter.CreateView(1, 0,
								RUNTIME_CLASS(CTemperatureNumbersView),
								CSize(cr.Width(), cr.Height() / 2),
								pContext);
	
	return rc;
}

// In an SDI app with a splitter with 2 different views, you have to
// put command handlers in the frame class to make them available
// regardless of which pane has focus.
// If you put it in a view class, then that menu is not available when
// the other view is active.
void CMainFrame::OnChangeSetdailytemp() 
{
	CTemperatureGraphDoc * pDoc = 
		(CTemperatureGraphDoc *)GetActiveDocument();
	
	// Create the dialog object.
	m_pDlg = new CTemperatureDlg(this);
	
	// Initialize members of the dialog class.
	m_pDlg->m_day = 1;
	m_pDlg->m_temperature = pDoc->temps[0].y;
	m_pDlg->m_MaxDays = pDoc->temps.GetSize();

	m_pDlg->Create(IDD_TEMPERATURE);

	m_pDlg->ShowWindow(SW_RESTORE);
}
