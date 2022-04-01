// DlgBarsDoc.cpp : implementation of the CDlgBarsDoc class
//

#include "stdafx.h"
#include "DlgBars.h"

#include "DlgBarsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsDoc

IMPLEMENT_DYNCREATE(CDlgBarsDoc, CDocument)

BEGIN_MESSAGE_MAP(CDlgBarsDoc, CDocument)
	//{{AFX_MSG_MAP(CDlgBarsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsDoc construction/destruction

CDlgBarsDoc::CDlgBarsDoc()
{
	// TODO: add one-time construction code here

}

CDlgBarsDoc::~CDlgBarsDoc()
{
}

BOOL CDlgBarsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_color = RGB(0,0,0);
	m_phrase.LoadString(IDS_WELCOME_MSG);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsDoc serialization

void CDlgBarsDoc::Serialize(CArchive& ar)
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
// CDlgBarsDoc diagnostics

#ifdef _DEBUG
void CDlgBarsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDlgBarsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgBarsDoc commands
