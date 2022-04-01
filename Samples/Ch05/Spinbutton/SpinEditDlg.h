#if !defined(AFX_SPINEDITDLG_H__4279138F_805D_11D1_8043_00AA006C20E3__INCLUDED_)
#define AFX_SPINEDITDLG_H__4279138F_805D_11D1_8043_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpinEditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpinEditDlg dialog


class CSpinEditDlg : public CDialog
{
// Construction
public:
	CSpinEditDlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CSpinEditDlg)
	enum { IDD = IDD_SPIN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEdit			m_wndCEdit;
	CSpinButtonCtrl m_wndCSpinButton;
	CStatic			*m_pCStaticCm;
	CProgressCtrl	*m_pMph, *m_pKmph;
	int nPos;

	// Generated message map functions
	//{{AFX_MSG(CSpinEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeBuddy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINEDITDLG_H__4279138F_805D_11D1_8043_00AA006C20E3__INCLUDED_)
