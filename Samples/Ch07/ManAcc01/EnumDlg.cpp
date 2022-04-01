// EnumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ManAcc01.h"
#include "MainFrm.h"
#include "EnumDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnumDlg dialog

CEnumDlg::CEnumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnumDlg)
	m_Enumerator = _T("");
	//}}AFX_DATA_INIT
}



void CEnumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnumDlg)
	DDX_LBString(pDX, IDC_ENUMERATOR, m_Enumerator);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnumDlg, CDialog)
	//{{AFX_MSG_MAP(CEnumDlg)
	ON_LBN_KILLFOCUS(IDC_ENUMERATOR, OnKillfocusEnumerator)
	ON_LBN_DBLCLK(IDC_ENUMERATOR, OnDblClkEnumerator)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumDlg message handlers

BOOL CEnumDlg::OnInitDialog() 
{
	USES_CONVERSION;
	CDialog::OnInitDialog();

	m_plbEnum=(CListBox*)GetDlgItem(IDC_ENUMERATOR);
	if(m_RootEnum.m_spSourcesRowset==NULL)
	{
		m_pOK=(CButton*)GetDlgItem(IDOK);
		m_pOK->EnableWindow(FALSE);
		if (m_RootEnum.Open() != S_OK)
		{
			::AfxMessageBox("Failed to Open Enumerator");
			OnCancel();
		}
		else
		{
			m_pOK->EnableWindow(TRUE);			
		}
	}
	if(m_RootEnum.MoveFirst() == S_OK)
	{
		int i=0;
		do
		{
			m_plbEnum->AddString(W2T(m_RootEnum.m_szDescription));
			m_listEnum[i]=W2T(m_RootEnum.m_szName);
			i++;
		}while (m_RootEnum.MoveNext() == S_OK);
		m_plbEnum->SetCurSel(0);
	}
		return TRUE;  // return TRUE unless you set the focus to a control
}	              // EXCEPTION: OCX Property Pages should return FALSE


void CEnumDlg::OnKillfocusEnumerator() 
{
	USES_CONVERSION;
	if(m_RootEnum.MoveFirst() == S_OK)
	{
		int nSelection=0;
		nSelection=m_plbEnum->GetCurSel();
		do
		{
			if (m_listEnum[nSelection]==W2T(m_RootEnum.m_szName)) 
			{
				return;
			}
		}while (m_RootEnum.MoveNext() == S_OK);
	}
}

void CEnumDlg::OnDblClkEnumerator() 
{

	OnKillfocusEnumerator();
	OnOK();
}
