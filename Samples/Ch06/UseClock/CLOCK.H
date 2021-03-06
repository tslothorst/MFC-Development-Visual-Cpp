#if !defined(AFX_CLOCK_H__07B7DC49_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_CLOCK_H__07B7DC49_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CClock wrapper class

class CClock : public CWnd
{
protected:
	DECLARE_DYNCREATE(CClock)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x6eb850a3, 0x263c, 0x11cf, { 0xa1, 0x51, 0x0, 0xaa, 0x0, 0x37, 0x4d, 0xd8 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	short GetAlarmHour();
	void SetAlarmHour(short);
	short GetAlarmMinute();
	void SetAlarmMinute(short);
	short GetAlarmType();
	void SetAlarmType(short);
	CString GetAlarmSound();
	void SetAlarmSound(LPCTSTR);
	CString GetAlarmCommand();
	void SetAlarmCommand(LPCTSTR);
	BOOL GetAlarmSet();
	void SetAlarmSet(BOOL);
	BOOL Get_AlarmSet();
	void Set_AlarmSet(BOOL);
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);

// Operations
public:
	void SetAlarmTime(short hour, short nNewValue);
	void TestAlarm();
	void AboutBox();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCK_H__07B7DC49_57ED_11D0_98AB_444553540000__INCLUDED_)
