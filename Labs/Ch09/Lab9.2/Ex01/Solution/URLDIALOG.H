// URLDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUrlDialog dialog

class CUrlDialog : public CDialog
{
// Construction
public:
	CUrlDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUrlDialog)
	enum { IDD = IDD_URL_DIALOG };
	//}}AFX_DATA

	CString	m_Server;
	CString	m_Object;
	DWORD m_ServerType;
	INTERNET_PORT m_Port;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUrlDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUrlDialog)
	afx_msg void OnParse();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditUrl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
