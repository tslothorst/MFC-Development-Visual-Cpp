// ListView.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"

#include "AnmlData.h"
#include "treedoc.h"

#include "ListView.h"
#include "TreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimpleListView

IMPLEMENT_DYNCREATE(CSimpleListView, CListView)

CSimpleListView::CSimpleListView()
{
}

CSimpleListView::~CSimpleListView()
{
}

BEGIN_MESSAGE_MAP(CSimpleListView, CListView)
	//{{AFX_MSG_MAP(CSimpleListView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleListView message handlers
int CSimpleListView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Initialize the document object's pointer
	// to the list view object.
	GetDocument()->m_pListView = this;

	return 0;
}

void CSimpleListView::DisplayTypeInfo(const HTREEITEM ParentNode)
{
	static char * headers[] = { "Animal", NULL };

	DisplayChildren(headers, ParentNode);
}

void CSimpleListView::DisplayClassInfo(const HTREEITEM ParentNode)
{
	static char * headers[] = { "Types", NULL };

	DisplayChildren(headers, ParentNode);
}

void CSimpleListView::DisplayChildren(char **headers, const HTREEITEM ParentNode)
{
	CListCtrl & clc = GetListCtrl();
	CTreeCtrl & ctc = GetDocument()->m_pTreeView->GetTreeCtrl();
	int i = 0;

	LV_COLUMN lv;
    lv.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
    lv.fmt = LVCFMT_LEFT;

	EraseList();
	
	while (headers[i])
	{
		lv.cx = 15 * clc.GetStringWidth(headers[i]) / 10;
		lv.pszText = headers[i];
		clc.InsertColumn(i++, &lv);
	    lv.fmt = LVCFMT_CENTER;
	}

	HTREEITEM node = ctc.GetChildItem(ParentNode);
	i = 0;	
	CString s;
	while (node != NULL)
	{
		s = ctc.GetItemText(node);
		clc.InsertItem(i++, s);
		node = ctc.GetNextItem(node, TVGN_NEXT);
	}
}

void CSimpleListView::DisplayAnimalInfo(const DWORD itemData)
{
	static char * headers[] = { "Type", "Animal",
								"Max. Weight (kgs)", NULL };
	int i = 0;
	LV_COLUMN lv;
    lv.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
    lv.fmt = LVCFMT_LEFT;
	CListCtrl & clc = GetListCtrl();

	EraseList();

	while (headers[i])
	{
		lv.cx = 15 * clc.GetStringWidth(headers[i]) / 10;
		lv.pszText = headers[i];
		clc.InsertColumn(i++, &lv);
	    lv.fmt = LVCFMT_CENTER;
	}

	CAnimalInfo & rAnimal = 
		GetDocument()->m_AnimalList.GetAt((POSITION)itemData);
		
	// Insert the 3 pieces of information and expand
	// column widths as necessary.
	clc.InsertItem(0, rAnimal.m_type);
	int w = clc.GetStringWidth(rAnimal.m_type);
	if ( w > clc.GetColumnWidth(0) )
		clc.SetColumnWidth(0, 15 * w / 10);
	
	clc.SetItemText(0, 1, rAnimal.m_animal);
	w = clc.GetStringWidth(rAnimal.m_animal);
	if ( clc.GetColumnWidth(1) - 10 < w )
		clc.SetColumnWidth(1, 17 * w / 10);
	
	CString weight;
	weight.Format("%d", rAnimal.m_weight);
	clc.SetItemText(0, 2, weight);
	w = clc.GetStringWidth(weight);
	if ( clc.GetColumnWidth(1) - 10 < w )
		clc.SetColumnWidth(1, 17 * w / 10);
}

void CSimpleListView::OnInitialUpdate() 
{
	GetListCtrl().ModifyStyle(NULL, LVS_REPORT);

	CListView::OnInitialUpdate();
}

void CSimpleListView::EraseList()
{
	CListCtrl& ctlList = GetListCtrl();
	
	// Remove all the list's data.
	ctlList.DeleteAllItems();
	// Remove all the columns and consequently their headers.
	while(ctlList.DeleteColumn(0));
	// Force a repaint.
	UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CSimpleListView diagnostics
#ifdef _DEBUG
void CSimpleListView::AssertValid() const
{
	CListView::AssertValid();
}

void CSimpleListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CTreeDoc* CSimpleListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeDoc)));
	return (CTreeDoc*)m_pDocument;
}

#endif //_DEBUG

