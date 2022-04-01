// UseClock.h : main header file for the USECLOCK application
//

#if !defined(AFX_USECLOCK_H__07B7DC3A_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_USECLOCK_H__07B7DC3A_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseClockApp:
// See UseClock.cpp for the implementation of this class
//

class CUseClockApp : public CWinApp
{
public:
	CUseClockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseClockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseClockApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECLOCK_H__07B7DC3A_57ED_11D0_98AB_444553540000__INCLUDED_)
