// FormDoc.cpp : implementation of the CFormDoc class
//

#include "stdafx.h"
#include "Form.h"

#include "FormDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormDoc

IMPLEMENT_DYNCREATE(CFormDoc, CDocument)

BEGIN_MESSAGE_MAP(CFormDoc, CDocument)
	//{{AFX_MSG_MAP(CFormDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormDoc construction/destruction

CFormDoc::CFormDoc()
{
	m_phrase.LoadString(IDS_WELCOME_MSG);
	SetColor(RGB(0,0,0));
}

CFormDoc::~CFormDoc()
{
}

BOOL CFormDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CFormDoc serialization

void CFormDoc::Serialize(CArchive& ar)
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
// CFormDoc diagnostics

#ifdef _DEBUG
void CFormDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFormDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormDoc commands
