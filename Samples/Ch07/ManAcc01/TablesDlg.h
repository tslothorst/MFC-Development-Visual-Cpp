#if !defined(AFX_TABLESDLG_H__D6AAC2D9_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
#define AFX_TABLESDLG_H__D6AAC2D9_BF27_11D1_BA5A_0000F806BD54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <atldbsch.h>
// TablesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTablesDlg dialog

class CTablesDlg : public CDialog
{
// Construction
public:
	CTablesDlg(CWnd* pParent = NULL);   // standard constructor

	CSession *m_pSession;
	CDataSource *m_pSource;

	CTables m_Tbl;
	
// Dialog Data
	//{{AFX_DATA(CTablesDlg)
	enum { IDD = IDD_TABLES };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTablesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListBox *m_lbTables;
	CListBox *m_plbTables;
	CString m_listTables[100];
	// Generated message map functions
	//{{AFX_MSG(CTablesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusTables();
	afx_msg void OnDblClkTables();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABLESDLG_H__D6AAC2D9_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
