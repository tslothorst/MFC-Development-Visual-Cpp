// PrgCtrl.h : main header file for the PRGCTRL application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Forward References
class CMainFrame;

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlApp:
// See PrgCtrl.cpp for the implementation of this class
//

class CPrgCtrlApp : public CWinApp
{
public:
	CPrgCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrgCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
public:
	static CPrgCtrlApp * GetApp() {return (CPrgCtrlApp *)AfxGetApp(); }
	CMainFrame * GetMainFrame() {return (CMainFrame *)m_pMainWnd; }

// Implementation

	//{{AFX_MSG(CPrgCtrlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
