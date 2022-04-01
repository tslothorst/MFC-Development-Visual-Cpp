// PrPrevue.h : main header file for the Print application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintApp:
// See Print.cpp for the implementation of this class
//

class CPrintApp : public CWinApp
{
public:
	CPrintApp();
	void QueryPrinterAndSetMaxLines();
	int GetMaxPageLength() const { return m_MaxLinesPerPage; }
	void SetMaxPageLength(int ml) { m_MaxLinesPerPage = ml; }

protected:
	int m_MaxLinesPerPage;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
