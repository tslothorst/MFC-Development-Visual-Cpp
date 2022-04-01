// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

class CFindDifferenceDialog;

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CSplitter* GetSplitter() { return &m_wndSplitter; }
	CProgressStatusBar *GetStatusBar() 
						{ return &m_wndStatusBar; }
	//ADDED HERE!!!!!!
	CDiffView *GetView(int nColumn);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CProgressStatusBar		m_wndStatusBar;
	CToolBar				m_wndToolBar;
	CSplitter				m_wndSplitter;
	CFindDifferenceDialog*	m_pFindDiffDlg;

	void OnFindNextDifference(BOOL bSearchDown, 
							  BOOL bNextDifference);	

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnEditFindDiff();
	//}}AFX_MSG
	afx_msg LRESULT OnFindDifferenceCmd (WPARAM, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
