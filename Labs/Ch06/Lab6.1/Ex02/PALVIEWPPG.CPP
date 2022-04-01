// PalViewPpg.cpp : Implementation of the CPalViewPropPage property page class.

#include "stdafx.h"
#include "PalView.h"
#include "PalViewPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CPalViewPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPalViewPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CPalViewPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPalViewPropPage, "PALVIEW.PalViewPropPage.1",
	0x7f7767c4, 0x365b, 0x11d0, 0x9c, 0x9d, 0, 0xa0, 0xd1, 0, 0xe3, 0xc8)


/////////////////////////////////////////////////////////////////////////////
// CPalViewPropPage::CPalViewPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CPalViewPropPage

BOOL CPalViewPropPage::CPalViewPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_PALVIEW_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewPropPage::CPalViewPropPage - Constructor

CPalViewPropPage::CPalViewPropPage() :
	COlePropertyPage(IDD, IDS_PALVIEW_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CPalViewPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewPropPage::DoDataExchange - Moves data between page and properties

void CPalViewPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CPalViewPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewPropPage message handlers
