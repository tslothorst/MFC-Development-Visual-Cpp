; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDiffView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "diff.h"
LastPage=0

ClassCount=8
Class1=CDiffApp
Class2=CAboutDlg
Class3=CDiffDoc
Class4=CDiffView
Class5=CDlgOpenFiles
Class6=CMainFrame
Class7=CProgressStatusBar
Class8=CSplitter

ResourceCount=6
Resource1=IDR_POPUP_DIFF_VIEW
Resource2=IDD_FILEOPEN_EX
Resource3=IDD_ABOUTBOX
Resource4=IDD_OPENFILES
Resource5=IDR_MAINFRAME
Resource6=IDD_DIALOGBAR

[CLS:CDiffApp]
Type=0
BaseClass=CWinApp
HeaderFile=diff.h
ImplementationFile=diff.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=diff.cpp
ImplementationFile=diff.cpp
LastObject=CAboutDlg

[CLS:CDiffDoc]
Type=0
BaseClass=CRichEditDoc
HeaderFile=diffdoc.h
ImplementationFile=diffdoc.cpp

[CLS:CDiffView]
Type=0
BaseClass=CRichEditView
HeaderFile=diffview.h
ImplementationFile=diffview.cpp
Filter=C
VirtualFilter=VWC
LastObject=CDiffView

[CLS:CDlgOpenFiles]
Type=0
BaseClass=CDialog
HeaderFile=dlgopenf.h
ImplementationFile=dlgopenf.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp

[CLS:CProgressStatusBar]
Type=0
BaseClass=CStatusBar
HeaderFile=progress.h
ImplementationFile=progress.cpp

[CLS:CSplitter]
Type=0
BaseClass=CSplitterWnd
HeaderFile=splitter.h
ImplementationFile=splitter.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEOPEN_EX]
Type=1
Class=CFileIOpenEx
ControlCount=6
Control1=1119,static,1342177280
Control2=IDC_BUTTON_OPTIONS,button,1342242816
Control3=IDC_EDIT_CONTENTS,RICHEDIT,1353711620
Control4=IDC_STATIC,static,1342308352
Control5=IDC_FOLDSIZE,static,1073741831
Control6=IDC_UNFOLDSIZE,static,1073741831

[DLG:IDD_OPENFILES]
Type=1
Class=CDlgOpenFiles
ControlCount=8
Control1=IDC_EDIT_FILE1,edit,1350631552
Control2=IDC_BUTTON_FILE1_BROWSE,button,1342242816
Control3=IDC_EDIT_FILE2,edit,1350631552
Control4=IDC_BUTTON_FILE2_BROWSE,button,1342242816
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[MNU:IDR_POPUP_DIFF_VIEW]
Type=1
Class=?
Command1=ID_EDIT_COPY
Command2=ID_EDIT_FIND
Command3=ID_EDIT_FONT
Command4=IDC_EDIT_COLOR_ADDITIONS
Command5=IDC_EDIT_COLOR_DELETIONS
CommandCount=5

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_FILE_PRINT
Command6=ID_APP_ABOUT
CommandCount=6

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_FILE_PRINT
Command3=ID_FILE_PRINT_PREVIEW
Command4=ID_FILE_PRINT_SETUP
Command5=ID_APP_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_VIEW_DIALOGBAR
Command13=ID_APP_ABOUT
CommandCount=13

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

[DLG:IDD_DIALOGBAR]
Type=1
Class=?
ControlCount=2
Control1=IDC_RIGHT,combobox,1344340291
Control2=IDC_LEFT,combobox,1344340291

