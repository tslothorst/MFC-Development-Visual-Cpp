// DynaView.h : interface of the CMenusDynamicView class
//
/////////////////////////////////////////////////////////////////////////////

class CMenusDynamicView : public CView
{
protected: // create from serialization only
	CMenusDynamicView();
	DECLARE_DYNCREATE(CMenusDynamicView)

// Attributes
public:
	CMenusDynamicDoc* GetDocument();
	COLORREF IDtoColorRef(int nID);

protected:
	//CMenu *m_pExtraColors;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenusDynamicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenusDynamicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenusDynamicView)
	afx_msg void OnOptionsExtracolors();
	afx_msg void OnOptionsStandardcolors();
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	afx_msg void OnUpdateOptions(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MenusDynamicView.cpp
inline CMenusDynamicDoc* CMenusDynamicView::GetDocument()
   { return (CMenusDynamicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
