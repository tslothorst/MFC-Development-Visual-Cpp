// UseCalView.h : interface of the CUseCalView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "calendar.h"
//}}AFX_INCLUDES

#if !defined(AFX_USECALVIEW_H__297106D1_8758_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_USECALVIEW_H__297106D1_8758_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUseCalView : public CFormView
{
protected: // create from serialization only
	CUseCalView();
	DECLARE_DYNCREATE(CUseCalView)

public:
	//{{AFX_DATA(CUseCalView)
	enum { IDD = IDD_USECAL_FORM };
	CCalendar	m_CalControl;
	//}}AFX_DATA

// Attributes
public:
	CUseCalDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseCalView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseCalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseCalView)
	afx_msg void OnCalendarShowcurrentdate();
	afx_msg void OnCalendarSetbackcolor();
	afx_msg void OnCalendarToggletitle();
	afx_msg void OnDblClickCalendarctrl();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseCalView.cpp
inline CUseCalDoc* CUseCalView::GetDocument()
   { return (CUseCalDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECALVIEW_H__297106D1_8758_11D1_818D_00AA006C270F__INCLUDED_)
