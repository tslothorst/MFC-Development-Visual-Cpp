#if !defined(AFX_QUERY_H__708461E1_C54E_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_QUERY_H__708461E1_C54E_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Query.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CQuery dialog

class CQuery : public CDialog
{
// Construction
public:
	CQuery(CWnd* pParent = NULL);   // standard constructor
	char m_operator[7];
	char cmd_str[51];

// Dialog Data
	//{{AFX_DATA(CQuery)
	enum { IDD = IDD_QUERY };
	CString	m_Field;
	CString	m_Value;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuery)
		// NOTE: the ClassWizard will add member functions here
	afx_msg void OnGreater();
	afx_msg void OnLesser();
	afx_msg void OnEqual();
	afx_msg void OnLike();
	afx_msg void OnSetCondition();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERY_H__708461E1_C54E_11D1_818D_00AA006C270F__INCLUDED_)
