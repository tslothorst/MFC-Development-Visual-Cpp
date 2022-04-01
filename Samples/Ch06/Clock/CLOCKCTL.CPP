// ClockCtl.cpp : Implementation of the CClockCtrl OLE control class.

#include "stdafx.h"
#include "mmsystem.h"
#include "Clock.h"
#include "ClockCtl.h"
#include "ClockPpg.h"
#include "AlarmPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CClockCtrl, COleControl)

const int ID_ALARMTYPE_BASE = 1000;
const int ID_EVENT_SOUND = 1;
const int ID_EVENT_COMMAND = 2;

/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CClockCtrl, COleControl)
	//{{AFX_MSG_MAP(CClockCtrl)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CClockCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CClockCtrl)
	DISP_PROPERTY_NOTIFY(CClockCtrl, "AlarmSet", m_bAlarmSet, OnAlarmSetChanged, VT_BOOL)
	DISP_PROPERTY_EX(CClockCtrl, "AlarmHour", GetAlarmHour, SetAlarmHour, VT_I2)
	DISP_PROPERTY_EX(CClockCtrl, "AlarmMinute", GetAlarmMinute, SetAlarmMinute, VT_I2)
	DISP_PROPERTY_EX(CClockCtrl, "AlarmType", GetAlarmType, SetAlarmType, VT_I2)
	DISP_PROPERTY_EX(CClockCtrl, "AlarmSound", GetAlarmSound, SetAlarmSound, VT_BSTR)
	DISP_PROPERTY_EX(CClockCtrl, "AlarmCommand", GetAlarmCommand, SetAlarmCommand, VT_BSTR)
	DISP_FUNCTION(CClockCtrl, "TestAlarm", TestAlarm, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_PARAM(CClockCtrl, "AlarmTime", GetNotSupported, SetAlarmTime, VT_I2, VTS_I2)
	DISP_DEFVALUE(CClockCtrl, "AlarmSet")
	DISP_STOCKPROP_BACKCOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CClockCtrl, COleControl)
	//{{AFX_EVENT_MAP(CClockCtrl)
	EVENT_CUSTOM("AlarmEvent", FireAlarmEvent, VTS_NONE)
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CClockCtrl, 3)
	PROPPAGEID(CClockPropPage::guid)
	PROPPAGEID(CAlarmPropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CClockCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockCtrl, "CLOCK.ClockCtrl.1",
	0x6eb850a3, 0x263c, 0x11cf, 0xa1, 0x51, 0, 0xaa, 0, 0x37, 0x4d, 0xd8)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CClockCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DClock =
		{ 0x6eb850a1, 0x263c, 0x11cf, { 0xa1, 0x51, 0, 0xaa, 0, 0x37, 0x4d, 0xd8 } };
const IID BASED_CODE IID_DClockEvents =
		{ 0x6eb850a2, 0x263c, 0x11cf, { 0xa1, 0x51, 0, 0xaa, 0, 0x37, 0x4d, 0xd8 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwClockOleMisc =
//	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CClockCtrl, IDS_CLOCK, _dwClockOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::CClockCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockCtrl

BOOL CClockCtrl::CClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CLOCK,
			IDB_CLOCK,
			TRUE,                       //  Insertable
			_dwClockOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::CClockCtrl - Constructor

CClockCtrl::CClockCtrl() 
{
	InitializeIIDs(&IID_DClock, &IID_DClockEvents);

	m_pClockFont = 0;
	m_pAlarmFont = 0;
	m_bAlarmSet = FALSE;
	m_AlarmHour = 0;
	m_AlarmMinute = 0;
	m_AlarmType = 3;
	m_TimerID = 0;
	m_bAlarmSounded = FALSE;
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::~CClockCtrl - Destructor

CClockCtrl::~CClockCtrl()
{
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::OnDraw - Drawing function

void CClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	CRect rcClock, rcAlarm;

	// First, draw the background using the Ambient BackColor
	pdc->FillRect(&rcBounds, &CBrush(TranslateColor(GetBackColor())));

	// Draw the current time. First, get the rectangle for the 
	// clock portion of the control.
	BOOL bResult = GetClockRect(RT_CLOCK, rcBounds, rcClock);
	ASSERT(bResult);
	DrawCurrentTime(pdc, rcClock);

	// Draw the current alarm state. First, get the rectangle for the 
	// alarm portion of the control.
	bResult = GetClockRect(RT_ALARM, rcBounds, rcAlarm);
	ASSERT(bResult);
	DrawAlarmDisplay(pdc, rcAlarm);
}

// This function draws the time portion of the clock control
void CClockCtrl::DrawCurrentTime(CDC* pdc, const CRect& rcBounds)
{
	// Create a formatted time string with hours, minutes, and seconds.
	CString strTime;
	strTime = m_dtCurrent.Format("%H:%M:%S");

	// Setup the DC with the font and drawing attributes. Remember to
	// use COleControl::TranslateColor to convert the OLE_COLOR ambient
	// color to an RGB color.
	COLORREF crText = pdc->SetTextColor(TranslateColor(AmbientForeColor()));
	int bkMode = pdc->SetBkMode(TRANSPARENT);
	CFont* pFont = pdc->SelectObject(m_pClockFont);

	// Draw the time. 
	pdc->DrawText(strTime, (LPRECT)&rcBounds,
					DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// DC cleanup. 
	pdc->SelectObject(pFont);
	pdc->SetBkMode(bkMode);
	pdc->SetTextColor(crText);
}

// This function draws the alarm portion of the clock control
void CClockCtrl::DrawAlarmDisplay(CDC* pdc, const CRect& rcBounds)
{
	// Create the alarm display string.
	CString strAlarm(m_bAlarmSet ? "Alarm:\rOn" :"Alarm:\rOff");

	// Setup the DC with the font and drawing attributes. Remember to
	// use COleControl::TranslateColor to convert the OLE_COLOR ambient
	// color to an RGB color.
	COLORREF crText = pdc->SetTextColor(TranslateColor(AmbientForeColor()));
	int bkMode = pdc->SetBkMode(TRANSPARENT);
	CFont* pFont = pdc->SelectObject(m_pAlarmFont);

	pdc->DrawText(strAlarm, (LPRECT)&rcBounds, DT_WORDBREAK);

	// DC Cleanup
	pdc->SetTextColor(crText);
	pdc->SetBkMode(bkMode);
	pdc->SelectObject(pFont);
}

// GetClockRect returns the clock or alarm rectangles. This is used in both
// the drawing routines and in the OnSize handler when creating the fonts for
// the two.
//
// Isolating this functionality here allows us to easily change how the control
// rectangle is split between the alarm and clock plus we can easily add more
// sections to the control for display.
BOOL CClockCtrl::GetClockRect(int nType, const CRect& rcBounds, CRect& rcResult)
{
	BOOL bResult = TRUE;
	rcResult = rcBounds;

	switch(nType)
	{
	case RT_CLOCK:
		// The left side of the time CRect is moved 30% to the right.
		rcResult.left = rcResult.left + 3 * rcResult.Width() / 10;
		break;

	case RT_ALARM:
		// The right side of the alarm CRect 30% of the width of the control.
		rcResult.right = rcResult.left + 3 * rcResult.Width() / 10;
		break;

	default:
		bResult = FALSE;
	}

	return bResult;
}

/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::DoPropExchange - Persistence support
void CClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::OnResetState - Reset control to default state
void CClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl::AboutBox - Display an "About" box to the user

void CClockCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_CLOCK);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CClockCtrl message handlers

void CClockCtrl::OnTimer(UINT nIDEvent) 
{
	m_dtCurrent = COleDateTime::GetCurrentTime();
	if(m_bAlarmSet) 
		DoAlarmCheck();

	// ReDraw the clock with the current time
	if(	m_ClockHour != m_dtCurrent.GetHour() ||
		m_ClockMinute != m_dtCurrent.GetMinute() ||
		m_ClockSecond != m_dtCurrent.GetSecond())
		InvalidateControl();

	m_ClockHour = m_dtCurrent.GetHour();
	m_ClockMinute = m_dtCurrent.GetMinute();
	m_ClockSecond = m_dtCurrent.GetSecond();
	
	COleControl::OnTimer(nIDEvent);
}

int CClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Initialization after the control window has been created
	m_TimerID = SetTimer(1, 1000, NULL);
	m_pClockFont = new CFont();
	m_pAlarmFont = new CFont();

	return 0;
}

void CClockCtrl::OnDestroy() 
{
	COleControl::OnDestroy();
	
	// Cleanup when the control is being destroyed
	KillTimer(m_TimerID);
	if(NULL != m_pClockFont)
		delete m_pClockFont;
	if(NULL != m_pAlarmFont)
		delete m_pAlarmFont;
}

void CClockCtrl::OnSize(UINT nType, int cx, int cy) 
{
	ASSERT(NULL != m_pClockFont);
	ASSERT(NULL != m_pAlarmFont);

	COleControl::OnSize(nType, cx, cy);
	
	// Create the control's Clock font based upon the current size of the control.
	// 
	// First, create temporary objects with which to create our fonts.
	CFont font;
	CClientDC dc(this);

	// Get the rectangle size of the clock portion of the control.
	CRect rcClock;
	BOOL bResult = GetClockRect(RT_CLOCK, CRect(0, 0, cx, cy), rcClock);
	ASSERT(bResult);

	// Create the clock GDI font
 	bResult = font.CreateFont(rcClock.Height(), 
						rcClock.Width() / 10, /*max time char width*/
						0, 
						0, 
						FW_NORMAL, 
						0,
						0,
						0,
						ANSI_CHARSET,
						OUT_TT_PRECIS,
						CLIP_TT_ALWAYS,
						DEFAULT_QUALITY,
						FF_DONTCARE,
						"Arial");

	// If the font creation succeeds, replace the GDI font in the clock font object.
	if(bResult)
	{
		// If the CFont object already contains a GDI font. Delete this font that
		// will be replaced by the new one.
		if(NULL != m_pClockFont->GetSafeHandle())
		{
			m_pClockFont->DeleteObject();
		}

		// Here we detach the GDI font from the temporary CFont object and
		// attach it to the permenant clock font object.
		m_pClockFont->Attach(HFONT(font.Detach()));
	}

	// Create the control's Alarm font based upon the current size of the control.
	// 

	// Get the rectangle size of the alarm portion of the control.
	CRect rcAlarm;
	bResult = GetClockRect(RT_ALARM, CRect(0, 0, cx, cy), rcAlarm);
	ASSERT(bResult);

	// Create the alarm's GDI font
 	bResult = font.CreateFont(rcAlarm.Height() / 4, 
						rcAlarm.Width() / 7, /*max alarm char width*/
						0, 
						0, 
						FW_NORMAL, 
						0,
						0,
						0,
						ANSI_CHARSET,
						OUT_TT_PRECIS,
						CLIP_TT_ALWAYS,
						DEFAULT_QUALITY,
						FF_DONTCARE,
						"Arial");

	// If the font creation succeeds, replace the GDI font in the alarm font object.
	if(bResult)
	{
		// If the CFont object already contains a GDI font, delete this font that
		// will be replaced by the new one.
		if(NULL != m_pAlarmFont->GetSafeHandle())
		{
			m_pAlarmFont->DeleteObject();
		}

		// Here we detach the GDI font from the temporary CFont object and
		// attach it to the permenant alarm font object.
		m_pAlarmFont->Attach(HFONT(font.Detach()));
	}
}


/////////////////////////////////////////////////////////////////////////////
// Property and Method functions
//
short CClockCtrl::GetAlarmHour() 
{
	return m_AlarmHour;
}

void CClockCtrl::SetAlarmHour(short nNewValue) 
{
	if (nNewValue < 0 || nNewValue >= 24)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, 
			"AlarmHour must be between 0 and 23, inclusive");
	}

	m_AlarmHour = nNewValue;
	SetModifiedFlag();
}

short CClockCtrl::GetAlarmMinute() 
{
	return m_AlarmMinute;
}

void CClockCtrl::SetAlarmMinute(short nNewValue) 
{
	if (nNewValue < 0 || nNewValue >= 60)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, 
			"AlarmMinute must be between 0 and 59, inclusive");
	}

	m_AlarmMinute = nNewValue;
	SetModifiedFlag();
}

// This is a parameterized property that conveniently allows for setting
// of the alarm time. Note that the associated Get function is not supported.
void CClockCtrl::SetAlarmTime(short hour, short minute) 
{
	SetAlarmHour(hour);
	SetAlarmMinute(minute);
	SetModifiedFlag();
}

short CClockCtrl::GetAlarmType() 
{
	return m_AlarmType;
}

void CClockCtrl::SetAlarmType(short nNewValue) 
{
	if (nNewValue < 0 || nNewValue > 3)
	{
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, 
			"AlarmType must be between 1 and 3, inclusive");
	}

	m_AlarmType = nNewValue;
	SetModifiedFlag();
}

BSTR CClockCtrl::GetAlarmSound() 
{
	return m_AlarmSound.AllocSysString();
}

void CClockCtrl::SetAlarmSound(LPCTSTR lpszNewValue) 
{
	m_AlarmSound = lpszNewValue;
	SetModifiedFlag();
}

BSTR CClockCtrl::GetAlarmCommand() 
{
	return m_AlarmCommand.AllocSysString();
}

void CClockCtrl::SetAlarmCommand(LPCTSTR lpszNewValue) 
{
	m_AlarmCommand = lpszNewValue;
	SetModifiedFlag();
}

void CClockCtrl::OnAlarmSetChanged() 
{
	TRACE0("AlarmSet notification\n");
	SetModifiedFlag();
}

void CClockCtrl::TestAlarm() 
{
	m_bAlarmSounded = FALSE;
	DoAlarm();
}

/////////////////////////////////////////////////////////////////////////////
// Alarm functions

// DoAlarmCheck checks to see if it is time to sound the alarm. It also
// resets m_bAlarmSounded. This variable is used to ensure that the alarm
// sounds only once during the alarm minute but get reset so that the alarm
// will sound 24 hours later if not turned off.
void CClockCtrl::DoAlarmCheck()
{
	if( m_bAlarmSet )
	{
		if( m_AlarmHour == m_dtCurrent.GetHour() &&
			m_AlarmMinute == m_dtCurrent.GetMinute() )
		{
			if( !m_bAlarmSounded )
				DoAlarm();
		}
		else
			m_bAlarmSounded = FALSE;
	}
}

// Execute the alarm function
void CClockCtrl::DoAlarm()
{
	ASSERT(!m_bAlarmSounded);

	m_bAlarmSounded = TRUE;
	if((1 == m_AlarmType || 3 == m_AlarmType) && 0 < m_AlarmSound.GetLength())
	{
		// Play Wave File
		PlaySound(LPCSTR(m_AlarmSound), NULL, SND_ASYNC | SND_FILENAME);
	}

	if((2 == m_AlarmType || 3 == m_AlarmType) && 0 < m_AlarmCommand.GetLength())
	{
		// Execute Alarm Command with CreateProcess
		STARTUPINFO  si;
		PROCESS_INFORMATION  pi;
		ZeroMemory(&si, sizeof(si));

		CreateProcess(NULL, LPTSTR(LPCTSTR(m_AlarmCommand)), NULL, NULL, 
			FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);
		// Be sure to release the handles of the newly 
		// created process and thread.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	FireAlarmEvent();
}

/////////////////////////////////////////////////////////////////////////////
// The following functions provide additional behaviors to the control,
// such as enumerated properties, the ability to invoke the control's 
// property pages at runtime and per-property browsing.

// OnGetPredefinedStrings provides an array of valid property strings
// to the container for display in its property browser.
// For each element added to pStringArray, you should add a corresponding
// "cookie" element to pCookieArray. These "cookie" values may later be
// passed by the framework to the COleControl::OnGetPredefinedValue
// function.
BOOL CClockCtrl::OnGetPredefinedStrings( DISPID dispid, 
							CStringArray* pStringArray, 
							CDWordArray* pCookieArray )
{
	BOOL bResult = FALSE;

	// Check if the dispid is for the AlarmType property
	if(dispidAlarmType == dispid)
	{
		try
		{
			// It is so fill in the values in pStringArray and pCookieArray
			for (int i = 0; i < 4; i++)
			{
				CString str;
				str.LoadString(ID_ALARMTYPE_BASE + i);
				pStringArray->Add(str);
				pCookieArray->Add(i);
			}

			bResult = TRUE;
		}
		catch(CException* e)
		{
			pStringArray->RemoveAll();
			pCookieArray->RemoveAll();
			e->Delete();
			bResult = FALSE;
		}
	}

	if (!bResult)
		bResult =  COleControl::OnGetPredefinedStrings(dispid, pStringArray, pCookieArray);

	return bResult;
}

// OnGetPredefinedValue is called by the framework to obtain the value
// corresponding to one of the predefined strings previously returned by
// a call to the override of COleControl::OnGetPredefinedStrings. This is
// done by passing in the "cookie" associated with the string as assigned
// in OnGetPredefinedStrings
BOOL CClockCtrl::OnGetPredefinedValue( DISPID dispid, DWORD dwCookie, VARIANT FAR* lpvarOut )
{
  if(dispidAlarmType == dispid)
  {
	  VariantClear(lpvarOut);
	  V_VT(lpvarOut) = VT_I2;
	  V_I2(lpvarOut) = (short)dwCookie;

	  return TRUE;
  }

  return COleControl::OnGetPredefinedValue(dispid, dwCookie, lpvarOut);
}

// OnGetDisplayString is called by the framework to obtain a string that
// represents the current value of the property identified by dispid.
BOOL CClockCtrl::OnGetDisplayString( DISPID dispid, CString& strValue )
{
	BOOL bResult = FALSE;

	// Validate that the dispid is for the AlarmType property
	if(dispidAlarmType == dispid)
	{
		switch(m_AlarmType)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			strValue.LoadString(ID_ALARMTYPE_BASE + m_AlarmType);
			bResult = TRUE;
			break;
		default:
			bResult = COleControl::OnGetDisplayString(dispid, strValue);
		}
	}

	return bResult;
}

// COleControl::OnProperties is called by the framework when 
// the control’s properties verb has been invoked by the container.
// In this case, we're calling it to allow the user to invoke the
// property pages at run-time based upon a right buttom up event.
void CClockCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// Call the base version.
	COleControl::OnRButtonUp(nFlags, point);

	COleControl::OnProperties(NULL, this->GetSafeHwnd(), NULL);
}

// OnMapPropertyToPage is called by the framework to obtain the class ID 
// of a property page that implements editing of the specified property.
// We override this function to provide a way to invoke your control’s property 
// pages from the container’s property browser.
//
BOOL CClockCtrl::OnMapPropertyToPage(DISPID dispid, LPCLSID lpclsid,
									 BOOL * pbPageOptional)
{
	BOOL bResult = FALSE;

	// If the dispid passed in is for the AlarmSound property, we will(rather
	// arbitrarily) pass back the class ID of the Alarm property page so that
	// it will be displayed by the container. All other dispids will be handled
	// with default behavior.
	if(dispidAlarmSound == dispid)
	{
		// Return the CLSID of the alarm property page 
		*lpclsid = CAlarmPropPage::guid;
		*pbPageOptional = FALSE;
		bResult = TRUE;
	}
	else
		bResult = COleControl::OnMapPropertyToPage(dispid, lpclsid,
			pbPageOptional);

	return bResult;
}
