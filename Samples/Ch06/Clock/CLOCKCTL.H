// ClockCtl.h : Declaration of the CClockCtrl OLE control class.

/////////////////////////////////////////////////////////////////////////////
// CClockCtrl : See ClockCtl.cpp for implementation.

class CClockCtrl : public COleControl
{
	DECLARE_DYNCREATE(CClockCtrl)

// Constructor
public:
	CClockCtrl();

// Overrides

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();
	virtual BOOL OnGetPredefinedStrings( DISPID dispid, 
		CStringArray* pStringArray, CDWordArray* pCookieArray );
	virtual BOOL OnGetPredefinedValue( DISPID dispid, DWORD dwCookie, 
		VARIANT FAR* lpvarOut );
	virtual BOOL OnGetDisplayString( DISPID dispid, CString& strValue );
	virtual BOOL OnMapPropertyToPage(DISPID dispid, LPCLSID lpclsid,
									 BOOL * pbPageOptional);
  

// Implementation
protected:
	CFont* m_pClockFont;
	CFont* m_pAlarmFont;
	~CClockCtrl();

	DECLARE_OLECREATE_EX(CClockCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CClockCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CClockCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CClockCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CClockCtrl)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CClockCtrl)
	BOOL m_bAlarmSet;
	afx_msg void OnAlarmSetChanged();
	afx_msg short GetAlarmHour();
	afx_msg void SetAlarmHour(short nNewValue);
	afx_msg short GetAlarmMinute();
	afx_msg void SetAlarmMinute(short nNewValue);
	afx_msg short GetAlarmType();
	afx_msg void SetAlarmType(short nNewValue);
	afx_msg BSTR GetAlarmSound();
	afx_msg void SetAlarmSound(LPCTSTR lpszNewValue);
	afx_msg BSTR GetAlarmCommand();
	afx_msg void SetAlarmCommand(LPCTSTR lpszNewValue);
	afx_msg void TestAlarm();
	afx_msg void SetAlarmTime(short hour, short nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CClockCtrl)
	void FireAlarmEvent()
		{FireEvent(eventidAlarmEvent,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CClockCtrl)
	dispidAlarmHour = 2L,
	dispidAlarmMinute = 3L,
	dispidAlarmType = 4L,
	dispidAlarmSound = 5L,
	dispidAlarmCommand = 6L,
	dispidAlarmSet = 1L,
	dispidAlarmTime = 8L,
	dispidTestAlarm = 7L,
	eventidAlarmEvent = 1L,
	//}}AFX_DISP_ID
	};
private:
	enum {RT_CLOCK = 1, RT_ALARM};
	int m_TimerID;
	COleDateTime m_dtCurrent;
	short m_ClockSecond;
	short m_ClockMinute;
	short m_ClockHour;
	short m_AlarmMinute;
	short m_AlarmHour;
	int m_AlarmType;
	CString m_AlarmSound;
	CString m_AlarmCommand;	
	BOOL m_bAlarmSounded;
	void DoAlarm();
	void DoAlarmCheck();
	virtual void DrawCurrentTime(
				CDC* pdc, const CRect& rcBounds);
	virtual void DrawAlarmDisplay(
				CDC* pdc, const CRect& rcBounds);
	virtual BOOL GetClockRect(int nType, const CRect& rcBounds, CRect& rcResult);
};
