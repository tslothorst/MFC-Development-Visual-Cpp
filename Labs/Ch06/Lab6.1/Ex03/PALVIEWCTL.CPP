// PalViewCtl.cpp : Implementation of the CPalViewCtrl ActiveX Control class.

#include "stdafx.h"
#include "PalView.h"

#include "dib.h"
#include "dibpal.h"

#include "PalViewCtl.h"
#include "PalViewPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CPalViewCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CPalViewCtrl, COleControl)
	//{{AFX_MSG_MAP(CPalViewCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CPalViewCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CPalViewCtrl)
	DISP_PROPERTY_NOTIFY(CPalViewCtrl, "DibFileName", m_dibFileName, OnDibFileNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CPalViewCtrl, "ShowColorSelection", m_showColorSelection, OnShowColorSelectionChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(CPalViewCtrl, "Show3D", m_show3D, OnShow3DChanged, VT_BOOL)
	DISP_PROPERTY_EX(CPalViewCtrl, "SelectionIndex", GetSelectionIndex, SetSelectionIndex, VT_I2)
	DISP_FUNCTION(CPalViewCtrl, "GetColorFromPalette", GetColorFromPalette, VT_I4, VTS_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CPalViewCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CPalViewCtrl, COleControl)
	//{{AFX_EVENT_MAP(CPalViewCtrl)
	EVENT_CUSTOM("SelChange", FireSelChange, VTS_I2)
	EVENT_STOCK_DBLCLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CPalViewCtrl, 1)
	PROPPAGEID(CPalViewPropPage::guid)
END_PROPPAGEIDS(CPalViewCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CPalViewCtrl, "PALVIEW.PalViewCtrl.1",
	0x7f7767c3, 0x365b, 0x11d0, 0x9c, 0x9d, 0, 0xa0, 0xd1, 0, 0xe3, 0xc8)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CPalViewCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DPalView =
		{ 0x7f7767c1, 0x365b, 0x11d0,
		{ 0x9c, 0x9d, 0, 0xa0, 0xd1, 0, 0xe3, 0xc8 } };
const IID BASED_CODE IID_DPalViewEvents =
		{ 0x7f7767c2, 0x365b, 0x11d0, 
		{ 0x9c, 0x9d, 0, 0xa0, 0xd1, 0, 0xe3, 0xc8 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwPalViewOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPalViewCtrl, IDS_PALVIEW, _dwPalViewOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::CPalViewCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CPalViewCtrl

BOOL CPalViewCtrl::CPalViewCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_PALVIEW,
			IDB_PALVIEW,
			afxRegApartmentThreading,
			_dwPalViewOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::CPalViewCtrl - Constructor

CPalViewCtrl::CPalViewCtrl()
{
	InitializeIIDs(&IID_DPalView, &IID_DPalViewEvents);
	m_pDibPal = NULL;
	m_dibFileName = _T("");
	m_showColorSelection = TRUE;
	m_show3D = FALSE;

}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::~CPalViewCtrl - Destructor

CPalViewCtrl::~CPalViewCtrl()
{
	if (NULL != m_pDibPal)
	{
		delete m_pDibPal;
		m_pDibPal = NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::OnDraw - Drawing function

void CPalViewCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if(NULL != m_pDibPal)
		m_pDibPal->Draw(pdc, rcBounds, m_showColorSelection);
	else
		pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));

}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::DoPropExchange - Persistence support

void CPalViewCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Bool(pPX, _T("ShowColorSelection"),m_showColorSelection, TRUE);
	PX_Bool(pPX, _T("Show3D"), m_show3D, FALSE);
	PX_String(pPX, _T("DibFileName"), m_dibFileName, _T(""));
	if (pPX->IsLoading())
		ExtractPalFromDIBFile(m_dibFileName);

}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::OnResetState - Reset control to default state

void CPalViewCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl::AboutBox - Display an "About" box to the user

void CPalViewCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_PALVIEW);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl message handlers
void CPalViewCtrl::ExtractPalFromDIBFile(LPCTSTR lpszFileSpec)
{
	CDIB	Dib;
	CFile	DibFile;
	
	if(DibFile.Open(lpszFileSpec, CFile::modeRead))
	{
		// Load the bitmap file into a CDIB object
		if(Dib.Load(&DibFile))
		{
			CDIBPal* pTemp = new CDIBPal;
			ASSERT(pTemp != NULL);
		
			//	This will extract the color table fron the CDIB object
			if(pTemp->Create(&Dib))
			{
				//	Get rid of any existing CDIBPal object
				if(NULL != m_pDibPal)
				{
					delete m_pDibPal;
					m_pDibPal = NULL;
				}
				//	Ready to go
				m_pDibPal = pTemp;
		
				//	Make sure the new palette reflects our current state
				m_pDibPal->SetDraw3D(m_show3D);

			}
			else
			{
				delete pTemp;
			}
		}
	}
}

void CPalViewCtrl::OnDibFileNameChanged() 
{
	ExtractPalFromDIBFile(m_dibFileName);
	InvalidateControl();

	SetModifiedFlag();
}

void CPalViewCtrl::OnShowColorSelectionChanged() 
{
	InvalidateControl();
	SetModifiedFlag();
}

void CPalViewCtrl::OnShow3DChanged() 
{
	if (NULL != m_pDibPal)
	{
		m_pDibPal->SetDraw3D(m_show3D);
		InvalidateControl();
	}
	SetModifiedFlag();
}

short CPalViewCtrl::GetSelectionIndex() 
{
	short nSelectionIndex = -1;
	if (NULL != m_pDibPal)
	{
		nSelectionIndex = m_pDibPal->GetSelectionIndex();
	}
	return nSelectionIndex;
}

void CPalViewCtrl::SetSelectionIndex(short nNewValue) 
{
	if(nNewValue >= 0 && nNewValue < 256)
	{
		if (NULL != m_pDibPal)
		{
			m_pDibPal->SetSelectionIndex(nNewValue);
			FireSelChange(nNewValue);
			InvalidateControl();
		}
	}
	SetModifiedFlag();

}

void CPalViewCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(NULL != m_pDibPal)
	{
		int x, y;
		GetControlSize(&x, &y);
		CRect rcControl(0, 0, x, y);
  
		//	Ask the DibPal object which palette index would
		//	be hit by the mouse click
		int nPalIndex = m_pDibPal->HitTest(rcControl, point);
		if(-1 != nPalIndex)
			//Change the selection property
			SetSelectionIndex(nPalIndex);
	}
	COleControl::OnLButtonDown(nFlags, point);
}

long CPalViewCtrl::GetColorFromPalette(short nPalIndex) 
{
		COLORREF		crRet = 0; // Default to BLACK
	if(nPalIndex >= 0 && nPalIndex < 256)
	{
		if(NULL != m_pDibPal)
			crRet = m_pDibPal->GetColorFromIndex(nPalIndex);
	}
	return crRet;

}
