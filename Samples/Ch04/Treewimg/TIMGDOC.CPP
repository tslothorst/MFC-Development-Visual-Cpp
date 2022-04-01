// TimgDoc.cpp : implementation of the CTreeWithImagesDoc class
//

#include "stdafx.h"
#include "TreeWimg.h"

#include "TimgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesDoc

IMPLEMENT_DYNCREATE(CTreeWithImagesDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeWithImagesDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeWithImagesDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesDoc construction/destruction

CTreeWithImagesDoc::CTreeWithImagesDoc()
{
	// TODO: add one-time construction code here

}

CTreeWithImagesDoc::~CTreeWithImagesDoc()
{
}

BOOL CTreeWithImagesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesDoc serialization

void CTreeWithImagesDoc::Serialize(CArchive& ar)
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
// CTreeWithImagesDoc diagnostics

#ifdef _DEBUG
void CTreeWithImagesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeWithImagesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesDoc commands
