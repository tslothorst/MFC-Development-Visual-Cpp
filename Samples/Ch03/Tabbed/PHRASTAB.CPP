// Tabbed.cpp : implementation file
//

#include "stdafx.h"
#include "Tabbed.h"
#include "PhrasTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhraseTab property page

IMPLEMENT_DYNCREATE(CPhraseTab, CPropertyPage)

CPhraseTab::CPhraseTab() : CPropertyPage(CPhraseTab::IDD)
{
	//{{AFX_DATA_INIT(CPhraseTab)
	m_phrase = _T("");
	//}}AFX_DATA_INIT
}

CPhraseTab::~CPhraseTab()
{
}

void CPhraseTab::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPhraseTab)
	DDX_Text(pDX, IDC_PHRASE, m_phrase);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPhraseTab, CPropertyPage)
	//{{AFX_MSG_MAP(CPhraseTab)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPhraseTab message handlers
