// SimpleTreeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeView view
class CTreeDoc;

class CSimpleTreeView : public CTreeView
{
protected:
	CSimpleTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSimpleTreeView)

// Attributes
public:
	CTreeDoc* GetDocument();

protected:

// Operations
public:
	void PopulateTree();
	BOOL LocateAndInsert(const CAnimalInfo &, const POSITION);
	void DeleteSelection();
	void EditSelection();
	void ModifySelection();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleTreeView)
	public:
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSimpleTreeView();

	void InsertRootNodes();
	void InsertDataNodes();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSimpleTreeView)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	HTREEITEM FindNode(const HTREEITEM, const CString &) const;
	HTREEITEM InsertNode(const HTREEITEM, const CString &str, const DWORD);
	void ModifyAnimal(const HTREEITEM selectedNode, const DWORD itemData);
	void ModifyType(const HTREEITEM selectedNode, const DWORD itemData);
	
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#ifndef _DEBUG  // debug version in SimpleTreeView.cpp
inline CTreeDoc* CSimpleTreeView::GetDocument()
   { return (CTreeDoc*)m_pDocument; }
#endif
