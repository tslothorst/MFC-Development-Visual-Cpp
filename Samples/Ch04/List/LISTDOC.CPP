// ListDoc.cpp : implementation of the CListDoc class
//

#include "stdafx.h"
#include "List.h"

#include "ListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListDoc

IMPLEMENT_DYNCREATE(CListDoc, CDocument)

BEGIN_MESSAGE_MAP(CListDoc, CDocument)
	//{{AFX_MSG_MAP(CListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListDoc construction/destruction

CListDoc::CListDoc()
{
}

CListDoc::~CListDoc()
{
}

BOOL CListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CListDoc serialization

void CListDoc::Serialize(CArchive& ar)
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
// CListDoc diagnostics

#ifdef _DEBUG
void CListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListDoc commands
