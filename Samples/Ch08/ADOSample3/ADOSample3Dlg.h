// ADOSample3Dlg.h : header file
//

#if !defined(AFX_ADOSample3DLG_H__06FEA287_C558_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_ADOSample3DLG_H__06FEA287_C558_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#import "C:\PROGRAM FILES\COMMON FILES\SYSTEM\ADO\MSADO15.DLL" rename_namespace("ADOCG") rename("EOF", "EndOfFile")
using namespace ADOCG;
#include "icrsint.h"
#include "FilterDlg.h"	
  


/////////////////////////////////////////////////////////////////////////////
// CADOSample3Dlg dialog
class CCustomRs : 
	public CADORecordBinding
{
BEGIN_ADO_BINDING(CCustomRs)
	ADO_FIXED_LENGTH_ENTRY(1, adInteger, m_lID, lIDStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(2, adVarChar, m_szName, sizeof(m_szName), lNameStatus, FALSE)
	ADO_VARIABLE_LENGTH_ENTRY2(3, adVarChar, m_szAddress, sizeof(m_szAddress), lAddressStatus, FALSE)
END_ADO_BINDING()

protected:
	LONG m_lID;
	ULONG lIDStatus;
	CHAR m_szName[51];
	ULONG lNameStatus;
	CHAR m_szAddress[51];
	ULONG lAddressStatus;
};


class CADOSample3Dlg : public CDialog, public CCustomRs
{
// Construction
public:
	CFilterDlg FilterDlg;
	~CADOSample3Dlg();
	CADOSample3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CADOSample3Dlg)
	enum { IDD = IDD_ADOSAMPLE3_DIALOG };
	long	m_lDlgID;
	CString	m_strDlgName;
	CString	m_strDlgAddress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOSample3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void BlankForm();
	void RefreshBoundData();
	void GenerateError(HRESULT hr, PWSTR pwszDescription);
	HICON m_hIcon;
	_RecordsetPtr m_pRs;

	CString m_strConnection;
	CString m_strCmdText;

	// Generated message map functions
	//{{AFX_MSG(CADOSample3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnMovefirst();
	afx_msg void OnBtnMovelast();
	afx_msg void OnBtnMovenext();
	afx_msg void OnBtnMoveprevious();
	afx_msg void OnSetFilter();
	afx_msg void OnResetFilter();
	afx_msg void OnFindRecordForward();
	afx_msg void OnFindRecordReverse();
	afx_msg void OnAddRecord();
	afx_msg void OnDelRecord();
	afx_msg void OnEditRecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSample3DLG_H__06FEA287_C558_11D1_8582_00AA006C20E3__INCLUDED_)
