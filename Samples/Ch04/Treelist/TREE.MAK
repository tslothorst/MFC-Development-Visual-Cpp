# Microsoft Developer Studio Generated NMAKE File, Based on tree.dsp
!IF "$(CFG)" == ""
CFG=tree - Win32 Release
!MESSAGE No configuration specified. Defaulting to tree - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "tree - Win32 Release" && "$(CFG)" != "tree - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tree.mak" CFG="tree - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tree - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "tree - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "tree - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tree.exe"

!ELSE 

ALL : "$(OUTDIR)\tree.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AnmlData.obj"
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\ListView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\tree.pch"
	-@erase "$(INTDIR)\tree.res"
	-@erase "$(INTDIR)\treeDoc.obj"
	-@erase "$(INTDIR)\TreeView.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\tree.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tree.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tree.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\tree.pdb" /machine:I386 /out:"$(OUTDIR)\tree.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AnmlData.obj" \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\ListView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\tree.res" \
	"$(INTDIR)\treeDoc.obj" \
	"$(INTDIR)\TreeView.obj"

"$(OUTDIR)\tree.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "tree - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\tree.exe"

!ELSE 

ALL : "$(OUTDIR)\tree.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AnmlData.obj"
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\ListView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tree.obj"
	-@erase "$(INTDIR)\tree.pch"
	-@erase "$(INTDIR)\tree.res"
	-@erase "$(INTDIR)\treeDoc.obj"
	-@erase "$(INTDIR)\TreeView.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\tree.exe"
	-@erase "$(OUTDIR)\tree.ilk"
	-@erase "$(OUTDIR)\tree.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.

.c{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_OBJS)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(CPP_SBRS)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tree.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tree.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\tree.pdb" /debug /machine:I386 /out:"$(OUTDIR)\tree.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AnmlData.obj" \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\ListView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tree.obj" \
	"$(INTDIR)\tree.res" \
	"$(INTDIR)\treeDoc.obj" \
	"$(INTDIR)\TreeView.obj"

"$(OUTDIR)\tree.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "tree - Win32 Release" || "$(CFG)" == "tree - Win32 Debug"
SOURCE=.\AnmlData.cpp
DEP_CPP_ANMLD=\
	".\AnmlData.h"\
	".\StdAfx.h"\
	".\tree.h"\
	

"$(INTDIR)\AnmlData.obj" : $(SOURCE) $(DEP_CPP_ANMLD) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\Dialogs.cpp
DEP_CPP_DIALO=\
	".\dialogs.h"\
	".\StdAfx.h"\
	".\tree.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\ListView.cpp
DEP_CPP_LISTV=\
	".\AnmlData.h"\
	".\ListView.h"\
	".\StdAfx.h"\
	".\tree.h"\
	".\treeDoc.h"\
	".\treeview.h"\
	

"$(INTDIR)\ListView.obj" : $(SOURCE) $(DEP_CPP_LISTV) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\AnmlData.h"\
	".\ListView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\tree.h"\
	".\treeDoc.h"\
	".\treeview.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "tree - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tree.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tree - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\tree.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tree.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\tree.cpp
DEP_CPP_TREE_=\
	".\AnmlData.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\tree.h"\
	".\treeDoc.h"\
	".\treeview.h"\
	

"$(INTDIR)\tree.obj" : $(SOURCE) $(DEP_CPP_TREE_) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\tree.rc
DEP_RSC_TREE_R=\
	".\res\Toolbar.bmp"\
	".\res\tree.ico"\
	".\res\tree.rc2"\
	".\res\treeDoc.ico"\
	

"$(INTDIR)\tree.res" : $(SOURCE) $(DEP_RSC_TREE_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\treeDoc.cpp
DEP_CPP_TREED=\
	".\AnmlData.h"\
	".\StdAfx.h"\
	".\tree.h"\
	".\treeDoc.h"\
	".\treeview.h"\
	

"$(INTDIR)\treeDoc.obj" : $(SOURCE) $(DEP_CPP_TREED) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\TreeView.cpp
DEP_CPP_TREEV=\
	".\AnmlData.h"\
	".\dialogs.h"\
	".\ListView.h"\
	".\StdAfx.h"\
	".\tree.h"\
	".\treeDoc.h"\
	".\treeview.h"\
	

"$(INTDIR)\TreeView.obj" : $(SOURCE) $(DEP_CPP_TREEV) "$(INTDIR)"\
 "$(INTDIR)\tree.pch"


SOURCE=.\AnmlData.h
SOURCE=.\dialogs.h
SOURCE=.\ListView.h
SOURCE=.\MainFrm.h
SOURCE=.\StdAfx.h
SOURCE=.\tree.h
SOURCE=.\treeDoc.h
SOURCE=.\treeview.h
SOURCE=.\res\Toolbar.bmp
SOURCE=.\res\tree.ico
SOURCE=.\res\tree.rc2
SOURCE=.\res\treeDoc.ico

!ENDIF 

