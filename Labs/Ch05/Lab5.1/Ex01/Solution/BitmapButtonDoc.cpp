// BitmapButtonDoc.cpp : implementation of the CBitmapButtonDoc class
//

#include "stdafx.h"
#include "BitmapButton.h"

#include "BitmapButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDoc

IMPLEMENT_DYNCREATE(CBitmapButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CBitmapButtonDoc, CDocument)
	//{{AFX_MSG_MAP(CBitmapButtonDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDoc construction/destruction

CBitmapButtonDoc::CBitmapButtonDoc()
{
	// TODO: add one-time construction code here

}

CBitmapButtonDoc::~CBitmapButtonDoc()
{
}

BOOL CBitmapButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDoc serialization

void CBitmapButtonDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDoc diagnostics

#ifdef _DEBUG
void CBitmapButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBitmapButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBitmapButtonDoc commands
