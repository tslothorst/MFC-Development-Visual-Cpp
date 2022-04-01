// MDI2ViewsDoc.h : interface of the CMDI2ViewsDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CMDI2ViewsDoc : public CDocument
{
protected: // create from serialization only
	CMDI2ViewsDoc();
	DECLARE_DYNCREATE(CMDI2ViewsDoc)

	CString m_phrase;
	COLORREF m_color;

// Operations
public:
	CString GetPhrase() const { return m_phrase; }
	COLORREF GetColor() const { return m_color; }

	void SetPhrase( CString & s) { m_phrase = s; }
	void SetColor( COLORREF c) { m_color = c; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDI2ViewsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDI2ViewsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDI2ViewsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
