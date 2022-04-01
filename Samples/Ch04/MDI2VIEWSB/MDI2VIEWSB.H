// MDI2ViewsB.h : main header file for the MDI2VIEWSB application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsBApp:
// See MDI2ViewsB.cpp for the implementation of this class
//

class CMDI2ViewsBApp : public CWinApp
{
public:
	CMDI2ViewsBApp();

	CMultiDocTemplate * m_pItalicsTemplate;
	CMultiDocTemplate * m_pDefaultTemplate;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDI2ViewsBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMDI2ViewsBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
