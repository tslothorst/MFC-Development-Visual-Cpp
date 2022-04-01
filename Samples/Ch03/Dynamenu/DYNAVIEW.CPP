// DynaView.cpp : implementation of the CMenusDynamicView class
//

#include "stdafx.h"
#include "DynaMenu.h"

#include "DynaMDoc.h"
#include "DynaView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF GREEN=RGB(0,255,0);
const COLORREF BLUE=RGB(0,0,255);

const COLORREF CYAN=RGB(0,255,255);
const COLORREF PURPLE=RGB(255,0,255);
const COLORREF YELLOW=RGB(255,255,0);

const COLORREF WHITE=RGB(255,255,255);

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView

IMPLEMENT_DYNCREATE(CMenusDynamicView, CView)

BEGIN_MESSAGE_MAP(CMenusDynamicView, CView)
	//{{AFX_MSG_MAP(CMenusDynamicView)
	ON_COMMAND(ID_OPTIONS_EXTRACOLORS, OnOptionsExtracolors)
	ON_COMMAND(ID_OPTIONS_STANDARDCOLORS, OnOptionsStandardcolors)
	ON_COMMAND(ID_OPTIONS_EXTRACOLORS_CASCADE, OnOptionsExtracolorsCascade)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_BLACK, ID_COLORS_BLUE, OnUpdateColors)
	ON_COMMAND_RANGE(ID_COLORS_CYAN, ID_COLORS_YELLOW, OnColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLORS_CYAN, ID_COLORS_YELLOW, OnUpdateColors)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OPTIONS_EXTRACOLORS, ID_OPTIONS_EXTRACOLORS_CASCADE, OnUpdateOptions)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView construction/destruction
CMenusDynamicView::CMenusDynamicView()
	:m_pExtraColors(0)
{
}

CMenusDynamicView::~CMenusDynamicView()
{
}

BOOL CMenusDynamicView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView drawing

void CMenusDynamicView::OnDraw(CDC* pDC)
{
	CMenusDynamicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView diagnostics

#ifdef _DEBUG
void CMenusDynamicView::AssertValid() const
{
	CView::AssertValid();
}

void CMenusDynamicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenusDynamicDoc* CMenusDynamicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenusDynamicDoc)));
	return (CMenusDynamicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenusDynamicView message handlers
void CMenusDynamicView::OnOptionsExtracolors() 
{
	CMenu *pAddinMenu, *pTopMenu;
	
	// To append to the Colors menu, we'll need a pointer to it.
	// We begin by obtaining a pointer to the top-level menu.
	pTopMenu = AfxGetMainWnd()->GetMenu();

	// Colors is the 3rd menu, but that's #2 in a 0-based system.
	pAddinMenu = pTopMenu->GetSubMenu(2);
	ASSERT(pAddinMenu != NULL);
	
	// First, add a separator to separate the default menus
	// from the dynamic menus.
	pAddinMenu->AppendMenu(MF_SEPARATOR);

	// Append the 3 menu items. They will generate consecutive
	// command IDs.
	CString prompt;
	for (int i = 0; i < 3; i++)
	{
		prompt.LoadString(ID_COLORS_CYAN + i);
		pAddinMenu->AppendMenu(MF_STRING, 
						ID_COLORS_CYAN + i, prompt);
	}
}

void CMenusDynamicView::OnOptionsStandardcolors() 
{
	CMenu *pAddinMenu, *pTopMenu;
	
	// To remove items from the Colors menu, we'll need a pointer to it.
	// We begin by obtaining a pointer to the top-level menu.
	pTopMenu = AfxGetMainWnd()->GetMenu();

	// Colors is the 3rd menu, but that's #2 in a 0-based system.
	pAddinMenu = pTopMenu->GetSubMenu(2);

	int i = pAddinMenu->GetMenuItemCount();
	
	// If the extra colors were displayed as additions
	// to the colors menu, then removing them is simple. 
	// We want to leave only 4 menu items.
	if (8 == i)
	{
		i--;				// adjust to 0-based.
		while(i > 3)
		{
			pAddinMenu->RemoveMenu(i, MF_BYPOSITION);
			i--;
		}
	}
	else
	// Otherwise, it's a cascading menu which must be properly
	// destroyed, since it was allocated using CreatePopupMenu
	// in another function.
	{
		// First delete the cascading menu. It's also
		// necessary to free the object that was allocated in
		// OnOptionsExtracolorsCascade.
		pAddinMenu->DeleteMenu(5, MF_BYPOSITION);
		delete m_pExtraColors;
		m_pExtraColors = 0;
		// Then remove the separator bar.
		pAddinMenu->RemoveMenu(4, MF_BYPOSITION);
	}

	// Finally, set the color to black and force a redraw;
	CMenusDynamicDoc* pDoc = GetDocument();
	pDoc->SetColor(BLACK);
	Invalidate();
}

// This functions updates the menu items under the Options menu.
void CMenusDynamicView::OnUpdateOptions(CCmdUI* pCmdUI)
{
	CMenu *pAddinMenu, *pTopMenu;
	pTopMenu = AfxGetMainWnd()->GetMenu();
	pAddinMenu = pTopMenu->GetSubMenu(2);

	switch (pCmdUI->m_nID)
	{
		case ID_OPTIONS_EXTRACOLORS:
		case ID_OPTIONS_EXTRACOLORS_CASCADE:
			pCmdUI->Enable(pAddinMenu->GetMenuItemCount() == 4);
			break;
		case ID_OPTIONS_STANDARDCOLORS:
			pCmdUI->Enable(pAddinMenu->GetMenuItemCount() != 4);
	}
}

void CMenusDynamicView::OnColors(UINT nID)
{
	CMenusDynamicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->SetColor(IDtoColorRef(nID));
	Invalidate();
}

void CMenusDynamicView::OnUpdateColors(CCmdUI* pCmdUI)
{
	CMenusDynamicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pCmdUI->SetCheck(pDoc->GetColor() == IDtoColorRef(pCmdUI->m_nID));
}

void CMenusDynamicView::OnOptionsExtracolorsCascade() 
{
	// A cascading menu is a new menu object that must persist
	// after this function terminates. Thus the use the pointer
	// m_pExtraColors, which is a member of the view class. It's needed
	// elsewhere in this class to properly delete the object
	// allocated in this function.
	m_pExtraColors = new CMenu;
	m_pExtraColors->CreatePopupMenu();

	// Next, add existing menu items to this newly created
	// menu object.
	CString prompt;
	for (int i = 0; i < 3; i++)
	{
		prompt.LoadString(ID_COLORS_CYAN + i);
		m_pExtraColors->AppendMenu(MF_STRING, 
									ID_COLORS_CYAN + i, prompt);
	}
	
	CMenu *pTopMenu, *pSubMenu;

	pTopMenu = AfxGetMainWnd()->GetMenu();
	pSubMenu = pTopMenu->GetSubMenu(2);
	
	// Now that we have a pointer to the appropriate sub menu,
	// the new menu object can be appended. The flag MF_POPUP
	// tells AppendMenu how to interpret the 3rd argument.
	prompt.LoadString(ID_EXTRA_COLORS);
	pSubMenu->AppendMenu(MF_STRING | MF_POPUP, 
				(UINT)m_pExtraColors->m_hMenu, prompt);

	// Be sure to examine the code in OnOptionsStandardcolors()
	// to see how this menu object is deleted, NOT removed!
	// Also, examine OnDestroy.
}

void CMenusDynamicView::OnDestroy() 
{
	CView::OnDestroy();

	// If the view allocated a cascading menu, its
	// memory must be given back.
	if (m_pExtraColors)
	{
		delete m_pExtraColors;
		m_pExtraColors = 0;
	}
}

CRect CMenusDynamicView::GetPhraseBounds()
{
	CClientDC dc(this);
	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	CMenusDynamicDoc* pDoc = GetDocument();
	CString temp = pDoc->GetPhrase();
	CSize cs = dc.GetTextExtent(temp, temp.GetLength());
	
	// Recall that the phrase is centered on a point in
	// the exact middle of the view. See View class's OnDraw.

	// This makes creating a bounding rectangle a bit tricky.
	// We'll have to divide the text extents by 2, and take into
	// account the amount of descent of the current font.
	CRect r;
	GetClientRect(&r);

	int x = (r.right / 2) - (cs.cx / 2);
	int y = (r.bottom / 2) - (cs.cy / 2) - tm.tmDescent;
	
	return CRect(CPoint(x, y), cs);
}

// This function converts one of the 7 Command IDs to a COLORREF value.
COLORREF CMenusDynamicView::IDtoColorRef(int nID)
{
	switch (nID)
	{
		case ID_COLORS_RED:
			return RED;
		case ID_COLORS_GREEN:
			return GREEN;		
		case ID_COLORS_BLUE:
			return BLUE;
		case ID_COLORS_CYAN:
			return CYAN;
		case ID_COLORS_PURPLE:
			return PURPLE;
		case ID_COLORS_YELLOW:
			return YELLOW;
		default:
			return BLACK;		
	}
}
