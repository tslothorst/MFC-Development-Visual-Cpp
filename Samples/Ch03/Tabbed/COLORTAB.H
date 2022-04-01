// ColorTab.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorTab dialog

class CColorTab : public CPropertyPage
{
	DECLARE_DYNCREATE(CColorTab)

// Construction
public:
	CColorTab();
	~CColorTab();

// Dialog Data
	//{{AFX_DATA(CColorTab)
	enum { IDD = IDD_COLORS };
	int		m_colorRadio;
	int		m_colorList;
	//}}AFX_DATA

	// Programmer added this member.
	COLORREF m_color;

	CColorListBox  m_colorListBox;

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CColorTab)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CColorTab)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeColorList();
	//}}AFX_MSG
	
	afx_msg void OnRadioClicked(UINT nID);

	DECLARE_MESSAGE_MAP()
};
