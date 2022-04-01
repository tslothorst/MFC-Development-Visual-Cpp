#ifndef _RsCgDlg_H_
#define _RsCgDlg_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "resource.h"
// CG : In order to use this code against a different version of ADO, the appropriate
// ADO library needs to be used in the #import statement
#import "C:\PROGRAM FILES\COMMON FILES\SYSTEM\ADO\MSADO15.DLL" rename_namespace("ADOCG") rename("EOF", "EndOfFile")
using namespace ADOCG;
#include "icrsint.h"

// RsCgDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCustomRs class

class CCustomRs : 
	public CADORecordBinding
{
BEGIN_ADO_BINDING(CCustomRs)
	ADO_VARIABLE_LENGTH_ENTRY2(3, adVarChar, m_szAddress, sizeof(m_szAddress), lAddressStatus, FALSE)
	ADO_FIXED_LENGTH_ENTRY(1, adInteger, m_lEmployeeID, lEmployeeIDStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(2, adVarChar, m_szName, sizeof(m_szName), lNameStatus, FALSE)
END_ADO_BINDING()

protected:
	CHAR m_szAddress[51];
	ULONG lAddressStatus;
	LONG m_lEmployeeID;
	ULONG lEmployeeIDStatus;
	CHAR m_szName[51];
	ULONG lNameStatus;
};

//
// TODO : These definitions should be moved to the resource header.
//
#define ID_BTN_MOVEPREVIOUS			201
#define ID_BTN_MOVENEXT				202
#define ID_BTN_MOVELAST				203
#define ID_BTN_MOVEFIRST				204
#define IDC_STATIC_ADDRESS		1001
#define IDC_EDIT_ADDRESS		2001
#define IDC_STATIC_EMPLOYEEID		1002
#define IDC_EDIT_EMPLOYEEID		2002
#define IDC_STATIC_NAME		1003
#define IDC_EDIT_NAME		2003


/////////////////////////////////////////////////////////////////////////////
// CRsCgDlg dialog

class CRsCgDlg : 
	public CDialog, 
	public CCustomRs
{
// Construction
public:
	CRsCgDlg(CWnd* pParent = NULL);
	~CRsCgDlg();

	BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(CRsCgDlg)
	enum { IDD = CG_IDD_RECORDSET };
	CString m_strDlgAddress;
	LONG m_lDlgEmployeeID;
	CString m_strDlgName;
	//}}AFX_DATA
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRsCgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	void RefreshBoundData();
	void GenerateError(HRESULT hr, PWSTR pwszDescription);

	_RecordsetPtr m_pRs;

	CString m_strConnection;
	CString m_strCmdText;

	// Generated message map functions
	//{{AFX_MSG(CRsCgDlg)
	afx_msg void OnBtnMoveFirst();
	afx_msg void OnBtnMoveLast();
	afx_msg void OnBtnMoveNext();
	afx_msg void OnBtnMovePrevious();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !_RsCgDlg_H_
