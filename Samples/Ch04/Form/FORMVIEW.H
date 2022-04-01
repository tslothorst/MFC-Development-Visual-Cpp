// FormView.h : interface of the CMyFormView class
//
/////////////////////////////////////////////////////////////////////////////

class CMyFormView : public CFormView
{
protected: // create from serialization only
	CMyFormView();
	DECLARE_DYNCREATE(CMyFormView)

public:
	//{{AFX_DATA(CMyFormView)
	enum { IDD = IDD_FORM_FORM };
	CString	m_dlgPhrase;
	BOOL	m_blue;
	BOOL	m_green;
	BOOL	m_red;
	//}}AFX_DATA

// Attributes
public:
	CFormDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFormView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyFormView)
	afx_msg void OnChangeWelcome();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	afx_msg void OnColor(UINT nID);
};

#ifndef _DEBUG  // debug version in FormView.cpp
inline CFormDoc* CMyFormView::GetDocument()
   { return (CFormDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
