// diffDoc.cpp : implementation of the CDiffDoc class
//

#include "stdafx.h"
#include "diff.h"

#include "diffDoc.h"
#include "diffview.h"

#include "splitter.h"
#include "mainfrm.h"
#include "dlgopenf.h"
#include <string.h>
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
	}
}


void CDiffDoc::RunComparison (LPCSTR lpszFile1, LPCSTR lpszFile2)
{
	CMainFrame * pFrame		= CDiffApp::GetApp()->GetMainFrame();
	
	if(pFrame)
	{
		CSplitter * pSplitter	= pFrame->GetSplitter();

	
		if(pSplitter)
		{
			CDiffView * pView;
			pView = (CDiffView *)pSplitter->GetPane(0,0);

			if (pView)
			{
				try
				{
				CFile	file(lpszFile1, CFile::modeRead);
				CArchive ar(&file, CArchive::load);
				pView->Serialize(ar);
				}
				catch(CFileException* e)
				{
					if(e->m_cause == CFileException::fileNotFound)
					{
						char errmsg[80];
						strcpy(errmsg,"File  ");
						strcat(errmsg, lpszFile1);
						strcat(errmsg," not found");
						::MessageBox(0,errmsg,"Error",MB_OK);
					
					}
					else if(e->m_cause == CFileException::tooManyOpenFiles)
						::MessageBox(0,"No more file handles available","Error",MB_OK);
					else if(e->m_cause == CFileException::hardIO)
						::MessageBox(0,"Hardware error","Error",MB_OK);
					else
						::MessageBox(0,"Unknown file error","Error",MB_OK);
					e->Delete();
				}

			}

			pView = (CDiffView *)pSplitter->GetPane(0,1);
			if (pView)
			{
				try
				{
				CFile	file(lpszFile2, CFile::modeRead);
				CArchive ar(&file, CArchive::load);
				pView->Serialize(ar);
				}
				catch(CFileException* e)
				{
					if(e->m_cause == CFileException::fileNotFound)
					{
						char errmsg[80];
						strcpy(errmsg,"File  ");
						strcat(errmsg, lpszFile2);
						strcat(errmsg," not found");
						::MessageBox(0,errmsg,"Error",MB_OK);
					}
					else if(e->m_cause == CFileException::tooManyOpenFiles)
						::MessageBox(0,"No more file handles available","Error",MB_OK);
					else if(e->m_cause == CFileException::hardIO)
						::MessageBox(0,"Hardware error","Error",MB_OK);
					else
						::MessageBox(0,"Unknown file error","Error",MB_OK);
					e->Delete();
				}

			}
			//      Flag as clean so that we won't get
			//      prompted to save
			SetModifiedFlag(FALSE);

		}
	}
}










