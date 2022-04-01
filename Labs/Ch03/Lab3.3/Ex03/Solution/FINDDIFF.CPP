// FindDiff.cpp : implementation file
//

#include "stdafx.h"
#include "diff.h"
#include "FindDiff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDifferenceDialog dialog


CFindDifferenceDialog::CFindDifferenceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDifferenceDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDifferenceDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_bTerminating = FALSE;
	m_bFindNext = FALSE;
}


void CFindDifferenceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDifferenceDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDifferenceDialog, CDialog)
	//{{AFX_MSG_MAP(CFindDifferenceDialog)
	ON_BN_CLICKED(IDOK, OnFindNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CFindDifferenceDialog::IsTerminating() const
{
	return m_bTerminating;
}

BOOL CFindDifferenceDialog::SearchDown() const       
{
	return(IsDlgButtonChecked(IDC_RADIO_DOWN));
}

BOOL CFindDifferenceDialog::FindDifference() const   
{
	return(IsDlgButtonChecked(IDC_RADIO_NEXTDIFF));
}

BOOL CFindDifferenceDialog::FindNext() const
{
	return m_bFindNext;
}


/////////////////////////////////////////////////////////////////////////////
// CFindDifferenceDialog message handlers

void CFindDifferenceDialog::OnFindNext() 
{
	m_bFindNext = TRUE;
	GetParent()->SendMessage(
		::RegisterWindowMessage(FINDDIFF_MSGSTRING), 
		0, (LPARAM)this);
	m_bFindNext = FALSE;
}

BOOL CFindDifferenceDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//	Our initialization
	CheckDlgButton(IDC_RADIO_NEXTDIFF, TRUE);
	CheckDlgButton(IDC_RADIO_DOWN, TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CFindDifferenceDialog::Create() 
{
	//	m_lpszTemplateName and m_pParent are set
	//	up by CDialog during construction
	return CDialog::Create (m_lpszTemplateName, m_pParentWnd);
}



void CFindDifferenceDialog::OnCancel() 
{
	DestroyWindow();
}

void CFindDifferenceDialog::PostNcDestroy() 
{
	//	Make sure our owner knows we are about
	//	to delete ourself. Directly access
	//	m_pParentWnd because a call to GetParent()
	//	ASSERTS that m_hWnd is still a window which
	//	is no longer true
	m_bTerminating = TRUE;
	m_pParentWnd->SendMessage(
		::RegisterWindowMessage(FINDDIFF_MSGSTRING), 
		0, (LPARAM)this);

	delete this;
}
