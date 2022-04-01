; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDefaultView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MDI2Views.h"
LastPage=0

ClassCount=7
Class1=CMDI2ViewsApp
Class2=CMDI2ViewsDoc
Class3=CDefaultView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDR_MDI2VITYPE
Class5=CAboutDlg
Class6=CChildFrame
Class7=CItalicsView
Resource3=IDD_ABOUTBOX

[CLS:CMDI2ViewsApp]
Type=0
HeaderFile=MDI2Views.h
ImplementationFile=MDI2Views.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=ID_APP_ABOUT

[CLS:CMDI2ViewsDoc]
Type=0
HeaderFile=MDI2ViewsDoc.h
ImplementationFile=MDI2ViewsDoc.cpp
Filter=N

[CLS:CDefaultView]
Type=0
HeaderFile=DefaultView.h
ImplementationFile=DefaultView.cpp
Filter=C
LastObject=CDefaultView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
BaseClass=CMDIChildWnd
VirtualFilter=mfWC
LastObject=CChildFrame

[CLS:CAboutDlg]
Type=0
HeaderFile=MDI2Views.cpp
ImplementationFile=MDI2Views.cpp
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
Command3=ID_FILE_MRU_FILE1
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MDI2VITYPE]
Type=1
Class=CDefaultView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_COLORS_BLACK
Command15=ID_COLORS_RED
Command16=ID_COLORS_GREEN
Command17=ID_COLORS_BLUE
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_ITALICS
Command20=ID_WINDOW_CASCADE
Command21=ID_WINDOW_TILE_HORZ
Command22=ID_WINDOW_ARRANGE
Command23=ID_APP_ABOUT
CommandCount=23

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

[CLS:CItalicsView]
Type=0
HeaderFile=ItalicsView.h
ImplementationFile=ItalicsView.cpp
BaseClass=CView
Filter=C
LastObject=CItalicsView

