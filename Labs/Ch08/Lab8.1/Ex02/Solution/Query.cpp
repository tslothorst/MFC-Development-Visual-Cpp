// Query.cpp : implementation file
//

#include "stdafx.h"
#include "ADODialog.h"
#include "Query.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CQuery dialog


CQuery::CQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuery)
	m_Field = _T("");
	m_Value = _T("");
	//}}AFX_DATA_INIT
}


void CQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuery)
	DDX_CBString(pDX, ID_FIELD, m_Field);
	DDX_Text(pDX, ID_VALUE, m_Value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuery, CDialog)
	//{{AFX_MSG_MAP(CQuery)
		// NOTE: the ClassWizard will add message map macros here
	ON_BN_CLICKED(ID_GREATER,OnGreater)
	ON_BN_CLICKED(ID_LESSER,OnLesser)
	ON_BN_CLICKED(ID_EQUAL,OnEqual)
	ON_BN_CLICKED(ID_LIK,OnLike)
	ON_BN_CLICKED(IDOK,OnSetCondition)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuery message handlers

void CQuery::OnGreater() 
{
	strcpy(m_operator, " > "); 
}

void CQuery::OnLesser() 
{
	strcpy(m_operator, " < "); 
}

void CQuery::OnEqual() 
{
	strcpy(m_operator, " = "); 
}

void CQuery::OnLike() 
{
	strcpy(m_operator, " like "); 
}

void CQuery::OnSetCondition() 
{
	UpdateData(TRUE);
	
	if(m_Field != _T("") && m_Value != _T(""))
	{
		strcpy(cmd_str,m_Field);
		strcat(cmd_str,m_operator);
		strcat(cmd_str,"'");
		strcat(cmd_str,m_Value);
		if(strcmp(m_operator," like ")==0)
			strcat(cmd_str, "*'");
		else
			strcat(cmd_str, "'");
	}
	
	CDialog::OnOK();
}
