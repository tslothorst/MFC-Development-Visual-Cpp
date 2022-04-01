// ItalicsView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CItalicsView view

class CItalicsView : public CView
{
protected:
	CItalicsView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CItalicsView)

	CMDI2ViewsDoc* GetDocument();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CItalicsView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CItalicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CItalicsView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#ifndef _DEBUG  // debug version in ItalicsView.cpp
inline CMDI2ViewsDoc* CItalicsView::GetDocument()
   { return (CMDI2ViewsDoc*)m_pDocument; }
#endif
