// DynAcc02Doc.cpp : implementation of the CDynAcc02Doc class
//

#include "stdafx.h"
#include "DynAcc02.h"


#include "DynAcc02Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02Doc

IMPLEMENT_DYNCREATE(CDynAcc02Doc, CDocument)

BEGIN_MESSAGE_MAP(CDynAcc02Doc, CDocument)
	//{{AFX_MSG_MAP(CDynAcc02Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02Doc construction/destruction

CDynAcc02Doc::CDynAcc02Doc()
{
	// TODO: add one-time construction code here

}

CDynAcc02Doc::~CDynAcc02Doc()
{
}

BOOL CDynAcc02Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynAcc02Doc serialization

void CDynAcc02Doc::Serialize(CArchive& ar)
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
// CDynAcc02Doc diagnostics

#ifdef _DEBUG
void CDynAcc02Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynAcc02Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynAcc02Doc commands
