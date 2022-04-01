; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OLEDBDynAccApp.h"
LastPage=0

ClassCount=6
Class1=COLEDBDynAccAppApp
Class2=COLEDBDynAccAppDoc
Class3=COLEDBDynAccAppView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=12
Resource1=IDD_ABOUTBOX
Resource2=IDD_EMUMERATOR
Resource7=IDD_OLEDBDYNACCAPP_FORM
Resource8=IDR_MAINFRAME
Resource9=IDD_MANACC_FORM
Resource10=IDD_TABLES
Resource11=IDD_DATASOURCE
Class5=COLEDBDynAccAppSet
Resource12=IDD_COLUMNS

[CLS:COLEDBDynAccAppApp]
Type=0
HeaderFile=OLEDBDynAccApp.h
ImplementationFile=OLEDBDynAccApp.cpp
Filter=N

[CLS:COLEDBDynAccAppDoc]
Type=0
HeaderFile=OLEDBDynAccAppDoc.h
ImplementationFile=OLEDBDynAccAppDoc.cpp
Filter=N

[CLS:COLEDBDynAccAppView]
Type=0
HeaderFile=OLEDBDynAccAppView.h
ImplementationFile=OLEDBDynAccAppView.cpp
Filter=D

[CLS:COLEDBDynAccAppSet]
Type=0
HeaderFile=OLEDBDynAccAppSet.h
ImplementationFile=OLEDBDynAccAppSet.cpp
Filter=N

[DB:COLEDBDynAccAppSet]
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




[CLS:CAboutDlg]
Type=0
HeaderFile=OLEDBDynAccApp.cpp
ImplementationFile=OLEDBDynAccApp.cpp
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
Command1=ID_FILE_OPEN
Command2=ID_APP_EXIT
Command3=ID_RECORD_FST
Command4=ID_RECORD_PRV
Command5=ID_RECORD_NXT
Command6=ID_RECORD_LST
Command7=ID_VIEW_TOOLBAR
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

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

[DLG:IDD_OLEDBDYNACCAPP_FORM]
Type=1
Class=COLEDBDynAccAppView
ControlCount=0

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_RECORD_FST
Command3=ID_RECORD_PRV
Command4=ID_RECORD_NXT
Command5=ID_RECORD_LST
Command6=ID_APP_ABOUT
CommandCount=6

[DLG:IDD_EMUMERATOR]
Type=1
Class=?
ControlCount=4
Control1=IDC_ENUMERATOR,listbox,1352728833
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[DLG:IDD_DATASOURCE]
Type=1
Class=?
ControlCount=6
Control1=IDC_DATASOURCE_PATH,edit,1350631552
Control2=IDC_DATASOURCE_NAME,combobox,1344339970
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_TABLES]
Type=1
Class=?
ControlCount=3
Control1=IDC_TABLES,listbox,1352728835
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816

[DLG:IDD_COLUMNS]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COLUMNS,listbox,1352728841

[DLG:IDD_MANACC_FORM]
Type=1
Class=?
ControlCount=1
Control1=IDC_DATA,listbox,1353777411

