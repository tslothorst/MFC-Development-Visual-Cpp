// Dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "Modeless.h"
#include "Dialogs.h"

#include "XtraFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListWithItemDataDlg dialog

CListWithItemDataDlg::CListWithItemDataDlg(CWnd * pWnd, CWnd* pParent /*=NULL*/)
	: CDialog(CListWithItemDataDlg::IDD, pParent),
	m_pWnd (pWnd)
{
	//{{AFX_DATA_INIT(CListWithItemDataDlg)
	m_phrase = _T("");
	//}}AFX_DATA_INIT
	m_UserMsg = RegisterWindowMessage(MY_DIALOGBOX_MSG);
}

void CListWithItemDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListWithItemDataDlg)
	DDX_Text(pDX, IDC_PHRASE, m_phrase);
	//}}AFX_DATA_MAP

	// 'Programmer-extended' DDV
	if (pDX->m_bSaveAndValidate)
		if (m_phrase.GetLength() == 0)
		{
			MessageBox("Phrase cannot be empty!");
			DDX_Text(pDX, IDC_PHRASE, m_phrase);
			pDX->Fail();
		}

	// If you want the list box's ItemData field available
	// in the dialog class, you've got to do the transfer
	// yourself. For this particular variable (m_color)
	// true DDX isn't appropriate. The variable m_color
	// is used to set the initial list box selection in
	// OnInitDialog.
	if (pDX->m_bSaveAndValidate)
	{
		CListBox * clb = (CListBox *)GetDlgItem(IDC_COLOR_LIST);
		m_color = clb->GetItemData(clb->GetCurSel());
	}
}

BEGIN_MESSAGE_MAP(CListWithItemDataDlg, CDialog)
	//{{AFX_MSG_MAP(CListWithItemDataDlg)
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_LBN_SELCHANGE(IDC_COLOR_LIST, EnableApplyButton)
	ON_EN_CHANGE(IDC_PHRASE, EnableApplyButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListWithItemDataDlg message handlers

BOOL CListWithItemDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Since no Listbox member exists in the dialog class
	// we'll access the list box via a pointer obtained
	// from GetDlgItem.
	CListBox * clb = (CListBox *)GetDlgItem(IDC_COLOR_LIST);
	
	// In this dialog box, the string is for appearance
	// only. The real value of the user's selection will be
	// the 32-bit value that is stored via SetItemData.
	// If there were more than 4 entries in the list box,
	// this section of code could be improved with some
	// arrays and a for loop.
	clb->AddString("Black");
	clb->SetItemData(0, BLACK);
	clb->AddString("Red");
	clb->SetItemData(1, RED);
	clb->AddString("Green");
	clb->SetItemData(2, GREEN);
	clb->AddString("Blue");
	clb->SetItemData(3, BLUE);
	
	// Set the initial selection in the list box.
	clb->SetCurSel(RgbToInt(m_color));

	// Size the list box.
	CRect rect;
	int itemHeight;
	clb->GetClientRect(&rect);
	clb->MapWindowPoints(this, & rect);
	itemHeight = clb->GetItemHeight(0) + 1;
	rect.bottom = rect.top + 4 * itemHeight;
	clb->MoveWindow(&rect);

	// Initially, the Apply button is disabled.
	CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);
	cb->EnableWindow(FALSE);
	
	return TRUE;
}

void CListWithItemDataDlg::OnApply() 
{
	UpdateData(TRUE);
	m_pWnd->SendMessage(m_UserMsg, ML_APPLY);

	// Now that the Apply button's work is done,
	// disable it.
	CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);
	cb->EnableWindow(FALSE);
}

void CListWithItemDataDlg::OnCancel() 
{
	m_pWnd->SendMessage(m_UserMsg, ML_CANCEL);
	DestroyWindow();
}

void CListWithItemDataDlg::PostNcDestroy() 
{
	delete this;
	CDialog::PostNcDestroy();
}

void CListWithItemDataDlg::EnableApplyButton() 
{
	// Enable the Apply button whenever a change is made in
	// the edit box, or the selection changes in the list box.
	// Note (from the message map) that this function is the
	// handler for 2 separate events.
	CButton * cb = (CButton *)GetDlgItem(IDC_APPLY);

	// Occasionally, at start up, cb may be null, so don't try
	// to use it unless it's good.
	if (cb)
		cb->EnableWindow(TRUE);
}
