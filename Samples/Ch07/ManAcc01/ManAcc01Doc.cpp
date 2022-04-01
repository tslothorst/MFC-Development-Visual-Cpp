// ManAcc01Doc.cpp : implementation of the CManAcc01Doc class
//

#include "stdafx.h"
#include "ManAcc01.h"


#include "ManAcc01Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManAcc01Doc

IMPLEMENT_DYNCREATE(CManAcc01Doc, CDocument)

BEGIN_MESSAGE_MAP(CManAcc01Doc, CDocument)
	//{{AFX_MSG_MAP(CManAcc01Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManAcc01Doc construction/destruction

CManAcc01Doc::CManAcc01Doc()
{
	// TODO: add one-time construction code here

}

CManAcc01Doc::~CManAcc01Doc()
{
}

BOOL CManAcc01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CManAcc01Doc serialization

void CManAcc01Doc::Serialize(CArchive& ar)
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
// CManAcc01Doc diagnostics

#ifdef _DEBUG
void CManAcc01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CManAcc01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CManAcc01Doc commands
