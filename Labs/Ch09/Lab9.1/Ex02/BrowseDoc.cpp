// BrowseDoc.cpp : implementation of the CBrowseDoc class
//

#include "stdafx.h"
#include "Browse.h"

#include "BrowseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrowseDoc

IMPLEMENT_DYNCREATE(CBrowseDoc, CDocument)

BEGIN_MESSAGE_MAP(CBrowseDoc, CDocument)
	//{{AFX_MSG_MAP(CBrowseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowseDoc construction/destruction

CBrowseDoc::CBrowseDoc()
{
	// TODO: add one-time construction code here

}

CBrowseDoc::~CBrowseDoc()
{
}

BOOL CBrowseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBrowseDoc serialization

void CBrowseDoc::Serialize(CArchive& ar)
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
// CBrowseDoc diagnostics

#ifdef _DEBUG
void CBrowseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBrowseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBrowseDoc commands
