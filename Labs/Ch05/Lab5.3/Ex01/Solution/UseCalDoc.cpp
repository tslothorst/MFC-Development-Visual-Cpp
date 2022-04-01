// UseCalDoc.cpp : implementation of the CUseCalDoc class
//

#include "stdafx.h"
#include "UseCal.h"

#include "UseCalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseCalDoc

IMPLEMENT_DYNCREATE(CUseCalDoc, CDocument)

BEGIN_MESSAGE_MAP(CUseCalDoc, CDocument)
	//{{AFX_MSG_MAP(CUseCalDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseCalDoc construction/destruction

CUseCalDoc::CUseCalDoc()
{
	// TODO: add one-time construction code here

}

CUseCalDoc::~CUseCalDoc()
{
}

BOOL CUseCalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUseCalDoc serialization

void CUseCalDoc::Serialize(CArchive& ar)
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
// CUseCalDoc diagnostics

#ifdef _DEBUG
void CUseCalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUseCalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseCalDoc commands
