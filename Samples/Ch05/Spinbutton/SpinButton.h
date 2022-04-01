// SpinButton.h : main header file for the SPINBUTTON application
//

#if !defined(AFX_SPINBUTTON_H__42791385_805D_11D1_8043_00AA006C20E3__INCLUDED_)
#define AFX_SPINBUTTON_H__42791385_805D_11D1_8043_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp:
// See SpinButton.cpp for the implementation of this class
//

class CSpinButtonApp : public CWinApp
{
public:
	CSpinButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SaveFile(LPCTSTR pstrPathName);

	//{{AFX_MSG(CSpinButtonApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINBUTTON_H__42791385_805D_11D1_8043_00AA006C20E3__INCLUDED_)
