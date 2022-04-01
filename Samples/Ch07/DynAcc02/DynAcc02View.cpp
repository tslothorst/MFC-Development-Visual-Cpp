// DynAcc02View.cpp : implementation of the CDynAcc02View class
//

#include "stdafx.h"
#include "DynAcc02.h"

#include "DynAcc02Doc.h"
#include "DynAcc02View.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02View

IMPLEMENT_DYNCREATE(CDynAcc02View, CFormView)

BEGIN_MESSAGE_MAP(CDynAcc02View, CFormView)
	//{{AFX_MSG_MAP(CDynAcc02View)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_RECORD_FST, OnRecordFst)
	ON_COMMAND(ID_RECORD_LST, OnRecordLst)
	ON_COMMAND(ID_RECORD_NXT, OnRecordNxt)
	ON_COMMAND(ID_RECORD_PRV, OnRecordPrv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02View construction/destruction

CDynAcc02View::CDynAcc02View()
	: CFormView(CDynAcc02View::IDD)
{
	//{{AFX_DATA_INIT(CDynAcc02View)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDynAcc02View::~CDynAcc02View()
{
}

void CDynAcc02View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynAcc02View)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CDynAcc02View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CDynAcc02View::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02View diagnostics

#ifdef _DEBUG
void CDynAcc02View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDynAcc02View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDynAcc02Doc* CDynAcc02View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynAcc02Doc)));
	return (CDynAcc02Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02View database support



/////////////////////////////////////////////////////////////////////////////
// CDynAcc02View message handlers

void CDynAcc02View::OnFileOpen() 
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
				RetrieveRecords();
			}
			
		}
		
	}	
}

void CDynAcc02View::RetrieveRecords()
{
	CDBPropSet	propset(DBPROPSET_ROWSET);
	char disp_str[500], TempStr[500];
	int nColCount=0;
	struct Field *pFieldData;
	
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->ResetContent();

	propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
	propset.AddProperty(DBPROP_IRowsetScroll, true);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);

	
	CCommand<CDynamicAccessor> da;
	
	if (S_OK != da.Open(m_session,m_cmd_str,&propset))
	{
		::AfxMessageBox("Failed to Open");
		return;
	}
	
	nColCount= m_columnsDlg.m_ColsSelected;
	pFieldData = new Field[nColCount];
		
	
	da.MoveFirst();
	for(int i = 1; i <= nColCount; i++)
	{
		da.GetColumnType(i, &((pFieldData + (i - 1))->ColType));
	}
	
	TempStr[0]='\0';
	m_RecCount=0;
	do
	{
		disp_str[0]='\0';
		for(int i =1 ; i <= nColCount; i++)
		{
			switch ((pFieldData + (i - 1))->ColType)
			{
			case DBTYPE_I2: (pFieldData + (i - 1))->pField = da.GetValue(i);
							sprintf(TempStr," %d ",*((int*)((pFieldData + (i - 1))->pField)));
							break;
			case DBTYPE_I4:	(pFieldData + (i - 1))->pField = da.GetValue(i);
							sprintf(TempStr," %d ", *((long*)((pFieldData + (i - 1))->pField)));
							break;
							break;
			default:		(pFieldData + (i - 1))->pField = da.GetValue(i);
							sprintf(TempStr," %s ", (pFieldData + (i - 1))->pField);
							break;
			}
			strcat(disp_str, TempStr);
		}
		
		m_plbData->AddString(disp_str);
		m_RecCount++;
	}while(da.MoveNext()==S_OK);
	m_plbData->SetCurSel(0);
}

void CDynAcc02View::OnRecordFst() 
{
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->SetCurSel(0);
	
}

void CDynAcc02View::OnRecordNxt() 
{
	int nCurSel;
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	nCurSel=m_plbData->GetCurSel();
	if(nCurSel!=m_RecCount)
	{
		m_plbData->SetCurSel(nCurSel + 1);
	}
	
}

void CDynAcc02View::OnRecordPrv() 
{
	int nCurSel;
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	nCurSel=m_plbData->GetCurSel();
	if(nCurSel!=0)
	{
		m_plbData->SetCurSel(nCurSel - 1);
	}
	
}


void CDynAcc02View::OnRecordLst() 
{
	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->SetCurSel(m_RecCount-1);
}


