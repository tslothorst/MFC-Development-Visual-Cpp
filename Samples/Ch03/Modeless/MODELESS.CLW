; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "modeless.h"
LastPage=0

ClassCount=6
Class1=CListWithItemDataDlg
Class2=CMainFrame
Class3=CModelessDoc
Class4=CModelessView
Class5=CModelessApp
Class6=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PHRASE_MODELESS

[CLS:CListWithItemDataDlg]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CModelessDoc]
Type=0
BaseClass=CDocument
HeaderFile=MdlesDoc.h
ImplementationFile=MdlesDoc.cpp

[CLS:CModelessView]
Type=0
BaseClass=CView
HeaderFile=MlesView.h
ImplementationFile=MlesView.cpp

[CLS:CModelessApp]
Type=0
BaseClass=CWinApp
HeaderFile=Modeless.h
ImplementationFile=Modeless.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Modeless.cpp
ImplementationFile=Modeless.cpp
LastObject=CAboutDlg

[DLG:IDD_PHRASE_MODELESS]
Type=1
Class=CListWithItemDataDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COLOR_LIST,listbox,1352728833
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PHRASE,edit,1350631552
Control5=IDCANCEL,button,1342242816
Control6=IDC_APPLY,button,1342242816

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_MODIFY_DISPLAYMODELESSDIALOG
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

