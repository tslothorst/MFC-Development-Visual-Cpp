; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPalViewPropPage
LastTemplate=COlePropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PalView.h"
CDK=Y

ClassCount=3
Class1=CPalViewCtrl
Class2=CPalViewPropPage

ResourceCount=3
Resource1=IDD_ABOUTBOX_PALVIEW
LastPage=0
Resource2=IDD_PROPPAGE_PALVIEW
Class3=CDibFilePropPage
Resource3=IDD_PROPPAGE_DIBFILE

[CLS:CPalViewCtrl]
Type=0
HeaderFile=PalViewCtl.h
ImplementationFile=PalViewCtl.cpp
Filter=W
BaseClass=COleControl
VirtualFilter=wWC
LastObject=CPalViewCtrl

[CLS:CPalViewPropPage]
Type=0
HeaderFile=PalViewPpg.h
ImplementationFile=PalViewPpg.cpp
Filter=D
BaseClass=COlePropertyPage
VirtualFilter=idWC
LastObject=IDC_COLORSELECTION

[DLG:IDD_ABOUTBOX_PALVIEW]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROPPAGE_PALVIEW]
Type=1
Class=CPalViewPropPage
ControlCount=2
Control1=IDC_COLORSELECTION,button,1342242819
Control2=IDC_3D_BOXES,button,1342242819

[DLG:IDD_PROPPAGE_DIBFILE]
Type=1
Class=CDibFilePropPage
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DIB_FILENAME,edit,1350631552
Control4=IDC_BROWSE,button,1342242816

[CLS:CDibFilePropPage]
Type=0
HeaderFile=DibPrpg.h
ImplementationFile=DibPrpg.Cpp
BaseClass=COlePropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_BROWSE

