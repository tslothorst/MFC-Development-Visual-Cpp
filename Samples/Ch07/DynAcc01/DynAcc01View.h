// DynAcc01View.h : interface of the CDynAcc01View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNACC01VIEW_H__AF74E68D_C883_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_DYNACC01VIEW_H__AF74E68D_C883_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynAcc01View : public CFormView
{
protected: // create from serialization only
	CDynAcc01View();
	DECLARE_DYNCREATE(CDynAcc01View)

public:
	//{{AFX_DATA(CDynAcc01View)
	enum { IDD = IDD_DYNACC01_FORM };
	//}}AFX_DATA

// Attributes
public:
	CDynAcc01Doc* GetDocument();
	long	m_EmployeeID;
	char	m_Address[101];
	char	m_Name[101];

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynAcc01View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynAcc01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void Refreshdata();
	CCommand<CDynamicAccessor> DynamicAccessor;
	CDataSource m_DataSource;
	CSession	m_session;
	int m_ColCnt;
	void *m_pVoid[3];
	//{{AFX_MSG(CDynAcc01View)
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynAcc01View.cpp
inline CDynAcc01Doc* CDynAcc01View::GetDocument()
   { return (CDynAcc01Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNACC01VIEW_H__AF74E68D_C883_11D1_8582_00AA006C20E3__INCLUDED_)
