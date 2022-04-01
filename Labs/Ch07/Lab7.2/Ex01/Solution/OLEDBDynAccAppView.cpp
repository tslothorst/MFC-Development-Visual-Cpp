// ManAcc01View.cpp : implementation of the COLEDBDynAccAppView class
//

#include "stdafx.h"
#include "OLEDBDynAccApp.h"

#include "OLEDBDynAccAppDoc.h"
#include "OLEDBDynAccAppView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView

IMPLEMENT_DYNCREATE(COLEDBDynAccAppView, CFormView)

BEGIN_MESSAGE_MAP(COLEDBDynAccAppView, CFormView)
	//{{AFX_MSG_MAP(COLEDBDynAccAppView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView construction/destruction

COLEDBDynAccAppView::COLEDBDynAccAppView()
	: CFormView(COLEDBDynAccAppView::IDD)
{
	//{{AFX_DATA_INIT(COLEDBDynAccAppView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COLEDBDynAccAppView::~COLEDBDynAccAppView()
{
}

void COLEDBDynAccAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COLEDBDynAccAppView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COLEDBDynAccAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COLEDBDynAccAppView::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView diagnostics

#ifdef _DEBUG
void COLEDBDynAccAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void COLEDBDynAccAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COLEDBDynAccAppDoc* COLEDBDynAccAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDBDynAccAppDoc)));
	return (COLEDBDynAccAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView database support



/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView message handlers

void COLEDBDynAccAppView::OnFileOpen() 
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




void COLEDBDynAccAppView::RetrieveRecords()
{
	CDBPropSet	propset(DBPROPSET_ROWSET);
	char dispStr[500], tempStr[500];
	struct Field *pFieldData;

	m_plbData=(CListBox*)GetDlgItem(IDC_DATA);
	m_plbData->ResetContent();

	propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);

	CCommand<CDynamicAccessor> dynamicAccessor;

	if (S_OK != dynamicAccessor.Open(m_session,m_cmd_str,&propset))
	{
		MessageBox("Failed to Open");
		return;
	}

	pFieldData = new Field[m_columnsDlg.m_ColsSelected];

	dynamicAccessor.MoveFirst();

	for(int i = 1; i <= m_columnsDlg.m_ColsSelected; i++)
	{
		dynamicAccessor.GetColumnType(i, &((pFieldData + (i - 1))->ColType));
	}	

	tempStr[0] = '\0';

	do
	{
		dispStr[0]='\0';
		for(int i =1 ; i <= m_columnsDlg.m_ColsSelected; i++)
		{
			switch ((pFieldData + (i - 1))->ColType)
			{
			case DBTYPE_I2: (pFieldData + (i - 1))->pField = dynamicAccessor.GetValue(i);
							sprintf(tempStr," %d ",*((int*)((pFieldData + (i - 1))->pField)));
							break;
			case DBTYPE_I4:	(pFieldData + (i - 1))->pField = dynamicAccessor.GetValue(i);
							sprintf(tempStr," %d ", *((long*)((pFieldData + (i - 1))->pField)));
							break;
			default:		(pFieldData + (i - 1))->pField = dynamicAccessor.GetValue(i);
							sprintf(tempStr," %s ", (pFieldData + (i - 1))->pField);
							break;
			}
			strcat(dispStr, tempStr);
		}
		
		m_plbData->AddString(dispStr);

	}while(dynamicAccessor.MoveNext()==S_OK);

	delete pFieldData;
}
