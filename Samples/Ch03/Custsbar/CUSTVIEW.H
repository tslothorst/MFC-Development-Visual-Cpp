// CustomStatusBarView.h : interface of the CCustomStatusBarView class
//
/////////////////////////////////////////////////////////////////////////////

class CCustomStatusBarView : public CView
{
protected: // create from serialization only
	CCustomStatusBarView();
	DECLARE_DYNCREATE(CCustomStatusBarView)

// Attributes
public:
	CCustomStatusBarDoc* GetDocument();

// Operations
public:

private:
	COLORREF IDtoColorRef(int nID);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomStatusBarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomStatusBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCustomStatusBarView)
	//}}AFX_MSG
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CustomStatusBarView.cpp
inline CCustomStatusBarDoc* CCustomStatusBarView::GetDocument()
   { return (CCustomStatusBarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
