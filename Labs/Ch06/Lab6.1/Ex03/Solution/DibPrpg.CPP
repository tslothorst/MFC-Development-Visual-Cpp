// DibFilePropPage.cpp : implementation file
//

#include "stdafx.h"
#include "PalView.h"
#include "DibPrpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage dialog

IMPLEMENT_DYNCREATE(CDibFilePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CDibFilePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CDibFilePropPage)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

// {7F7767D6-365B-11D0-9C9D-00A0D100E3C8}
IMPLEMENT_OLECREATE_EX(CDibFilePropPage, "PalView.CDibFilePropPage",
	0x7f7767d6, 0x365b, 0x11d0, 0x9c, 0x9d, 0x0, 0xa0, 0xd1, 0x0, 0xe3, 0xc8)


/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage::CDibFilePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDibFilePropPage

BOOL CDibFilePropPage::CDibFilePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Define string resource for page type; replace '0' below with ID.

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DIBPAGE);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage::CDibFilePropPage - Constructor

// TODO: Define string resource for page caption; replace '0' below with ID.

CDibFilePropPage::CDibFilePropPage() :
	COlePropertyPage(IDD, IDS_DIBPAGE_CAPTION)
{
	//{{AFX_DATA_INIT(CDibFilePropPage)
	m_DibFileName = _T("");
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage::DoDataExchange - Moves data between page and properties

void CDibFilePropPage::DoDataExchange(CDataExchange* pDX)
{
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_DATA_MAP(CDibFilePropPage)
	DDP_Text(pDX, IDC_DIB_FILENAME, m_DibFileName, _T("DibFileName") );
	DDX_Text(pDX, IDC_DIB_FILENAME, m_DibFileName);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage message handlers

void CDibFilePropPage::OnBrowse() 
{
	CFileDialog dlg(TRUE);

	if(dlg.DoModal() == IDOK)
	{
		CEdit * pEdit = (CEdit *)GetDlgItem(IDC_DIB_FILENAME);
		if(0 != pEdit)
		{		
			pEdit->SetWindowText(dlg.GetPathName());	
		}
	}
}
