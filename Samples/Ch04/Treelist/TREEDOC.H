// treeDoc.h : interface of the CTreeDoc class
//
/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CSimpleTreeView;
class CSimpleListView;

class CTreeDoc : public CDocument
{
protected: // create from serialization only
	CTreeDoc();
	DECLARE_DYNCREATE(CTreeDoc)

// Attributes
public:
	// To simplify one view accessing the other, this document class
	// stores a pointer to each view, rather than relying on the collection
	// of generic view pointers that all documents maintain.
	CSimpleTreeView * m_pTreeView;
	CSimpleListView * m_pListView;

	CList <CAnimalInfo, CAnimalInfo&> m_AnimalList;

// Operations
public:
	POSITION InsertData (CAnimalInfo &);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTreeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
