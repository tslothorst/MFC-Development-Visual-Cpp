#if !defined(AFX_DATASOURCEDLG_H__D6AAC2D8_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
#define AFX_DATASOURCEDLG_H__D6AAC2D8_BF27_11D1_BA5A_0000F806BD54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataSourceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataSourceDlg dialog

class CDataSourceDlg : public CDialog
{
// Construction
public:
	CDataSourceDlg(CWnd* pParent = NULL);   // standard constructor
	CEnumerator *m_pRootEnum;
	CEnumerator m_Enum;
	CString m_listDataSource[100];

	CDataSource m_source;
	CSession m_session;


// Dialog Data
	//{{AFX_DATA(CDataSourceDlg)
	enum { IDD = IDD_DATASOURCE };
	char	m_Path[256];
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataSourceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CComboBox *m_pDataSource;
	CEdit *m_pDataSourcePath;
	CButton *m_pOK;
	// Generated message map functions
	//{{AFX_MSG(CDataSourceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusDatasourceName();
	afx_msg void OnKillfocusDatasourcePath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASOURCEDLG_H__D6AAC2D8_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
