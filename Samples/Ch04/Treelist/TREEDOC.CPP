// treeDoc.cpp : implementation of the CTreeDoc class
//

#include "stdafx.h"
#include "AnmlData.h"

#include "tree.h"

#include "treeview.h"
#include "treeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc

IMPLEMENT_DYNCREATE(CTreeDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc construction/destruction

// The document must initialize its 2 view pointers to 0.
CTreeDoc::CTreeDoc()
	: m_pTreeView(0), m_pListView(0)
{
}

CTreeDoc::~CTreeDoc()
{
}

POSITION CTreeDoc::InsertData (CAnimalInfo &animal)
{
	// No attempt is made here to keep the list ordered.
	// The tree view will take care of that.
	POSITION pos = m_AnimalList.AddTail(animal);

	SetModifiedFlag();

	return pos;
}

BOOL CTreeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	// Even an empty document (in this app) has
	// something to display in the tree view.
	m_pTreeView->PopulateTree();

	return TRUE;
}

void CTreeDoc::DeleteContents() 
{
	// Clear out everything from the document object's CList.
	m_AnimalList.RemoveAll();
	
	CDocument::DeleteContents();
}

BOOL CTreeDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// Now that the document is open and its CList object
	// has been deserialized, display the data in the tree view.
	m_pTreeView->PopulateTree();
	
	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CTreeDoc serialization

// This helper function, which is not a member of any class,
// is needed by the CList object in the document class. Without it,
// CAnimalInfo's Serialize function won't be called. When called
// for a CList, nCount is always 1. 

// The default SerializeElements called by CList does a bit-wise
// read/write, which won't work for CAnimalInfo's CString members.
void AFXAPI SerializeElements(CArchive& ar, CAnimalInfo * pMyData, int nCount)
{
	pMyData->Serialize(ar);
}

void CTreeDoc::Serialize(CArchive& ar)
{
	m_AnimalList.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc diagnostics

#ifdef _DEBUG
void CTreeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc commands

