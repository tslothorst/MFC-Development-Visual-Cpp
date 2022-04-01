// ScrolDoc.cpp : implementation of the CScrollDoc class
//

#include "stdafx.h"
#include "Scroll.h"

#include "ScrolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc

IMPLEMENT_DYNCREATE(CScrollDoc, CDocument)

BEGIN_MESSAGE_MAP(CScrollDoc, CDocument)
	//{{AFX_MSG_MAP(CScrollDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc construction/destruction

CScrollDoc::CScrollDoc()
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
	m_pt.x = 0;
	m_pt.y = 0;
}

CScrollDoc::~CScrollDoc()
{
}

BOOL CScrollDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc serialization

void CScrollDoc::Serialize(CArchive& ar)
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
// CScrollDoc diagnostics

#ifdef _DEBUG
void CScrollDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScrollDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CScrollDoc commands
