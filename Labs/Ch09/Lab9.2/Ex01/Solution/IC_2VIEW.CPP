// IC_2View.cpp : implementation of the CIC_2View class
//

#include "stdafx.h"
#include "IC_2.h"

#include "IC_2Doc.h"
#include "IC_2View.h"

#include "UrlDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIC_2View

IMPLEMENT_DYNCREATE(CIC_2View, CScrollView)

BEGIN_MESSAGE_MAP(CIC_2View, CScrollView)
	//{{AFX_MSG_MAP(CIC_2View)
	ON_COMMAND(ID_INTERNET_CREATESESSION, OnInternetCreateSession)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_CREATESESSION, OnUpdateInternetCreateSession)
	ON_COMMAND(ID_INTERNET_GETCONNECTION, OnInternetGetConnection)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_GETCONNECTION, OnUpdateInternetGetConnection)
	ON_COMMAND(ID_INTERNET_CLOSESESSION, OnInternetCloseSession)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_CLOSESESSION, OnUpdateInternetCloseSession)
	ON_COMMAND(ID_INTERNET_SENDREQUEST, OnInternetSendRequest)
	ON_COMMAND(ID_INTERNET_OPENREQUEST, OnInternetOpenRequest)
	ON_COMMAND(ID_INTERNET_READINFORMATION, OnInternetReadInformation)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_OPENREQUEST, OnUpdateInternetOpenRequest)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_SENDREQUEST, OnUpdateInternetSendRequest)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_READINFORMATION, OnUpdateInternetReadInformation)
	ON_COMMAND(ID_INTERNET_OBTAINURL, OnInternetObtainUrl)
	ON_COMMAND(ID_INTERNET_ALLTHEABOVE, OnInternetAllTheAbove)
	ON_UPDATE_COMMAND_UI(ID_INTERNET_ALLTHEABOVE, OnUpdateInternetAllTheAbove)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIC_2View construction/destruction

CIC_2View::CIC_2View()
{
}

CIC_2View::~CIC_2View()
{
	CloseSession();
}

BOOL CIC_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CIC_2View drawing

void CIC_2View::OnDraw(CDC* pDC)
{
	CIC_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Do nothing if there's nothing to display.
	if (pDoc->m_WebPage.IsEmpty() == TRUE)
		return;

	int BeginningRow, EndingRow, i, x, y;
	TEXTMETRIC tm;
	CPoint pt;
	CRect rect;

	pDC->GetTextMetrics(&tm);
	pt = GetScrollPosition();
  
	// In the interest of efficiency, only display as many rows of the
	// retrieved document as the view's height will allow. This requires
	// knowing 2 things: the current vertical scroll position...
	BeginningRow = pt.y / tm.tmHeight;

	// and the current height of the view window, which determines
	// how many 'rows' can be displayed.
	GetClientRect(&rect);
	EndingRow = BeginningRow + rect.Height() / tm.tmHeight;
	
	// However, don't attempt to display more lines than exist
	// in the document.
	int linecount = pDoc->m_WebPage.GetCount();
	if (EndingRow > linecount)
		EndingRow = linecount;
		
	x = 0;
	y = BeginningRow * tm.tmHeight;
	POSITION pos = pDoc->m_WebPage.FindIndex(BeginningRow);
	for (i = BeginningRow; i <= EndingRow; i++, y += tm.tmHeight)
	{
		if (!pos) break;
		CString & s = pDoc->m_WebPage.GetNext(pos);
		pDC->TabbedTextOut( x, y, s, 0, NULL, 0);
	}
	
}

// CIC_2View diagnostics

#ifdef _DEBUG
void CIC_2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CIC_2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CIC_2Doc* CIC_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIC_2Doc)));
	return (CIC_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CIC_2View message handlers
void CIC_2View::OnInternetObtainUrl() 
{
	CIC_2Doc* pDoc = GetDocument();

	CUrlDialog dlg;
	
	if (IDOK == dlg.DoModal())
	{
		pDoc->m_Object = dlg.m_Object;
		pDoc->m_Server = dlg.m_Server;
		pDoc->m_Port = dlg.m_Port;
		pDoc->m_ServerType = dlg.m_ServerType;
		m_processState = 0;
	}
}

void CIC_2View::OnInternetCreateSession() 
{
	// Member function to close any previous session.
	CloseSession();

	// Create a new session.
	m_pInternetSession = new CInternetSession;
	ASSERT(m_pInternetSession != NULL);

	// Update the state.
	m_processState++;
}

void CIC_2View::OnInternetGetConnection() 
{
	CIC_2Doc* pDoc = GetDocument();

	// Attempt to get an HTTP connection.
	try {
		m_pHttpConnection = m_pInternetSession->GetHttpConnection(pDoc->m_Server, pDoc->m_Port);
	}
	catch (CInternetException *e)
	{
		char buff[256];
		e->GetErrorMessage(buff,256);
		MessageBox(buff);
		e->Delete();
		return;
	}
	ASSERT(m_pHttpConnection != NULL);
	
	// Update the state.
	m_processState++;
}

void CIC_2View::OnInternetOpenRequest() 
{
	// Set some request flags.
	DWORD dwHttpRequestFlags = INTERNET_FLAG_EXISTING_CONNECT | INTERNET_FLAG_NO_AUTO_REDIRECT;

	CIC_2Doc* pDoc = GetDocument();

	// Open a GET request and get an Internet File handle to communicate through.
	m_pHttpFile = m_pHttpConnection->OpenRequest(CHttpConnection::HTTP_VERB_GET,
								pDoc->m_Object, 
								NULL, 1, NULL, NULL, dwHttpRequestFlags);

	if (NULL == m_pHttpFile)
	{
		CString s;
		s.Format ("An error occurred opening the request");
		MessageBox(s);
		return;
	}

	// Update the state.
	m_processState++;
}

void CIC_2View::OnInternetSendRequest() 
{
	// Initialize our request header.
	const TCHAR szHeaders[] =
		_T("Accept: text/*\r\nUser-Agent: IC_2\r\n");
	
	BOOL rc;

	// Send the request.
	try {
		rc = m_pHttpFile->AddRequestHeaders(szHeaders);
		rc = m_pHttpFile->SendRequest();
	}

	catch (CInternetException * e)
	{
		char buff[256];
		e->GetErrorMessage(buff,256);
		MessageBox(buff);
		e->Delete();
		return;
	}

	// Update the state.
	m_processState++;
}

void CIC_2View::OnInternetReadInformation() 
{
	char s[1024];
	CIC_2Doc* pDoc = GetDocument();

	//
	// Get the received header and prepend to view output.
	//
	DWORD bufsiz= 1024;
	if (m_pHttpFile->QueryInfo(HTTP_QUERY_RAW_HEADERS_CRLF, s, &bufsiz))
	{
		char * p = strtok(s, "\n\r");
		// Extract line at a time.
		while (p)
		{
			pDoc->m_WebPage.AddTail(p);
			p = strtok(NULL, "\n\r");
		}
		// Delimiter between header and body.
		pDoc->m_WebPage.AddTail("+=+=+=+=+=+=+=+=+=+ End of Header +=+=+=+=+=+=+=+=+=+=+=+=+=+");
	}

	//
	// Read body.
	//
	m_pHttpFile->SetReadBufferSize(4096);
		
	while(m_pHttpFile->ReadString(s, 1023))
	{
		// Extract a line at a time.
		char * p = strtok(s, "\n\r");
		while (p)
		{
			pDoc->m_WebPage.AddTail(p);
			p = strtok(NULL, "\n\r");
		}
	}
	
	// Have view repaint itself.
	pDoc->UpdateAllViews(NULL);

	// Update state.
	m_processState++;
}

// This is a shortcut way of calling all the 5 menu items.
void CIC_2View::OnInternetAllTheAbove() 
{
	this->SendMessage(WM_COMMAND, ID_INTERNET_CREATESESSION);
	this->SendMessage(WM_COMMAND, ID_INTERNET_GETCONNECTION);
	this->SendMessage(WM_COMMAND, ID_INTERNET_OPENREQUEST);
	this->SendMessage(WM_COMMAND, ID_INTERNET_SENDREQUEST);
	this->SendMessage(WM_COMMAND, ID_INTERNET_READINFORMATION);
}

void CIC_2View::OnInternetCloseSession() 
{
	// Clean up view and any objects that are lying around.
	CloseSession();

	// Clear the view.
	CIC_2Doc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);

	// Initialize the state.
	m_processState = -1;
}

void CIC_2View::OnUpdateInternetCreateSession(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 0);
}

void CIC_2View::OnUpdateInternetGetConnection(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 1);
}

void CIC_2View::OnUpdateInternetOpenRequest(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 2);
}

void CIC_2View::OnUpdateInternetSendRequest(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 3);
}

void CIC_2View::OnUpdateInternetReadInformation(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 4);
}

void CIC_2View::OnUpdateInternetAllTheAbove(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState == 0);
}

void CIC_2View::OnUpdateInternetCloseSession(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_processState > 0);
}

void CIC_2View::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	m_pInternetSession = NULL;
	m_pHttpConnection = NULL;
	m_pHttpFile = NULL;
	m_processState = -1;
}

BOOL CIC_2View::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// If we're scrolling in the vertical direction by use of the
	// thumbtack, we only want to scroll in units equal to a character's
	// height. nPos is adjusted so it's always equal to some multiple
	// of a character's height.
	if (SB_THUMBTRACK == HIBYTE(nScrollCode))
	{
		TEXTMETRIC tm;
		CClientDC dc(this);
		dc.GetTextMetrics(&tm);
		while ((nPos % tm.tmHeight) != 0)
			nPos--;
	}

	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}

void CIC_2View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CView::OnUpdate(pSender, lHint, pHint);
	SetScrollingAttributes();
}

void CIC_2View::SetScrollingAttributes()
{
	CIC_2Doc* pDoc = GetDocument();

	CSize sizeTotal, sizePage, sizeLine;

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	// Calculate the total size of this view
	sizeTotal.cx = 80 * tm.tmMaxCharWidth;
	
	// Just for grins, if there are no lines to be displayed,
	// I'll use the classic 25x80 display size.
	if (pDoc->m_WebPage.GetCount() == 0)
		sizeTotal.cy = 25 * tm.tmHeight;	 
	else
		sizeTotal.cy = pDoc->m_WebPage.GetCount() * tm.tmHeight;	 
	// Note: this value cannot exceed 32767

	// Scroll one letter in either direction when
	// clicking on a scroll bar's arrows.
	// Current page length when clicking in the vertical shaft.
	// 5 characters when clicking in the horizontal shaft.
	sizeLine.cx = tm.tmAveCharWidth;
	sizeLine.cy = tm.tmHeight;
	sizePage.cx = 5 * tm.tmAveCharWidth;
	sizePage.cy = 25 * tm.tmHeight;

	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}
void CIC_2View::CloseSession()
{
	if (m_pInternetSession != NULL)
	{
		m_pInternetSession->Close();
		delete m_pInternetSession;
		m_pInternetSession = NULL;
	}
	
	if (m_pHttpConnection != NULL)
	{
		m_pHttpConnection->Close();
		delete m_pHttpConnection;
		m_pHttpConnection = NULL;
	}

	if (m_pHttpFile != NULL)
	{
		m_pHttpFile->Close();
		delete m_pHttpFile;
		m_pHttpFile = NULL;
	}
	
	CIC_2Doc* pDoc = GetDocument();
	while (!pDoc->m_WebPage.IsEmpty()) 
	{
		CString String= pDoc->m_WebPage.RemoveHead();
	}

//	pDoc->m_WebPage.RemoveAll();

}


