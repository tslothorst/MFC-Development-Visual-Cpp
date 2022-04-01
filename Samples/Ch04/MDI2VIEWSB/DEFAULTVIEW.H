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
	CMDI2ViewsBDoc* GetDocument();

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
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DefaultView.cpp
inline CMDI2ViewsBDoc* CDefaultView::GetDocument()
   { return (CMDI2ViewsBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
