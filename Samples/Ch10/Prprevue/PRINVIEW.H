// PrinView.h : interface of the CPrintView class
//
/////////////////////////////////////////////////////////////////////////////

class CPrintView : public CScrollView
{
protected: // create from serialization only
	CPrintView();
	DECLARE_DYNCREATE(CPrintView)

// Attributes
public:
	CPrintDoc* GetDocument();
	int GetPageLength() const { return m_LinesPerPage; }
	void SetPageLength(int pl) { m_LinesPerPage = pl; }

protected:
	int m_LinesPerPage;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void SetScrollingAttributes();
	void ShowPageBreaks(CDC* pDC);

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintView)
	afx_msg void OnFileLinesperpage();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrintView.cpp
inline CPrintDoc* CPrintView::GetDocument()
   { return (CPrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
