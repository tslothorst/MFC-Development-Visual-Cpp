// BmpBut.h : main header file for the BMPBUT application
//

#if !defined(AFX_BMPBUT_H__AADAD065_8CF8_11D1_8043_00AA006C20E3__INCLUDED_)
#define AFX_BMPBUT_H__AADAD065_8CF8_11D1_8043_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpButApp:
// See BmpBut.cpp for the implementation of this class
//

class CBmpButApp : public CWinApp
{
public:
	CBmpButApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmpButApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPBUT_H__AADAD065_8CF8_11D1_8043_00AA006C20E3__INCLUDED_)
