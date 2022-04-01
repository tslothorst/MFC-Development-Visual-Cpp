; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "toolbar.h"
LastPage=0

ClassCount=5
Class1=CMainFrame
Class2=CAdditionalToolbarsDoc
Class3=CAdditionalToolbarsView
Class4=CAdditionalToolbarsApp
Class5=CAboutDlg

ResourceCount=3
Resource1=IDR_COLOR_TOOLBAR
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=Mainfrm.h
ImplementationFile=Mainfrm.cpp
LastObject=ID_COLORS_BLACK

[CLS:CAdditionalToolbarsDoc]
Type=0
BaseClass=CDocument
HeaderFile=TBarDoc.h
ImplementationFile=TBarDoc.cpp

[CLS:CAdditionalToolbarsView]
Type=0
BaseClass=CView
HeaderFile=TBarView.h
ImplementationFile=TBarView.cpp
LastObject=ID_COLORS_BLACK

[CLS:CAdditionalToolbarsApp]
Type=0
BaseClass=CWinApp
HeaderFile=ToolBar.h
ImplementationFile=ToolBar.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ToolBar.cpp
ImplementationFile=ToolBar.cpp
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_APP_ABOUT
CommandCount=7

[TB:IDR_COLOR_TOOLBAR]
Type=1
Class=?
Command1=ID_COLORS_RED
Command2=ID_COLORS_GREEN
Command3=ID_COLORS_BLUE
CommandCount=3

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
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_COLORTOOLBAR
Command13=ID_COLORS_BLACK
Command14=ID_COLORS_RED
Command15=ID_COLORS_GREEN
Command16=ID_COLORS_BLUE
Command17=ID_APP_ABOUT
CommandCount=17

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

