// DynAcc01.h : main header file for the DYNACC01 application
//

#if !defined(AFX_DYNACC01_H__AF74E685_C883_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_DYNACC01_H__AF74E685_C883_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01App:
// See DynAcc01.cpp for the implementation of this class
//

class CDynAcc01App : public CWinApp
{
public:
	CDynAcc01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynAcc01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDynAcc01App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNACC01_H__AF74E685_C883_11D1_8582_00AA006C20E3__INCLUDED_)
