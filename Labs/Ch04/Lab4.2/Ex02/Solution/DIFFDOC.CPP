// diffDoc.cpp : implementation of the CDiffDoc class
//

#include "stdafx.h"
#include "diff.h"

#include "diffDoc.h"

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
	// TODO: add one-time construction code here

}

CDiffDoc::~CDiffDoc()
{
}

CRichEditCntrItem* CDiffDoc::CreateClientItem(REOBJECT* preo) const
{
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
	static char BASED_CODE szFilter[] =
			"All Files (*.*)|*.*|C++ Files (*.cpp, *.h)" \
			"|*.cpp;*.h||";

	CFileDialog dlg(TRUE,NULL,NULL,NULL,szFilter);

	if(dlg.DoModal() == IDOK)
	{
		m_File1 = m_File2 = dlg.GetPathName();
	}
}
