#if !defined(AFX_CLOCKPROPERTIESDLG_H__07B7DC4B_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_CLOCKPROPERTIESDLG_H__07B7DC4B_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ClockPropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClockPropertiesDlg dialog

class CClockPropertiesDlg : public CDialog
{
// Construction
public:
	CClockPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClockPropertiesDlg)
	enum { IDD = IDD_CLOCK_PROPERTIES };
	CString	m_command;
	short	m_hours;
	short	m_minutes;
	short	m_type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClockPropertiesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKPROPERTIESDLG_H__07B7DC4B_57ED_11D0_98AB_444553540000__INCLUDED_)
