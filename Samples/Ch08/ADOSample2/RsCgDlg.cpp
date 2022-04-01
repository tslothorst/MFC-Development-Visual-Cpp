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
	m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.3.51;Data Source=.\\emp.mdb");
	m_strCmdText = _T("Employees");

	m_pRs = NULL;
	
	//{{AFX_DATA_INIT(CRsCgDlg)
	m_strDlgAddress = _T("");
	m_lDlgEmployeeID = 0;
	m_strDlgName = _T("");
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
	if (adFldOK == lEmployeeIDStatus)
		m_lDlgEmployeeID = m_lEmployeeID;
	else
		m_lDlgEmployeeID = 0;
	if (adFldOK == lNameStatus)
		m_strDlgName = m_szName;
	else
		m_strDlgName = _T("");

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
	DDX_Text(pDX, IDC_EDIT_EMPLOYEEID, m_lDlgEmployeeID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strDlgName);
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
		RefreshBoundData();
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
		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}
