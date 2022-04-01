// ManAcc01.h : main header file for the MANACC01 application
//

#if !defined(AFX_MANACC01_H__C1A311E5_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_MANACC01_H__C1A311E5_C93E_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CManAcc01App:
// See ManAcc01.cpp for the implementation of this class
//

class CManAcc01App : public CWinApp
{
public:
	CManAcc01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManAcc01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CManAcc01App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01_H__C1A311E5_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
