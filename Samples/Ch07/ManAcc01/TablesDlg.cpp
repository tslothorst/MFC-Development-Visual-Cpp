// TablesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ManAcc01.h"
#include "TablesDlg.h"
#include <atldbsch.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTablesDlg dialog


CTablesDlg::CTablesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTablesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTablesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTablesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTablesDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTablesDlg, CDialog)
	//{{AFX_MSG_MAP(CTablesDlg)
	ON_LBN_KILLFOCUS(IDC_TABLES, OnKillfocusTables)
	ON_LBN_DBLCLK(IDC_TABLES, OnDblClkTables)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTablesDlg message handlers

BOOL CTablesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_plbTables=(CListBox*)GetDlgItem(IDC_TABLES);
	m_pSession->Close();
	if(m_pSession->Open(*m_pSource) != S_OK)
	{
		::AfxMessageBox("Failed to open session");	
		OnCancel();
		return FALSE;
	}
	m_Tbl.Close();
	if(m_Tbl.Open(*m_pSession,NULL,NULL,NULL,"TABLE")==S_OK)
	{
		if(m_Tbl.MoveFirst()==S_OK)
		{
			int i=0;
			do
			{
				m_plbTables->AddString(m_Tbl.m_szName);
				m_listTables[i]=m_Tbl.m_szName;
				i++;
			}while (m_Tbl.MoveNext() == S_OK);
			m_plbTables->SetCurSel(0);
		}
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTablesDlg::OnKillfocusTables() 
{
	int nSelection;
	nSelection=m_plbTables->GetCurSel();
	if(m_Tbl.MoveFirst()==S_OK)
	{	
		do
		{
			if(m_Tbl.m_szName==m_listTables[nSelection])
			{
				return;
			}
		}while (m_Tbl.MoveNext() == S_OK);
	}
}

void CTablesDlg::OnDblClkTables() 
{
	OnKillfocusTables();
	OnOK();
}
