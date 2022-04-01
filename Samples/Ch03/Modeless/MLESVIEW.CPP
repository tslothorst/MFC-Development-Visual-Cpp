// MlesView.cpp : implementation of the CModelessView class
//

#include "stdafx.h"
#include "Modeless.h"

#include "Dialogs.H"

#include "MdlesDoc.h"
#include "MlesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModelessView

IMPLEMENT_DYNCREATE(CModelessView, CView)

BEGIN_MESSAGE_MAP(CModelessView, CView)
	//{{AFX_MSG_MAP(CModelessView)
	ON_COMMAND(ID_MODIFY_DISPLAYMODELESSDIALOG, OnModifyDisplaymodelessdialog)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_DISPLAYMODELESSDIALOG, OnUpdateModifyDisplaymodelessdialog)
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(CModelessView::m_UserMsg, MyMessageHandler)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModelessView construction/destruction

// Static member variables must be initialized.
// Register the message the dialog box will send to this object.
UINT CModelessView::m_UserMsg = 
	RegisterWindowMessage(MY_DIALOGBOX_MSG);

CModelessView::CModelessView()
	:m_pDlg(0)
{
}

CModelessView::~CModelessView()
{
}

BOOL CModelessView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CModelessView drawing

void CModelessView::OnDraw(CDC* pDC)
{
	CModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect r;
	GetClientRect(&r);
	int x = r.right / 2, y = r.bottom / 2;

	pDC->SetTextColor(pDoc->GetColor());
	pDC->SetTextAlign (TA_CENTER | TA_BASELINE);
	pDC->TextOut (x, y, pDoc->GetPhrase());
}

/////////////////////////////////////////////////////////////////////////////
// CModelessView diagnostics

#ifdef _DEBUG
void CModelessView::AssertValid() const
{
	CView::AssertValid();
}

void CModelessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CModelessDoc* CModelessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModelessDoc)));
	return (CModelessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CModelessView message handlers

void CModelessView::OnModifyDisplaymodelessdialog() 
{
	CModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Create and initialize the dialog box object.
	// It must be persistent (not stack-based).
	m_pDlg = new CListWithItemDataDlg(this);
	m_pDlg->m_color = pDoc->GetColor();
	m_pDlg->m_phrase = pDoc->GetPhrase();
	m_pDlg->Create(IDD_PHRASE_MODELESS);

	// The call to Create has caused DDX to occur.
	// Everything's done, show the window. Note that the
	// DB itself has its visible property set to false.
	m_pDlg->ShowWindow(SW_RESTORE);
}

LRESULT CModelessView::MyMessageHandler(WPARAM wParam, LPARAM lParam)
{
	CModelessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	switch (wParam)
	{
		case ML_APPLY:
			pDoc->SetPhrase(m_pDlg->m_phrase);
			pDoc->SetColor(m_pDlg->m_color);
			Invalidate();
			break;

		case ML_CANCEL:
			// The dialog box's own code will properly destroy
			// the object, but it's important that this class
			// set its pointer to the dialog box to 0.
			m_pDlg = 0;
	}
	return TRUE;
}

void CModelessView::OnUpdateModifyDisplaymodelessdialog(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(0 == m_pDlg);
}
