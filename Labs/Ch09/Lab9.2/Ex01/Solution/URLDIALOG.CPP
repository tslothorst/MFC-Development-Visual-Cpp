// URLDialog.cpp : implementation file
//

#include "stdafx.h"
#include "IC_2.h"

#include "URLDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUrlDialog dialog


CUrlDialog::CUrlDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CUrlDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUrlDialog)
	m_Server = _T("");
	m_Object = _T("");
	//}}AFX_DATA_INIT
}


void CUrlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUrlDialog)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUrlDialog, CDialog)
	//{{AFX_MSG_MAP(CUrlDialog)
	ON_BN_CLICKED(IDC_PARSE, OnParse)
	ON_EN_CHANGE(IDC_EDIT_URL, OnChangeEditUrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUrlDialog message handlers

void CUrlDialog::OnParse() 
{
	CString url;
	CEdit * ce = (CEdit *)GetDlgItem(IDC_EDIT_URL);
	
	ce->GetWindowText(url);
	
	// Parse the URL and place its 4 components into the appropriate variables
	AfxParseURL(url, m_ServerType, m_Server, m_Object, m_Port);

	// Display the 4 components in the static controls on the dialog box.
	CStatic * cs = (CStatic *)GetDlgItem(IDC_SERVER);
	cs->SetWindowText(m_Server);

	cs = (CStatic *)GetDlgItem(IDC_OBJECT);
	cs->SetWindowText(m_Object);

	cs = (CStatic *)GetDlgItem(IDC_SERVICE_TYPE);
	switch (m_ServerType)
	{
		case AFX_INET_SERVICE_FTP:
			cs->SetWindowText("FTP");
			break;
		case AFX_INET_SERVICE_HTTP:
			cs->SetWindowText("HTTP");
			break;
		case AFX_INET_SERVICE_GOPHER:
			cs->SetWindowText("GOPHER");
			break;
		case AFX_INET_SERVICE_FILE:
			cs->SetWindowText("FILE");
			break;
		case AFX_INET_SERVICE_MAILTO:
			cs->SetWindowText("MAILTO");
			break;
		case AFX_INET_SERVICE_NEWS:
			cs->SetWindowText("NEWS");
			break;
		case AFX_INET_SERVICE_NNTP:
			cs->SetWindowText("NNTP");
			break;
		case AFX_INET_SERVICE_TELNET:
			cs->SetWindowText("TELNET");
			break;
		case AFX_INET_SERVICE_WAIS:
			cs->SetWindowText("WAIS");
			break;
		case AFX_INET_SERVICE_MID:
			cs->SetWindowText("MID");
			break;
		case AFX_INET_SERVICE_CID:
			cs->SetWindowText("CID");
			break;
		case AFX_INET_SERVICE_PROSPERO:
			cs->SetWindowText("PROSPERO");
			break;
		case AFX_INET_SERVICE_AFS:
			cs->SetWindowText("AFS");
			break;
		case AFX_INET_SERVICE_UNK:
			cs->SetWindowText("Unknown");
	}

	// convert the port number to a string.
	char buff[10];
	itoa(m_Port, buff, 10);
	cs = (CStatic *)GetDlgItem(IDC_PORT);
	cs->SetWindowText(buff);

	// Finally, enable the OK button,
	CButton * cb = (CButton *)GetDlgItem(IDOK);
	cb->EnableWindow(TRUE);

	// and disable the Parse button.
	cb = (CButton *)GetDlgItem(IDC_PARSE);
	cb->EnableWindow(FALSE);

}

BOOL CUrlDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Initially, the OK button and Parse buttons are disabled
	CButton * cb = (CButton *)GetDlgItem(IDOK);
	cb->EnableWindow(FALSE);
	cb = (CButton *)GetDlgItem(IDC_PARSE);
	cb->EnableWindow(FALSE);

	CEdit * ce = (CEdit *)GetDlgItem(IDC_EDIT_URL);

	// The default server will be on this same machine.
	unsigned long len = MAX_COMPUTERNAME_LENGTH + 1;
	char buff[MAX_COMPUTERNAME_LENGTH + 1];
	
	GetComputerName(buff,  &len);
	strlwr(buff);
	
	CString sMachineName("microsoft.com");
	CString sHTTP = "http://";
	CString sScripts = "/";
	
	// Assemble the 3 pieces.
	CString sURL = sHTTP + sMachineName + sScripts;
	int textlen = sURL.GetLength();
	ce->SetWindowText(sURL);

	// Place the cursor at the end of the supplied string.
	ce->SetSel(textlen, textlen);
	ce->SetFocus();

	// return FALSE since I set focus.
	return FALSE;
}

void CUrlDialog::OnChangeEditUrl() 
{
	CButton * cb = (CButton *)GetDlgItem(IDC_PARSE);
	cb->EnableWindow(TRUE);
}
