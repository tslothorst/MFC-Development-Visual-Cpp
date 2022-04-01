// DlgOpenF.cpp : implementation file
//

#include "stdafx.h"
#include "PrgCtrl.h"
#include "DlgOpenF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOpenFiles dialog


CDlgOpenFiles::CDlgOpenFiles(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOpenFiles::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOpenFiles)
	m_File1 = _T("");
	m_File2 = _T("");
	//}}AFX_DATA_INIT
}


void CDlgOpenFiles::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOpenFiles)
	DDX_Text(pDX, IDC_EDIT_FILE1, m_File1);
	DDV_MaxChars(pDX, m_File1, 255);
	DDX_Text(pDX, IDC_EDIT_FILE2, m_File2);
	DDV_MaxChars(pDX, m_File2, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOpenFiles, CDialog)
	//{{AFX_MSG_MAP(CDlgOpenFiles)
	ON_BN_CLICKED(IDC_BUTTON_FILE1_BROWSE, OnButtonFile1Browse)
	ON_BN_CLICKED(IDC_BUTTON_FILE2_BROWSE, OnButtonFile2Browse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOpenFiles attributes
void CDlgOpenFiles::GetFile1(CString& rFile)
{
		rFile = m_File1;
}

void CDlgOpenFiles::GetFile2(CString& rFile)
{
		rFile = m_File2;
}

BOOL CDlgOpenFiles::IsValidFileSpec (LPCSTR lpszFileSpec)
{
	OFSTRUCT	of;
	if(OpenFile(lpszFileSpec, &of, OF_EXIST) == HFILE_ERROR)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CDlgOpenFiles message handlers

void CDlgOpenFiles::OnButtonFile1Browse() 
{
	UpdateData();
	static char BASED_CODE szFilter[] = 
		"All Files (*.*)|*.*|C++ Files (*.cpp, *.h)"\
		"|*.cpp;*.h||";
	CFileDialog dlg(TRUE,NULL,m_File1,NULL,szFilter);
	
	if (dlg.DoModal() == IDOK)
	{
		m_File1 = dlg.GetPathName();
	}
	UpdateData(FALSE);
}

void CDlgOpenFiles::OnButtonFile2Browse() 
{
	UpdateData();
	static char BASED_CODE szFilter[] = 
		"All Files (*.*)|*.*|C++ Files (*.cpp, *.h)"\
		"|*.cpp;*.h||";
	CFileDialog dlg(TRUE,NULL,m_File2,NULL,szFilter);
	
	if (dlg.DoModal() == IDOK)
	{
		m_File2 = dlg.GetPathName();
	}
	UpdateData(FALSE);
}

void CDlgOpenFiles::OnOK() 
{
	UpdateData();
	if(IsValidFileSpec(m_File1) && 
		(IsValidFileSpec(m_File2)))
	{	
		CDialog::OnOK();
	}
	else
	{
		CString ErrMsg;
		AfxFormatString2(ErrMsg, IDS_ERRFMT_INVALIDFILE, 
							m_File1, m_File2);
		MessageBox (ErrMsg);
	}
}
