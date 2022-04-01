// ADOSample1.h : main header file for the ADOSAMPLE1 application
//

#if !defined(AFX_ADOSAMPLE1_H__247FA825_B434_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_ADOSAMPLE1_H__247FA825_B434_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOSample1App:
// See ADOSample1.cpp for the implementation of this class
//

class CADOSample1App : public CWinApp
{
public:
	CADOSample1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSample1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOSample1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSAMPLE1_H__247FA825_B434_11D1_8582_00AA006C20E3__INCLUDED_)
