// AdditionalToolbarsView.h : interface of the CAdditionalToolbarsView class
//
/////////////////////////////////////////////////////////////////////////////

class CAdditionalToolbarsView : public CView
{
protected: // create from serialization only
	CAdditionalToolbarsView();
	DECLARE_DYNCREATE(CAdditionalToolbarsView)

// Attributes
public:
	CAdditionalToolbarsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdditionalToolbarsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAdditionalToolbarsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	COLORREF IDtoColorRef(int nID);

// Generated message map functions
protected:
	//{{AFX_MSG(CAdditionalToolbarsView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	afx_msg void OnColors(UINT nID);
	afx_msg void OnUpdateColors(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AdditionalToolbarsView.cpp
inline CAdditionalToolbarsDoc* CAdditionalToolbarsView::GetDocument()
   { return (CAdditionalToolbarsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
