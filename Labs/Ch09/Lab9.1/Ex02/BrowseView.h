// BrowseView.h : interface of the CBrowseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BROWSEVIEW_H__72DE4D4D_9252_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_BROWSEVIEW_H__72DE4D4D_9252_11D1_818D_00AA006C270F__INCLUDED_

#include "webbrowser2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBrowseView : public CView
{
protected: // create from serialization only
	CBrowseView();
	DECLARE_DYNCREATE(CBrowseView)

// Attributes
public:
	CBrowseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	CWebBrowser2* m_pBrowse;
	virtual ~CBrowseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBrowseView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BrowseView.cpp
inline CBrowseDoc* CBrowseView::GetDocument()
   { return (CBrowseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEVIEW_H__72DE4D4D_9252_11D1_818D_00AA006C270F__INCLUDED_)
