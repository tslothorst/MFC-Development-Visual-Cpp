// SimpleListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimpleListView view

class CSimpleListView : public CListView
{
protected:
	CSimpleListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSimpleListView)

// Attributes
public:

// Operations
public:
	CTreeDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleListView)
	public:
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation

public:
	void DisplayClassInfo(const HTREEITEM);
	void DisplayTypeInfo(const HTREEITEM);
	void DisplayAnimalInfo(const DWORD);
	void EraseList();

protected:
	virtual ~CSimpleListView();
	void DisplayChildren(char **, const HTREEITEM);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSimpleListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#ifndef _DEBUG  // debug version in SimpleTreeView.cpp
inline CTreeDoc* CSimpleListView::GetDocument()
   { return (CTreeDoc*)m_pDocument; }
#endif
