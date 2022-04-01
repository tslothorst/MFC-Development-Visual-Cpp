// DlgFilex.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileOpenEx dialog

class CFileOpenEx : public CFileDialog
{
// Construction
public:
	CFileOpenEx(LPCTSTR lpszDefExt = NULL,
				LPCTSTR lpszFileName = NULL,
				DWORD dwFlags = OFN_HIDEREADONLY,
				LPCTSTR lpszFilter = NULL,
				CWnd* pParentWnd = NULL);

// Dialog Data
	//{{AFX_DATA(CFileIOpenEx)
	enum { IDD = IDD_FILEOPEN_EX };
	CRichEditCtrl	m_RichEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileIOpenEx)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnFileNameChange();
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL 	m_bFirstTime;
	BOOL	m_bUnfolded;

	void	Expand(const BOOL bExpand = TRUE);
	void	EnableOptionalChildren (	const CRect& rectBasic,
								const BOOL bEnable = TRUE );
	void	PreviewContents(LPCSTR lpszFilespec);

	// Generated message map functions
	//{{AFX_MSG(CFileIOpenEx)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void CFileOpenEx::OnButtonOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
