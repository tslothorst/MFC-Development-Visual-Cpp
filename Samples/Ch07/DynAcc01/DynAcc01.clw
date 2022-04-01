; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDynAcc01View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DynAcc01.h"
LastPage=0

ClassCount=6
Class1=CDynAcc01App
Class2=CDynAcc01Doc
Class3=CDynAcc01View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CDynAcc01Set
Resource7=IDD_DYNACC01_FORM

[CLS:CDynAcc01App]
Type=0
HeaderFile=DynAcc01.h
ImplementationFile=DynAcc01.cpp
Filter=N
LastObject=CDynAcc01App

[CLS:CDynAcc01Doc]
Type=0
HeaderFile=DynAcc01Doc.h
ImplementationFile=DynAcc01Doc.cpp
Filter=N

[CLS:CDynAcc01View]
Type=0
HeaderFile=DynAcc01View.h
ImplementationFile=DynAcc01View.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CDynAcc01View

[CLS:CDynAcc01Set]
Type=0
HeaderFile=DynAcc01Set.h
ImplementationFile=DynAcc01Set.cpp
Filter=N

[DB:CDynAcc01Set]
DB=1
DBType=ODBC
ColumnCount=3
		COLUMN_ENTRY_TYPE(3, DBTYPE_STR, m_Address)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_EmployeeID)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_Name)

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_APP_EXIT
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=DynAcc01.cpp
ImplementationFile=DynAcc01.cpp
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
Command1=ID_APP_EXIT
Command2=ID_RECORD_FIRST
Command3=ID_RECORD_PREV
Command4=ID_RECORD_NEXT
Command5=ID_RECORD_LAST
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

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

[DLG:IDD_DYNACC01_FORM]
Type=1
Class=CDynAcc01View
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EMPLOYEE_ID,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ADDRESS,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_RECORD_FIRST
Command2=ID_RECORD_PREV
Command3=ID_RECORD_NEXT
Command4=ID_RECORD_LAST
Command5=ID_APP_ABOUT
CommandCount=5

