; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpinEditDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SpinButton.h"
LastPage=0

ClassCount=4
Class1=CSpinButtonApp

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class2=CMainFrame
Class3=CAboutDlg
Class4=CSpinEditDlg
Resource3=IDD_SPIN_DIALOG

[CLS:CSpinButtonApp]
Type=0
HeaderFile=SpinButton.h
ImplementationFile=SpinButton.cpp
Filter=N

[CLS:CSpinButtonDoc]
Type=0
HeaderFile=SpinButtonDoc.h
ImplementationFile=SpinButtonDoc.cpp
Filter=N

[CLS:CSpinButtonView]
Type=0
HeaderFile=SpinButtonView.h
ImplementationFile=SpinButtonView.cpp
Filter=C

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_SPINCONTROL



[CLS:CAboutDlg]
Type=0
HeaderFile=SpinButton.cpp
ImplementationFile=SpinButton.cpp
Filter=D
LastObject=CAboutDlg

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
Class=CMainFrame
Command1=ID_SPINCONTROL
Command2=ID_VIEW_STATUS_BAR
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[CLS:CSpinEditDlg]
Type=0
HeaderFile=SpinEditDlg.h
ImplementationFile=SpinEditDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSpinEditDlg

[DLG:IDD_SPIN_DIALOG]
Type=1
Class=CSpinEditDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LENGTH_CM,static,1342308352
Control5=IDC_MPH,msctls_progress32,1350565888
Control6=IDC_KMPH,msctls_progress32,1350565888
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

