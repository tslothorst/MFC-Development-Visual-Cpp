; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMenusDynamicView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dynamenu.h"
LastPage=0

ClassCount=5
Class1=CMenusDynamicDoc
Class2=CMenusDynamicApp
Class3=CAboutDlg
Class4=CMenusDynamicView
Class5=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=CG_IDR_POPUP_MENUS_DYNAMIC_VIEW
Resource3=IDD_ABOUTBOX

[CLS:CMenusDynamicDoc]
Type=0
BaseClass=CDocument
HeaderFile=DynaMDoc.h
ImplementationFile=DynaMDoc.cpp

[CLS:CMenusDynamicApp]
Type=0
BaseClass=CWinApp
HeaderFile=DynaMenu.h
ImplementationFile=DynaMenu.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=DynaMenu.cpp
ImplementationFile=DynaMenu.cpp
LastObject=CAboutDlg

[CLS:CMenusDynamicView]
Type=0
BaseClass=CView
HeaderFile=DynaView.h
ImplementationFile=DynaView.cpp
LastObject=CMenusDynamicView

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
LastObject=CMainFrame

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
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_COLORS_BLACK
Command12=ID_COLORS_RED
Command13=ID_COLORS_GREEN
Command14=ID_COLORS_BLUE
Command15=ID_OPTIONS_EXTRACOLORS
Command16=ID_OPTIONS_EXTRACOLORS_CASCADE
Command17=ID_OPTIONS_STANDARDCOLORS
Command18=ID_APP_ABOUT
CommandCount=18

[MNU:CG_IDR_POPUP_MENUS_DYNAMIC_VIEW]
Type=1
Class=?
Command1=ID_COLORS_BLACK
Command2=ID_COLORS_RED
Command3=ID_COLORS_GREEN
Command4=ID_COLORS_BLUE
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=?
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

