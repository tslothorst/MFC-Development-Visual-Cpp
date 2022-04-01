; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileOpenEx
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "diff.h"
LastPage=0

ClassCount=9
Class1=CDiffApp
Class2=CAboutDlg
Class3=CDiffDoc
Class4=CDiffView
Class5=CMainFrame
Class6=CSplitter

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class7=CDlgOpenFiles
Resource3=IDD_OPENFILES
Class8=CProgressStatusBar
Class9=CFileOpenEx
Resource4=IDD_FILEOPEN_EX

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
Command1=ID_FILE_OPEN
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_FILE_PRINT
Command6=ID_APP_ABOUT
CommandCount=6

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_FILE_PRINT_PREVIEW
Command4=ID_FILE_PRINT_SETUP
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT
Command4=ID_EDIT_PASTE
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_NEXT_PANE
Command8=ID_PREV_PANE
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_CUT
Command12=ID_EDIT_UNDO
CommandCount=12

[DLG:IDD_OPENFILES]
Type=1
Class=CDlgOpenFiles
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_FILE1,edit,1350631552
Control3=IDC_BUTTON_FILE1_BROWSE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_FILE2,edit,1350631552
Control6=IDC_BUTTON_FILE2_BROWSE,button,1342242816
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[CLS:CDlgOpenFiles]
Type=0
HeaderFile=DlgOpenF.h
ImplementationFile=DlgOpenF.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgOpenFiles

[CLS:CProgressStatusBar]
Type=0
HeaderFile=Progress.h
ImplementationFile=Progress.cpp
BaseClass=CStatusBar
Filter=W
LastObject=CProgressStatusBar

[DLG:IDD_FILEOPEN_EX]
Type=1
Class=CFileOpenEx
ControlCount=3
Control1=1119,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_CONTENTS,RICHEDIT,1353711620

[CLS:CFileOpenEx]
Type=0
HeaderFile=FileOpenEx.h
ImplementationFile=FileOpenEx.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_OPTIONS
VirtualFilter=dWC

