// Dialogs.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinesDLG dialog

class CLinesDLG : public CDialog
{
// Construction
public:
	CLinesDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLinesDLG)
	enum { IDD = IDD_PRINTLINES_DIALOG };
	CSpinButtonCtrl	m_spinner;
	int		m_linesPerPage;
	//}}AFX_DATA

	int m_MaxPageLength;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinesDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLinesDLG)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
