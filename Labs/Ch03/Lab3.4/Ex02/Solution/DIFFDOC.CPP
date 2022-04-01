// diffDoc.cpp : implementation of the CDiffDoc class
//

#include "stdafx.h"
#include "diff.h"

#include "diffDoc.h"
#include "diffview.h"

#include "progress.h"
#include "splitter.h"
#include "mainfrm.h"
#include "dlgopenf.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiffDoc

IMPLEMENT_DYNCREATE(CDiffDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CDiffDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CDiffDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiffDoc construction/destruction

CDiffDoc::CDiffDoc()
{
	m_File1 = "";
	m_File2 = "";
	m_bRTF	= FALSE;
}

CDiffDoc::~CDiffDoc()
{
}

CRichEditCntrItem* CDiffDoc::CreateClientItem(REOBJECT* preo) const
{
        // cast away constness of this
        return new CRichEditCntrItem();
}

BOOL CDiffDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDiffDoc serialization

void CDiffDoc::Serialize(CArchive& ar)
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
// CDiffDoc diagnostics

#ifdef _DEBUG
void CDiffDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CDiffDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiffDoc commands

void CDiffDoc::OnFileOpen() 
{

	CDlgOpenFiles dlg;

	if(dlg.DoModal() == IDOK)
	{
		dlg.GetFile1(m_File1);
		dlg.GetFile2(m_File2);
		RunComparison (m_File1, m_File2);
	
			//Added for the dialog bar lab
		CMainFrame * pFrm = ( CMainFrame * ) AfxGetMainWnd( );
		pFrm->SetList(CMainFrame::LEFT, m_File1);	
		pFrm->SetList(CMainFrame::RIGHT, m_File2);			
	}
}

void CDiffDoc::RunComparison (LPCSTR lpszFile1, LPCSTR lpszFile2)
{
		//	For effect, use the progress feedback available
		//	from our status bar class
		//
	CProgressStatusBar *pStatus = CDiffApp::GetApp()->
		GetMainFrame()->GetStatusBar();
	if(pStatus)
	{
		CString	Label;
		Label.LoadString(IDS_COMPARING);
		pStatus->SetProgressLabel(Label);

			//	
			//	Flip the StatusBar into Progress Mode
			//
		pStatus->ShowProgressDisplay(TRUE);

			//	
			//	Simulate some bogus progress
			//
		CProgressCtrl *pProgress = pStatus->GetProgressCtrl();
		if(pProgress)
		{
			pProgress->SetRange(0, 10);
			pProgress->SetStep(1);
			while(pProgress->StepIt() != 10)
			{
				for(LONG l = 0; l < 2000000; l++);
			}
		}
		pStatus->ShowProgressDisplay(FALSE);
	}
	
	CMainFrame * pFrame	= CDiffApp::GetApp()->GetMainFrame();
	
	if(pFrame)
	{
		CSplitter * pSplitter	= pFrame->GetSplitter();

	
		if(pSplitter)
		{
			CDiffView * pView;
			pView = (CDiffView *)pSplitter->GetPane(0,0);

			if (pView)
			{
				CFile	file(lpszFile1, CFile::modeRead);
				CArchive ar(&file, CArchive::load);
				pView->Serialize(ar);
			}

			pView = (CDiffView *)pSplitter->GetPane(0,1);
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










