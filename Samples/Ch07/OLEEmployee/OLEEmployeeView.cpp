// OLEEmployeeView.cpp : implementation of the COLEEmployeeView class
//

#include "stdafx.h"
#include "OLEEmployee.h"

#include "OLEEmployeeSet.h"
#include "OLEEmployeeDoc.h"
#include "OLEEmployeeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView

IMPLEMENT_DYNCREATE(COLEEmployeeView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COLEEmployeeView, COleDBRecordView)
	//{{AFX_MSG_MAP(COLEEmployeeView)
	ON_COMMAND(ID_RECORD_DELETE, OnRecordDelete)
	ON_COMMAND(ID_RECORD_COMMIT, OnRecordCommit)
	ON_COMMAND(ID_RECORD_ADD, OnRecordAdd)
	ON_COMMAND(ID_RECORD_CLEAR, OnRecordClear)
	ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, COleDBRecordView::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_RECORD_DELETE, OnUpdateDelete)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView construction/destruction

COLEEmployeeView::COLEEmployeeView()
	: COleDBRecordView(COLEEmployeeView::IDD)
{
	//{{AFX_DATA_INIT(COLEEmployeeView)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COLEEmployeeView::~COLEEmployeeView()
{
}

void COLEEmployeeView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COLEEmployeeView)
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EMPLOYEE_ID, m_pSet->m_EmployeeID);
	DDX_Text(pDX, IDC_ADDRESS, m_pSet->m_Address, 51);
	DDX_Text(pDX, IDC_NAME, m_pSet->m_Name, 51);
}

BOOL COLEEmployeeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void COLEEmployeeView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_oLEEmployeeSet;
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
			m_pSet->m_EmployeeID = 0;
			m_pSet->m_Name[0] = '\0';
			m_pSet->m_Address[0]= '\0';
		}				
	}
	COleDBRecordView::OnInitialUpdate();

}
/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView printing

BOOL COLEEmployeeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COLEEmployeeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COLEEmployeeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView diagnostics

#ifdef _DEBUG
void COLEEmployeeView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COLEEmployeeView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COLEEmployeeDoc* COLEEmployeeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEEmployeeDoc)));
	return (COLEEmployeeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView database support
CRowset* COLEEmployeeView::OnGetRowset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COLEEmployeeView message handlers

void COLEEmployeeView::OnRecordDelete() 
{
	m_pSet->Delete();
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

void COLEEmployeeView::OnRecordCommit() 
{
	m_pSet->session.Commit();	
}

void COLEEmployeeView::OnRecordAdd() 
{
	UpdateData(TRUE);
	m_pSet->Insert();
	m_pSet->MoveLast();
	if(m_bOnFirstRecord && m_bOnLastRecord)
	{
		m_bOnFirstRecord = FALSE;
		m_bOnLastRecord = FALSE;

	}
}

void COLEEmployeeView::OnRecordClear() 
{
	m_pSet->m_EmployeeID = 0;
	m_pSet->m_Name[0] = '\0';
	m_pSet->m_Address[0]= '\0';
	UpdateData(FALSE);
}

void COLEEmployeeView::OnRecordPrev() 
{
	if(!OnMove(ID_RECORD_PREV))
		OnMove(ID_RECORD_FIRST);
}

void COLEEmployeeView::OnRecordNext() 
{
	if(!OnMove(ID_RECORD_NEXT))
		OnMove(ID_RECORD_LAST);
}

void COLEEmployeeView::OnUpdateDelete(CCmdUI* pCmdUI)
{
		if(m_bOnFirstRecord && m_bOnLastRecord)
			pCmdUI->Enable(FALSE);
		else
			pCmdUI->Enable(TRUE);		
}

