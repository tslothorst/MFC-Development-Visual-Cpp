// UseClockView.cpp : implementation of the CUseClockView class
//

#include "stdafx.h"
#include "UseClock.h"

#include "clock.h"
#include "hoursminutesdlg.h"
#include "clockpropertiesdlg.h"

#include "UseClockDoc.h"
#include "UseClockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseClockView

IMPLEMENT_DYNCREATE(CUseClockView, CFormView)

BEGIN_MESSAGE_MAP(CUseClockView, CFormView)
	//{{AFX_MSG_MAP(CUseClockView)
	ON_COMMAND(ID_CLOCK_TOGGLEALARM, OnClockToggleAlarm)
	ON_COMMAND(ID_CLOCK_SETALARMHOUR, OnClockSetAlarmHour)
	ON_COMMAND(ID_CLOCK_SETALARMMINUTE, OnClockSetAlarmMinute)
	ON_COMMAND(ID_CLOCK_SETBACKCOLOR, OnClockSetBackColor)
	ON_COMMAND(ID_CLOCK_ABOUTBOXMETHOD, OnClockAboutBoxMethod)
	ON_COMMAND(ID_CLOCK_ALARMTIMEMETHOD, OnClockAlarmTimeMethod)
	ON_COMMAND(ID_CLOCK_TESTALARMMETHOD, OnClockTestAlarmMethod)
	ON_COMMAND(ID_CLOCK_SETALARMCOMMAND, OnClockSetAlarmCommand)
	ON_COMMAND(ID_CLOCK_SHOWPROPERTIES, OnClockShowProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_EVENTSINK_MAP(CUseClockView, CFormView)
    //{{AFX_EVENTSINK_MAP(CUseClockView)
	ON_EVENT(CUseClockView, IDC_CLOCKCTRL, 1 /* AlarmEvent */, OnAlarmEventClockCtrl, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseClockView construction/destruction

CUseClockView::CUseClockView()
	: CFormView(CUseClockView::IDD)
{
	//{{AFX_DATA_INIT(CUseClockView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}

CUseClockView::~CUseClockView()
{
}

void CUseClockView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUseClockView)
	DDX_Control(pDX, IDC_CLOCKCTRL, m_ClockControl);
	//}}AFX_DATA_MAP
}

BOOL CUseClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUseClockView diagnostics

#ifdef _DEBUG
void CUseClockView::AssertValid() const
{
	CFormView::AssertValid();
}

void CUseClockView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUseClockDoc* CUseClockView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseClockDoc)));
	return (CUseClockDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseClockView message handlers

void CUseClockView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// Make the view exactly the same size as the dialog
	// box it contains.
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);	
}

void CUseClockView::OnClockToggleAlarm() 
{
	BOOL bAlarmState = m_ClockControl.GetAlarmSet();
	
	m_ClockControl.SetAlarmSet(! bAlarmState);
}


void CUseClockView::OnAlarmEventClockCtrl() 
{
	MessageBeep(-1);
	MessageBox("The control has fired its alarm event!");
}

void CUseClockView::OnClockSetAlarmHour() 
{
	CHoursMinutesDlg dlg(2);
	dlg.m_hours = m_ClockControl.GetAlarmHour();
	dlg.m_minutes = m_ClockControl.GetAlarmMinute();
	if (IDOK == dlg.DoModal())
		m_ClockControl.SetAlarmHour(dlg.m_hours);
}

void CUseClockView::OnClockSetAlarmMinute() 
{
	CHoursMinutesDlg dlg(1);
	dlg.m_hours = m_ClockControl.GetAlarmHour();
	dlg.m_minutes = m_ClockControl.GetAlarmMinute();
	if (IDOK == dlg.DoModal())
		m_ClockControl.SetAlarmMinute(dlg.m_minutes);
}

void CUseClockView::OnClockSetBackColor() 
{
	OLE_COLOR current_color = m_ClockControl.GetBackColor();
	COLORREF old_color;

	// OLE_COLOR must be converted to a COLORREF for use
	// by CColorDialog.
	if (S_OK != ::OleTranslateColor(current_color,
									NULL, &old_color))
		return;

	CColorDialog dlg(old_color);

	if (IDOK == dlg.DoModal())
	{
		// No translation is needed from COLORREF to OLE_COLOR
		COLORREF new_color = dlg.GetColor();
		if (new_color != old_color)
		{
			current_color = new_color;
			m_ClockControl.SetBackColor(current_color);
		}
	}
}

void CUseClockView::OnClockAboutBoxMethod() 
{
	m_ClockControl.AboutBox();
}

void CUseClockView::OnClockAlarmTimeMethod() 
{
	CHoursMinutesDlg dlg;

	dlg.m_hours = m_ClockControl.GetAlarmHour();
	dlg.m_minutes = m_ClockControl.GetAlarmMinute();
	if (IDOK == dlg.DoModal())
		m_ClockControl.SetAlarmTime(dlg.m_hours, dlg.m_minutes);
}

void CUseClockView::OnClockTestAlarmMethod() 
{
	// Invoke the control's TestAlarm method
	m_ClockControl.TestAlarm();
}

void CUseClockView::OnClockSetAlarmCommand() 
{
	m_ClockControl.SetAlarmCommand("calc.exe");
}

void CUseClockView::OnClockShowProperties() 
{
	CClockPropertiesDlg dlg;

	dlg.m_minutes =	m_ClockControl.GetAlarmMinute();
	dlg.m_hours = m_ClockControl.GetAlarmHour();
	dlg.m_type = m_ClockControl.GetAlarmType();
	dlg.m_command = m_ClockControl.GetAlarmCommand();

	dlg.DoModal();
}
