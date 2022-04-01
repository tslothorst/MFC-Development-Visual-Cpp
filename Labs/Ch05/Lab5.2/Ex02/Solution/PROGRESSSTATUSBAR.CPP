// ProgressStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "diff.h"
#include "ProgressStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar

CProgressStatusBar::CProgressStatusBar()
{
	m_bProgressMode = FALSE;
	m_nProgressCtrlWidth = PROGRESS_CTRL_CX;
}

CProgressStatusBar::~CProgressStatusBar()
{
}


BEGIN_MESSAGE_MAP(CProgressStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CProgressStatusBar)
	ON_WM_CREATE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CProgressStatusBar message handlers

void CProgressStatusBar::SetProgressCtrlWidth(int nWidth)
{
	m_nProgressCtrlWidth = nWidth;
}

void CProgressStatusBar::RecalcProgressDisplay()
{
	//	Adjust the postions of the Label and Progress Controls
	//	Place the Label Control to the right of the 
	//	Progress Control
	//
	//		[Progress Control] Label Text... 
	CRect ControlRect;
	CRect ClientRect;
	GetClientRect(&ClientRect);
	ControlRect = ClientRect; 
	
	//	First the Progress bar
	ControlRect.left += X_MARGIN;
	ControlRect.right = ControlRect.left + m_nProgressCtrlWidth;
	ControlRect.top += Y_MARGIN;
	ControlRect.bottom -= Y_MARGIN;
	
	m_ProgressCtrl.MoveWindow(ControlRect, FALSE);
	
	//	Then the text label using the rest of the status
	//	bars client area
	ControlRect.left = ControlRect.right + X_MARGIN;
	ControlRect.right = ClientRect.right - X_MARGIN;

	m_ProgressLabel.MoveWindow(ControlRect, FALSE);
}

void CProgressStatusBar::SetProgressLabel(LPCSTR lpszProgressLabel)
{
	m_ProgressLabel.SetWindowText(lpszProgressLabel);

	//  If were currently displaying progress, update 
	//	placement of label and progress control
	
	if(m_bProgressMode)
	{
		RecalcProgressDisplay();
		Invalidate();
		UpdateWindow();
	}
}

void CProgressStatusBar::ShowProgressDisplay(BOOL bShow)
{
	m_bProgressMode = bShow;
	if(m_bProgressMode)
	{
		RecalcProgressDisplay();
	}
	m_ProgressLabel.ShowWindow(m_bProgressMode ? SW_SHOW :
												SW_HIDE);
	m_ProgressCtrl.ShowWindow (m_bProgressMode ? SW_SHOW :
												SW_HIDE);
	Invalidate();
	UpdateWindow();
}

int CProgressStatusBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatusBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// 	Create the Progress Control - we'll calculate its size and
	//	position later - in response to a ShowProgressDisplay() call.
	if(!m_ProgressCtrl.Create(	0, 				// Style - Don't Show Position or Percent
								CRect(0,0,0,0),	// Initial position
								this,			// Parent
								0))				// Child ID
	{
		return -1;
	}

	// 	Create the Progress Label - we'll calculate its size and
	//	position later - in response to a ShowProgressDisplay() call.
	if(!m_ProgressLabel.Create(	NULL,				// Text
								WS_CHILD|SS_LEFT, 	// Style
								CRect(0,0,0,0),		// Initial position
								this))				// Parent
	{
		return -1;
	}
	
	//	Use the same font as the Status Bar
	m_ProgressLabel.SetFont(GetFont());
	
	return 0;
}

void CProgressStatusBar::OnPaint() 
{
	//	If we were displaying the progress control, then we
 	//	need to handle painting of the Status Bar,
	//	otherwise defer to the base class
	if(!m_bProgressMode)
	{
		CStatusBar::OnPaint();
	}
}
