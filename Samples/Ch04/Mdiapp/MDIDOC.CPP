// MDIDoc.cpp : implementation of the CMDIAppDoc class
//

#include "stdafx.h"
#include "MDIApp.h"

#include "MDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIAppDoc

IMPLEMENT_DYNCREATE(CMDIAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDIAppDoc, CDocument)
	//{{AFX_MSG_MAP(CMDIAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIAppDoc construction/destruction

CMDIAppDoc::CMDIAppDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CMDIAppDoc::~CMDIAppDoc()
{
}

BOOL CMDIAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMDIAppDoc serialization

void CMDIAppDoc::Serialize(CArchive& ar)
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
// CMDIAppDoc diagnostics

#ifdef _DEBUG
void CMDIAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDIAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIAppDoc commands
