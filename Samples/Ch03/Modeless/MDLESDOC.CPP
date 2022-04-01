// MdlesDoc.cpp : implementation of the CModelessDoc class
//

#include "stdafx.h"
#include "Modeless.h"

#include "MdlesDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelessDoc

IMPLEMENT_DYNCREATE(CModelessDoc, CDocument)

BEGIN_MESSAGE_MAP(CModelessDoc, CDocument)
	//{{AFX_MSG_MAP(CModelessDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelessDoc construction/destruction

CModelessDoc::CModelessDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CModelessDoc::~CModelessDoc()
{
}

BOOL CModelessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CModelessDoc serialization

void CModelessDoc::Serialize(CArchive& ar)
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
// CModelessDoc diagnostics

#ifdef _DEBUG
void CModelessDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CModelessDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CModelessDoc commands
