// IC_2Doc.cpp : implementation of the CIC_2Doc class
//

#include "stdafx.h"
#include "IC_2.h"

#include "IC_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIC_2Doc

IMPLEMENT_DYNCREATE(CIC_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CIC_2Doc, CDocument)
	//{{AFX_MSG_MAP(CIC_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIC_2Doc construction/destruction

CIC_2Doc::CIC_2Doc()
{
	// TODO: add one-time construction code here

}

CIC_2Doc::~CIC_2Doc()
{
}

BOOL CIC_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Initialize the doc object's members

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CIC_2Doc serialization

void CIC_2Doc::Serialize(CArchive& ar)
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
// CIC_2Doc diagnostics

#ifdef _DEBUG
void CIC_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CIC_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIC_2Doc commands
