// PrintDoc.h : interface of the CPrintDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CPrintDoc : public CDocument
{
protected: // create from serialization only
	CPrintDoc();
	DECLARE_DYNCREATE(CPrintDoc)

// Attributes
public:
	// In Win95 with a tmHeight of 16, this number cannot
	// exceed 2047, since scroll size is a 16-bit signed number.
	int LinesOnDocument() const { return m_linesOnDocument; }
	CString & GetLine(int r) const;

protected:
	int m_linesOnDocument;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
