// PrgCView.h : interface of the CPrgCtrlView class
//
/////////////////////////////////////////////////////////////////////////////

class CPrgCtrlView : public CRichEditView
{
protected: // create from serialization only
	CPrgCtrlView();
	DECLARE_DYNCREATE(CPrgCtrlView)

// Attributes
public:
	CPrgCtrlDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrgCtrlView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrgCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrgCtrlView)
	afx_msg void OnDropFiles(HDROP hDropInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrgCView.cpp
inline CPrgCtrlDoc* CPrgCtrlView::GetDocument()
   { return (CPrgCtrlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
