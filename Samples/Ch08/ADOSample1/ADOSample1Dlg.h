// ADOSample1Dlg.h : header file
//

#if !defined(AFX_ADOSAMPLE1DLG_H__247FA827_B434_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_ADOSAMPLE1DLG_H__247FA827_B434_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOSample1Dlg dialog

class CADOSample1Dlg : public CDialog
{
// Construction
public:
	CADOSample1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADOSample1Dlg)
	enum { IDD = IDD_ADOSAMPLE1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSample1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOSample1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSAMPLE1DLG_H__247FA827_B434_11D1_8582_00AA006C20E3__INCLUDED_)
