// ADOSample3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOSample3.h"
#include "ADOSample3Dlg.h"
#include "FilterDlg.h"	

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOSample3Dlg dialog

CADOSample3Dlg::CADOSample3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOSample3Dlg::IDD, pParent)
{
	m_strConnection = _T("Provider=Microsoft.Jet.OLEDB.3.51;Data Source=.\\emp.mdb;Mode=Read|Write|ReadWrite");
	m_strCmdText = _T("Employees");
	m_pRs=NULL;
	//{{AFX_DATA_INIT(CADOSample3Dlg)
	m_lDlgID = 0;
	m_strDlgName = _T("");
	m_strDlgAddress = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CADOSample3Dlg::~CADOSample3Dlg()
{
	m_pRs=NULL;
}

void CADOSample3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOSample3Dlg)
	DDX_Text(pDX, IDC_ID, m_lDlgID);
	DDX_Text(pDX, IDC_NAME, m_strDlgName);
	DDX_Text(pDX, IDC_ADDRESS, m_strDlgAddress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOSample3Dlg, CDialog)
	//{{AFX_MSG_MAP(CADOSample3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_MOVEFIRST, OnBtnMovefirst)
	ON_BN_CLICKED(IDC_BTN_MOVELAST, OnBtnMovelast)
	ON_BN_CLICKED(IDC_BTN_MOVENEXT, OnBtnMovenext)
	ON_BN_CLICKED(IDC_BTN_MOVEPREVIOUS, OnBtnMoveprevious)
	ON_BN_CLICKED(IDC_SET_FILTER, OnSetFilter)
	ON_BN_CLICKED(IDC_RESET_FILTER, OnResetFilter)
	ON_BN_CLICKED(IDC_FIND_RECORD_FORWARD, OnFindRecordForward)
	ON_BN_CLICKED(IDC_FIND_RECORD_REVERSE, OnFindRecordReverse)
	ON_BN_CLICKED(IDC_ADD_RECORD, OnAddRecord)
	ON_BN_CLICKED(IDC_DEL_RECORD, OnDelRecord)
	ON_BN_CLICKED(IDC_EDIT_RECORD, OnEditRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOSample3Dlg message handlers

BOOL CADOSample3Dlg::OnInitDialog()
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


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOSample3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CADOSample3Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CADOSample3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CADOSample3Dlg::RefreshBoundData()
{
	if (adFldOK == lIDStatus)
		m_lDlgID = m_lID;
	else
		m_lDlgID = 0;
	if (adFldOK == lNameStatus)
		m_strDlgName = m_szName;
	else
		m_strDlgName = _T("");
	if (adFldOK == lAddressStatus)
		m_strDlgAddress = m_szAddress;
	else
		m_strDlgAddress = _T("");

	UpdateData(FALSE);
}

void CADOSample3Dlg::GenerateError(HRESULT hr, PWSTR pwszDescription)
{
	CString strError;

	strError.Format("Run-time error '%d (%x)'", hr, hr);
	strError += "\n\n";
	strError += pwszDescription;

	AfxMessageBox(strError);
}

void CADOSample3Dlg::OnBtnMovefirst() 
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

void CADOSample3Dlg::OnBtnMovelast() 
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

void CADOSample3Dlg::OnBtnMovenext() 
{
	try
	{
		m_pRs->MoveNext();
		if(m_pRs->EndOfFile)
			m_pRs->MoveLast();
		RefreshBoundData();
	}
	catch (_com_error &e)
	{
		GenerateError(e.Error(), e.Description());
	}
}

void CADOSample3Dlg::OnBtnMoveprevious() 
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


void CADOSample3Dlg::OnSetFilter() 
{
	if(FilterDlg.DoModal()==IDOK)
	{

		try
		{
			m_pRs->Filter=FilterDlg.m_ConditionStr.GetBuffer(300);
			RefreshBoundData();
		}
		catch (_com_error &e)
		{
			GenerateError(e.Error(), e.Description());
		}
	}
	
}

void CADOSample3Dlg::OnResetFilter() 
{
	m_pRs->Filter="";	
}

void CADOSample3Dlg::OnFindRecordForward() 
{
	if(FilterDlg.DoModal()==IDOK)
	{

		try
		{
			m_pRs->Find(FilterDlg.m_ConditionStr.GetBuffer(300),0,adSearchForward);
			RefreshBoundData();
		}
		catch (_com_error &e)
		{
			GenerateError(e.Error(), e.Description());
		}
	}
	
}

void CADOSample3Dlg::OnFindRecordReverse() 
{
	if(FilterDlg.DoModal()==IDOK)
	{

		try
		{
			m_pRs->Find(FilterDlg.m_ConditionStr.GetBuffer(300),0,adSearchBackward);
			RefreshBoundData();
		}
		catch (_com_error &e)
		{
			GenerateError(e.Error(), e.Description());
		}
	}
	
	
}

void CADOSample3Dlg::OnAddRecord() 
{
	long rgIndices[1];
	VARIANT rgf;
	VARIANT rgv;
	COleVariant fld[3], val[3];
	SAFEARRAYBOUND bound;
	try
	{	
		UpdateData(TRUE);
		fld[0]="EmployeeID";	
		val[0]=m_lDlgID;
		fld[1]="Name";	
		val[1]=m_strDlgName;
		fld[2]="Address";	
		val[2]=m_strDlgAddress;

		rgf.vt=VT_ARRAY|VT_VARIANT;
		rgv.vt=VT_ARRAY|VT_VARIANT;
		
		bound.cElements=3;
		bound.lLbound=0;

		rgv.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgv.parray==NULL)
			AfxThrowMemoryException();
		rgf.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgf.parray==NULL)
			AfxThrowMemoryException();

		for ( int i = 0; i < 3; i++)
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

void CADOSample3Dlg::OnDelRecord() 
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
			{
				BlankForm();
				UpdateData(FALSE);
			}
			else
				GenerateError(e.Error(), e.Description());
		}
}

void CADOSample3Dlg::OnEditRecord() 
{
	long rgIndices[1];
	VARIANT rgf;
	VARIANT rgv;
	COleVariant fld[3], val[3];
	SAFEARRAYBOUND bound;
	
	try
	{
		UpdateData(TRUE);
		fld[0]="EmployeeID";	
		val[0]=m_lDlgID;
		fld[1]="Name";	
		val[1]=m_strDlgName;
		fld[2]="Address";	
		val[2]=m_strDlgAddress;

		rgf.vt=VT_ARRAY|VT_VARIANT;
		rgv.vt=VT_ARRAY|VT_VARIANT;
		
		bound.cElements=3;
		bound.lLbound=0;

		rgv.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgv.parray==NULL)
			AfxThrowMemoryException();
		rgf.parray=::SafeArrayCreate(VT_VARIANT,1,&bound);
		if(rgf.parray==NULL)
			AfxThrowMemoryException();

		for ( int i = 0; i < 3; i++)
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

void CADOSample3Dlg::BlankForm()
{
	m_lDlgID = 0;
	m_strDlgName = _T("");
	m_strDlgAddress = _T("");
	UpdateData(FALSE);
}
