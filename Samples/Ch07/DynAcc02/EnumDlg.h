#if !defined(AFX_ENUMDLG_H__D6AAC2D7_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
#define AFX_ENUMDLG_H__D6AAC2D7_BF27_11D1_BA5A_0000F806BD54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnumDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnumDlg dialog

class CEnumDlg : public CDialog
{
// Construction
public:
	CEnumDlg(CWnd* pParent = NULL);   // standard constructor
	CEnumerator m_RootEnum;
	CString m_listEnum[100];

// Dialog Data
	//{{AFX_DATA(CEnumDlg)
	enum { IDD = IDD_EMUMERATOR };
	CString	m_Enumerator;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CListBox	*m_plbEnum;
	CButton		*m_pOK;
	

	// Generated message map functions
	//{{AFX_MSG(CEnumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEnumerator();
	afx_msg void OnDblClkEnumerator();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMDLG_H__D6AAC2D7_BF27_11D1_BA5A_0000F806BD54__INCLUDED_)
