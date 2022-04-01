// SDI2ViewsDoc.h : interface of the CSDI2ViewsDoc class
//
/////////////////////////////////////////////////////////////////////////////
class CSDI2ViewsDoc : public CDocument
{
protected: // create from serialization only
	CSDI2ViewsDoc();
	DECLARE_DYNCREATE(CSDI2ViewsDoc)

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
	//{{AFX_VIRTUAL(CSDI2ViewsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSDI2ViewsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDI2ViewsDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
