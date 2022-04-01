// ScrollDoc.h : interface of the CScrollDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CScrollDoc : public CDocument
{
protected: // create from serialization only
	CScrollDoc();
	DECLARE_DYNCREATE(CScrollDoc)

// Attributes
public:
	CPoint GetLocation() const { return m_pt; }
	void SetLocation(CPoint p) { m_pt = p; }
	CString GetPhrase() const { return m_phrase; } 
	void SetPhrase(CString & s) { m_phrase = s; } 

protected:	
	CString m_phrase;
	CPoint m_pt;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CScrollDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScrollDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
