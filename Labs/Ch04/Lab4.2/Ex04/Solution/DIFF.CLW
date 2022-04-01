; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiffView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "diff.h"
LastPage=0

ClassCount=6
Class1=CDiffApp
Class2=CAboutDlg
Class3=CDiffDoc
Class4=CDiffView
Class5=CMainFrame
Class6=CSplitter

ResourceCount=2
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX

[CLS:CDiffApp]
Type=0
BaseClass=CWinApp
HeaderFile=diff.h
ImplementationFile=diff.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=diff.cpp
ImplementationFile=diff.cpp
LastObject=CAboutDlg

[CLS:CDiffDoc]
Type=0
BaseClass=CRichEditDoc
HeaderFile=diffdoc.h
ImplementationFile=diffdoc.cpp
Filter=N
VirtualFilter=DC
LastObject=CDiffDoc

[CLS:CDiffView]
Type=0
BaseClass=CRichEditView
HeaderFile=diffview.h
ImplementationFile=diffview.cpp
LastObject=CDiffView
Filter=C
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
Filter=T
VirtualFilter=fWC

[CLS:CSplitter]
Type=0
BaseClass=CSplitterWnd
HeaderFile=splitter.h
ImplementationFile=splitter.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
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
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

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

