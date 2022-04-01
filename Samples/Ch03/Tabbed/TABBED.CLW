; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tabbed.h"
LastPage=0

ClassCount=7
Class1=CColorTab
Class2=CMainFrame
Class3=CPhraseTab
Class4=CTabbedColorPhraseApp
Class5=CAboutDlg
Class6=CTabbedColorPhraseDoc
Class7=CTabbedColorPhraseView

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDD_PHRASE
Resource3=IDR_MAINFRAME
Resource4=IDD_COLORS

[CLS:CColorTab]
Type=0
BaseClass=CPropertyPage
HeaderFile=ColorTab.h
ImplementationFile=ColorTab.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CPhraseTab]
Type=0
BaseClass=CPropertyPage
HeaderFile=PhrasTab.h
ImplementationFile=PhrasTab.cpp

[CLS:CTabbedColorPhraseApp]
Type=0
BaseClass=CWinApp
HeaderFile=Tabbed.h
ImplementationFile=Tabbed.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Tabbed.cpp
ImplementationFile=Tabbed.cpp
LastObject=CAboutDlg

[CLS:CTabbedColorPhraseDoc]
Type=0
BaseClass=CDocument
HeaderFile=TabbeDoc.h
ImplementationFile=TabbeDoc.cpp

[CLS:CTabbedColorPhraseView]
Type=0
BaseClass=CView
HeaderFile=TabbView.h
ImplementationFile=TabbView.cpp

[DLG:IDD_COLORS]
Type=1
Class=CColorTab
ControlCount=6
Control1=IDC_STATIC,button,1342177287
Control2=IDC_BLACK,button,1342373897
Control3=IDC_RED,button,1342242825
Control4=IDC_GREEN,button,1342242825
Control5=IDC_BLUE,button,1342242825
Control6=IDC_COLOR_LIST,listbox,1352859937

[DLG:IDD_PHRASE]
Type=1
Class=CPhraseTab
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_PHRASE,edit,1350631552

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
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_MODIFY_SHOWTABBEDDIALOGBOX
Command11=ID_APP_ABOUT
CommandCount=11

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

