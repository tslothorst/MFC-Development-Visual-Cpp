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

IMPLEMENT_DYNCREATE(CDiffDoc, CDocument)

BEGIN_MESSAGE_MAP(CDiffDoc, CDocument)
	//{{AFX_MSG_MAP(CDiffDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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

BOOL CDiffDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
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
	CDocument::AssertValid();
}

void CDiffDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiffDoc commands
