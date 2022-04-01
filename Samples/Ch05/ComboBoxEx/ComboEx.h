// ComboEx.h : main header file for the COMBOEX application
//

#if !defined(AFX_COMBOEX_H__9899A665_E36A_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_COMBOEX_H__9899A665_E36A_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboExApp:
// See ComboEx.cpp for the implementation of this class
//

class CComboExApp : public CWinApp
{
public:
	CComboExApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboExApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CComboExApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOEX_H__9899A665_E36A_11D1_8582_00AA006C20E3__INCLUDED_)
