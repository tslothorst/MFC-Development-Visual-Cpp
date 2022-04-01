// Dialogs.h : header file
//

#define MY_DIALOGBOX_MSG "LWIDMsg"
#define ML_APPLY 1
#define ML_CANCEL 2

/////////////////////////////////////////////////////////////////////////////
// CListWithItemDataDlg dialog

class CListWithItemDataDlg : public CDialog
{
// Construction
public:
	CListWithItemDataDlg(CWnd *pWnd, CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CListWithItemDataDlg)
	enum { IDD = IDD_PHRASE_MODELESS };
	CString	m_phrase;
	//}}AFX_DATA

	// Programmer added this.
	COLORREF m_color;

protected:
	CWnd * m_pWnd;
	UINT m_UserMsg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListWithItemDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListWithItemDataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnApply();
	virtual void OnCancel();
	afx_msg void EnableApplyButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
