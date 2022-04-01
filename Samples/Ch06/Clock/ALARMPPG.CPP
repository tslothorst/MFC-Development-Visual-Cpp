// AlarmPropPage.cpp : implementation file
//

#include "stdafx.h"
#include "Clock.h"
#include "AlarmPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage dialog

IMPLEMENT_DYNCREATE(CAlarmPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAlarmPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAlarmPropPage)
	ON_BN_CLICKED(IDC_FILE_SELECT, OnSoundFileSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

// {FAF0BF81-27D6-11CF-A151-00AA00374DD8}
IMPLEMENT_OLECREATE_EX(CAlarmPropPage, "Clock.CAlarmPropPage",
	0xfaf0bf81, 0x27d6, 0x11cf, 0xa1, 0x51, 0x0, 0xaa, 0x0, 0x37, 0x4d, 0xd8)


/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage::CAlarmPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAlarmPropPage

BOOL CAlarmPropPage::CAlarmPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Define string resource for page type; replace '0' below with ID.

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ALARM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage::CAlarmPropPage - Constructor

// TODO: Define string resource for page caption; replace '0' below with ID.

CAlarmPropPage::CAlarmPropPage() :
	COlePropertyPage(IDD, IDS_ALARM_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAlarmPropPage)
	m_AlarmHour = 0;
	m_AlarmMinute = 0;
	m_AlarmSound = _T("");
	m_AlarmCommand = _T("");
	m_bAlarmSet = FALSE;
	m_AlarmType = -1;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage::DoDataExchange - Moves data between page and properties

void CAlarmPropPage::DoDataExchange(CDataExchange* pDX)
{
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_DATA_MAP(CAlarmPropPage)
	DDP_Text(pDX, IDC_ALARM_HOUR, m_AlarmHour, _T("AlarmHour") );
	DDX_Text(pDX, IDC_ALARM_HOUR, m_AlarmHour);
	DDV_MinMaxInt(pDX, m_AlarmHour, 0, 23);
	DDP_Text(pDX, IDC_ALARM_MINUTE, m_AlarmMinute, _T("AlarmMinute") );
	DDX_Text(pDX, IDC_ALARM_MINUTE, m_AlarmMinute);
	DDV_MinMaxInt(pDX, m_AlarmMinute, 0, 59);
	DDP_Text(pDX, IDC_ALARM_SOUND, m_AlarmSound, _T("AlarmSound") );
	DDX_Text(pDX, IDC_ALARM_SOUND, m_AlarmSound);
	DDP_Text(pDX, IDC_ALARM_COMMAND, m_AlarmCommand, _T("AlarmCommand") );
	DDX_Text(pDX, IDC_ALARM_COMMAND, m_AlarmCommand);
	DDP_Check(pDX, IDC_ALARM_SET, m_bAlarmSet, _T("AlarmSet") );
	DDX_Check(pDX, IDC_ALARM_SET, m_bAlarmSet);
	DDP_CBIndex(pDX, IDC_ALARM_TYPE, m_AlarmType, _T("AlarmType") );
	DDX_CBIndex(pDX, IDC_ALARM_TYPE, m_AlarmType);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAlarmPropPage message handlers
//
// This routine allows the user to the alarm's sound file using
// the Window's Open File common dialog.
void CAlarmPropPage::OnSoundFileSelect() 
{
	CString strFilter("Sound Files(*.wav, *.mid) | *.wav;*.mid | "
		"All Files(*.*) | *.* ||");
	CFileDialog dlg(TRUE, 
					NULL, 
					m_AlarmSound,
					OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
					strFilter,
					this);

	if(IDOK == dlg.DoModal())
	{
		// Update the sound member variable
		m_AlarmSound = dlg.GetPathName();
		// Update the sound control string
		CEdit* pAlarmSound = (CEdit*)GetDlgItem(IDC_ALARM_SOUND);
		pAlarmSound->SetWindowText(m_AlarmSound);
	}
}
  

BOOL CAlarmPropPage::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();
	
	// Load the combobox with the alarm type selections and set
	// the appropriate selection
	CComboBox* pcb = (CComboBox*)GetDlgItem(IDC_ALARM_TYPE);
	ASSERT(pcb != NULL);

	for (int i = IDS_ALARMTYPE_EVENT; i <= IDS_ALARMTYPE_ALL ; i++)
	{
		CString str;
		str.LoadString(i);
		pcb->AddString(LPCTSTR(str));
	}
	pcb->SetCurSel(m_AlarmType == -1 ? 0 : m_AlarmType);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
