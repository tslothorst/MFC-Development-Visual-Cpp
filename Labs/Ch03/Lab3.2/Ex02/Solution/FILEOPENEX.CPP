// FileOpenEx.cpp : implementation file
//

#include "stdafx.h"
#include "diff.h"
#include "FileOpenEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileOpenEx dialog


CFileOpenEx::CFileOpenEx(CWnd* pParent /*=NULL*/)
	: CDialog(CFileOpenEx::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileOpenEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFileOpenEx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileOpenEx)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileOpenEx, CDialog)
	//{{AFX_MSG_MAP(CFileOpenEx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOpenEx message handlers

int CFileOpenEx::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void CFileOpenEx::OnFileNameChange()
{

}
