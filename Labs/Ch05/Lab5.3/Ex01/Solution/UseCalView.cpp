// UseCalView.cpp : implementation of the CUseCalView class
//

#include "stdafx.h"
#include "UseCal.h"

#include "UseCalDoc.h"
#include "UseCalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CUseCalView

IMPLEMENT_DYNCREATE(CUseCalView, CFormView)

BEGIN_MESSAGE_MAP(CUseCalView, CFormView)
	//{{AFX_MSG_MAP(CUseCalView)
	ON_COMMAND(ID_CALENDAR_SHOWCURRENTDATE, OnCalendarShowcurrentdate)
	ON_COMMAND(ID_CALENDAR_SETBACKCOLOR, OnCalendarSetbackcolor)
	ON_COMMAND(ID_CALENDAR_TOGGLETITLE, OnCalendarToggletitle)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseCalView construction/destruction

CUseCalView::CUseCalView()
	: CFormView(CUseCalView::IDD)
{
	//{{AFX_DATA_INIT(CUseCalView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CUseCalView::~CUseCalView()
{
}

void CUseCalView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUseCalView)
	DDX_Control(pDX, IDC_CALENDARCTRL, m_CalControl);
	//}}AFX_DATA_MAP
}

BOOL CUseCalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CUseCalView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CUseCalView printing

BOOL CUseCalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUseCalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUseCalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CUseCalView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add code to print the controls
}

/////////////////////////////////////////////////////////////////////////////
// CUseCalView diagnostics

#ifdef _DEBUG
void CUseCalView::AssertValid() const
{
	CFormView::AssertValid();
}

void CUseCalView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUseCalDoc* CUseCalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseCalDoc)));
	return (CUseCalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseCalView message handlers

void CUseCalView::OnCalendarShowcurrentdate() 
{
	// TODO: Add your command handler code here
	m_CalControl.Today();
}

void CUseCalView::OnCalendarSetbackcolor() 
{
	// TODO: Add your command handler code here
	OLE_COLOR current_color = m_CalControl.GetBackColor();
	COLORREF old_color;

	// OLE_COLOR must be converted to a COLORREF for use
	// by CColorDialog.
	if (S_OK != ::OleTranslateColor(current_color,
									NULL, &old_color))
		return;

	CColorDialog dlg(old_color);

	if (IDOK == dlg.DoModal())
	{
		// No translation is needed from COLORREF to OLE_COLOR
		COLORREF new_color = dlg.GetColor();
		if (new_color != old_color)
		{
			current_color = new_color;
			m_CalControl.SetBackColor(current_color);
		}
	}
}

void CUseCalView::OnCalendarToggletitle() 
{
	// TODO: Add your command handler code here
	BOOL bTitleState = m_CalControl.GetShowTitle();
	m_CalControl.SetShowTitle(! bTitleState);
}

BEGIN_EVENTSINK_MAP(CUseCalView, CFormView)
    //{{AFX_EVENTSINK_MAP(CUseCalView)
	ON_EVENT(CUseCalView, IDC_CALENDARCTRL, -601 /* DblClick */, OnDblClickCalendarctrl, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CUseCalView::OnDblClickCalendarctrl() 
{
	// TODO: Add your control notification handler code here
	short year = m_CalControl.GetYear();
	short month = m_CalControl.GetMonth();
	short day = m_CalControl.GetDay();
	WORD hh,min,sec,mlsec;
	SYSTEMTIME mtime;
	GetSystemTime(&mtime);
	hh=mtime.wHour;
	min=mtime.wMinute;
	sec=mtime.wSecond;
	mlsec=mtime.wMilliseconds;

	mtime.wYear= (WORD)year;
	mtime.wMonth= (WORD)month;
	mtime.wDay= (WORD)day;
	mtime.wHour=hh;
	mtime.wMinute=min;
	mtime.wSecond=sec;
	mtime.wMilliseconds=mlsec;
	
	CString str;
	str.Format("Set System Date to: %d/%d/%d ?",month,day,year);

	int i=::MessageBox(0,str,"Date",MB_YESNO);
	if(i==IDYES)
		::SetSystemTime(&mtime);

}
