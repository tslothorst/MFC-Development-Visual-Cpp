// BmpButView.h : interface of the CBmpButView class
//
/////////////////////////////////////////////////////////////////////////////

class CBmpButView : public CView
{
protected: // create from serialization only
	CBmpButView();
	DECLARE_DYNCREATE(CBmpButView)

// Attributes
public:
	CBmpButDoc* GetDocument();
	CRect GetPhraseBounds();
	COLORREF IDtoColorRef(int nID);

protected:
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBmpButView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBmpButView)
	afx_msg void OnColors(UINT nID);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MenusDynamicView.cpp
inline CBmpButDoc* CBmpButView::GetDocument()
   { return (CBmpButDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
