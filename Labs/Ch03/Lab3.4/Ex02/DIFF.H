// diff.h : main header file for the DIFF application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Forward References
class CMainFrame;

/////////////////////////////////////////////////////////////////////////////
// CDiffApp:
// See diff.cpp for the implementation of this class
//

class CDiffApp : public CWinApp
{
public:
	CDiffApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiffApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
public:
	static CDiffApp * GetApp() {return (CDiffApp *)AfxGetApp(); }
	CMainFrame * GetMainFrame() {return (CMainFrame *)m_pMainWnd; }

// Implementation

	//{{AFX_MSG(CDiffApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
