// MlesView.h : interface of the CModelessView class
//
/////////////////////////////////////////////////////////////////////////////

class CModelessView : public CView
{
protected: // create from serialization only
	CModelessView();
	DECLARE_DYNCREATE(CModelessView)

// Attributes
public:
	CModelessDoc* GetDocument();
	static UINT m_UserMsg;

protected:
	CListWithItemDataDlg * m_pDlg;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CModelessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CModelessView)
	afx_msg void OnModifyDisplaymodelessdialog();
	afx_msg void OnUpdateModifyDisplaymodelessdialog(CCmdUI* pCmdUI);
	//}}AFX_MSG
	afx_msg LRESULT MyMessageHandler(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ModelessView.cpp
inline CModelessDoc* CModelessView::GetDocument()
   { return (CModelessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
