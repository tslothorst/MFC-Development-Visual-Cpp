// DynAcc01View.cpp : implementation of the CDynAcc01View class
//

#include "stdafx.h"
#include "DynAcc01.h"

#include "DynAcc01Doc.h"
#include "DynAcc01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




/////////////////////////////////////////////////////////////////////////////
// CDynAcc01View

IMPLEMENT_DYNCREATE(CDynAcc01View, CFormView)

BEGIN_MESSAGE_MAP(CDynAcc01View, CFormView)
	//{{AFX_MSG_MAP(CDynAcc01View)
	ON_COMMAND(ID_RECORD_FIRST, OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, OnRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01View construction/destruction

CDynAcc01View::CDynAcc01View()
	: CFormView(CDynAcc01View::IDD)
{
	//{{AFX_DATA_INIT(CDynAcc01View)
	//}}AFX_DATA_INIT
	m_EmployeeID = 0;
	m_Address[0] = '\0';
	m_Name[0] = '\0';
	// TODO: add construction code here

}

CDynAcc01View::~CDynAcc01View()
{
	DynamicAccessor.Close();
	m_DataSource.Close();
	m_session.Close();
}

void CDynAcc01View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDynAcc01View)
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EMPLOYEE_ID, m_EmployeeID);
	DDX_Text(pDX, IDC_ADDRESS, m_Address, 51);
	DDX_Text(pDX, IDC_NAME, m_Name,51);
}

BOOL CDynAcc01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}



/////////////////////////////////////////////////////////////////////////////
// CDynAcc01View diagnostics

#ifdef _DEBUG
void CDynAcc01View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDynAcc01View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDynAcc01Doc* CDynAcc01View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynAcc01Doc)));
	return (CDynAcc01Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01View database support



/////////////////////////////////////////////////////////////////////////////
// CDynAcc01View message handlers

void CDynAcc01View::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	HRESULT		hr;

	CDBPropSet	dbinit(DBPROPSET_DBINIT);
	dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
	dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
	dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
	dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
	dbinit.AddProperty(DBPROP_AUTH_PERSIST_ENCRYPTED, false);
	dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
	dbinit.AddProperty(DBPROP_INIT_DATASOURCE, ".\\employees.mdb");
	dbinit.AddProperty(DBPROP_INIT_MODE, (long)3);
	dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)2);
	dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, ";COUNTRY=0;CP=1252;LANGID=0x0409");
	dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);

	hr = m_DataSource.Open("Microsoft.Jet.OLEDB.3.51", &dbinit);
	if (FAILED(hr))
		return;

	hr = m_session.Open(m_DataSource);
	if (FAILED(hr))
		return;

	CDBPropSet	propset(DBPROPSET_ROWSET);

	propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
	propset.AddProperty(DBPROP_IRowsetScroll, true);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE);

	hr = DynamicAccessor.Open(m_session, "SELECT * FROM Employees", &propset);
	if (FAILED(hr))
		return;

	DynamicAccessor.MoveFirst();
	Refreshdata();
	
	
	// TODO: Add your specialized code here and/or call the base class
	
}

void CDynAcc01View::Refreshdata()
{ 
	m_ColCnt = DynamicAccessor.GetColumnCount();
	
	for(int i = 0; i < m_ColCnt - 1; i++)
		m_pVoid[i]=DynamicAccessor.GetValue(i + 1);
	
	
	m_EmployeeID = *(int*)(m_pVoid[0]);
	sprintf(m_Name, "%s", m_pVoid[1]);
	sprintf(m_Address, "%s", m_pVoid[2]);

	UpdateData(FALSE);

}

void CDynAcc01View::OnRecordFirst() 
{
	DynamicAccessor.MoveFirst();
	Refreshdata();
}

void CDynAcc01View::OnRecordLast() 
{
	DynamicAccessor.MoveLast();
	Refreshdata();
}

void CDynAcc01View::OnRecordNext() 
{
	DynamicAccessor.MoveNext();
	Refreshdata();
	
}

void CDynAcc01View::OnRecordPrev() 
{
	DynamicAccessor.MovePrev();
	Refreshdata();
	
}

