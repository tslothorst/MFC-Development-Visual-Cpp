// DlgOpenF.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgOpenFiles dialog

class CDlgOpenFiles : public CDialog
{
// Construction
public:
	CDlgOpenFiles(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgOpenFiles)
	enum { IDD = IDD_OPENFILES };
	CString	m_File1;
	CString	m_File2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOpenFiles)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOpenFiles)
	afx_msg void OnButtonFile1Browse();
	afx_msg void OnButtonFile2Browse();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	BOOL IsValidFileSpec (LPCSTR lpszFileSpec);

// attributes
public:
	void GetFile1 (CString& rFile);
	void GetFile2 (CString& rFile);

};
