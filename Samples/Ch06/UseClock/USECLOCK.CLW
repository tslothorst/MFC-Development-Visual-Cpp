; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUseClockView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UseClock.h"
LastPage=0

ClassCount=7
Class1=CUseClockApp
Class2=CUseClockDoc
Class3=CUseClockView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_USECLOCK_FORM
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX
Class6=CHoursMinutesDlg
Resource4=IDD_HOURS_MINUTES
Class7=CClockPropertiesDlg
Resource5=IDD_CLOCK_PROPERTIES

[CLS:CUseClockApp]
Type=0
HeaderFile=UseClock.h
ImplementationFile=UseClock.cpp
Filter=N
LastObject=CUseClockApp

[CLS:CUseClockDoc]
Type=0
HeaderFile=UseClockDoc.h
ImplementationFile=UseClockDoc.cpp
Filter=N

[CLS:CUseClockView]
Type=0
HeaderFile=UseClockView.h
ImplementationFile=UseClockView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_CLOCKCTRL

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=UseClock.cpp
ImplementationFile=UseClock.cpp
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
Command11=ID_CLOCK_TOGGLEALARM
Command12=ID_CLOCK_SETBACKCOLOR
Command13=ID_CLOCK_SETALARMCOMMAND
Command14=ID_CLOCK_SETALARMHOUR
Command15=ID_CLOCK_SETALARMMINUTE
Command16=ID_CLOCK_ALARMTIMEMETHOD
Command17=ID_CLOCK_TESTALARMMETHOD
Command18=ID_CLOCK_ABOUTBOXMETHOD
Command19=ID_CLOCK_SHOWPROPERTIES
Command20=ID_APP_ABOUT
CommandCount=20

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

[DLG:IDD_USECLOCK_FORM]
Type=1
Class=CUseClockView
ControlCount=1
Control1=IDC_CLOCKCTRL,{6EB850A3-263C-11CF-A151-00AA00374DD8},1342242816

[DLG:IDD_HOURS_MINUTES]
Type=1
Class=CHoursMinutesDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308354
Control2=IDC_HOURS,edit,1350631552
Control3=IDC_STATIC,static,1342308354
Control4=IDC_MINUTES,edit,1350631552
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[CLS:CHoursMinutesDlg]
Type=0
HeaderFile=HoursMinutesDlg.h
ImplementationFile=HoursMinutesDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_HOURS
VirtualFilter=dWC

[DLG:IDD_CLOCK_PROPERTIES]
Type=1
Class=CClockPropertiesDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_HOURS,edit,1350633600
Control3=IDC_STATIC,static,1342308354
Control4=IDC_MINUTES,edit,1350633600
Control5=IDC_STATIC,static,1342308354
Control6=IDC_TYPE,edit,1350633600
Control7=IDC_STATIC,static,1342308354
Control8=IDC_COMMAND,edit,1350633600
Control9=IDC_STATIC,static,1342308354

[CLS:CClockPropertiesDlg]
Type=0
HeaderFile=ClockPropertiesDlg.h
ImplementationFile=ClockPropertiesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMMAND

