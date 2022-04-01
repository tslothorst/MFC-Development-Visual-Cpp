// DataSourceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OLEDBDynAccApp.h"
#include "DataSourceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataSourceDlg dialog

CDataSourceDlg::CDataSourceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataSourceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataSourceDlg)
	m_Path[0] = '\0';
	//}}AFX_DATA_INIT
}


void CDataSourceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataSourceDlg)
	DDX_Text(pDX, IDC_DATASOURCE_PATH, m_Path, 256);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataSourceDlg, CDialog)
	//{{AFX_MSG_MAP(CDataSourceDlg)
	ON_CBN_KILLFOCUS(IDC_DATASOURCE_NAME, OnKillfocusDatasourceName)
	ON_EN_KILLFOCUS(IDC_DATASOURCE_PATH, OnKillfocusDatasourcePath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataSourceDlg message handlers

BOOL CDataSourceDlg::OnInitDialog() 
{
	USES_CONVERSION;

	CDialog::OnInitDialog();
	m_pDataSourcePath=(CEdit*)GetDlgItem(IDC_DATASOURCE_PATH);
	m_pDataSource=(CComboBox*)GetDlgItem(IDC_DATASOURCE_NAME);
	m_pOK=(CButton*)GetDlgItem(IDOK);

	if(m_pRootEnum->m_nType==1)
	{
		m_pDataSourcePath->EnableWindow(TRUE);
		m_pDataSource->EnableWindow(FALSE);	
	}
	else
	{
		m_pDataSourcePath->EnableWindow(FALSE);
		m_pDataSource->EnableWindow(TRUE);	
		
		CComPtr<IMoniker> spMoniker;
				
		if(m_pRootEnum->GetMoniker(&spMoniker, W2T(m_pRootEnum->m_szParseName))==S_OK)
		{
			if(m_Enum.m_spSourcesRowset==NULL)
			{
				
				if (m_Enum.Open(spMoniker) != S_OK)
				{
					::AfxMessageBox("Failed to Open Data Source");
					m_pOK->EnableWindow(FALSE);
					OnCancel();
					return FALSE;
				}
				else
				{
					m_pOK->EnableWindow(TRUE);
				}
			}
			
			int i=0;
			if(m_Enum.MoveFirst()==S_OK)
			{
				do
				{	
					m_pDataSource->AddString(W2T(m_Enum.m_szName));
					m_listDataSource[i]= W2T(m_Enum.m_szName);
					i++;
				}while (m_Enum.MoveNext() == S_OK);
				m_pDataSource->SetCurSel(0);
			}
			else
			{
				m_pOK->EnableWindow(FALSE);
				OnCancel();
				return FALSE;
			}

		}

	}		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDataSourceDlg::OnKillfocusDatasourceName() 
{
	USES_CONVERSION;
	int nSelection=0;
	CComPtr<IMoniker> spMoniker;
	CDBPropSet	dbinit(DBPROPSET_DBINIT);
	
	nSelection=m_pDataSource->GetCurSel();
	if(nSelection == -1)
	{
		CString dataSourceName;
		GetDlgItemText(IDC_DATASOURCE_NAME, dataSourceName);
		if((nSelection=m_pDataSource->SelectString(-1,dataSourceName))==CB_ERR)
		{
			m_pDataSource->SetCurSel(0);
			nSelection = 0;
		}
	}
	if(m_pRootEnum->m_nType==2)
	{
		if(m_pRootEnum->GetMoniker(&spMoniker, W2T(m_pRootEnum->m_szParseName))==S_OK)
		{
			if(m_Enum.m_spSourcesRowset==NULL)
			{
				if (m_Enum.Open(spMoniker) == S_OK)
				{
					m_Enum.MoveFirst();
				
				}
			}
			else
			{
				m_Enum.MoveFirst();
			}
			do
			{	
				if(m_listDataSource[nSelection]==W2T(m_Enum.m_szName))
				{
					if(m_pRootEnum->m_nType==2)
					{
						dbinit.AddProperty(DBPROP_INIT_DATASOURCE, W2T(m_Enum.m_szName));
						dbinit.AddProperty(DBPROP_INIT_PROMPT, (long)4);
						dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
						if (m_source.Open(m_Enum,&dbinit)== S_OK)
						{
							return;
						}
						else
						{
							::AfxMessageBox("Failed to Open Data Source");
							m_pOK->EnableWindow(FALSE);
							OnCancel();
							return; 
						}

					}
				}
			
			}while (m_Enum.MoveNext() == S_OK);
		}	
	}
	return;
}


void CDataSourceDlg::OnKillfocusDatasourcePath() 
{
	USES_CONVERSION;
	UpdateData(TRUE);
	CDBPropSet	dbinit(DBPROPSET_DBINIT);
	dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
	dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
	dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
	dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
	dbinit.AddProperty(DBPROP_AUTH_PERSIST_ENCRYPTED, false);
	dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
	dbinit.AddProperty(DBPROP_INIT_DATASOURCE, m_Path);
	dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
	dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)2);
	dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, ";COUNTRY=0;CP=1252;LANGID=0x0409");
	dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
	if (m_source.Open(*m_pRootEnum,&dbinit)!= S_OK)
	{
		::AfxMessageBox("Failed to Open Data Source");
		m_pOK->EnableWindow(FALSE);
		OnCancel();
		return;
	}
}


