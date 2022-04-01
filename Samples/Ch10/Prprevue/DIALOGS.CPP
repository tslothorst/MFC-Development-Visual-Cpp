// Dialogs.cpp : implementation file
//

#include "stdafx.h"
#include "PrPrevue.h"
#include "dialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinesDLG dialog


CLinesDLG::CLinesDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CLinesDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinesDLG)
	m_linesPerPage = 0;
	//}}AFX_DATA_INIT
}

void CLinesDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinesDLG)
	DDX_Control(pDX, IDC_SPIN, m_spinner);
	DDX_Text(pDX, IDC_LINES, m_linesPerPage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLinesDLG, CDialog)
	//{{AFX_MSG_MAP(CLinesDLG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinesDLG message handlers

BOOL CLinesDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_spinner.SetRange(1, m_MaxPageLength);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
