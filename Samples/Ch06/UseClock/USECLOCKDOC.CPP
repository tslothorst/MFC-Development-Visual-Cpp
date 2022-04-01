// UseClockDoc.cpp : implementation of the CUseClockDoc class
//

#include "stdafx.h"
#include "UseClock.h"

#include "UseClockDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseClockDoc

IMPLEMENT_DYNCREATE(CUseClockDoc, CDocument)

BEGIN_MESSAGE_MAP(CUseClockDoc, CDocument)
	//{{AFX_MSG_MAP(CUseClockDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseClockDoc construction/destruction

CUseClockDoc::CUseClockDoc()
{
	// TODO: add one-time construction code here

}

CUseClockDoc::~CUseClockDoc()
{
}

BOOL CUseClockDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUseClockDoc serialization

void CUseClockDoc::Serialize(CArchive& ar)
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
// CUseClockDoc diagnostics

#ifdef _DEBUG
void CUseClockDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUseClockDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseClockDoc commands
