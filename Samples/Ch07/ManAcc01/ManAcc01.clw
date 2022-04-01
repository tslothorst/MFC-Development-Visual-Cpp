; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CManAcc01View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ManAcc01.h"
LastPage=0

ClassCount=6
Class1=CManAcc01App
Class2=CManAcc01Doc
Class3=CManAcc01View
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=13
Resource1=IDD_DATASOURCE
Resource2="IDD_MANACC01_FORM"
Resource7=IDR_MAINFRAME
Resource8=IDD_EMUMERATOR
Resource9=IDD_COLUMNS
Resource10=IDD_ABOUTBOX
Resource11=IDD_MANACC01_FORM
Resource12=IDD_TABLES
Class5=CManAcc01Set
Resource13=IDD_DIALOG1

[CLS:CManAcc01App]
Type=0
HeaderFile=ManAcc01.h
ImplementationFile=ManAcc01.cpp
Filter=N

[CLS:CManAcc01Doc]
Type=0
HeaderFile=ManAcc01Doc.h
ImplementationFile=ManAcc01Doc.cpp
Filter=N

[CLS:CManAcc01View]
Type=0
HeaderFile=ManAcc01View.h
ImplementationFile=ManAcc01View.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CManAcc01View

[CLS:CManAcc01Set]
Type=0
HeaderFile=ManAcc01Set.h
ImplementationFile=ManAcc01Set.cpp
Filter=N

[DB:CManAcc01Set]
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
LastObject=ID_RECORD_FST




[CLS:CAboutDlg]
Type=0
HeaderFile=ManAcc01.cpp
ImplementationFile=ManAcc01.cpp
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

[DLG:IDD_MANACC01_FORM]
Type=1
Class=CManAcc01View
ControlCount=1
Control1=IDC_DATA,listbox,1353777409

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

[DLG:IDD_COLUMNS]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COLUMNS,listbox,1352728841

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

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:"IDD_MANACC01_FORM"]
Type=1
Class=?
ControlCount=1
Control1=IDC_DATA,listbox,1353777411

