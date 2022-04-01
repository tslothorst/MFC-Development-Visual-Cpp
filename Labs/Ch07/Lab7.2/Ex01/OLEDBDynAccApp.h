// OLEDBDynAccApp.h : main header file for the OLEDBDYNACCAPP application
//

#if !defined(AFX_OLEDBDYNACCAPP_H__A800F225_C961_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEDBDYNACCAPP_H__A800F225_C961_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppApp:
// See OLEDBDynAccApp.cpp for the implementation of this class
//

class COLEDBDynAccAppApp : public CWinApp
{
public:
	COLEDBDynAccAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBDynAccAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COLEDBDynAccAppApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBDYNACCAPP_H__A800F225_C961_11D1_8582_00AA006C20E3__INCLUDED_)
