// FindDiff.h : header file
//

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


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindDifferenceDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindDifferenceDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
