#if !defined(AFX_HOURSMINUTESDLG_H__07B7DC4A_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_HOURSMINUTESDLG_H__07B7DC4A_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// HoursMinutesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHoursMinutesDlg dialog

class CHoursMinutesDlg : public CDialog
{
// Construction
public:
	CHoursMinutesDlg(short DisablingFlag = 0, 
					CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHoursMinutesDlg)
	enum { IDD = IDD_HOURS_MINUTES };
	short	m_hours;
	short	m_minutes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHoursMinutesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	short m_DisablingFlag;

	// Generated message map functions
	//{{AFX_MSG(CHoursMinutesDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOURSMINUTESDLG_H__07B7DC4A_57ED_11D0_98AB_444553540000__INCLUDED_)
