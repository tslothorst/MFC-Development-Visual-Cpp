// HoursMinutesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UseClock.h"
#include "HoursMinutesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHoursMinutesDlg dialog


CHoursMinutesDlg::CHoursMinutesDlg(short DisablingFlag, CWnd* pParent /*=NULL*/)
	: CDialog(CHoursMinutesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHoursMinutesDlg)
	m_hours = 0;
	m_minutes = 0;
	//}}AFX_DATA_INIT
	
	m_DisablingFlag = DisablingFlag;
}


void CHoursMinutesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHoursMinutesDlg)
	DDX_Text(pDX, IDC_HOURS, m_hours);
	DDV_MinMaxInt(pDX, m_hours, 0, 23);
	DDX_Text(pDX, IDC_MINUTES, m_minutes);
	DDV_MinMaxInt(pDX, m_minutes, 0, 59);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHoursMinutesDlg, CDialog)
	//{{AFX_MSG_MAP(CHoursMinutesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHoursMinutesDlg message handlers

BOOL CHoursMinutesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (1 == m_DisablingFlag)
		GetDlgItem(IDC_HOURS)->EnableWindow(FALSE);
	
	if (2 == m_DisablingFlag)
		GetDlgItem(IDC_MINUTES)->EnableWindow(FALSE);
	
	return TRUE;
}
