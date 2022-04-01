// TabbedColorPhraseView.h : interface of the CTabbedColorPhraseView class
//
/////////////////////////////////////////////////////////////////////////////

class CTabbedColorPhraseView : public CView
{
protected: // create from serialization only
	CTabbedColorPhraseView();
	DECLARE_DYNCREATE(CTabbedColorPhraseView)

// Attributes
public:
	CTabbedColorPhraseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabbedColorPhraseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTabbedColorPhraseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTabbedColorPhraseView)
	afx_msg void OnModifyShowtabbeddialogbox();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TabbedColorPhraseView.cpp
inline CTabbedColorPhraseDoc* CTabbedColorPhraseView::GetDocument()
   { return (CTabbedColorPhraseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
