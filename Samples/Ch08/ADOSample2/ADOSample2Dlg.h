// ADOSample2Dlg.h : header file
//

#if !defined(AFX_ADOSAMPLE2DLG_H__47D03CE7_C7C1_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_ADOSAMPLE2DLG_H__47D03CE7_C7C1_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOSample2Dlg dialog

class CADOSample2Dlg : public CDialog
{
// Construction
public:
	CADOSample2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADOSample2Dlg)
	enum { IDD = IDD_ADOSAMPLE2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSample2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CADOSample2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSAMPLE2DLG_H__47D03CE7_C7C1_11D1_8582_00AA006C20E3__INCLUDED_)
