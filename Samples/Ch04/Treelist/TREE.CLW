; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CModifyTypeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "tree.h"
LastPage=0

ClassCount=9
Class1=CAnimalDlg
Class2=CModifyDlg
Class3=CModifyTypeDlg
Class4=CSimpleListView
Class5=CMainFrame
Class6=CTreeApp
Class7=CAboutDlg
Class8=CTreeDoc
Class9=CSimpleTreeView

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Resource3=IDD_ANIMAL_ENTRY
Resource4=IDD_ANIMAL_MODIFY
Resource5=IDD_TYPE_MODIFY

[CLS:CAnimalDlg]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CModifyDlg]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp

[CLS:CModifyTypeDlg]
Type=0
BaseClass=CDialog
HeaderFile=Dialogs.h
ImplementationFile=Dialogs.cpp
Filter=D
VirtualFilter=dWC
LastObject=CModifyTypeDlg

[CLS:CSimpleListView]
Type=0
BaseClass=CListView
HeaderFile=ListView.h
ImplementationFile=ListView.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp

[CLS:CTreeApp]
Type=0
BaseClass=CWinApp
HeaderFile=Tree.h
ImplementationFile=tree.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=tree.cpp
ImplementationFile=tree.cpp
LastObject=CAboutDlg

[CLS:CTreeDoc]
Type=0
BaseClass=CDocument
HeaderFile=TreeDoc.h
ImplementationFile=TreeDoc.cpp

[CLS:CSimpleTreeView]
Type=0
BaseClass=CTreeView
HeaderFile=TreeView.h
ImplementationFile=TreeView.cpp

[DLG:IDD_ANIMAL_ENTRY]
Type=1
Class=CAnimalDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CLASS_LIST,listbox,1352728833
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TYPE,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_ANIMAL,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_WEIGHT,edit,1350631552
Control9=IDOK,button,1342242817
Control10=IDCANCEL,button,1342242816

[DLG:IDD_ANIMAL_MODIFY]
Type=1
Class=CModifyDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_ANIMAL,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_WEIGHT,edit,1350631552
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816

[DLG:IDD_TYPE_MODIFY]
Type=1
Class=CModifyTypeDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TYPE,edit,1350631552

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
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_ADDANIMAL
Command8=ID_EDIT_MODIFYANIMAL
Command9=ID_EDIT_DELETEANIMAL
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

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

