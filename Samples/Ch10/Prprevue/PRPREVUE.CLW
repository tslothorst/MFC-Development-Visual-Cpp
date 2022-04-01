; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "prprevue.h"
LastPage=0

ClassCount=6
Class1=CLinesDLG
Class2=CMainFrame
Class3=CPrintDoc
Class4=CPrintView
Class5=CPrintApp
Class6=CAboutDlg

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDR_DUMMY
Resource3=IDD_ABOUTBOX
Resource4=IDD_PRINTLINES_DIALOG

[CLS:CLinesDLG]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CPrintDoc]
Type=0
BaseClass=CDocument
HeaderFile=PrintDoc.h
ImplementationFile=PrintDoc.cpp

[CLS:CPrintView]
Type=0
BaseClass=CScrollView
HeaderFile=PrinView.h
ImplementationFile=PrinView.cpp

[CLS:CPrintApp]
Type=0
BaseClass=CWinApp
HeaderFile=PrPrevue.h
ImplementationFile=PrPrevue.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=PrPrevue.cpp
ImplementationFile=PrPrevue.cpp
LastObject=CAboutDlg

[DLG:IDD_PRINTLINES_DIALOG]
Type=1
Class=CLinesDLG
ControlCount=5
Control1=IDC_STATIC,static,1342308354
Control2=IDC_LINES,edit,1350631552
Control3=IDC_SPIN,msctls_updown32,1342177334
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_LINESPERPAGE
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

[MNU:IDR_DUMMY]
Type=1
Class=?
Command1=ID_DUMMY_PAGELENGTH
CommandCount=1

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

