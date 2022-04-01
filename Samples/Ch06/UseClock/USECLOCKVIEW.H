// UseClockView.h : interface of the CUseClockView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "clock.h"
//}}AFX_INCLUDES

#if !defined(AFX_USECLOCKVIEW_H__07B7DC42_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_USECLOCKVIEW_H__07B7DC42_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CUseClockView : public CFormView
{
protected: // create from serialization only
	CUseClockView();
	DECLARE_DYNCREATE(CUseClockView)

public:
	//{{AFX_DATA(CUseClockView)
	enum { IDD = IDD_USECLOCK_FORM };
	CClock	m_ClockControl;
	//}}AFX_DATA

// Attributes
public:
	CUseClockDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseClockView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseClockView)
	afx_msg void OnClockToggleAlarm();
	afx_msg void OnAlarmEventClockCtrl();
	afx_msg void OnClockSetAlarmHour();
	afx_msg void OnClockSetAlarmMinute();
	afx_msg void OnClockSetBackColor();
	afx_msg void OnClockAboutBoxMethod();
	afx_msg void OnClockAlarmTimeMethod();
	afx_msg void OnClockTestAlarmMethod();
	afx_msg void OnClockSetAlarmCommand();
	afx_msg void OnClockShowProperties();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseClockView.cpp
inline CUseClockDoc* CUseClockView::GetDocument()
   { return (CUseClockDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECLOCKVIEW_H__07B7DC42_57ED_11D0_98AB_444553540000__INCLUDED_)
