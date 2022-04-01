// CustSDoc.cpp : implementation of the CCustomStatusBarDoc class
//

#include "stdafx.h"
#include "CustSBar.h"

#include "CustSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarDoc

IMPLEMENT_DYNCREATE(CCustomStatusBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CCustomStatusBarDoc, CDocument)
	//{{AFX_MSG_MAP(CCustomStatusBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarDoc construction/destruction

CCustomStatusBarDoc::CCustomStatusBarDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CCustomStatusBarDoc::~CCustomStatusBarDoc()
{
}

BOOL CCustomStatusBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarDoc serialization

void CCustomStatusBarDoc::Serialize(CArchive& ar)
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
// CCustomStatusBarDoc diagnostics

#ifdef _DEBUG
void CCustomStatusBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCustomStatusBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCustomStatusBarDoc commands
