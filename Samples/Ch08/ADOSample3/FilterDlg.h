#if !defined(AFX_FILTERDLG_H__20C86221_C56F_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_FILTERDLG_H__20C86221_C56F_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg dialog

class CFilterDlg : public CDialog
{
// Construction
public:
	CString m_ConditionStr;
	CFilterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFilterDlg)
	enum { IDD = IDD_CONDITION_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_Operator;
	CString m_FieldName;
	CString m_Value;

	// Generated message map functions
	//{{AFX_MSG(CFilterDlg)
	afx_msg void OnEqual();
	afx_msg void OnLike();
	afx_msg void OnGreater();
	afx_msg void OnLesser();
	afx_msg void OnKillfocusFieldName();
	afx_msg void OnKillfocusValue();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILTERDLG_H__20C86221_C56F_11D1_8582_00AA006C20E3__INCLUDED_)
