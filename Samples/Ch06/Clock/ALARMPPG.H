// AlarmPropPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage : Property page dialog

class CAlarmPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAlarmPropPage)
	DECLARE_OLECREATE_EX(CAlarmPropPage)

// Constructors
public:
	CAlarmPropPage();

// Dialog Data
	//{{AFX_DATA(CAlarmPropPage)
	enum { IDD = IDD_PROPPAGE_ALARM };
	int		m_AlarmHour;
	int		m_AlarmMinute;
	CString	m_AlarmSound;
	CString	m_AlarmCommand;
	BOOL	m_bAlarmSet;
	int		m_AlarmType;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAlarmPropPage)
	afx_msg void OnSoundFileSelect();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


