#if !defined(AFX_COMBOEXDLG_H__74B6C630_8833_11D1_8043_00AA006C20E3__INCLUDED_)
#define AFX_COMBOEXDLG_H__74B6C630_8833_11D1_8043_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboExDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboExDlg dialog

class CComboExDlg : public CDialog
{
// Construction
public:
	CComboExDlg(CWnd* pParent = NULL);   // standard constructor
	COLORREF	m_Color;
// Dialog Data
	//{{AFX_DATA(CComboExDlg)
	enum { IDD = IDD_COLORS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboExDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_ImageList;
	CBitmap m_Bitmap1;
	CBitmap m_Bitmap2;
	CBitmap m_Bitmap3;
	CBitmap m_Bitmap4;
	CBitmap m_Bitmap5;
	CBitmap m_Bitmap6;
	CBitmap m_Bitmap7;
	CBitmap m_Bitmap8;
	CBitmap m_Bitmap9;
	// Generated message map functions
	//{{AFX_MSG(CComboExDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboboxex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOEXDLG_H__74B6C630_8833_11D1_8043_00AA006C20E3__INCLUDED_)
