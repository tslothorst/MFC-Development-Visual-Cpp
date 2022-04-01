// SpinButton.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SpinButton.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp

BEGIN_MESSAGE_MAP(CSpinButtonApp, CWinApp)
	//{{AFX_MSG_MAP(CSpinButtonApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp construction

CSpinButtonApp::CSpinButtonApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSpinButtonApp object

CSpinButtonApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp initialization

BOOL CSpinButtonApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// This application has no document templates. To create the main
	// window, this code creates a new frame window object and then
	// sets it as the application's main window object.

	CRuntimeClass* pClass = RUNTIME_CLASS(CMainFrame);
	CFrameWnd* pFrame = (CFrameWnd*) pClass->CreateObject();
	ASSERT_KINDOF(CFrameWnd, pFrame);
	m_pMainWnd = pFrame;

	// load the frame against an empty context

	CCreateContext context;

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
         NULL, &context);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp message handlers

void CSpinButtonApp::OnFileNew() 
{
	CString strUntitled;
	CFrameWnd* pFrameWnd = DYNAMIC_DOWNCAST(CFrameWnd, m_pMainWnd);
	if (pFrameWnd != NULL)
	{
		//TODO: close and destroy any file-specific data you've got
		// in memory. Once done, execute the following if statement
		// to reset the title of the frame window.

		if (strUntitled.LoadString(AFX_IDS_UNTITLED))
			pFrameWnd->UpdateFrameTitleForDocument(strUntitled);
		else
			pFrameWnd->UpdateFrameTitleForDocument(NULL);
	}
}

void CSpinButtonApp::OnFileOpen() 
{
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		//TODO: Add your file-open code here using the filename
		// returned dlg.GetFilePath()

		//TODO: if your loading code is successful, execute these lines
		// to set the title of the frame window to match your file name
		CFrameWnd* pFrameWnd = DYNAMIC_DOWNCAST(CFrameWnd, m_pMainWnd);
		pFrameWnd->UpdateFrameTitleForDocument(dlg.GetFileTitle());
	}
}	

void CSpinButtonApp::OnFileSave() 
{
	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
		SaveFile(dlg.GetPathName());
	}
}

void CSpinButtonApp::OnFileSaveAs() 
{
	// prompt the user for a filename for saving

	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
		CFrameWnd* pFrameWnd = DYNAMIC_DOWNCAST(CFrameWnd, m_pMainWnd);

		if (SaveFile(dlg.GetPathName()))
		{
			pFrameWnd->UpdateFrameTitleForDocument(dlg.GetFileTitle());

			//TODO: Add your file-save code here using the filename
			// returned dlg.GetFilePath()
		}
	}
}

BOOL CSpinButtonApp::SaveFile(LPCTSTR pstrPathName)
{
	// TODO: Insert code to handle your save logic here
	// return TRUE for success or FALSE for failure

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CSpinButtonApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CSpinButtonApp commands
