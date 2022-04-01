; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTemperatureGraphView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tmpgraph.h"
LastPage=0

ClassCount=7
Class1=CTemperatureDlg
Class2=CTemperatureGraphView
Class3=CMainFrame
Class4=CTemperatureNumbersView
Class5=CTemperatureGraphDoc
Class6=CTemperatureGraphApp
Class7=CAboutDlg

ResourceCount=3
Resource1=IDD_TEMPERATURE
Resource2=IDD_ABOUTBOX
Resource3=IDR_MAINFRAME

[CLS:CTemperatureDlg]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CTemperatureGraphView]
Type=0
BaseClass=CView
HeaderFile=GrafView.h
ImplementationFile=GrafView.cpp
Filter=C
VirtualFilter=VWC
LastObject=CTemperatureGraphView

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CTemperatureNumbersView]
Type=0
BaseClass=CView
HeaderFile=NumbView.h
ImplementationFile=NumbView.cpp

[CLS:CTemperatureGraphDoc]
Type=0
BaseClass=CDocument
HeaderFile=TGrafDoc.h
ImplementationFile=TGrafDoc.cpp

[CLS:CTemperatureGraphApp]
Type=0
BaseClass=CWinApp
HeaderFile=TmpGraph.h
ImplementationFile=TmpGraph.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=TmpGraph.cpp
ImplementationFile=TmpGraph.cpp
LastObject=CAboutDlg

[DLG:IDD_TEMPERATURE]
Type=1
Class=CTemperatureDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308354
Control2=IDC_DAY,edit,1350631552
Control3=IDC_DAY_SPINNER,msctls_updown32,1342177330
Control4=IDC_STATIC,static,1342308354
Control5=IDC_TEMPERATURE,edit,1350631552
Control6=IDC_TEMP_SPINNER,msctls_updown32,1342177330
Control7=IDCANCEL,button,1342242816
Control8=IDC_APPLY,button,1342242816

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
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_MONTH_JANUARY
Command8=ID_MONTH_FEBRUARY
Command9=ID_MONTH_MARCH
Command10=ID_MONTH_APRIL
Command11=ID_MONTH_MAY
Command12=ID_MONTH_JUNE
Command13=ID_MONTH_JULY
Command14=ID_MONTH_AUGUST
Command15=ID_MONTH_SEPTEMBER
Command16=ID_MONTH_OCTOBER
Command17=ID_MONTH_NOVEMBER
Command18=ID_MONTH_DECEMBER
Command19=ID_MONTH_LEAPFEBRUARY
Command20=ID_CHANGE_SETDAILYTEMP
CommandCount=20

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

