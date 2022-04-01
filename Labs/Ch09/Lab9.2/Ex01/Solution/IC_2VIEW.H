// IC_2View.h : interface of the CIC_2View class
//
/////////////////////////////////////////////////////////////////////////////

class CIC_2View : public CScrollView
{
protected: // create from serialization only
	CIC_2View();
	DECLARE_DYNCREATE(CIC_2View)

// Attributes
public:
	void CloseSession();
	CIC_2Doc* GetDocument();

// Operations
public:

protected:
	CInternetSession * m_pInternetSession;
	CHttpConnection * m_pHttpConnection;
	CHttpFile * m_pHttpFile;
	int m_processState;

	void SetScrollingAttributes();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIC_2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIC_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIC_2View)
	afx_msg void OnInternetCreateSession();
	afx_msg void OnUpdateInternetCreateSession(CCmdUI* pCmdUI);
	afx_msg void OnInternetGetConnection();
	afx_msg void OnUpdateInternetGetConnection(CCmdUI* pCmdUI);
	afx_msg void OnInternetCloseSession();
	afx_msg void OnUpdateInternetCloseSession(CCmdUI* pCmdUI);
	afx_msg void OnInternetSendRequest();
	afx_msg void OnInternetOpenRequest();
	afx_msg void OnInternetReadInformation();
	afx_msg void OnUpdateInternetOpenRequest(CCmdUI* pCmdUI);
	afx_msg void OnUpdateInternetSendRequest(CCmdUI* pCmdUI);
	afx_msg void OnUpdateInternetReadInformation(CCmdUI* pCmdUI);
	afx_msg void OnInternetObtainUrl();
	afx_msg void OnInternetAllTheAbove();
	afx_msg void OnUpdateInternetAllTheAbove(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IC_2View.cpp
inline CIC_2Doc* CIC_2View::GetDocument()
   { return (CIC_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
