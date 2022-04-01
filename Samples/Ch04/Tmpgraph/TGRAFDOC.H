// TGrafDoc.h : interface of the CTemperatureGraphDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CTemperatureGraphDoc : public CDocument
{
protected: // create from serialization only
	CTemperatureGraphDoc();
	DECLARE_DYNCREATE(CTemperatureGraphDoc)

// Attributes
public:

// Operations
public:
	CString m_city;
	CString m_month;
	UINT m_year;
	CArray<CPoint, CPoint&> temps;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTemperatureGraphDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTemperatureGraphDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTemperatureGraphDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
