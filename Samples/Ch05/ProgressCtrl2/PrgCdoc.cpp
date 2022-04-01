// PrgCDoc.cpp : implementation of the CPrgCDoc class
//

#include "stdafx.h"
#include "PrgCtrl.h"

#include "PrgCdoc.h"
#include "PrgCview.h"

#include "splitter.h"
#include "mainfrm.h"
#include "dlgopenf.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlDoc

IMPLEMENT_DYNCREATE(CPrgCtrlDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CPrgCtrlDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CPrgCtrlDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlDoc construction/destruction

CPrgCtrlDoc::CPrgCtrlDoc()
{
	m_File1 = "";
	m_File2 = "";
	m_bRTF	= FALSE;
}

CPrgCtrlDoc::~CPrgCtrlDoc()
{
}

CRichEditCntrItem* CPrgCtrlDoc::CreateClientItem(REOBJECT* preo) const
{
        // cast away constness of this
        return new CRichEditCntrItem();
}

BOOL CPrgCtrlDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlDoc serialization

void CPrgCtrlDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlDoc diagnostics

#ifdef _DEBUG
void CPrgCtrlDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CPrgCtrlDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrgCtrlDoc commands

void CPrgCtrlDoc::OnFileOpen() 
{

	CDlgOpenFiles dlg;

	if(dlg.DoModal() == IDOK)
	{
		dlg.GetFile1(m_File1);
		dlg.GetFile2(m_File2);
		m_pProgDlg = new CProgressDlg;
		m_pProgDlg->Create(IDD_PROGRESS);
		m_pProgDlg->ShowWindow(SW_SHOW);
		
		RunComparison (m_File1, m_File2);
		m_pProgDlg->DestroyWindow();
	}
}


void CPrgCtrlDoc::RunComparison (LPCSTR lpszFile1, LPCSTR lpszFile2)
{
	CMainFrame * pFrame		= CPrgCtrlApp::GetApp()->GetMainFrame();
	
	if(pFrame)
	{
		CSplitter * pSplitter	= pFrame->GetSplitter();
		m_pProgCtrl=(CProgressCtrl*)m_pProgDlg->GetDlgItem(IDC_PROGRESS);
		int upper, lower;
		m_pProgCtrl->GetRange(lower, upper); 
		for(; m_pProgCtrl->StepIt() < upper - 1;);
		

		if(pSplitter)
		{
			CPrgCtrlView * pView;
			pView = (CPrgCtrlView *)pSplitter->GetPane(0,0);

			if (pView)
			{
				CFile	file(lpszFile1, CFile::modeRead);
				CArchive ar(&file, CArchive::load);
				pView->Serialize(ar);
			}

			pView = (CPrgCtrlView *)pSplitter->GetPane(0,1);
			if (pView)
			{
				CFile	file(lpszFile2, CFile::modeRead);
				CArchive ar(&file, CArchive::load);
				pView->Serialize(ar);
			}
			//      Flag as clean so that we won't get
			//      prompted to save
			SetModifiedFlag(FALSE);

		}
	}
}










