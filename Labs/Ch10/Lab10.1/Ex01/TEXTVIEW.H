// TextView.h : interface of the CTextView class
//
/////////////////////////////////////////////////////////////////////////////

class CTextView : public CScrollView
{
protected: // create from serialization only
	CTextView();
	DECLARE_DYNCREATE(CTextView)
	//print properties
	CSize 	m_PrintCharSize;	
	int		m_nLinesPerPrintPage;
	int		m_nPrintPages;

// Attributes
public:
	CTextDoc*	GetDocument();
	CFont*		GetFont();
	CSize		GetDocSize() const { return m_DocSize; }
	CSize		GetCharSize() const { return m_ViewCharSize; }
	int GetLinesPerPrintPage() const 
	{ return m_nLinesPerPrintPage; }

	int GetPrintPageCount() const 
	{	return m_nPrintPages; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnDraw(CDC* pDC, int nFirstLn, int nLastLn, int nXPos = 0, int nYPos = 0);   
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CSize 	m_ViewCharSize;		//	Dimensions of screen character
								//	in device units
	CSize	m_DocSize;			//	Document size in device units
	CFont*	m_pFont;			//	Current font



	void ComputeViewMetrics();
	void ComputeVisibleLines(CDC* pDC, int& nFirst, int& nLast);


// Generated message map functions
protected:
	void ComputePrintableLines( CDC* pDC, CPrintInfo* pInfo, int& nFirst, int& nLast);
	CDC* CreatePrinterDC();
	void ComputePrintMetrics();
	//{{AFX_MSG(CTextView)
	afx_msg void OnFormatFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TextView.cpp
inline CTextDoc* CTextView::GetDocument()
   { return (CTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
