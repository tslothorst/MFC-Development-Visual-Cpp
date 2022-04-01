// SDI2ViewsDoc.cpp : implementation of the CSDI2ViewsDoc class
//

#include "stdafx.h"
#include "SDI2Views.h"

#include "SDI2ViewsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDI2ViewsDoc

IMPLEMENT_DYNCREATE(CSDI2ViewsDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDI2ViewsDoc, CDocument)
	//{{AFX_MSG_MAP(CSDI2ViewsDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSDI2ViewsDoc construction/destruction

CSDI2ViewsDoc::CSDI2ViewsDoc()
{
}

CSDI2ViewsDoc::~CSDI2ViewsDoc()
{
}

BOOL CSDI2ViewsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_phrase.LoadString(IDS_WELCOME_MSG);
	
	m_color = RGB(0, 0, 0); // black

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSDI2ViewsDoc serialization

void CSDI2ViewsDoc::Serialize(CArchive& ar)
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
// CSDI2ViewsDoc diagnostics

#ifdef _DEBUG
void CSDI2ViewsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDI2ViewsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSDI2ViewsDoc commands

