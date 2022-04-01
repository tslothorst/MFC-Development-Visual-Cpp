#if !defined(AFX_COLUMNSDLG_H__D6AAC2DA_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
#define AFX_COLUMNSDLG_H__D6AAC2DA_BF27_11D1_BA5A_0000F806BD54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColumnsDlg.h : header file
//
#include <atldbsch.h>
/////////////////////////////////////////////////////////////////////////////
// CColumnsDlg dialog

class CColumnsDlg : public CDialog
{
// Construction
public:
	CColumnsDlg(CWnd* pParent = NULL);   // standard constructor
	CSession *m_pSession;
	CTables *m_pTbl;
	CString m_cmd_str;
	int m_ColsSelected;
// Dialog Data
	//{{AFX_DATA(CColumnsDlg)
	enum { IDD = IDD_COLUMNS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColumnsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	int m_fld_cnt;
	CListBox *m_plbColumns, *m_plbData;
	CString listColumns[100];
	CColumns m_Col;
	// Generated message map functions
	//{{AFX_MSG(CColumnsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLUMNSDLG_H__D6AAC2DA_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
