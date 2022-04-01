// SpinEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpinButton.h"
#include "SpinEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinEditDlg dialog


CSpinEditDlg::CSpinEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSpinEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpinEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSpinEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpinEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpinEditDlg, CDialog)
	//{{AFX_MSG_MAP(CSpinEditDlg)
	ON_EN_CHANGE(IDC_BUDDY, OnChangeBuddy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinEditDlg message handlers

BOOL CSpinEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CRect rect1(10, 30, 100, 55);
	CRect rect2(101, 30, 110, 55);
    m_wndCEdit.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |
             ES_AUTOHSCROLL | WS_BORDER, rect1, this, IDC_BUDDY);
    m_wndCSpinButton.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP |
             ES_AUTOHSCROLL | WS_BORDER|UDS_SETBUDDYINT, rect2, this, IDC_SPIN_BUTTON);
    m_wndCSpinButton.SetFocus();  
	m_wndCSpinButton.SetBuddy(&m_wndCEdit);
	
	m_wndCSpinButton.SetRange(0,100);

	m_pCStaticCm = (CStatic*)GetDlgItem(IDC_LENGTH_CM); 
	
	m_pMph=(CProgressCtrl*)GetDlgItem(IDC_MPH);
	m_pKmph=(CProgressCtrl*)GetDlgItem(IDC_KMPH);

	m_pMph->SetRange(0,200);
	m_pKmph->SetRange(0,200);

	m_pMph->SetStep(1);
	m_pKmph->SetStep(1);
	SetDlgItemInt(IDC_BUDDY,m_wndCSpinButton.GetPos());

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CSpinEditDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	if(wParam==IDC_SPIN_BUTTON)
	{
		float nCtr = 0;
		
		m_pMph->SetPos(0);
		m_pKmph->SetPos(0);

		nPos=m_wndCSpinButton.GetPos();

		for(nCtr = 0; nCtr  <  nPos; nCtr ++)
			m_pMph->StepIt();
	
		for( nCtr = 0; nCtr <  (nPos * 1.65); nCtr++)
			m_pKmph->StepIt();

	}
			
	return CDialog::OnNotify(wParam, lParam, pResult);

}


void CSpinEditDlg::OnChangeBuddy() 
{
	char strLengthCms[14];
	float nCtr = 0;

	nPos=m_wndCSpinButton.GetPos();
	
	m_pMph->SetPos(0);
	m_pKmph->SetPos(0);

	for(nCtr = 0; nCtr  <  nPos; nCtr ++)
		m_pMph->StepIt();
	
	for( nCtr = 0; nCtr <  (nPos * 1.65); nCtr++)
		m_pKmph->StepIt();

	sprintf(strLengthCms, "%.2f Kmph.", nPos * 1.65);
	SetDlgItemText(IDC_LENGTH_CM, strLengthCms);
}


