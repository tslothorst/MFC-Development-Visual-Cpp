// TimgView.cpp : implementation of the CTreeWithImagesView class
//

#include "stdafx.h"
#include "TreeWimg.h"

#include "TimgDoc.h"
#include "TimgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView

IMPLEMENT_DYNCREATE(CTreeWithImagesView, CTreeView)

BEGIN_MESSAGE_MAP(CTreeWithImagesView, CTreeView)
	//{{AFX_MSG_MAP(CTreeWithImagesView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView construction/destruction

CTreeWithImagesView::CTreeWithImagesView()
{
	cim = 0;
}

CTreeWithImagesView::~CTreeWithImagesView()
{
	if (cim)
	{
		delete cim;
		cim = 0;
	}
}

BOOL CTreeWithImagesView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView drawing

void CTreeWithImagesView::OnDraw(CDC* pDC)
{
	CTreeWithImagesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

void CTreeWithImagesView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	GetTreeCtrl().ModifyStyle(NULL,
		TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	
	InsertBitmaps();
}

void CTreeWithImagesView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	GetTreeCtrl().DeleteAllItems();
	InsertAnimals();
}

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView printing

BOOL CTreeWithImagesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTreeWithImagesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTreeWithImagesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView diagnostics

#ifdef _DEBUG
void CTreeWithImagesView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTreeWithImagesView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeWithImagesDoc* CTreeWithImagesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeWithImagesDoc)));
	return (CTreeWithImagesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeWithImagesView message handlers
void CTreeWithImagesView::InsertBitmaps()
{
	// Create the CImageList. It's destroyed in the destructor.
	cim = new CImageList();
	cim->Create(BITMAP_WIDTH, BITMAP_HEIGHT, TRUE, NUM_BITMAPS, 0);

	CBitmap bitmap;

	// Load the bitmaps and add them to the image list.
	for (int i = IDB_AMPHIBIAN; i <= IDB_REPTILE_SELECTED; i++)
	{
		bitmap.LoadBitmap(i);
		cim->Add(&bitmap, (COLORREF)0xFFFFFF);
		bitmap.DeleteObject();
	}

	// Associate the image list with the tree control.
	GetTreeCtrl().SetImageList(cim, TVSIL_NORMAL);
}

void CTreeWithImagesView::InsertAnimals()
{
	static char * classes[] = {  "amphibians", "birds", "fishes",
								"mammals", "reptiles", NULL };
	static char * types[][4] = { "frogs", "toads", "salamanders", NULL,
								"eagles", "owls", "falcons", NULL,
								"trout", "perch", "bass", NULL,
								"bears", "whales", "rodents", NULL,
								"snakes", "turtles", "lizards", NULL };

	HTREEITEM hSubTree;
	int ImageListIndex = 0;

	CTreeCtrl & ctc = GetTreeCtrl();

	for (int r = 0; r < 5; r++)
	{
		hSubTree = ctc.InsertItem(classes[r], TVI_ROOT, TVI_SORT);
		ctc.SetItemImage(hSubTree, ImageListIndex, ImageListIndex + 1);
		// The string from the classes array is placed at the root...
		// and the newly-inserted node serves as parent to the types.
		InsertNodes(hSubTree, types[r], ImageListIndex, ImageListIndex + 1);
		ImageListIndex += 2;
	}

	static char * beartypes[] = { "grizzly", "polar", "black", NULL };
	HTREEITEM hSubTree2;

	// Now that the tree is built, the bears node will have children
	// added to it. This requires 2 lookup operations. 
	hSubTree = FindNode(ctc.GetRootItem(), classes[3]);
	if (NULL != hSubTree)
	{
		hSubTree2 = FindNode(hSubTree, types[3][0]);
		if (NULL != hSubTree2)
			InsertNodes(hSubTree2, beartypes, MAMMAL, MAMMAL + 1);
	}
}

// The function iterates over the children of ParentNode looking for a match.
// If ParentNode is NULL, the search starts in the root, otherwise it starts
// in the designated node. Returns NULL if not found, the HTREEITEM if found.
HTREEITEM CTreeWithImagesView::FindNode(const HTREEITEM ParentNode,
										const CString &str) const
{
	CTreeCtrl & ctc = GetTreeCtrl();
	HTREEITEM node;
	CString s;

	if (NULL == ParentNode)
		node = ctc.GetRootItem();
	else
		if (ctc.GetRootItem() == ParentNode)
			node = ParentNode;
		else
			node = ctc.GetChildItem(ParentNode);
	
	while (node != NULL)
	{
		s = ctc.GetItemText(node);
		// Halt the search when we find what we're looking for.
		if (0 == s.CompareNoCase(str))
			return node;
		node = ctc.GetNextItem(node, TVGN_NEXT);
	}
	// If we get to here, string was never found, and node == NULL.
	return node;
}

// This function inserts the array of strings pointed to by the 2nd
// argument into the tree at the node represented by the first
// argument. All nodes have the same 2 image IDs.
void CTreeWithImagesView::InsertNodes(const HTREEITEM hSubTree, char ** AnimalClass,
							const int ImageID, const int SelectedImageID)
{
	HTREEITEM node;
	CTreeCtrl & ctc = GetTreeCtrl();
	
	int i = 0;
	while (AnimalClass[i])
	{
		// Insert a node as a child of hSubTree and set its images.
		node = ctc.InsertItem(AnimalClass[i++], hSubTree, TVI_SORT);
		ctc.SetItemImage(node, ImageID, SelectedImageID);
	}
}
