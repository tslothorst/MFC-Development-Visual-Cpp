// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	CDialogBar m_wndDialogBar;
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CSplitter* GetSplitter() { return &m_wndSplitter; }
	CProgressStatusBar *GetStatusBar() 
						{ return &m_wndStatusBar; }

// Operations
public:
	void SetList( int nID, const CString & strFile );
	enum { LEFT = IDC_LEFT, RIGHT = IDC_RIGHT };

protected: 
	void AddItem( int nID, const CString & str );
	void ResetFile( int nID, const CString & str );

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
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
