// MDI2ViewsDoc.cpp : implementation of the CMDI2ViewsDoc class
//

#include "stdafx.h"
#include "MDI2Views.h"

#include "MDI2ViewsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsDoc

IMPLEMENT_DYNCREATE(CMDI2ViewsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDI2ViewsDoc, CDocument)
	//{{AFX_MSG_MAP(CMDI2ViewsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsDoc construction/destruction

CMDI2ViewsDoc::CMDI2ViewsDoc()
{
}

CMDI2ViewsDoc::~CMDI2ViewsDoc()
{
}

BOOL CMDI2ViewsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_phrase.LoadString(IDS_WELCOME_MSG);
	m_color = 0;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsDoc serialization

void CMDI2ViewsDoc::Serialize(CArchive& ar)
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
// CMDI2ViewsDoc diagnostics

#ifdef _DEBUG
void CMDI2ViewsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDI2ViewsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDI2ViewsDoc commands
