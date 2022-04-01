// ColumnsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OLEDBDynAccApp.h"
#include "ColumnsDlg.h"
#include <atldbsch.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColumnsDlg dialog




CColumnsDlg::CColumnsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColumnsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColumnsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CColumnsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColumnsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColumnsDlg, CDialog)
	//{{AFX_MSG_MAP(CColumnsDlg)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColumnsDlg message handlers

BOOL CColumnsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CColumns Col;
	
	m_plbColumns=(CListBox*)GetDlgItem(IDC_COLUMNS);


	Col.Open(*m_pSession,NULL,NULL,m_pTbl->m_szName);
		
	if(Col.MoveFirst()==S_OK)
	{
		m_fld_cnt=0;
		do
		{
			m_plbColumns->AddString(Col.m_szColumnName);
			m_listColumns[m_fld_cnt]=Col.m_szColumnName;
			m_fld_cnt++;	
		}while (Col.MoveNext() == S_OK);
	}
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CColumnsDlg::OnKillFocus(CWnd* pNewWnd) 
{
	int nLbSelItems[100];
	CDialog::OnKillFocus(pNewWnd);
	
	m_plbColumns->GetSelItems(m_fld_cnt,nLbSelItems);	
	m_ColsSelected=m_plbColumns->GetSelCount();	
	m_cmd_str="Select";
	for(int j = 0 ; j < m_ColsSelected; j++)
	{
		if(j==0)
		{
			m_cmd_str=m_cmd_str+ "  " + m_listColumns[nLbSelItems[j]];
		}
		else
		{
			m_cmd_str=m_cmd_str+ " , " + m_listColumns[nLbSelItems[j]];
		}
		
	}
	if(m_ColsSelected==0)
	{
		m_ColsSelected=m_fld_cnt;
		m_cmd_str="Select * ";
	}
	m_cmd_str=m_cmd_str + " FROM ";
	m_cmd_str=m_cmd_str + m_pTbl->m_szName;
	
}
