// Dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"

#include "dialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimalDlg dialog
CAnimalDlg::CAnimalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnimalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnimalDlg)
	m_animal = _T("");
	m_type = _T("");
	m_weight = 0;
	m_class = _T("");
	//}}AFX_DATA_INIT
}

void CAnimalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnimalDlg)
	DDX_Control(pDX, IDC_CLASS_LIST, m_classNames);
	DDX_Text(pDX, IDC_ANIMAL, m_animal);
	DDX_Text(pDX, IDC_TYPE, m_type);
	DDX_Text(pDX, IDC_WEIGHT, m_weight);
	DDX_LBString(pDX, IDC_CLASS_LIST, m_class);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnimalDlg, CDialog)
	//{{AFX_MSG_MAP(CAnimalDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnimalDlg message handlers

BOOL CAnimalDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString s;
	
	// Insert the class names into the list box and 
	// set the default selection to 0 ...
	for (int i = IDS_AMPHIBIANS; i <= IDS_REPTILES; i++)
	{
		s.LoadString(i);
		m_classNames.AddString(s);
	}
	m_classNames.SetCurSel(0);

	// and then size the list box.
	CRect rect;
	int itemHeight;
	m_classNames.GetClientRect(&rect);
	m_classNames.MapWindowPoints(this, &rect);
	// Increase each item's height by 1.
	itemHeight = m_classNames.GetItemHeight(0) + 1;
	rect.bottom = rect.top + ((IDS_REPTILES - IDS_AMPHIBIANS) + 1) * itemHeight;
	m_classNames.MoveWindow(&rect);
	
	return TRUE;
}

// ModifyDlg.cpp : implementation
/////////////////////////////////////////////////////////////////////////////
// CModifyDlg dialog
CModifyDlg::CModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModifyDlg)
	m_animal = _T("");
	m_weight = 0;
	//}}AFX_DATA_INIT
}

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyDlg)
	DDX_Text(pDX, IDC_ANIMAL, m_animal);
	DDX_Text(pDX, IDC_WEIGHT, m_weight);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CModifyDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyDlg message handlers


// ModifyTypeDlg.cpp : implementation
/////////////////////////////////////////////////////////////////////////////
// CModifyTypeDlg dialog
CModifyTypeDlg::CModifyTypeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModifyTypeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModifyTypeDlg)
	m_type = _T("");
	//}}AFX_DATA_INIT
}

void CModifyTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModifyTypeDlg)
	DDX_Text(pDX, IDC_TYPE, m_type);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CModifyTypeDlg, CDialog)
	//{{AFX_MSG_MAP(CModifyTypeDlg)
	ON_EN_CHANGE(IDC_TYPE, OnChangeType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModifyTypeDlg message handlers

void CModifyTypeDlg::OnChangeType() 
{
	CButton * pButton = (CButton *) GetDlgItem(IDOK);
	pButton->EnableWindow(TRUE);
}

BOOL CModifyTypeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// Initially, the OK button is disabled. When the user changes
	// the edit control, it's enabled.
	CButton * pButton = (CButton *) GetDlgItem(IDOK);
	pButton->EnableWindow(FALSE);
	
	return TRUE;
}
