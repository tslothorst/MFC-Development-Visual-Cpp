// OLEDBDynAccAppView.h : interface of the COLEDBDynAccAppView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANACC01VIEW_H__C1A311ED_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_MANACC01VIEW_H__C1A311ED_C93E_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EnumDlg.h"
#include "DataSourceDlg.h"
#include "TablesDlg.h"
#include "ColumnsDlg.h"

class COLEDBDynAccAppView : public CFormView
{
protected: // create from serialization only
	COLEDBDynAccAppView();
	DECLARE_DYNCREATE(COLEDBDynAccAppView)

public:
	//{{AFX_DATA(COLEDBDynAccAppView)
	enum{ IDD = IDD_MANACC_FORM };

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	COLEDBDynAccAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBDynAccAppView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDBDynAccAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void RetrieveRecords();
	CString m_cmd_str;
	CSession m_session;
	CDataSourceDlg m_datasourceDlg;
	CEnumDlg m_enumDlg;
	CTablesDlg	m_tablesDlg;
	CColumnsDlg m_columnsDlg;
	CListBox *m_plbData;
	//{{AFX_MSG(COLEDBDynAccAppView)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

struct Field
{
	void *pField;
	DBTYPE ColType;
};

#ifndef _DEBUG  // debug version in COLEDBDynAccAppView.cpp
inline COLEDBDynAccAppDoc* COLEDBDynAccAppView::GetDocument()
   { return (COLEDBDynAccAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01VIEW_H__C1A311ED_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
