// DlgBarsView.h : interface of the CDlgBarsView class
//
/////////////////////////////////////////////////////////////////////////////

class CDlgBarsView : public CView
{
protected: // create from serialization only
	CDlgBarsView();
	DECLARE_DYNCREATE(CDlgBarsView)

	COLORREF IDtoColorRef(int nID);

// Attributes
public:
	CDlgBarsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgBarsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgBarsView)
	afx_msg void OnSelchangeListColors();
	//}}AFX_MSG
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DlgBarsView.cpp
inline CDlgBarsDoc* CDlgBarsView::GetDocument()
   { return (CDlgBarsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
