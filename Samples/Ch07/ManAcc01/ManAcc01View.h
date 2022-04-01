// ManAcc01View.h : interface of the CManAcc01View class
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

class CManAcc01View : public CFormView
{
protected: // create from serialization only
	CManAcc01View();
	DECLARE_DYNCREATE(CManAcc01View)

public:
	//{{AFX_DATA(CManAcc01View)
	enum{ IDD = IDD_MANACC01_FORM };

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CManAcc01Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManAcc01View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CManAcc01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int m_ColsSelected;
	int m_RecCount;
	CString m_cmd_str;
	CSession m_session;
	CDataSourceDlg m_datasourceDlg;
	CEnumDlg m_enumDlg;
	CTablesDlg	m_tablesDlg;
	CColumnsDlg m_columnsDlg;
	void RetrieveRecords();
	CListBox *m_plbData;
	//{{AFX_MSG(CManAcc01View)
	afx_msg void OnFileOpen();
	afx_msg void OnRecordFst();
	afx_msg void OnRecordLst();
	afx_msg void OnRecordNxt();
	afx_msg void OnRecordPrv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

struct MyBind
{
	MyBind()
	{
		memset(this, 0, sizeof(*this));
	}

	TCHAR   szValue[40];
	DWORD   dwStatus;
};

#ifndef _DEBUG  // debug version in ManAcc01View.cpp
inline CManAcc01Doc* CManAcc01View::GetDocument()
   { return (CManAcc01Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01VIEW_H__C1A311ED_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
