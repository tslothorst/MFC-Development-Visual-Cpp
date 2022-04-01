// IC_2Doc.h : interface of the CIC_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

class CIC_2Doc : public CDocument
{
protected: // create from serialization only
	CIC_2Doc();
	DECLARE_DYNCREATE(CIC_2Doc)

// Attributes
public:
	CString m_Server;
	CString m_Object;
	DWORD m_ServerType;
	INTERNET_PORT m_Port;

	CStringList m_WebPage;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIC_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIC_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIC_2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
