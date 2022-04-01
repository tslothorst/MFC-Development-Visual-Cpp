// FilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOSample3.h"
#include "FilterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg dialog


CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFilterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFilterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFilterDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialog)
	//{{AFX_MSG_MAP(CFilterDlg)
	ON_BN_CLICKED(IDC_EQUAL, OnEqual)
	ON_BN_CLICKED(IDC_LIKE, OnLike)
	ON_BN_CLICKED(IDC_GREATER, OnGreater)
	ON_BN_CLICKED(IDC_LESSER, OnLesser)
	ON_CBN_KILLFOCUS(IDC_FIELD_NAME, OnKillfocusFieldName)
	ON_EN_KILLFOCUS(IDC_VALUE, OnKillfocusValue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilterDlg message handlers

void CFilterDlg::OnEqual() 
{
	m_Operator= " = ";
	
}

void CFilterDlg::OnLike() 
{
	m_Operator= " like ";
	
}

void CFilterDlg::OnGreater() 
{
	m_Operator= " > ";
	
}

void CFilterDlg::OnLesser() 
{
	m_Operator= " < ";
	
}

void CFilterDlg::OnKillfocusFieldName() 
{
	GetDlgItemText(IDC_FIELD_NAME, m_FieldName);
}

void CFilterDlg::OnKillfocusValue() 
{
	GetDlgItemText(IDC_VALUE, m_Value);

}



void CFilterDlg::OnOK() 
{
	if(m_Operator==" like ")
		m_Value = "'" + m_Value + "*'";
	else
		m_Value = "'" + m_Value + "'";
	m_ConditionStr = m_FieldName + m_Operator + m_Value;
	CDialog::OnOK();
}
