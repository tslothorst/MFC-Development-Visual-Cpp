; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIC_2View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "IC_2.h"
LastPage=0

ClassCount=6
Class1=CIC_2App
Class2=CIC_2Doc
Class3=CIC_2View
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CUrlDialog
Resource3=IDD_URL_DIALOG

[CLS:CIC_2App]
Type=0
HeaderFile=IC_2.h
ImplementationFile=IC_2.cpp
Filter=N

[CLS:CIC_2Doc]
Type=0
HeaderFile=IC_2Doc.h
ImplementationFile=IC_2Doc.cpp
Filter=N

[CLS:CIC_2View]
Type=0
HeaderFile=IC_2View.h
ImplementationFile=IC_2View.cpp
Filter=C
LastObject=CIC_2View
BaseClass=CScrollView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_MRU_FILE1



[CLS:CAboutDlg]
Type=0
HeaderFile=IC_2.cpp
ImplementationFile=IC_2.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_INTERNET_OBTAINURL
Command14=ID_INTERNET_CREATESESSION
Command15=ID_INTERNET_GETCONNECTION
Command16=ID_INTERNET_OPENREQUEST
Command17=ID_INTERNET_SENDREQUEST
Command18=ID_INTERNET_READINFORMATION
Command19=ID_INTERNET_ALLTHEABOVE
Command20=ID_INTERNET_CLOSESESSION
Command21=ID_APP_ABOUT
CommandCount=21

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_APP_ABOUT
CommandCount=7

[DLG:IDD_URL_DIALOG]
Type=1
Class=CUrlDialog
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_URL,edit,1350631552
Control3=IDC_PARSE,button,1342242817
Control4=IDOK,button,1342242816
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SERVER,static,1350696960
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OBJECT,static,1350696960
Control10=IDC_STATIC,static,1342308352
Control11=IDC_PORT,static,1350696960
Control12=IDC_STATIC,static,1342308352
Control13=IDC_SERVICE_TYPE,static,1350696960

[CLS:CUrlDialog]
Type=0
HeaderFile=URLDialog.h
ImplementationFile=URLDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUrlDialog

