// OLEEmployee.h : main header file for the OLEEMPLOYEE application
//

#if !defined(AFX_OLEEMPLOYEE_H__6BF9D1E5_DB61_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEEMPLOYEE_H__6BF9D1E5_DB61_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeApp:
// See OLEEmployee.cpp for the implementation of this class
//

class COLEEmployeeApp : public CWinApp
{
public:
	COLEEmployeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEEmployeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COLEEmployeeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEMPLOYEE_H__6BF9D1E5_DB61_11D1_8582_00AA006C20E3__INCLUDED_)
