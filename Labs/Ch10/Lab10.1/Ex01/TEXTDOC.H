// TextDoc.h : interface of the CTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CTextDoc : public CDocument
{
protected: // create from serialization only
	CTextDoc();
	DECLARE_DYNCREATE(CTextDoc)

// Attributes
public:
	CStringList*	GetLineList() { return &m_LineList; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CStringList	m_LineList;


// Generated message map functions
protected:
	//{{AFX_MSG(CTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
