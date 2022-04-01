// TGrafDoc.cpp : implementation of the CTemperatureGraphDoc class
//

#include "stdafx.h"
#include "TmpGraph.h"

#include "TGrafDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphDoc

IMPLEMENT_DYNCREATE(CTemperatureGraphDoc, CDocument)

BEGIN_MESSAGE_MAP(CTemperatureGraphDoc, CDocument)
	//{{AFX_MSG_MAP(CTemperatureGraphDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphDoc construction/destruction

CTemperatureGraphDoc::CTemperatureGraphDoc()
{
}

CTemperatureGraphDoc::~CTemperatureGraphDoc()
{
}

BOOL CTemperatureGraphDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// These are defaults. m_month can be changed from a menu.
	// Changing city and year are left as exercises.
	m_month = "January";
	m_year = 1996;
	m_city = "Seattle";
	temps.SetSize(31);
	for (int i = 0; i < temps.GetSize(); i++)
	{
		temps[i].x = i;
		temps[i].y = DEFAULT_TEMPERATURE;
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphDoc serialization

void CTemperatureGraphDoc::Serialize(CArchive& ar)
{
	// The three simple data members of the document are serialized
	// using the overloaded insertion and extraction operators...
	if( ar.IsStoring() )
		ar << m_month << m_year << m_city;
	else
		ar >> m_month >> m_year >> m_city;

	// and the CArray takes care of itself.
	temps.Serialize(ar);
	return;
}

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphDoc diagnostics

#ifdef _DEBUG
void CTemperatureGraphDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTemperatureGraphDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTemperatureGraphDoc commands
