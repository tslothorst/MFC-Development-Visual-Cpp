; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUseCalView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UseCal.h"
LastPage=0

ClassCount=5
Class1=CUseCalApp
Class2=CUseCalDoc
Class3=CUseCalView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource7=IDD_USECAL_FORM

[CLS:CUseCalApp]
Type=0
HeaderFile=UseCal.h
ImplementationFile=UseCal.cpp
Filter=N

[CLS:CUseCalDoc]
Type=0
HeaderFile=UseCalDoc.h
ImplementationFile=UseCalDoc.cpp
Filter=N

[CLS:CUseCalView]
Type=0
HeaderFile=UseCalView.h
ImplementationFile=UseCalView.cpp
Filter=D
LastObject=IDC_CALENDARCTRL
BaseClass=CFormView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=UseCal.cpp
ImplementationFile=UseCal.cpp
Filter=D

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
Command1=ID_APP_EXIT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_CALENDAR_SHOWCURRENTDATE
Command9=ID_CALENDAR_SETBACKCOLOR
Command10=ID_CALENDAR_TOGGLETITLE
Command11=ID_APP_ABOUT
CommandCount=11

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
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

[DLG:IDD_USECAL_FORM]
Type=1
Class=CUseCalView
ControlCount=1
Control1=IDC_CALENDARCTRL,{8E27C92B-1264-101C-8A2F-040224009C02},1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_APP_ABOUT
CommandCount=4

