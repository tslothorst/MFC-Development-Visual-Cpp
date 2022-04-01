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
