// OLEDBDynAccAppDoc.cpp : implementation of the COLEDBDynAccAppDoc class
//

#include "stdafx.h"
#include "OLEDBDynAccApp.h"

#include "OLEDBDynAccAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppDoc

IMPLEMENT_DYNCREATE(COLEDBDynAccAppDoc, CDocument)

BEGIN_MESSAGE_MAP(COLEDBDynAccAppDoc, CDocument)
	//{{AFX_MSG_MAP(COLEDBDynAccAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppDoc construction/destruction

COLEDBDynAccAppDoc::COLEDBDynAccAppDoc()
{
	// TODO: add one-time construction code here

}

COLEDBDynAccAppDoc::~COLEDBDynAccAppDoc()
{
}

BOOL COLEDBDynAccAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppDoc serialization

void COLEDBDynAccAppDoc::Serialize(CArchive& ar)
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
// COLEDBDynAccAppDoc diagnostics

#ifdef _DEBUG
void COLEDBDynAccAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COLEDBDynAccAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppDoc commands
