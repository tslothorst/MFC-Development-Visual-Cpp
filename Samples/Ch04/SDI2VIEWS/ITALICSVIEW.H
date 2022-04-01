// ItalicsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CItalicsView view

class CItalicsView : public CView
{
protected:
	CItalicsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CItalicsView)

// Attributes
public:
	CSDI2ViewsDoc* GetDocument();

// Operations
public:
	CItalicsView(CDocument * pDoc);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CItalicsView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CItalicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CItalicsView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ItalicsView.cpp
inline CSDI2ViewsDoc* CItalicsView::GetDocument()
   { return (CSDI2ViewsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
