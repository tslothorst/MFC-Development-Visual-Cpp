// FormView.cpp : implementation of the CMyFormView class
//

#include "stdafx.h"
#include "Form.h"

#include "FormDoc.h"
#include "FormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyFormView

IMPLEMENT_DYNCREATE(CMyFormView, CFormView)

BEGIN_MESSAGE_MAP(CMyFormView, CFormView)
	//{{AFX_MSG_MAP(CMyFormView)
	ON_EN_CHANGE(IDC_WELCOME, OnChangeWelcome)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RED, IDC_BLUE, OnColor)
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyFormView construction/destruction

CMyFormView::CMyFormView()
	: CFormView(CMyFormView::IDD)
{
	//{{AFX_DATA_INIT(CMyFormView)
	m_dlgPhrase = _T("");
	m_blue = FALSE;
	m_green = FALSE;
	m_red = FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
}

CMyFormView::~CMyFormView()
{
}

void CMyFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyFormView)
	DDX_Text(pDX, IDC_WELCOME, m_dlgPhrase);
	DDX_Check(pDX, IDC_BLUE, m_blue);
	DDX_Check(pDX, IDC_GREEN, m_green);
	DDX_Check(pDX, IDC_RED, m_red);
	//}}AFX_DATA_MAP
}

BOOL CMyFormView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyFormView printing

BOOL CMyFormView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMyFormView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMyFormView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CMyFormView::OnPrint(CDC* pDC, CPrintInfo*)
{
}

/////////////////////////////////////////////////////////////////////////////
// CMyFormView diagnostics

#ifdef _DEBUG
void CMyFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMyFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFormDoc* CMyFormView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormDoc)));
	return (CFormDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyFormView message handlers

void CMyFormView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// Obtain a pointer to the document object.
	// Note that OnDraw isn't used, since controls in a dialog
	// box can paint themselves.
	CFormDoc * pDoc = (CFormDoc *)GetDocument();

	// Set the dialog class's member variables to those in the document.
	m_dlgPhrase = pDoc->GetPhrase();
	m_blue = GetBValue(pDoc->GetColor()) == 255;
	m_green = GetGValue(pDoc->GetColor()) == 255;
	m_red = GetRValue(pDoc->GetColor()) == 255;
	
	// Cause DDX to occur from dialog object to dialog box.
	UpdateData(FALSE);
}

void CMyFormView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// These next 2 calls make the main frame exactly the size
	// of form object.
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

void CMyFormView::OnChangeWelcome() 
{
	// Cause DDX to occur from dialog box to dialog object.
	UpdateData(TRUE);

	// Set the document's member variables to those in the dialog object.
	CFormDoc * pDoc = (CFormDoc *)GetDocument();
	pDoc->SetPhrase(m_dlgPhrase);
}

void CMyFormView::OnColor(UINT nID) 
{
	// Cause DDX to occur from dialog box to dialog object.
	UpdateData(TRUE);

	// Determine the state of the color check boxes, build an RGB
	// value, and store it back into the document.
	int r, g, b;
	r = m_red ? 255 : 0;
	g = m_green ? 255 : 0;
	b = m_blue ? 255 : 0;

	CFormDoc * pDoc = (CFormDoc *)GetDocument();
	pDoc->SetColor(RGB(r,g,b));

	// Now, invalidate the edit control so it repaints itself.
	CWnd * pWnd = GetDlgItem(IDC_WELCOME);
	pWnd->Invalidate();
}

HBRUSH CMyFormView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// Note that this function is called before all controls on
	// the form are painted. The intent is to only change the
	// color of the edit box, so it's necessary to clarify for
	// which control this function is being called.
	if (GetDlgItem(IDC_WELCOME)->m_hWnd == pWnd->m_hWnd)
	{
		CFormDoc * pDoc = (CFormDoc *)GetDocument();
		pDC->SetTextColor(pDoc->GetColor());
	}
	
	return hbr;
}
