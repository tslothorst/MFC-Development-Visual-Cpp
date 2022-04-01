// FindDiff.h : header file
//

const char* const FINDDIFF_MSGSTRING = "diffapp_FindDifference";

/////////////////////////////////////////////////////////////////////////////
// CFindDifferenceDialog dialog

class CFindDifferenceDialog : public CDialog
{
// Construction
public:
	CFindDifferenceDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindDifferenceDialog)
	enum { IDD = IDD_NEXTDIFF };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

//attributes
protected:
	BOOL	m_bTerminating;
	BOOL	m_bFindNext;
public:
	BOOL	IsTerminating() const;	//TRUE if terminating
	BOOL	SearchDown() const;		//TRUE if searching down, 
									//FALSE if searching up
	BOOL	FindDifference() const; //TRUE if finding next difference
									//FALSE if finding next equal
	BOOL	FindNext() const;		//TRUE if find next button pressed

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDifferenceDialog)
	public:
	virtual BOOL Create();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindDifferenceDialog)
	afx_msg void OnFindNext();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
