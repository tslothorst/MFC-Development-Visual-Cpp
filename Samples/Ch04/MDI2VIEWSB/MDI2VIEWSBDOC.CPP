// MDI2ViewsBDoc.cpp : implementation of the CMDI2ViewsBDoc class
//

#include "stdafx.h"
#include "MDI2ViewsB.h"

#include "MDI2ViewsBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsBDoc

IMPLEMENT_DYNCREATE(CMDI2ViewsBDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDI2ViewsBDoc, CDocument)
	//{{AFX_MSG_MAP(CMDI2ViewsBDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsBDoc construction/destruction

CMDI2ViewsBDoc::CMDI2ViewsBDoc()
{
	// TODO: add one-time construction code here

}

CMDI2ViewsBDoc::~CMDI2ViewsBDoc()
{
}

BOOL CMDI2ViewsBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_phrase.LoadString(IDS_WELCOME_MSG);
	m_color = 0;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsBDoc serialization

void CMDI2ViewsBDoc::Serialize(CArchive& ar)
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
// CMDI2ViewsBDoc diagnostics

#ifdef _DEBUG
void CMDI2ViewsBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDI2ViewsBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsBDoc commands
