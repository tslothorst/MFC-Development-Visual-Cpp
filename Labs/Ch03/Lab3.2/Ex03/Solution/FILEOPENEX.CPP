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

CFileOpenEx::CFileOpenEx(LPCTSTR lpszDefExt /*= NULL*/,
						LPCTSTR lpszFileName /*= NULL*/,
						DWORD dwFlags /*= OFN_HIDEREADONLY*/,
						LPCTSTR lpszFilter /*= NULL*/,
						CWnd* pParentWnd /*= NULL*/)
			: CFileDialog(TRUE, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	//	Always start out folded

	//{{AFX_DATA_INIT(CFileOpenEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CFileOpenEx::DoDataExchange(CDataExchange* pDX)
{
	CFileDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileOpenEx)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_EDIT_CONTENTS, m_RichEdit);
}


BEGIN_MESSAGE_MAP(CFileOpenEx, CFileDialog)
	//{{AFX_MSG_MAP(CFileOpenEx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOpenEx message handlers

int CFileOpenEx::DoModal() 
{
	SetTemplate(NULL, MAKEINTRESOURCE(IDD_FILEOPEN_EX));	
	return CFileDialog::DoModal();
}


void CFileOpenEx::OnFileNameChange()
{
	//	Called when the filename changes in the Explorer
	//	portion of the Dialog. If unfolded, load the
	//	contents of the file into the RichEdit control

	CString FileName = GetPathName();
	if(FileName.GetLength())
	{
		OFSTRUCT of;
		if(OpenFile(FileName, &of, OF_EXIST) != HFILE_ERROR)
		{
			PreviewContents(FileName);
		}
	}
}

DWORD CALLBACK OpenCallback(DWORD dwCookie, LPBYTE pbBuff, 
							LONG cb, LONG * pcb)
{
	CFile *pFile = (CFile *)dwCookie;
	
	*pcb = pFile->Read(pbBuff, cb);
	return 0;
}

void CFileOpenEx::PreviewContents(LPCSTR lpszFilespec)
{
	CFile File(lpszFilespec, CFile::modeRead);	
	
	EDITSTREAM es;
	es.dwCookie	= (DWORD)&File;
	es.dwError = 0;
	es.pfnCallback = OpenCallback;
	
	m_RichEdit.StreamIn(SF_TEXT, es);
}


