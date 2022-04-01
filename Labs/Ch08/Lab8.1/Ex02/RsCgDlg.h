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
	ADO_VARIABLE_LENGTH_ENTRY2(5, adVarChar, m_szAddress, sizeof(m_szAddress), lAddressStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(6, adVarChar, m_szCity, sizeof(m_szCity), lCityStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(8, adVarChar, m_szCountry, sizeof(m_szCountry), lCountryStatus, FALSE)
	ADO_FIXED_LENGTH_ENTRY(1, adInteger, m_lEmployeeID, lEmployeeIDStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(3, adVarChar, m_szFirstName, sizeof(m_szFirstName), lFirstNameStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(9, adVarChar, m_szHomePhone, sizeof(m_szHomePhone), lHomePhoneStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(2, adVarChar, m_szLastName, sizeof(m_szLastName), lLastNameStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(7, adVarChar, m_szRegion, sizeof(m_szRegion), lRegionStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(4, adVarChar, m_szTitle, sizeof(m_szTitle), lTitleStatus, FALSE)
END_ADO_BINDING()

protected:
	CHAR m_szAddress[61];
	ULONG lAddressStatus;
	CHAR m_szCity[16];
	ULONG lCityStatus;
	CHAR m_szCountry[16];
	ULONG lCountryStatus;
	LONG m_lEmployeeID;
	ULONG lEmployeeIDStatus;
	CHAR m_szFirstName[11];
	ULONG lFirstNameStatus;
	CHAR m_szHomePhone[25];
	ULONG lHomePhoneStatus;
	CHAR m_szLastName[21];
	ULONG lLastNameStatus;
	CHAR m_szRegion[16];
	ULONG lRegionStatus;
	CHAR m_szTitle[31];
	ULONG lTitleStatus;
};

//
// TODO : These definitions should be moved to the resource header.
//
#define ID_BTN_MOVEPREVIOUS			201
#define ID_BTN_MOVENEXT				202
#define ID_BTN_MOVELAST				203
#define ID_BTN_MOVEFIRST				204
#define IDC_STATIC_ADDRESS		1005
#define IDC_EDIT_ADDRESS		2005
#define IDC_STATIC_CITY		1006
#define IDC_EDIT_CITY		2006
#define IDC_STATIC_COUNTRY		1008
#define IDC_EDIT_COUNTRY		2008
#define IDC_STATIC_EMPLOYEEID		1001
#define IDC_EDIT_EMPLOYEEID		2001
#define IDC_STATIC_FIRSTNAME		1003
#define IDC_EDIT_FIRSTNAME		2003
#define IDC_STATIC_HOMEPHONE		1009
#define IDC_EDIT_HOMEPHONE		2009
#define IDC_STATIC_LASTNAME		1002
#define IDC_EDIT_LASTNAME		2002
#define IDC_STATIC_REGION		1007
#define IDC_EDIT_REGION		2007
#define IDC_STATIC_TITLE		1004
#define IDC_EDIT_TITLE		2004


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
	CString m_strDlgCity;
	CString m_strDlgCountry;
	LONG m_lDlgEmployeeID;
	CString m_strDlgFirstName;
	CString m_strDlgHomePhone;
	CString m_strDlgLastName;
	CString m_strDlgRegion;
	CString m_strDlgTitle;
	//}}AFX_DATA
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRsCgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void BlankForm();

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
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnUpdate();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !_RsCgDlg_H_
