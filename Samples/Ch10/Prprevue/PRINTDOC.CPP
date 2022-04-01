// PrintDoc.cpp : implementation of the CPrintDoc class
//

#include "stdafx.h"
#include "PrPrevue.h"

#include "PrintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc

IMPLEMENT_DYNCREATE(CPrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintDoc, CDocument)
	//{{AFX_MSG_MAP(CPrintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc construction/destruction

CPrintDoc::CPrintDoc()
	// In Win95 with a tmHeight of 16, this number cannot
	// exceed 2047, since scroll size is a 16-bit signed number.
	: m_linesOnDocument(200)
{
}

CPrintDoc::~CPrintDoc()
{
}

BOOL CPrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc serialization

void CPrintDoc::Serialize(CArchive& ar)
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
// CPrintDoc diagnostics

#ifdef _DEBUG
void CPrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintDoc commands
// This function simulates a text-like document by
// returning the requested line. It is 1-based.
CString & CPrintDoc::GetLine(int r) const
{
	static CString s;

	ASSERT (r > 0 && r <= LinesOnDocument());
	
	s.Format(IDS_WELCOME_MSG, r);
	return s;
}