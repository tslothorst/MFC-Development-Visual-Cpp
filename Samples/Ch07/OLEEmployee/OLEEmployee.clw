; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COLEEmployeeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OLEEmployee.h"
LastPage=0

ClassCount=6
Class1=COLEEmployeeApp
Class2=COLEEmployeeDoc
Class3=COLEEmployeeView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=COLEEmployeeSet
Resource7=IDD_OLEEMPLOYEE_FORM

[CLS:COLEEmployeeApp]
Type=0
HeaderFile=OLEEmployee.h
ImplementationFile=OLEEmployee.cpp
Filter=N

[CLS:COLEEmployeeDoc]
Type=0
HeaderFile=OLEEmployeeDoc.h
ImplementationFile=OLEEmployeeDoc.cpp
Filter=N

[CLS:COLEEmployeeView]
Type=0
HeaderFile=OLEEmployeeView.h
ImplementationFile=OLEEmployeeView.cpp
Filter=D
LastObject=COLEEmployeeView


[CLS:COLEEmployeeSet]
Type=0
HeaderFile=OLEEmployeeSet.h
ImplementationFile=OLEEmployeeSet.cpp
Filter=N

[DB:COLEEmployeeSet]
DB=1
DBType=ODBC
ColumnCount=3
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_EmployeeID)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_Name)
		COLUMN_ENTRY_TYPE(3, DBTYPE_STR, m_Address)

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=OLEEmployee.cpp
ImplementationFile=OLEEmployee.cpp
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

[DLG:IDD_OLEEMPLOYEE_FORM]
Type=1
Class=COLEEmployeeView
ControlCount=6
Control1=IDC_EMPLOYEE_ID,edit,1350631552
Control2=IDC_NAME,edit,1350631552
Control3=IDC_ADDRESS,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

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

