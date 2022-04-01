// OledbAppView.h : interface of the COledbAppView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBAPPVIEW_H__95BFF76E_0C18_11D2_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEDBAPPVIEW_H__95BFF76E_0C18_11D2_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COledbAppSet;

class COledbAppView : public COleDBRecordView
{
protected: // create from serialization only
	COledbAppView();
	DECLARE_DYNCREATE(COledbAppView)

public:
	//{{AFX_DATA(COledbAppView)
	enum{ IDD = IDD_OLEDBAPP_FORM };
	COledbAppSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	COledbAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COledbAppView)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COledbAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COledbAppView)
		afx_msg void OnRecordPrev();
		afx_msg void OnRecordNext();
		afx_msg void OnRecordClear();
		afx_msg void OnRecordAdd();
		afx_msg void OnRecordDelete();
		afx_msg void OnRecordCommit();
	afx_msg void OnUpdateRecordDelete(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OledbAppView.cpp
inline COledbAppDoc* COledbAppView::GetDocument()
   { return (COledbAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBAPPVIEW_H__95BFF76E_0C18_11D2_8582_00AA006C20E3__INCLUDED_)
