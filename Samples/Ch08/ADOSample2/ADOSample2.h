// ADOSample2.h : main header file for the ADOSAMPLE2 application
//

#if !defined(AFX_ADOSAMPLE2_H__47D03CE5_C7C1_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_ADOSAMPLE2_H__47D03CE5_C7C1_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOSample2App:
// See ADOSample2.cpp for the implementation of this class
//

class CADOSample2App : public CWinApp
{
public:
	CADOSample2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSample2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOSample2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSAMPLE2_H__47D03CE5_C7C1_11D1_8582_00AA006C20E3__INCLUDED_)
