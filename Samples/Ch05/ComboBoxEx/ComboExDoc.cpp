// ComboExDoc.cpp : implementation of the CComboExDoc class
//

#include "stdafx.h"
#include "ComboEx.h"

#include "ComboExDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ComboExDoc

IMPLEMENT_DYNCREATE(CComboExDoc, CDocument)

BEGIN_MESSAGE_MAP(CComboExDoc, CDocument)
	//{{AFX_MSG_MAP(CComboExDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ComboExDoc construction/destruction

CComboExDoc::CComboExDoc()
	:m_color(RGB(0,0,0))
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
}

CComboExDoc::~CComboExDoc()
{
}

BOOL CComboExDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// ComboExDoc serialization

void CComboExDoc::Serialize(CArchive& ar)
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
// ComboExDoc diagnostics

#ifdef _DEBUG
void CComboExDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CComboExDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ComboExDoc commands
