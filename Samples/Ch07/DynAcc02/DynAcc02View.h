// DynAcc02View.h : interface of the CDynAcc02View class
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

class CDynAcc02View : public CFormView
{
protected: // create from serialization only
	CDynAcc02View();
	DECLARE_DYNCREATE(CDynAcc02View)

public:
	//{{AFX_DATA(CDynAcc02View)
	enum{ IDD = IDD_DYNACC02_FORM };

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDynAcc02Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynAcc02View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynAcc02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString m_cmd_str;
	CSession m_session;
	CDataSourceDlg m_datasourceDlg;
	CEnumDlg m_enumDlg;
	CTablesDlg	m_tablesDlg;
	CColumnsDlg m_columnsDlg;
	void RetrieveRecords();
	int m_RecCount;
	CListBox *m_plbData;
	//{{AFX_MSG(CDynAcc02View)
	afx_msg void OnFileOpen();
	afx_msg void OnRecordFst();
	afx_msg void OnRecordLst();
	afx_msg void OnRecordNxt();
	afx_msg void OnRecordPrv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

struct Field
{
	void *pField;
	DBTYPE ColType;
};

#ifndef _DEBUG  // debug version in DynAcc02View.cpp
inline CDynAcc02Doc* CDynAcc02View::GetDocument()
   { return (CDynAcc02Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01VIEW_H__C1A311ED_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
