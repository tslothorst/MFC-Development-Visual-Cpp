// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	void ResetFile( int nID, const CString & str );
	void AddItem( int nID, const CString & str );
	CDialogBar m_wndDialogBar;
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	void SetList( int nID, const CString & strFile );
	enum { LEFT = IDC_LEFT, RIGHT = IDC_RIGHT };
	
	CSplitter* GetSplitter() { return &m_wndSplitter; }
	CProgressStatusBar *GetStatusBar() 
						{ return &m_wndStatusBar; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CProgressStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CSplitter	m_wndSplitter;


// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnViewDialogbar();
	afx_msg void OnUpdateViewDialogbar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	
	afx_msg void OnSelendokLeft();	
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
