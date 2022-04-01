// ListView.cpp : implementation of the CMyListView class
//

#include "stdafx.h"
#include "List.h"

#include "ListDoc.h"
#include "ListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

BEGIN_MESSAGE_MAP(CMyListView, CListView)
	//{{AFX_MSG_MAP(CMyListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListView construction/destruction

CMyListView::CMyListView()
{
}

CMyListView::~CMyListView()
{
}

BOOL CMyListView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyListView drawing

void CMyListView::OnDraw(CDC* pDC)
{
	CListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

void CMyListView::OnInitialUpdate()
{
	int i;
	CString s;
	LV_COLUMN lv;
	CListCtrl & clc = GetListCtrl();

	clc.ModifyStyle(NULL, LVS_REPORT);

    lv.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
    lv.fmt = LVCFMT_LEFT;
	
	// Create 4 columns in the list control and
	// give each column a header string.
	for (i = ID_COLUMN1; i <= ID_COLUMN4; i++)
	{
		s.LoadString(i);
		lv.cx = 15 * clc.GetStringWidth(s) / 10;
		lv.pszText = (char *) (const char *)s;
		clc.InsertColumn(i - ID_COLUMN1, &lv);
	    lv.fmt = LVCFMT_CENTER;
	}

	CListView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CMyListView diagnostics

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListDoc* CMyListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListDoc)));
	return (CListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyListView message handlers

void CMyListView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CListCtrl & clc = GetListCtrl();
	CString s;

	// Remove all the list's data. Since OnUpdate will be called
	// when the list's data changes, this call is necessary before
	// rebuilding the list.
	clc.DeleteAllItems();

	// Each iteration of the loop builds 1 row. InsertItem fills
	// column 0, SetItemText fills the other columns.
	for (int i = ID_BLACK; i <= ID_WHITE; i++)
	{
		s.LoadString(i);
		// row will be 0-7, which corresponds to the 8 basic colors
		int row = i-ID_BLACK;
		// insert the string
		clc.InsertItem(row, s);

		// convert the color to its component RGB values
		int mask = 4;
		for (int col = 1; col <= 3; col++)
		{
			// Determine if a bit is on or not.
			s.Format("%d", row & mask ? 255 : 0);
			clc.SetItemText(row, col, s);
			mask /= 2;
		}
	}
}
