// TBarDoc.cpp : implementation of the CAdditionalToolbarsDoc class
//

#include "stdafx.h"
#include "Toolbar.h"

#include "TBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsDoc

IMPLEMENT_DYNCREATE(CAdditionalToolbarsDoc, CDocument)

BEGIN_MESSAGE_MAP(CAdditionalToolbarsDoc, CDocument)
	//{{AFX_MSG_MAP(CAdditionalToolbarsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsDoc construction/destruction
CAdditionalToolbarsDoc::CAdditionalToolbarsDoc()
	: m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CAdditionalToolbarsDoc::~CAdditionalToolbarsDoc()
{
}

BOOL CAdditionalToolbarsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsDoc serialization

void CAdditionalToolbarsDoc::Serialize(CArchive& ar)
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
// CAdditionalToolbarsDoc diagnostics

#ifdef _DEBUG
void CAdditionalToolbarsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAdditionalToolbarsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdditionalToolbarsDoc commands
