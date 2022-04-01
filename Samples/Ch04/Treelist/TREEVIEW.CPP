// TreeView.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"

#include "AnmlData.h"
#include "treedoc.h"

#include "TreeView.h"
#include "ListView.h"

#include "dialogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeView

IMPLEMENT_DYNCREATE(CSimpleTreeView, CTreeView)

CSimpleTreeView::CSimpleTreeView()
{
}

CSimpleTreeView::~CSimpleTreeView()
{
}

BEGIN_MESSAGE_MAP(CSimpleTreeView, CTreeView)
	//{{AFX_MSG_MAP(CSimpleTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeView message handlers

void CSimpleTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();

	GetTreeCtrl().ModifyStyle(NULL,
							TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
}

void CSimpleTreeView::PopulateTree()
{
	GetTreeCtrl().DeleteAllItems();
	GetDocument()->m_pListView->EraseList();
	InsertRootNodes();
	InsertDataNodes();
}

void CSimpleTreeView::InsertRootNodes()
{	
	// For this simple program, where the tree goes at most 2 levels deep,
	// item data will be 0 at all root nodes and -1 at all first level nodes.
	// At second level nodes, item data will be the POSITION of a given node
	// in the document object's CList member. Each node also contains a string.
	// See OnSelchanged to see how these 2 pieces of information are extracted
	// and used when the user clicks on a node in the tree control.

	CString s;
	for (int i = IDS_AMPHIBIANS; i <= IDS_REPTILES; i++)
	{
		s.LoadString(i);
		InsertNode(TVI_ROOT, s, 0);
	}
}

void CSimpleTreeView::InsertDataNodes()
{
	CTreeDoc* pDoc = GetDocument();

	// The idea here is to iterate over the document's CList object	and
	// insert some data from each member of the CList into the tree control.
	// Data not inserted in the tree will be shown in the list view when the
	// user selects an item from the tree. The leaf nodes of the tree control
	// will store a POSITION member that will facilitate searching the
	// document's CList by the list view.
	POSITION current, pos = pDoc->m_AnimalList.GetHeadPosition();
	while (NULL != pos)
	{
		current = pos;
		CAnimalInfo & rAnimal = pDoc->m_AnimalList.GetNext(pos);
		LocateAndInsert(rAnimal, current);
	}
}

BOOL CSimpleTreeView::LocateAndInsert(const CAnimalInfo & Animal, const POSITION pos)
{
	HTREEITEM classnode, typenode;

	// Begin by locating the node where the item will be inserted.
	// If the root node doesn't exist, return from function.
	if ((classnode = FindNode(NULL, Animal.m_class)) == 0)
		return FALSE;

	// Next, iterate over that node looking for the type,
	// and insert type if it doesn't exist.
	if ((typenode = FindNode(classnode, Animal.m_type)) == 0)
		typenode = InsertNode(classnode, Animal.m_type, (DWORD)-1);

	if (0 == typenode)
		return FALSE;

	// By this time we know we've got the class and the type.
	// If the animal itself isn't already inserted, insert it.
	if ((FindNode(typenode, Animal.m_animal)) == 0)
		if (InsertNode(typenode, Animal.m_animal, (DWORD) pos) != 0)
			return TRUE;
	return FALSE;
}

// The function iterates over the children of ParentNode looking for a match.
// If ParentNode is NULL, the search starts in the root, otherwise it starts
// in the designated node. Returns NULL if not found, the HTREEITEM if found.
HTREEITEM CSimpleTreeView::FindNode(const HTREEITEM ParentNode, const CString &str) const
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

HTREEITEM CSimpleTreeView::InsertNode(const HTREEITEM ParentNode,  const CString &str, const DWORD itemData)
{
	CTreeCtrl & ctc = GetTreeCtrl();
	HTREEITEM node;

	node = ctc.InsertItem(str, ParentNode, TVI_SORT);
	ctc.SetItemData(node, itemData);

	return node;
}

void CSimpleTreeView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	*pResult = 0;

	// Obtain a reference to the CTreeControl object that is
	// embedded in this view class.
	CTreeCtrl & ctlTree = GetTreeCtrl();
	
	// Determining which item the user has selected is a 2-step
	// process. You first obtain the handle to the selected item.
	HTREEITEM selectedNode = ctlTree.GetSelectedItem();

	// In the second step, you call a specific function
	// (GetItemText, GetItemData, GetItemState or GetItemImage)
	// to obtain a specific piece of information from the selected item,
	DWORD itemData = ctlTree.GetItemData(selectedNode);

	CTreeDoc * pDoc = GetDocument();
	switch (itemData)
	{
		case 0:
			// For root nodes, the list will iterate over the selected
			// item and display all the types it contains.
			pDoc->m_pListView->DisplayClassInfo(selectedNode);
			break;
		case -1:
			// In the case of a level 1 node, give it the HTREEITEM
			// and let it iterate over that node's children.
			pDoc->m_pListView->DisplayTypeInfo(selectedNode);
			break;
		default:
			// For level 2 nodes, the selected item's data contains
			// its POSITION in the document object's CList.
			pDoc->m_pListView->DisplayAnimalInfo(itemData);
	}
}

int CSimpleTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Initialize the document object's pointer to the tree
	// view object.
	GetDocument()->m_pTreeView = this;

	return 0;
}
void CSimpleTreeView::ModifySelection()
{
	// Obtain a reference to the CTreeControl object.
	CTreeCtrl & ctlTree = GetTreeCtrl();
	
	// Obtain the handle of the selected item.
	HTREEITEM selectedNode = ctlTree.GetSelectedItem();

	// If item data indicates it's at level 0, do nothing.
	// At level one, let the user change the spelling of the animal's type. 
	// Otherwise, let the user modify the animal's name or weight,
	// but not its class or type.
	DWORD itemData = ctlTree.GetItemData(selectedNode);
	switch (itemData)
	{
		case 0:
			break;
		case -1:
			ModifyType(selectedNode, itemData);
			break;
		default:
			ModifyAnimal(selectedNode, itemData);
	}
}

void CSimpleTreeView::DeleteSelection()
{
	// Obtain a reference to the CTreeControl object.
	CTreeCtrl & ctlTree = GetTreeCtrl();
	
	// Obtain the handle of the selected item.
	HTREEITEM selectedNode = ctlTree.GetSelectedItem();

	// If item data indicates it's at level 0 or -1 do nothing.
	// Otherwise, confirm the deletion, delete the item from the tree,
	// then delete it from the CList.
	DWORD itemData = ctlTree.GetItemData(selectedNode);

	if (0 == itemData || -1 == itemData)
		return;

	CString AnimalName = ctlTree.GetItemText(selectedNode);
	CString s;
	s.Format("Are you sure you want to delete '%s' from the database?",
			 AnimalName);
	int rc = MessageBox(s, "Confirm Deletion", MB_YESNO | MB_ICONQUESTION);
	if (IDNO == rc)
		return;

	// Before deleting the selected item, obtain a handle to its parent.
	HTREEITEM parent = ctlTree.GetParentItem(selectedNode);

	// Remove the selected item from the tree.
	ctlTree.DeleteItem(selectedNode);

	// Then remove it from the document's CList and set the modified flag.
	CTreeDoc * pDoc = GetDocument();
	pDoc->m_AnimalList.RemoveAt((POSITION)itemData);
	pDoc->SetModifiedFlag();

	// Finally, select the deleted node's parent.
	ctlTree.SelectItem(parent);
}

void CSimpleTreeView::EditSelection()
{
	CAnimalDlg dlg;

	if (IDOK == dlg.DoModal())
	{
		// Construct CAnimalInfo object with 4 values from the dialog object.
		CAnimalInfo my_object(dlg.m_class, dlg.m_type,
								dlg.m_animal, dlg.m_weight);
		
		// Insert the object into the document class.
		CTreeDoc * pDoc = GetDocument();
		POSITION pos = pDoc->InsertData(my_object);
		
		// Then insert it into the tree view.
		LocateAndInsert(my_object, pos);
	}
}

void CSimpleTreeView::ModifyType(const HTREEITEM selectedNode, const DWORD itemData)
{
	CTreeCtrl & ctlTree = GetTreeCtrl();
	CString AnimalType = ctlTree.GetItemText(selectedNode);

	CModifyTypeDlg dlg;
	dlg.m_type = AnimalType;

	if (IDOK == dlg.DoModal())
	{
		// First, change the text in the selected node of the tree.
		ctlTree.SetItemText(selectedNode, dlg.m_type);
		
		// Second, sort the parent of the selected node, since the
		// new spelling may require a re-sort.
		HTREEITEM parent = ctlTree.GetParentItem(selectedNode);
		ctlTree.SortChildren(parent);
		
		// Iterate over the CList and change any node with the old spelling.
		CTreeDoc * pDoc = GetDocument();
		POSITION current, pos = pDoc->m_AnimalList.GetHeadPosition();
		while (NULL != pos)
		{
			// Since GetNext advances its POSITION argument, save it.
			current = pos;

			// Grab the current object.
			CAnimalInfo & rAnimal2 = pDoc->m_AnimalList.GetNext(pos);

			// If its type is that same as the selected node,
			// change the spelling.
			if (rAnimal2.m_type == AnimalType)
				pDoc->m_AnimalList.GetAt(current).m_type = dlg.m_type;
		}
		pDoc->SetModifiedFlag();
	}
}

void CSimpleTreeView::ModifyAnimal(const HTREEITEM selectedNode, const DWORD itemData)
{
	CTreeDoc * pDoc = GetDocument();

	// Obtain, from the document's Clist, the selected item.
	// The node in the tree contains that object's POSITION in the CList.
	CAnimalInfo & rAnimal = pDoc->m_AnimalList.GetAt((POSITION)itemData);

	// Create the modifying dialog box and initialize it.
	CModifyDlg dlg;
	dlg.m_animal = rAnimal.m_animal;
	dlg.m_weight = rAnimal.m_weight;

	// If user chooses OK, modify object in the CList, and
	// modify the object in the tree view.
	if (IDOK == dlg.DoModal())
	{
		rAnimal.m_animal = dlg.m_animal;
		rAnimal.m_weight = dlg.m_weight;

		// Since the CList is not const, GetAt() can be used as an lvalue.
		pDoc->m_AnimalList.GetAt((POSITION)itemData) = rAnimal;
		pDoc->SetModifiedFlag();

		// Since the tree doesn't store the weight, there's only
		// one thing to update in the tree.
		CTreeCtrl & ctlTree = GetTreeCtrl();
		ctlTree.SetItemText(selectedNode, rAnimal.m_animal);

		// The selected node will refresh itself. However, changing
		// the spelling may require that the parent of the selected
		// node have its children sorted.
		HTREEITEM parent = ctlTree.GetParentItem(selectedNode);
		ctlTree.SortChildren(parent);

		// The list must be manually refreshed. This is the
		// same line of code used in CTreeView::OnSelchanged.
		pDoc->m_pListView->DisplayAnimalInfo(itemData);
	}
}
/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeView diagnostics
#ifdef _DEBUG
void CSimpleTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSimpleTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeDoc* CSimpleTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeDoc)));
	return (CTreeDoc*)m_pDocument;
}

#endif //_DEBUG
