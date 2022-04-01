// ClockPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UseClock.h"
#include "ClockPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockPropertiesDlg dialog


CClockPropertiesDlg::CClockPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClockPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClockPropertiesDlg)
	m_command = _T("");
	m_hours = 0;
	m_minutes = 0;
	m_type = 0;
	//}}AFX_DATA_INIT
}


void CClockPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClockPropertiesDlg)
	DDX_Text(pDX, IDC_COMMAND, m_command);
	DDX_Text(pDX, IDC_HOURS, m_hours);
	DDV_MinMaxInt(pDX, m_hours, 0, 23);
	DDX_Text(pDX, IDC_MINUTES, m_minutes);
	DDV_MinMaxInt(pDX, m_minutes, 0, 59);
	DDX_Text(pDX, IDC_TYPE, m_type);
	DDV_MinMaxInt(pDX, m_type, 1, 3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClockPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CClockPropertiesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockPropertiesDlg message handlers
