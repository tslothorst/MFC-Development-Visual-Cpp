// DynAcc01Doc.cpp : implementation of the CDynAcc01Doc class
//

#include "stdafx.h"
#include "DynAcc01.h"

#include "DynAcc01Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01Doc

IMPLEMENT_DYNCREATE(CDynAcc01Doc, CDocument)

BEGIN_MESSAGE_MAP(CDynAcc01Doc, CDocument)
	//{{AFX_MSG_MAP(CDynAcc01Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01Doc construction/destruction

CDynAcc01Doc::CDynAcc01Doc()
{
	// TODO: add one-time construction code here

}

CDynAcc01Doc::~CDynAcc01Doc()
{
}

BOOL CDynAcc01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynAcc01Doc serialization

void CDynAcc01Doc::Serialize(CArchive& ar)
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
// CDynAcc01Doc diagnostics

#ifdef _DEBUG
void CDynAcc01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynAcc01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynAcc01Doc commands
