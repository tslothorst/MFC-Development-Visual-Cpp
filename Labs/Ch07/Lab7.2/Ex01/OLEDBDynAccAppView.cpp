// ManAcc01View.cpp : implementation of the COLEDBDynAccAppView class
//

#include "stdafx.h"
#include "OLEDBDynAccApp.h"

#include "OLEDBDynAccAppDoc.h"
#include "OLEDBDynAccAppView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView

IMPLEMENT_DYNCREATE(COLEDBDynAccAppView, CFormView)

BEGIN_MESSAGE_MAP(COLEDBDynAccAppView, CFormView)
	//{{AFX_MSG_MAP(COLEDBDynAccAppView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView construction/destruction

COLEDBDynAccAppView::COLEDBDynAccAppView()
	: CFormView(COLEDBDynAccAppView::IDD)
{
	//{{AFX_DATA_INIT(COLEDBDynAccAppView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COLEDBDynAccAppView::~COLEDBDynAccAppView()
{
}

void COLEDBDynAccAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COLEDBDynAccAppView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL COLEDBDynAccAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COLEDBDynAccAppView::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView diagnostics

#ifdef _DEBUG
void COLEDBDynAccAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void COLEDBDynAccAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COLEDBDynAccAppDoc* COLEDBDynAccAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDBDynAccAppDoc)));
	return (COLEDBDynAccAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView database support



/////////////////////////////////////////////////////////////////////////////
// COLEDBDynAccAppView message handlers

void COLEDBDynAccAppView::OnFileOpen() 
{
	
	if(m_enumDlg.DoModal()==IDOK)
	{
		m_datasourceDlg.m_pRootEnum = &(m_enumDlg.m_RootEnum);
		if(m_datasourceDlg.DoModal()==IDOK)
		{
			m_tablesDlg.m_pSession = &(m_datasourceDlg.m_session);
			m_tablesDlg.m_pSource = &(m_datasourceDlg.m_source);
			if(m_tablesDlg.DoModal()==IDOK)
			{
				m_columnsDlg.m_pSession = m_tablesDlg.m_pSession;
				m_session = *(m_tablesDlg.m_pSession);
				m_columnsDlg.m_pTbl = &(m_tablesDlg.m_Tbl);
				m_columnsDlg.DoModal();
				m_cmd_str =  m_columnsDlg.m_cmd_str;	
			
			}
			
		}
		
	}
}



