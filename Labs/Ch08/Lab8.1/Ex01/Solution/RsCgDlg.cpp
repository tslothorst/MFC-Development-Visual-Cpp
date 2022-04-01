// RsCgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RsCgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRsCgDlg dialog


CRsCgDlg::CRsCgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRsCgDlg::IDD, pParent)
{
	m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.3.51;Data Source=Employees.mdb");
	m_strCmdText = _T("Employees");

	m_pRs = NULL;
	
	//{{AFX_DATA_INIT(CRsCgDlg)
	m_strDlgAddress = _T("");
	m_strDlgCity = _T("");
	m_strDlgCountry = _T("");
	m_lDlgEmployeeID = 0;
	m_strDlgFirstName = _T("");
	m_strDlgHomePhone = _T("");
	m_strDlgLastName = _T("");
	m_strDlgRegion = _T("");
	m_strDlgTitle = _T("");
	//}}AFX_DATA_INIT
}

CRsCgDlg::~CRsCgDlg()
{
	m_pRs = NULL;
}

BOOL CRsCgDlg::OnInitDialog()
{
	IADORecordBinding *piAdoRecordBinding = NULL;

	CDialog::OnInitDialog();

	try
	{
		m_pRs.CreateInstance(__uuidof(Recordset));

		m_pRs->CursorLocation = adUseServer;
		m_pRs->Open((LPCTSTR)m_strCmdText, (LPCTSTR)m_strConnection, adOpenStatic, 
			adLockOptimistic, adCmdTableDirect);

		if (FAILED(m_pRs->QueryInterface(__uuidof(IADORecordBinding), (LPVOID *)&piAdoRecordBinding)))
			_com_issue_error(E_NOINTERFACE);
		piAdoRecordBinding->BindToRecordset(this);

		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}

	if (piAdoRecordBinding)
		piAdoRecordBinding->Release();

	return TRUE;
}

void CRsCgDlg::RefreshBoundData()
{
	if (adFldOK == lAddressStatus)
		m_strDlgAddress = m_szAddress;
	else
		m_strDlgAddress = _T("");
	if (adFldOK == lCityStatus)
		m_strDlgCity = m_szCity;
	else
		m_strDlgCity = _T("");
	if (adFldOK == lCountryStatus)
		m_strDlgCountry = m_szCountry;
	else
		m_strDlgCountry = _T("");
	if (adFldOK == lEmployeeIDStatus)
		m_lDlgEmployeeID = m_lEmployeeID;
	else
		m_lDlgEmployeeID = 0;
	if (adFldOK == lFirstNameStatus)
		m_strDlgFirstName = m_szFirstName;
	else
		m_strDlgFirstName = _T("");
	if (adFldOK == lHomePhoneStatus)
		m_strDlgHomePhone = m_szHomePhone;
	else
		m_strDlgHomePhone = _T("");
	if (adFldOK == lLastNameStatus)
		m_strDlgLastName = m_szLastName;
	else
		m_strDlgLastName = _T("");
	if (adFldOK == lRegionStatus)
		m_strDlgRegion = m_szRegion;
	else
		m_strDlgRegion = _T("");
	if (adFldOK == lTitleStatus)
		m_strDlgTitle = m_szTitle;
	else
		m_strDlgTitle = _T("");

	UpdateData(FALSE);
}

void CRsCgDlg::GenerateError(HRESULT hr, PWSTR pwszDescription)
{
	CString strError;

	strError.Format("Run-time error '%d (%x)'", hr, hr);
	strError += "\n\n";
	strError += pwszDescription;

	AfxMessageBox(strError);
}

void CRsCgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRsCgDlg)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strDlgAddress);
	DDX_Text(pDX, IDC_EDIT_CITY, m_strDlgCity);
	DDX_Text(pDX, IDC_EDIT_COUNTRY, m_strDlgCountry);
	DDX_Text(pDX, IDC_EDIT_EMPLOYEEID, m_lDlgEmployeeID);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, m_strDlgFirstName);
	DDX_Text(pDX, IDC_EDIT_HOMEPHONE, m_strDlgHomePhone);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, m_strDlgLastName);
	DDX_Text(pDX, IDC_EDIT_REGION, m_strDlgRegion);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strDlgTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRsCgDlg, CDialog)
	//{{AFX_MSG_MAP(CRsCgDlg)
	ON_BN_CLICKED(ID_BTN_MOVEFIRST, OnBtnMoveFirst)
	ON_BN_CLICKED(ID_BTN_MOVELAST, OnBtnMoveLast)
	ON_BN_CLICKED(ID_BTN_MOVENEXT, OnBtnMoveNext)
	ON_BN_CLICKED(ID_BTN_MOVEPREVIOUS, OnBtnMovePrevious)
	ON_BN_CLICKED(ID_ADD,OnAdd)
	ON_BN_CLICKED(ID_DELETE,OnDelete)
	ON_BN_CLICKED(ID_UPDATE,OnUpdate)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRsCgDlg message handlers

void CRsCgDlg::OnBtnMoveFirst() 
{
	try
	{
		m_pRs->MoveFirst();
		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}

void CRsCgDlg::OnBtnMoveLast() 
{
	try
	{
		m_pRs->MoveLast();
		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}

void CRsCgDlg::OnBtnMoveNext() 
{
	try
	{
		m_pRs->MoveNext();
		if(m_pRs->EndOfFile)
			m_pRs->MoveLast();
		RefreshBoundData();;
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}

void CRsCgDlg::OnBtnMovePrevious() 
{
	try
	{
		m_pRs->MovePrevious();
		if(m_pRs->BOF)
			m_pRs->MoveFirst();
		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}

void CRsCgDlg::OnAdd() 
{
	
	try
	{	
		UpdateData(TRUE);
		
		COleVariant fld[9],val[9];
		fld[0]="EmployeeID";	
		val[0]=m_lDlgEmployeeID;
		fld[1]="LastName";	
		val[1]=m_strDlgLastName;
		fld[2]="FirstName";	
		val[2]=m_strDlgFirstName;
		fld[3]="Title";
		val[3]=m_strDlgTitle;
		fld[4]="Address";
		val[4]=m_strDlgAddress;
		fld[5]="City";
		val[5]=m_strDlgCity;
		fld[6]="Region";
		val[6]=m_strDlgRegion;
		fld[7]="Country";
		val[7]=m_strDlgCountry;
		fld[8]="HomePhone";
		val[8]=m_strDlgHomePhone;

		VARIANT rgf,rgv;
		rgf.vt=VT_ARRAY|VT_VARIANT;
		rgv.vt=VT_ARRAY|VT_VARIANT;
		SAFEARRAYBOUND bound;
		bound.cElements=9;
		bound.lLbound=0;

		rgv.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgv.parray==NULL)
			AfxThrowMemoryException();
		rgf.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgf.parray==NULL)
			AfxThrowMemoryException();

		long rgIndices[1];
		for(int i=0; i<9;i++)
		{
		rgIndices[0]=i;
		::SafeArrayPutElement(rgf.parray, rgIndices, &fld[i]);
		::SafeArrayPutElement(rgv.parray, rgIndices, &val[i]);
		}
		m_pRs->AddNew(&rgf,&rgv);	
		
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}


void CRsCgDlg::OnDelete() 
{
	try
		{
			m_pRs->Delete(adAffectCurrent);
			m_pRs->MoveNext();
			if(m_pRs->EndOfFile)
				m_pRs->MoveLast();
			RefreshBoundData();
	
		}
		catch (_com_error &e)
		{
			if(m_pRs->EndOfFile && m_pRs->BOF)
				BlankForm();
			else
				GenerateError(e.Error(), e.Description());
		}
}


void CRsCgDlg::OnUpdate() 
{
	
	try
	{	
		UpdateData(TRUE);

		COleVariant fld[9],val[9];
		fld[0]="EmployeeID";	
		val[0]=m_lDlgEmployeeID;
		fld[1]="LastName";	
		val[1]=m_strDlgLastName;
		fld[2]="FirstName";	
		val[2]=m_strDlgFirstName;
		fld[3]="Title";
		val[3]=m_strDlgTitle;
		fld[4]="Address";
		val[4]=m_strDlgAddress;
		fld[5]="City";
		val[5]=m_strDlgCity;
		fld[6]="Region";
		val[6]=m_strDlgRegion;
		fld[7]="Country";
		val[7]=m_strDlgCountry;
		fld[8]="HomePhone";
		val[8]=m_strDlgHomePhone;

		VARIANT rgf,rgv;
		rgf.vt=VT_ARRAY|VT_VARIANT;
		rgv.vt=VT_ARRAY|VT_VARIANT;
		SAFEARRAYBOUND bound;
		bound.cElements=9;
		bound.lLbound=0;

		rgv.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgv.parray==NULL)
			AfxThrowMemoryException();
		rgf.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgf.parray==NULL)
			AfxThrowMemoryException();

		long rgIndices[1];
		for(int i=0; i<9;i++)
		{
		rgIndices[0]=i;
		::SafeArrayPutElement(rgf.parray, rgIndices, &fld[i]);
		::SafeArrayPutElement(rgv.parray, rgIndices, &val[i]);
		}
			m_pRs->Update(&rgf,&rgv);	
		
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}



void CRsCgDlg::BlankForm()
{
	m_strDlgAddress = _T("");
	m_strDlgCity = _T("");
	m_strDlgCountry = _T("");
	m_lDlgEmployeeID = 0;
	m_strDlgFirstName = _T("");
	m_strDlgHomePhone = _T("");
	m_strDlgLastName = _T("");
	m_strDlgRegion = _T("");
	m_strDlgTitle = _T("");
	UpdateData(FALSE);
}
