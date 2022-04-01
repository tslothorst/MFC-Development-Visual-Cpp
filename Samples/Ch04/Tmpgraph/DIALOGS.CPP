// Dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "TmpGraph.h"
#include "Dialogs.h"

#include "TGrafDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemperatureDlg dialog

CTemperatureDlg::CTemperatureDlg(CWnd * pWnd, CWnd* pParent /*=NULL*/)
	: CDialog(CTemperatureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTemperatureDlg)
	m_temperature = 0;
	m_day = 0;
	//}}AFX_DATA_INIT
	m_pWnd = pWnd;
	m_UserMsg = RegisterWindowMessage(MY_TEMP_MSG);
}

void CTemperatureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTemperatureDlg)
	DDX_Control(pDX, IDC_TEMP_SPINNER, m_temp_spinner);
	DDX_Control(pDX, IDC_DAY_SPINNER, m_day_spinner);
	DDX_Text(pDX, IDC_TEMPERATURE, m_temperature);
	DDV_MinMaxInt(pDX, m_temperature, -10, 40);
	DDX_Text(pDX, IDC_DAY, m_day);
	DDV_MinMaxInt(pDX, m_day, 1, 31);
	//}}AFX_DATA_MAP

	// Only proceed if the day is in range. Doing otherwise
	// causes an access violation in the recipient of this message.
	if (m_day < 1 || m_day > m_MaxDays)
	{
		AfxMessageBox("Day is out of range");
		DDX_Text(pDX, IDC_DAY, m_day);
		pDX->Fail();
	}
}

BEGIN_MESSAGE_MAP(CTemperatureDlg, CDialog)
	//{{AFX_MSG_MAP(CTemperatureDlg)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_NOTIFY(UDN_DELTAPOS, IDC_DAY_SPINNER, OnDeltaposDaySpinner)
	ON_EN_CHANGE(IDC_TEMPERATURE, OnChangeTemperature)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemperatureDlg message handlers

BOOL CTemperatureDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_day_spinner.SetRange(1, 31);
	m_temp_spinner.SetRange(-10, 40);

	// Initially, the Apply button is disabled.
	CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);
	cb->EnableWindow(FALSE);

	return TRUE;
}

void CTemperatureDlg::OnApply() 
{
	UpdateData(TRUE);
	
	// Only send the apply message and disable the apply button
	// if the m_day is in range.
	if (m_day >=1 && m_day <= m_MaxDays)
	{
		m_pWnd->SendMessage(m_UserMsg, ML_APPLY);
		CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);
		cb->EnableWindow(FALSE);
	}
}

void CTemperatureDlg::OnCancel() 
{
	m_pWnd->SendMessage(m_UserMsg, ML_CANCEL);
	DestroyWindow();
}

void CTemperatureDlg::PostNcDestroy() 
{
	delete this;
	CDialog::PostNcDestroy();
}

void CTemperatureDlg::OnDeltaposDaySpinner(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	CTemperatureGraphDoc * pDoc;
	CMainFrame * pFrame;
	int newValue;

	pFrame = (CMainFrame *) m_pWnd;
	pDoc = (CTemperatureGraphDoc *)pFrame->GetActiveDocument();

	newValue = pNMUpDown->iPos + pNMUpDown->iDelta;
	
	if (newValue < 1 || newValue > m_MaxDays)
	{
		*pResult = TRUE;
		return;
	}

	m_day = newValue;
	m_temperature = pDoc->temps[m_day-1].y;
	UpdateData(FALSE);
	
	*pResult = FALSE;
}

void CTemperatureDlg::OnChangeTemperature() 
{
	// When temperature changes enable the Apply button.
	CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);
	
	// This function may be called too early in the life of the
	// dialog box, so do nothing if the control doesn't exist yet.
	if (cb)
		cb->EnableWindow(TRUE);
}
