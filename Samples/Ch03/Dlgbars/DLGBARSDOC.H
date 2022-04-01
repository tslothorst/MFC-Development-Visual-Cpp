// DlgBarsDoc.h : interface of the CDlgBarsDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CDlgBarsDoc : public CDocument
{
protected: // create from serialization only
	CDlgBarsDoc();
	DECLARE_DYNCREATE(CDlgBarsDoc)

// Attributes
	CString m_phrase;
	COLORREF m_color;

// Operations
public:
	CString GetPhrase() const { return m_phrase; }
	void SetPhrase(CString & s) { m_phrase = s; }
	COLORREF GetColor() const { return m_color; }
	void SetColor(COLORREF c) { m_color = c; }

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBarsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgBarsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgBarsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
