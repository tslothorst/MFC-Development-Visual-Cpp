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
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDifferenceDialog message handlers
