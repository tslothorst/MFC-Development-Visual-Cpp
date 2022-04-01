; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COledbAppView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OledbApp.h"
LastPage=0

ClassCount=6
Class1=COledbAppApp
Class2=COledbAppDoc
Class3=COledbAppView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=COledbAppSet
Resource7=IDD_OLEDBAPP_FORM

[CLS:COledbAppApp]
Type=0
HeaderFile=OledbApp.h
ImplementationFile=OledbApp.cpp
Filter=N

[CLS:COledbAppDoc]
Type=0
HeaderFile=OledbAppDoc.h
ImplementationFile=OledbAppDoc.cpp
Filter=N

[CLS:COledbAppView]
Type=0
HeaderFile=OledbAppView.h
ImplementationFile=OledbAppView.cpp
Filter=D
LastObject=ID_RECORD_DELETE
BaseClass=COleDBRecordView
VirtualFilter=RVWC

[CLS:COledbAppSet]
Type=0
HeaderFile=OledbAppSet.h
ImplementationFile=OledbAppSet.cpp
Filter=N

[DB:COledbAppSet]
DB=1
DBType=ODBC
ColumnCount=6
		COLUMN_ENTRY_TYPE(5, DBTYPE_STR, m_Address)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_EmployeeID)
		COLUMN_ENTRY_TYPE(3, DBTYPE_STR, m_FirstName)
		COLUMN_ENTRY_TYPE(6, DBTYPE_STR, m_HomePhone)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_LastName)
		COLUMN_ENTRY_TYPE(4, DBTYPE_STR, m_Title)

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=OledbApp.cpp
ImplementationFile=OledbApp.cpp
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
Command2=ID_RECORD_FIRST
Command3=ID_RECORD_PREV
Command4=ID_RECORD_NEXT
Command5=ID_RECORD_LAST
Command6=ID_RECORD_CLEAR
Command7=ID_RECORD_ADD
Command8=ID_RECORD_DELETE
Command9=ID_RECORD_COMMIT
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

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

[DLG:IDD_OLEDBAPP_FORM]
Type=1
Class=COledbAppView
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=ID_EMPID,edit,1350631552
Control8=ID_LNAME,edit,1350631552
Control9=ID_FNAME,edit,1350631552
Control10=ID_TITLE,edit,1350631552
Control11=ID_ADDRESS,edit,1350631552
Control12=ID_PHONE,edit,1350631552

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_RECORD_FIRST
Command2=ID_RECORD_PREV
Command3=ID_RECORD_NEXT
Command4=ID_RECORD_LAST
Command5=ID_RECORD_CLEAR
Command6=ID_RECORD_ADD
Command7=ID_RECORD_DELETE
Command8=ID_RECORD_COMMIT
Command9=ID_APP_ABOUT
CommandCount=9

