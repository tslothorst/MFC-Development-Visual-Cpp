// BmpButDoc.cpp : implementation of the CBmpButDoc class
//

#include "stdafx.h"
#include "BmpBut.h"

#include "BmpButDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BmpButDoc

IMPLEMENT_DYNCREATE(CBmpButDoc, CDocument)

BEGIN_MESSAGE_MAP(CBmpButDoc, CDocument)
	//{{AFX_MSG_MAP(CBmpButDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BmpButDoc construction/destruction

CBmpButDoc::CBmpButDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CBmpButDoc::~CBmpButDoc()
{
}

BOOL CBmpButDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// BmpButDoc serialization

void CBmpButDoc::Serialize(CArchive& ar)
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
// BmpButDoc diagnostics

#ifdef _DEBUG
void CBmpButDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBmpButDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// BmpButDoc commands
