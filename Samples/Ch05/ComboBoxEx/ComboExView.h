// ComboExView.h : interface of the CComboExView class
//
/////////////////////////////////////////////////////////////////////////////


class CComboExView : public CView
{
protected: // create from serialization only
	CComboExView();
	DECLARE_DYNCREATE(CComboExView)

// Attributes
public:
	CComboExDoc* GetDocument();
	CRect GetPhraseBounds();


protected:
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboExView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboExView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComboExView)
	afx_msg void OnColors();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MenusDynamicView.cpp
inline CComboExDoc* CComboExView::GetDocument()
   { return (CComboExDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
