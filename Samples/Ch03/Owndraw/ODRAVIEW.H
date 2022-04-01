// OwnerDrawMenusView.h : interface of the COwnerDrawMenusView class
//
/////////////////////////////////////////////////////////////////////////////

class COwnerDrawMenusView : public CView
{
protected: // create from serialization only
	COwnerDrawMenusView();
	DECLARE_DYNCREATE(COwnerDrawMenusView)

// Attributes
public:
	COwnerDrawMenusDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COwnerDrawMenusView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COwnerDrawMenusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COwnerDrawMenusView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OwnerDrawMenusView.cpp
inline COwnerDrawMenusDoc* COwnerDrawMenusView::GetDocument()
   { return (COwnerDrawMenusDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
