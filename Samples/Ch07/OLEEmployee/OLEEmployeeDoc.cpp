// OLEEmployeeDoc.cpp : implementation of the COLEEmployeeDoc class
//

#include "stdafx.h"
#include "OLEEmployee.h"

#include "OLEEmployeeSet.h"
#include "OLEEmployeeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeDoc

IMPLEMENT_DYNCREATE(COLEEmployeeDoc, CDocument)

BEGIN_MESSAGE_MAP(COLEEmployeeDoc, CDocument)
	//{{AFX_MSG_MAP(COLEEmployeeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeDoc construction/destruction

COLEEmployeeDoc::COLEEmployeeDoc()
{
	// TODO: add one-time construction code here

}

COLEEmployeeDoc::~COLEEmployeeDoc()
{
}

BOOL COLEEmployeeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeDoc serialization

void COLEEmployeeDoc::Serialize(CArchive& ar)
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
// COLEEmployeeDoc diagnostics

#ifdef _DEBUG
void COLEEmployeeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COLEEmployeeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeDoc commands
