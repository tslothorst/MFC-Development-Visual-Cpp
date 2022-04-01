// TabbeDoc.cpp : implementation of the CTabbedColorPhraseDoc class
//

#include "stdafx.h"
#include "Tabbed.h"

#include "TabbeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseDoc

IMPLEMENT_DYNCREATE(CTabbedColorPhraseDoc, CDocument)

BEGIN_MESSAGE_MAP(CTabbedColorPhraseDoc, CDocument)
	//{{AFX_MSG_MAP(CTabbedColorPhraseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseDoc construction/destruction

CTabbedColorPhraseDoc::CTabbedColorPhraseDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);

}

CTabbedColorPhraseDoc::~CTabbedColorPhraseDoc()
{
}

BOOL CTabbedColorPhraseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseDoc serialization

void CTabbedColorPhraseDoc::Serialize(CArchive& ar)
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
// CTabbedColorPhraseDoc diagnostics

#ifdef _DEBUG
void CTabbedColorPhraseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTabbedColorPhraseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTabbedColorPhraseDoc commands
