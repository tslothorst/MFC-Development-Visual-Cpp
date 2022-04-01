// ODrawDoc.cpp : implementation of the COwnerDrawMenusDoc class
//

#include "stdafx.h"
#include "OwnDraw.h"

#include "ODrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusDoc

IMPLEMENT_DYNCREATE(COwnerDrawMenusDoc, CDocument)

BEGIN_MESSAGE_MAP(COwnerDrawMenusDoc, CDocument)
	//{{AFX_MSG_MAP(COwnerDrawMenusDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusDoc construction/destruction

COwnerDrawMenusDoc::COwnerDrawMenusDoc()
	: m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

COwnerDrawMenusDoc::~COwnerDrawMenusDoc()
{
}

BOOL COwnerDrawMenusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusDoc serialization

void COwnerDrawMenusDoc::Serialize(CArchive& ar)
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
// COwnerDrawMenusDoc diagnostics

#ifdef _DEBUG
void COwnerDrawMenusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COwnerDrawMenusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenusDoc commands
