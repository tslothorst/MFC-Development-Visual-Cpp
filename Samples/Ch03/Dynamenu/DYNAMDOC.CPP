// DynaMDoc.cpp : implementation of the CMenusDynamicDoc class
//

#include "stdafx.h"
#include "DynaMenu.h"

#include "DynaMDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicDoc

IMPLEMENT_DYNCREATE(CMenusDynamicDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenusDynamicDoc, CDocument)
	//{{AFX_MSG_MAP(CMenusDynamicDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicDoc construction/destruction

CMenusDynamicDoc::CMenusDynamicDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CMenusDynamicDoc::~CMenusDynamicDoc()
{
}

BOOL CMenusDynamicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicDoc serialization

void CMenusDynamicDoc::Serialize(CArchive& ar)
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
// CMenusDynamicDoc diagnostics

#ifdef _DEBUG
void CMenusDynamicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenusDynamicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicDoc commands
