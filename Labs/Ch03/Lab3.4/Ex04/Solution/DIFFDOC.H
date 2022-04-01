// diffDoc.h : interface of the CDiffDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CDiffDoc : public CRichEditDoc
{
	//Added for DialogBar lab
	friend class CMainFrame;

protected: // create from serialization only
	CDiffDoc();
	DECLARE_DYNCREATE(CDiffDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiffDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CDiffDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void RunComparison(LPCSTR lpszFile1, LPCSTR lpszFile2);

protected:
	CString m_File1;
	CString m_File2;

// Generated message map functions
protected:
	//{{AFX_MSG(CDiffDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
