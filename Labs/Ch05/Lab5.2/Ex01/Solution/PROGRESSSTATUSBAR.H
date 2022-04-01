#ifndef __PROGRESSSTATUSBAR_H__
#define __PROGRESSSTATUSBAR_H__

// ProgressStatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar window

const int PROGRESS_CTRL_CX = 160;
const int X_MARGIN = 5;
const int Y_MARGIN = 2;

class CProgressStatusBar : public CStatusBar
{
// Construction
public:
	void ShowProgressDisplay(BOOL bShow = TRUE);
	void SetProgressLabel(LPCSTR lpszProgressLabel);
	void RecalcProgressDisplay();
	void SetProgressCtrlWidth(int nWidth = PROGRESS_CTRL_CX);
	CProgressStatusBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProgressStatusBar();

	// Generated message map functions
protected:
	int m_nProgressCtrlWidth;
	BOOL m_bProgressMode;
	CStatic m_ProgressLabel;
	CProgressCtrl m_ProgressCtrl;
	//{{AFX_MSG(CProgressStatusBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // __PROGRESSSTATUSBAR_H__
