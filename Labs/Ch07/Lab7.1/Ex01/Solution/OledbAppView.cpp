// OledbAppView.cpp : implementation of the COledbAppView class
//

#include "stdafx.h"
#include "OledbApp.h"

#include "OledbAppSet.h"
#include "OledbAppDoc.h"
#include "OledbAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COledbAppView

IMPLEMENT_DYNCREATE(COledbAppView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COledbAppView, COleDBRecordView)
	//{{AFX_MSG_MAP(COledbAppView)
		ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
		ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
		ON_COMMAND(ID_RECORD_CLEAR, OnRecordClear)
		ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
		ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
		ON_COMMAND(ID_RECORD_COMMIT, OnRecordCommit)
	ON_UPDATE_COMMAND_UI(ID_RECORD_DELETE, OnUpdateRecordDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COledbAppView construction/destruction

COledbAppView::COledbAppView()
	: COleDBRecordView(COledbAppView::IDD)
{
	//{{AFX_DATA_INIT(COledbAppView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COledbAppView::~COledbAppView()
{
}

void COledbAppView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COledbAppView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text(pDX, ID_EMPID, m_pSet->m_EmployeeID);
	DDX_Text(pDX, ID_LNAME, m_pSet->m_LastName,21);
	DDX_Text(pDX, ID_FNAME, m_pSet->m_FirstName,11);
	DDX_Text(pDX, ID_TITLE, m_pSet->m_Title,31);
	DDX_Text(pDX, ID_ADDRESS, m_pSet->m_Address,61);
	DDX_Text(pDX, ID_PHONE, m_pSet->m_HomePhone,25);

}

BOOL COledbAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COledbAppView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oledbAppSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->Open();
		if (hr != S_OK)
		{
			AfxMessageBox(_T("Record set failed to open."), MB_OK);
			// Disable the Next and Previous record commands,
			// since attempting to change the current record without an
			// open RecordSet will cause a crash.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// COledbAppView diagnostics

#ifdef _DEBUG
void COledbAppView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COledbAppView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COledbAppDoc* COledbAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COledbAppDoc)));
	return (COledbAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COledbAppView database support
CRowset* COledbAppView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COledbAppView message handlers
void COledbAppView::OnRecordPrev() 
{
	//Ensures that the user does not scroll ahead of BOF
	if(!OnMove(ID_RECORD_PREV))
		OnMove(ID_RECORD_FIRST);
}
  

void COledbAppView::OnRecordNext() 
{
	//Ensures that the user does not scroll beyond EOF
	if(!OnMove(ID_RECORD_NEXT))
		OnMove(ID_RECORD_LAST);
}

void COledbAppView::OnRecordClear()
{
	m_pSet->m_EmployeeID = 0;
	m_pSet->m_LastName[0] = '\0';
	m_pSet->m_FirstName[0]= '\0';
	m_pSet->m_Title[0]= '\0';
	m_pSet->m_Address[0]= '\0';
	m_pSet->m_HomePhone[0]= '\0';
	UpdateData(FALSE);
}

void COledbAppView::OnRecordAdd() 
{
	UpdateData(TRUE);
	m_pSet->Insert();
	m_pSet->MoveLast();
	//If the record was added to a table which contained no records
	//the view's record scroll functionality, which would have been
	//turned off in OnInitialUpdate, has to be turned on

	if(m_bOnFirstRecord && m_bOnLastRecord)
	{
		m_bOnFirstRecord = FALSE;
		m_bOnLastRecord = FALSE;
  
	}
}

void COledbAppView::OnRecordDelete() 
{
	m_pSet->Delete();

	//If the record that has just been deleted, is the last record
	//in the table, the form has to be cleared and the record
	//scrolling functionality of the view has to be turned off.

	if(!OnMove(ID_RECORD_NEXT))
	{
		if(!OnMove(ID_RECORD_LAST))
		{
			OnRecordClear();
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	UpdateData(FALSE);
}

void COledbAppView::OnRecordCommit() 
{
	m_pSet->session.Commit();	
}


void COledbAppView::OnUpdateRecordDelete(CCmdUI* pCmdUI) 
{
	if(m_bOnFirstRecord && m_bOnLastRecord)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	
}
