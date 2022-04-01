// TreeWithImagesView.h : interface of the CTreeWithImagesView class
//
/////////////////////////////////////////////////////////////////////////////

class CTreeWithImagesView : public CTreeView
{
protected: // create from serialization only
	CTreeWithImagesView();
	DECLARE_DYNCREATE(CTreeWithImagesView)

	CImageList *cim;

// Attributes
public:
	CTreeWithImagesDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeWithImagesView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeWithImagesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void InsertBitmaps();
	void InsertAnimals();
	void InsertNodes(const HTREEITEM, char **, const int, const int);
	HTREEITEM FindNode(const HTREEITEM, const CString &str) const;

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeWithImagesView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TreeWithImagesView.cpp
inline CTreeWithImagesDoc* CTreeWithImagesView::GetDocument()
   { return (CTreeWithImagesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
