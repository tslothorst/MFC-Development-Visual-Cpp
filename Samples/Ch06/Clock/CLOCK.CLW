; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClockCtrl
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "clock.h"
LastPage=0
CDK=Y

ClassCount=3
Class1=CAlarmPropPage
Class2=CClockCtrl
Class3=CClockPropPage

ResourceCount=3
Resource1=IDD_ABOUTBOX_CLOCK
Resource2=IDD_PROPPAGE_CLOCK
Resource3=IDD_PROPPAGE_ALARM

[CLS:CAlarmPropPage]
Type=0
BaseClass=COlePropertyPage
HeaderFile=alarmppg.h
ImplementationFile=AlarmPpg.cpp
Filter=D
VirtualFilter=idWC
LastObject=IDC_ALARM_SET

[CLS:CClockCtrl]
Type=0
BaseClass=COleControl
HeaderFile=ClockCtl.h
ImplementationFile=ClockCtl.cpp
Filter=W
VirtualFilter=WC
LastObject=CClockCtrl

[CLS:CClockPropPage]
Type=0
BaseClass=COlePropertyPage
HeaderFile=ClockPpg.h
ImplementationFile=ClockPpg.cpp

[DLG:IDD_PROPPAGE_ALARM]
Type=1
Class=CAlarmPropPage
ControlCount=12
Control1=IDC_ALARM_SET,button,1342243107
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ALARM_HOUR,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_ALARM_MINUTE,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ALARM_SOUND,edit,1350631552
Control8=IDC_FILE_SELECT,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ALARM_COMMAND,edit,1350631552
Control11=IDC_ALARM_TYPE,combobox,1344340227
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_PROPPAGE_CLOCK]
Type=1
Class=CClockPropPage
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX_CLOCK]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

