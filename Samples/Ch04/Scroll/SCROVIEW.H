// ScrollView.h : interface of the CMyScrollView class
//
/////////////////////////////////////////////////////////////////////////////

class CMyScrollView : public CScrollView
{
protected: // create from serialization only
	CMyScrollView();
	DECLARE_DYNCREATE(CMyScrollView)

// Attributes
public:
	CScrollDoc* GetDocument();


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyScrollView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyScrollView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ScrollView.cpp
inline CScrollDoc* CMyScrollView::GetDocument()
   { return (CScrollDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
