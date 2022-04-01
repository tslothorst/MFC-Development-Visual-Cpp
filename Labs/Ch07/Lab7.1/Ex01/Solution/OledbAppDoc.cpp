// OledbAppDoc.cpp : implementation of the COledbAppDoc class
//

#include "stdafx.h"
#include "OledbApp.h"

#include "OledbAppSet.h"
#include "OledbAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COledbAppDoc

IMPLEMENT_DYNCREATE(COledbAppDoc, CDocument)

BEGIN_MESSAGE_MAP(COledbAppDoc, CDocument)
	//{{AFX_MSG_MAP(COledbAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COledbAppDoc construction/destruction

COledbAppDoc::COledbAppDoc()
{
	// TODO: add one-time construction code here

}

COledbAppDoc::~COledbAppDoc()
{
}

BOOL COledbAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COledbAppDoc serialization

void COledbAppDoc::Serialize(CArchive& ar)
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
// COledbAppDoc diagnostics

#ifdef _DEBUG
void COledbAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COledbAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COledbAppDoc commands
