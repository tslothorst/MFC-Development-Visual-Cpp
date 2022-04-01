// OLEEmployeeView.h : interface of the COLEEmployeeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEEMPLOYEEVIEW_H__776051CD_C7EE_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEEMPLOYEEVIEW_H__776051CD_C7EE_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COLEEmployeeSet;



class COLEEmployeeView : public COleDBRecordView
{
protected: // create from serialization only
	COLEEmployeeView();
	DECLARE_DYNCREATE(COLEEmployeeView)

public:
	//{{AFX_DATA(COLEEmployeeView)
	enum { IDD = IDD_OLEEMPLOYEE_FORM };
	COLEEmployeeSet* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	COLEEmployeeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEEmployeeView)
	public:
	virtual CRowset* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEEmployeeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEEmployeeView)
	afx_msg void OnRecordDelete();
	afx_msg void OnRecordCommit();
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordClear();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	//}}AFX_MSG
	afx_msg void OnUpdateDelete(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OLEEmployeeView.cpp
inline COLEEmployeeDoc* COLEEmployeeView::GetDocument()
   { return (COLEEmployeeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEMPLOYEEVIEW_H__776051CD_C7EE_11D1_8582_00AA006C20E3__INCLUDED_)
