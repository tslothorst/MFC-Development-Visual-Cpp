; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrgCtrlDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PrgCtrl.h"
LastPage=0

ClassCount=8
Class1=CPrgCtrlApp
Class2=CAboutDlg
Class3=CPrgCtrlDoc
Class4=CPrgCtrlView
Class5=CMainFrame
Class6=CSplitter

ResourceCount=4
Resource1=IDD_OPENFILES
Resource2=IDD_ABOUTBOX
Class7=CDlgOpenFiles
Resource3=IDR_MAINFRAME
Class8=CProgressDlg
Resource4=IDD_PROGRESS

[CLS:CPrgCtrlApp]
Type=0
BaseClass=CWinApp
HeaderFile=PrgCtrl.h
ImplementationFile=PrgCtrl.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=PrgCtrl.cpp
ImplementationFile=PrgCtrl.cpp
LastObject=CAboutDlg

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CSplitter]
Type=0
BaseClass=CSplitterWnd
HeaderFile=splitter.h
ImplementationFile=splitter.cpp
LastObject=CSplitter

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

[DLG:IDD_PROGRESS]
Type=1
Class=CProgressDlg
ControlCount=0

[CLS:CProgressDlg]
Type=0
HeaderFile=ProgressDlg.h
ImplementationFile=ProgressDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProgressDlg

[CLS:CPrgCtrlView]
Type=0
HeaderFile=prgcview.h
ImplementationFile=prgcview.cpp
BaseClass=CRichEditView
LastObject=CPrgCtrlView

[CLS:CPrgCtrlDoc]
Type=0
HeaderFile=prgcdoc.h
ImplementationFile=prgcdoc.cpp
BaseClass=CRichEditDoc
LastObject=CPrgCtrlDoc

