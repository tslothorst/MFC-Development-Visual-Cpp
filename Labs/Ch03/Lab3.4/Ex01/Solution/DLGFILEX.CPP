// DlgFilex.cpp : implementation file
//

#include "stdafx.h"
#include "diff.h"
#include "DlgFilex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileIOpenEx dialog


CFileOpenEx::CFileOpenEx(	LPCTSTR lpszDefExt /*= NULL*/,
							LPCTSTR lpszFileName /*= NULL*/,
							DWORD dwFlags /*= OFN_HIDEREADONLY*/,
							LPCTSTR lpszFilter /*= NULL*/,
							CWnd* pParentWnd /*= NULL*/)
			: CFileDialog(TRUE, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{

	//
	//	Always start out folded
	//
	m_bUnfolded = TRUE;
	m_bFirstTime = TRUE;
	//{{AFX_DATA_INIT(CFileOpenEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFileOpenEx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileIOpenEx)
		DDX_Control(pDX, IDC_EDIT_CONTENTS, m_RichEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileOpenEx, CDialog)
	//{{AFX_MSG_MAP(CFileOpenEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_OPTIONS, OnButtonOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileIOpenEx message handlers

int CFileOpenEx::DoModal() 
{
	//	
	//	Use our template
	//	
	//SetTemplate(NULL, MAKEINTRESOURCE(IDD));	
	SetTemplate(NULL, MAKEINTRESOURCE(IDD_FILEOPEN_EX));	

	return CFileDialog::DoModal();
}

void CFileOpenEx::OnSize(UINT nType, int cx, int cy) 
{
	CFileDialog::OnSize(nType, cx, cy);
	
	if(m_bFirstTime)
	{
		m_bFirstTime = FALSE;
		Expand(FALSE);
	}	
	
}

void CFileOpenEx::OnButtonOptions() 
{
		//
		//	Toggle the expanded state
		//
	Expand(!m_bUnfolded);	
}

void CFileOpenEx::OnFileNameChange()
{
	//
	//	Called when the filename changes in the Explorer
	//	portion of the Dialog. If were unfolded, load the
	//	contents of the file into the RcihEdit control
	//

	if(m_bUnfolded)
	{
		CString FileName = GetPathName();
		if(FileName.GetLength())
		{
			OFSTRUCT	of;
			if(OpenFile(FileName, &of, OF_EXIST) != HFILE_ERROR)
			{
				PreviewContents(FileName);
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// Support functions

void CFileOpenEx::Expand(const BOOL bExpand)
{
	if( (bExpand && !m_bUnfolded) ||
		(!bExpand && m_bUnfolded) )
	{
		CRect	rectInitDlg, rectNewDlg, rectBasic;
		GetParent()->GetWindowRect(&rectInitDlg);

		WORD wSizeCtrl = IDC_FOLDSIZE;
		if(bExpand)
		{
			wSizeCtrl = IDC_UNFOLDSIZE;
		}
		
		CWnd* pSizeMarker = GetDlgItem(wSizeCtrl);
	
		CRect rectMarker;
		pSizeMarker->GetWindowRect(&rectMarker);
		ScreenToClient(&rectMarker);
		
		rectNewDlg.SetRect(0, 0, rectMarker.right, rectMarker.bottom);
		
		::AdjustWindowRectEx(	&rectNewDlg, 
								GetParent()->GetStyle(),
								FALSE,
								GetParent()->GetExStyle());
		
		GetParent()->SetWindowPos(	NULL, 
									0, 0,
									rectNewDlg.Width(), rectNewDlg.Height(),
									SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOZORDER);
		
		rectBasic = bExpand?rectInitDlg:rectNewDlg;
		ClientToScreen(&rectBasic);
		
		EnableOptionalChildren(rectBasic, bExpand);
		
		m_bUnfolded = bExpand;
		
	}
}


void CFileOpenEx::EnableOptionalChildren (const CRect& rectBasic,
										  const BOOL   bEnable)
{
	CRect rectChild;
	
	CWnd *pChild = GetTopWindow();
	
	while (pChild)
	{
		pChild->GetWindowRect(&rectChild);
		
		if(		!rectBasic.PtInRect(rectChild.TopLeft()) 
			||	!rectBasic.PtInRect(rectChild.BottomRight()) )
		{
			pChild->EnableWindow(bEnable);
		}
		pChild = pChild->GetNextWindow();
	}
}

DWORD CALLBACK OpenCallback(DWORD	dwCookie,
							LPBYTE	pbBuff,
							LONG	cb,
							LONG	*pcb )
{
	CFile *pFile = (CFile *)dwCookie;
	
	*pcb = pFile->Read(pbBuff, cb);
	return 0;
}

void CFileOpenEx::PreviewContents(LPCSTR lpszFilespec)
{
	CFile		File(lpszFilespec, CFile::modeRead);	
	
	EDITSTREAM		es;
	es.dwCookie	= (DWORD)&File;
	es.dwError		= 0;
	es.pfnCallback	= OpenCallback;
	
	m_RichEdit.StreamIn(SF_TEXT, es);
}


