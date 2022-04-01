// Progress.h : header file
//

const int PROGRESS_CTRL_CX = 160;	// Default width of progress control

const int X_MARGIN = 5;	// X value used for margins 
						// and control spacing
const int Y_MARGIN = 2;	// Y value used for margins 
						// and control spacing


/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar window

class CProgressStatusBar : public CStatusBar
{
// Construction
public:
	CProgressStatusBar();

// Attributes
public:
	void SetProgressCtrlWidth(UINT nWidth = PROGRESS_CTRL_CX);
	void SetProgressLabel(LPCSTR lpszProgressLabel);
	CProgressCtrl * GetProgressCtrl() 
						{ return &m_ProgressCtrl; }

// Operations
public:
	void ShowProgressDisplay(BOOL  bShow = TRUE);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProgressStatusBar();
	void RecalcProgressDisplay();

// Generated message map functions
protected:
	//{{AFX_MSG(CProgressStatusBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

		// Data Members
protected:
    CProgressCtrl	m_ProgressCtrl;			//	Embedded progress control
	CStatic			m_ProgressLabel;		//	Text of the label
	BOOL			m_bProgressMode;		//	TRUE when displaying the progress control
	int				m_nProgressCtrlWidth;	//	Width of progress control

};

/////////////////////////////////////////////////////////////////////////////
