// ClockPpg.cpp : Implementation of the CClockPropPage property page class.

#include "stdafx.h"
#include "Clock.h"
#include "ClockPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CClockPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CClockPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CClockPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockPropPage, "CLOCK.ClockPropPage.1",
	0x6eb850a4, 0x263c, 0x11cf, 0xa1, 0x51, 0, 0xaa, 0, 0x37, 0x4d, 0xd8)


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::CClockPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockPropPage

BOOL CClockPropPage::CClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::CClockPropPage - Constructor

CClockPropPage::CClockPropPage() :
	COlePropertyPage(IDD, IDS_CLOCK_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CClockPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::DoDataExchange - Moves data between page and properties

void CClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CClockPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage message handlers
