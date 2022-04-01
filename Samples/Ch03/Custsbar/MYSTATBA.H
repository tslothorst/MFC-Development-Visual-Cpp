// StatusBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBar window

class CCustomStatusBar : public CStatusBarCtrl
{
// Construction
public:
	CCustomStatusBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomStatusBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomStatusBar();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DetermineKeyboardState();
	void DetermineTextColor();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomStatusBar)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
