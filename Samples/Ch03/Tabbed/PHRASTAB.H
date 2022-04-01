// PhraseTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhraseTab dialog

class CPhraseTab : public CPropertyPage
{
	DECLARE_DYNCREATE(CPhraseTab)

// Construction
public:
	CPhraseTab();
	~CPhraseTab();

// Dialog Data
	//{{AFX_DATA(CPhraseTab)
	enum { IDD = IDD_PHRASE };
	CString	m_phrase;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPhraseTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPhraseTab)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
