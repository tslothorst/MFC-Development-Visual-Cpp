// ManAcc01View.cpp : implementation of the CManAcc01View class
//

#include "stdafx.h"
#include "ManAcc01.h"

#include "ManAcc01Doc.h"
#include "ManAcc01View.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManAcc01View

IMPLEMENT_DYNCREATE(CManAcc01View, CFormView)

BEGIN_MESSAGE_MAP(CManAcc01View, CFormView)
	//{{AFX_MSG_MAP(CManAcc01View)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_RECORD_FST, OnRecordFst)
	ON_COMMAND(ID_RECORD_LST, OnRecordLst)
	ON_COMMAND(ID_RECORD_NXT, OnRecordNxt)
	ON_COMMAND(ID_RECORD_PRV, OnRecordPrv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManAcc01View construction/destruction

CManAcc01View::CManAcc01View()
	: CFormView(CManAcc01View::IDD)
{
	//{{AFX_DATA_INIT(CManAcc01View)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CManAcc01View::~CManAcc01View()
{
}

void CManAcc01View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManAcc01View)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CManAcc01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CManAcc01View::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CManAcc01View diagnostics

#ifdef _DEBUG
void CManAcc01View::AssertValid() const
{
	CFormView::AssertValid();
}

void CManAcc01View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CManAcc01Doc* CManAcc01View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CManAcc01Doc)));
	return (CManAcc01Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CManAcc01View database support



/////////////////////////////////////////////////////////////////////////////
// CManAcc01View message handlers

void CManAcc01View::OnFileOpen() 
{
	
	if(m_enumDlg.DoModal()==IDOK)
	{
		m_datasourceDlg.m_pRootEnum = &(m_enumDlg.m_RootEnum);
		if(m_datasourceDlg.DoModal()==IDOK)
		{
			m_tablesDlg.m_pSession = &(m_datasourceDlg.m_session);
			m_tablesDlg.m_pSource = &(m_datasourceDlg.m_source);
			if(m_tablesDlg.DoModal()==IDOK)
			{
				m_columnsDlg.m_pSession = m_tablesDlg.m_pSession;
				m_session = *(m_tablesDlg.m_pSession);
				m_columnsDlg.m_pTbl = &(m_tablesDlg.m_Tbl);
				m_columnsDlg.DoModal();
				m_cmd_str =  m_columnsDlg.m_cmd_str;
				m_ColsSelected = m_columnsDlg.m_ColsSelected;
				RetrieveRecords();
			}
			
		}
		
	}	
}

void CManAcc01View::RetrieveRecords() 
{
	struct MyBind* pBind  = NULL;
	
	pBind = new MyBind[m_ColsSelected];

	CCommand<CManualAccessor> manAcc;

	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->ResetContent();

	manAcc.CreateAccessor(m_ColsSelected, pBind, sizeof(MyBind)*m_ColsSelected);

	for (ULONG i=0; i < (ULONG)m_ColsSelected; i++)
		manAcc.AddBindEntry(i+1, DBTYPE_STR, sizeof(TCHAR)*40, &pBind[i].szValue,
	NULL, &pBind[i].dwStatus);

	if(manAcc.Open(m_session,m_cmd_str)!=S_OK)
	{
		::AfxMessageBox("Failed to Open Session");
		return;
	}

	if(manAcc.MoveFirst()==S_OK)
	{
		m_RecCount=0;
		
		do
		{
			char disp_str[500];
			disp_str[0]='\0';
			for(int ctr=0;ctr < m_ColsSelected;ctr++)
			{
				char m_temp_disp_str[500];
				sprintf(m_temp_disp_str,"%s  ", pBind[ctr].szValue);
				strcat(disp_str,m_temp_disp_str);
			}
			m_plbData->AddString(disp_str);
			m_RecCount++;
		}while(manAcc.MoveNext()==S_OK);	
	}	
	m_plbData->SetCurSel(0);
}




void CManAcc01View::OnRecordFst() 
{
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->SetCurSel(0);
	
}

void CManAcc01View::OnRecordNxt() 
{
	int nCurSel;
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	nCurSel=m_plbData->GetCurSel();
	if(nCurSel!=m_RecCount)
	{
		m_plbData->SetCurSel(nCurSel + 1);
	}
	
}

void CManAcc01View::OnRecordPrv() 
{
	int nCurSel;
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	nCurSel=m_plbData->GetCurSel();
	if(nCurSel!=0)
	{
		m_plbData->SetCurSel(nCurSel - 1);
	}
	
}


void CManAcc01View::OnRecordLst() 
{
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->SetCurSel(m_RecCount-1);
}

