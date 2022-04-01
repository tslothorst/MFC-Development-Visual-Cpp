// TextDoc.cpp : implementation of the CTextDoc class
//

#include "stdafx.h"
#include "Text.h"

#include "TextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextDoc

IMPLEMENT_DYNCREATE(CTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextDoc, CDocument)
	//{{AFX_MSG_MAP(CTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTextDoc construction/destruction

CTextDoc::CTextDoc()
{
	// TODO: add one-time construction code here

}

CTextDoc::~CTextDoc()
{
}

BOOL CTextDoc::OnNewDocument()
{
	//	Return FALSE to prevent an empty new document from
	//	being opened at start up. Since this is a simple
	//	text viewer all of our document will be created
	//	by opening a file and processing OnOpenDocuement()
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CTextDoc serialization

void CTextDoc::Serialize(CArchive& ar)
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
// CTextDoc diagnostics

#ifdef _DEBUG
void CTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTextDoc commands

BOOL CTextDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	//	Could be a big file
   	BeginWaitCursor();

	//	Clear List, this will cleanup the CString objects
	m_LineList.RemoveAll();

	//	Read the file and store as a list
	//	of CStrings
	CStdioFile	file(lpszPathName, 
					CFile::modeRead | CFile::typeText);

	CString	strLine;
	while (file.ReadString(strLine) != NULL)
	{
    	//remove the noise characters at the end of the line            
        int nLastCharIndex = strLine.GetLength()-1;
		while (nLastCharIndex >= 0 && strLine[nLastCharIndex] < ' ')
		{
        	strLine.SetAt(nLastCharIndex--, '\0');
		}

		//	Add to CStringList
		m_LineList.AddTail(strLine);
	}

	EndWaitCursor();
	return TRUE;
}
