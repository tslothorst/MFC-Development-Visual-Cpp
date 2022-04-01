// DefaultView.h : interface of the CDefaultView class
//
/////////////////////////////////////////////////////////////////////////////

class CDefaultView : public CView
{
protected: // create from serialization only
	CDefaultView();
	DECLARE_DYNCREATE(CDefaultView)

// Attributes
public:
	CSDI2ViewsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDefaultView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDefaultView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDefaultView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DefaultView.cpp
inline CSDI2ViewsDoc* CDefaultView::GetDocument()
   { return (CSDI2ViewsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
