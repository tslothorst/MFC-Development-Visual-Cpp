// MDIView.h : interface of the CMDIAppView class
//
/////////////////////////////////////////////////////////////////////////////

class CMDIAppView : public CView
{
protected: // create from serialization only
	CMDIAppView();
	DECLARE_DYNCREATE(CMDIAppView)

// Attributes
public:
	CMDIAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIAppView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDIAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	COLORREF IDtoColorRef(int nID);

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIAppView)
	//}}AFX_MSG
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDIView.cpp
inline CMDIAppDoc* CMDIAppView::GetDocument()
   { return (CMDIAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
