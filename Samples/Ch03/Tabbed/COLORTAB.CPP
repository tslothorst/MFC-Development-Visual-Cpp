// ColorTab.cpp : implementation file
//

#include "stdafx.h"
#include "tabbed.h"
#include "ClrLstBx.h"
#include "ColorTab.h"
#include "XtraFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorTab property page

IMPLEMENT_DYNCREATE(CColorTab, CPropertyPage)

CColorTab::CColorTab() : CPropertyPage(CColorTab::IDD)
{
	//{{AFX_DATA_INIT(CColorTab)
	m_colorRadio = -1;
	m_colorList = -1;
	//}}AFX_DATA_INIT
}

CColorTab::~CColorTab()
{
}

void CColorTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CColorTab)
	DDX_Radio(pDX, IDC_BLACK, m_colorRadio);
	DDX_LBIndex(pDX, IDC_COLOR_LIST, m_colorList);
	//}}AFX_DATA_MAP

	// If you want the list box's ItemData field available
	// in the dialog class, you've got to do the transfer
	// yourself. For this particular variable (m_color)
	// true DDX isn't appropriate. The variable m_color
	// is used to set the initial list box selection in
	// OnInitDialog.

	if (pDX->m_bSaveAndValidate)
	{
		int cs = m_colorListBox.GetCurSel();
		m_color = m_colorListBox.GetItemData(cs);
	}
}

BEGIN_MESSAGE_MAP(CColorTab, CPropertyPage)
	//{{AFX_MSG_MAP(CColorTab)
	ON_LBN_SELCHANGE(IDC_COLOR_LIST, OnSelchangeColorList)
	//}}AFX_MSG_MAP
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BLACK, IDC_BLUE, OnRadioClicked )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorTab message handlers

BOOL CColorTab::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	// Subclass the control. From now on all references to the
	// control on the dialog box will be via the custom
	// list box m_colorListBox.
	m_colorListBox.SubclassDlgItem(IDC_COLOR_LIST, this);
	
	// Add 4 colors to the listbox. See DrawItem in the
	// derived list box's implementation file to see how
	// this value is used.
	m_colorListBox.AddString((LPCTSTR) BLACK);
	m_colorListBox.AddString((LPCTSTR) RED);
	m_colorListBox.AddString((LPCTSTR) GREEN);
	m_colorListBox.AddString((LPCTSTR) BLUE);

	// Set the initial selection in the radio buttons
	// and the list box.
	m_colorList = m_colorRadio = RgbToInt(m_color);
	
	return TRUE;
}

// In order to make the list box and the group of radio
// buttons operate in sync, when the selection changes in
// the list box, change the radio button as well.
void CColorTab::OnSelchangeColorList() 
{
	m_colorList = m_colorRadio = m_colorListBox.GetCurSel();
	UpdateData(FALSE);
}

// Click events for all four radio buttons end up here.
// See this class's message map for more information.
// When the radio button changes, change selection in
// the list box also. Since the radio buttons have
// consecutive IDs, a simple subtraction provides the 
// needed integer.
void CColorTab::OnRadioClicked(UINT nID) 
{
	m_colorList = m_colorRadio = nID - IDC_BLACK;
	UpdateData(FALSE);
}
