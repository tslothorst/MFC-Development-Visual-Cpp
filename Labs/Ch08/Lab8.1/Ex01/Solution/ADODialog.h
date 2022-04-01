// ADODialog.h : main header file for the ADODIALOG application
//

#if !defined(AFX_ADODIALOG_H__152CF616_C49E_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_ADODIALOG_H__152CF616_C49E_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADODialogApp:
// See ADODialog.cpp for the implementation of this class
//

class CADODialogApp : public CWinApp
{
public:
	CADODialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADODialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODIALOG_H__152CF616_C49E_11D1_818D_00AA006C270F__INCLUDED_)
