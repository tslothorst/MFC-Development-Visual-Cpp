# Microsoft Developer Studio Generated NMAKE File, Based on List.dsp
!IF "$(CFG)" == ""
CFG=List - Win32 Release
!MESSAGE No configuration specified. Defaulting to List - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "List - Win32 Release" && "$(CFG)" != "List - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "List.mak" CFG="List - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "List - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "List - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "List - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\List.exe"

!ELSE 

ALL : "$(OUTDIR)\List.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\List.obj"
	-@erase "$(INTDIR)\List.pch"
	-@erase "$(INTDIR)\List.res"
	-@erase "$(INTDIR)\ListDoc.obj"
	-@erase "$(INTDIR)\ListView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\List.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\List.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\List.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\List.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\List.pdb" /machine:I386 /out:"$(OUTDIR)\List.exe" 
LINK32_OBJS= \
	"$(INTDIR)\List.obj" \
	"$(INTDIR)\List.res" \
	"$(INTDIR)\ListDoc.obj" \
	"$(INTDIR)\ListView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\List.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "List - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\List.exe"

!ELSE 

ALL : "$(OUTDIR)\List.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\List.obj"
	-@erase "$(INTDIR)\List.pch"
	-@erase "$(INTDIR)\List.res"
	-@erase "$(INTDIR)\ListDoc.obj"
	-@erase "$(INTDIR)\ListView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\List.exe"
	-@erase "$(OUTDIR)\List.ilk"
	-@erase "$(OUTDIR)\List.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\List.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\List.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\List.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\List.pdb" /debug /machine:I386 /out:"$(OUTDIR)\List.exe" 
LINK32_OBJS= \
	"$(INTDIR)\List.obj" \
	"$(INTDIR)\List.res" \
	"$(INTDIR)\ListDoc.obj" \
	"$(INTDIR)\ListView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\List.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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


!IF "$(CFG)" == "List - Win32 Release" || "$(CFG)" == "List - Win32 Debug"
SOURCE=.\List.cpp
DEP_CPP_LIST_=\
	".\List.h"\
	".\ListDoc.h"\
	".\ListView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\List.obj" : $(SOURCE) $(DEP_CPP_LIST_) "$(INTDIR)"\
 "$(INTDIR)\List.pch"


SOURCE=.\List.rc
DEP_RSC_LIST_R=\
	".\res\List.ico"\
	".\res\List.rc2"\
	".\res\ListDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\List.res" : $(SOURCE) $(DEP_RSC_LIST_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ListDoc.cpp
DEP_CPP_LISTD=\
	".\List.h"\
	".\ListDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ListDoc.obj" : $(SOURCE) $(DEP_CPP_LISTD) "$(INTDIR)"\
 "$(INTDIR)\List.pch"


SOURCE=.\ListView.cpp
DEP_CPP_LISTV=\
	".\List.h"\
	".\ListDoc.h"\
	".\ListView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ListView.obj" : $(SOURCE) $(DEP_CPP_LISTV) "$(INTDIR)"\
 "$(INTDIR)\List.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\List.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\List.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "List - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\List.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\List.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "List - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\List.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\List.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

