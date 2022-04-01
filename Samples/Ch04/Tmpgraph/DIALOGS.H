// Dialogs.h : header file
//

#define MY_TEMP_MSG "temperature message"
#define ML_APPLY 1
#define ML_CANCEL 2

/////////////////////////////////////////////////////////////////////////////
// CTemperatureDlg dialog

class CTemperatureDlg : public CDialog
{
// Construction
public:
	CTemperatureDlg(CWnd * pWnd, CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CTemperatureDlg)
	enum { IDD = IDD_TEMPERATURE };
	CSpinButtonCtrl	m_temp_spinner;
	CSpinButtonCtrl	m_day_spinner;
	int		m_temperature;
	int		m_day;
	//}}AFX_DATA

	int m_MaxDays;

protected:
	CWnd * m_pWnd;
	UINT m_UserMsg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTemperatureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTemperatureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnApply();
	virtual void OnCancel();
	afx_msg void OnDeltaposDaySpinner(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeTemperature();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
