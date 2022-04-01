# Microsoft Developer Studio Generated NMAKE File, Based on MDIApp.dsp
!IF "$(CFG)" == ""
CFG=MDIApp - Win32 Release
!MESSAGE No configuration specified. Defaulting to MDIApp - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MDIApp - Win32 Release" && "$(CFG)" != "MDIApp - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDIApp.mak" CFG="MDIApp - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDIApp - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "MDIApp - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "MDIApp - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDIApp.exe"

!ELSE 

ALL : "$(OUTDIR)\MDIApp.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDIApp.obj"
	-@erase "$(INTDIR)\MDIApp.pch"
	-@erase "$(INTDIR)\MDIApp.res"
	-@erase "$(INTDIR)\MDIDoc.obj"
	-@erase "$(INTDIR)\MDIView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\MDIApp.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDIApp.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDIApp.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDIApp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\MDIApp.pdb" /machine:I386 /out:"$(OUTDIR)\MDIApp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDIApp.obj" \
	"$(INTDIR)\MDIApp.res" \
	"$(INTDIR)\MDIDoc.obj" \
	"$(INTDIR)\MDIView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDIApp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MDIApp - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDIApp.exe"

!ELSE 

ALL : "$(OUTDIR)\MDIApp.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDIApp.obj"
	-@erase "$(INTDIR)\MDIApp.pch"
	-@erase "$(INTDIR)\MDIApp.res"
	-@erase "$(INTDIR)\MDIDoc.obj"
	-@erase "$(INTDIR)\MDIView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\MDIApp.exe"
	-@erase "$(OUTDIR)\MDIApp.ilk"
	-@erase "$(OUTDIR)\MDIApp.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDIApp.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDIApp.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDIApp.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\MDIApp.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MDIApp.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDIApp.obj" \
	"$(INTDIR)\MDIApp.res" \
	"$(INTDIR)\MDIDoc.obj" \
	"$(INTDIR)\MDIView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDIApp.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "MDIApp - Win32 Release" || "$(CFG)" == "MDIApp - Win32 Debug"
SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\MDIApp.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\MDIApp.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\MDIApp.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\MDIApp.pch"


SOURCE=.\MDIApp.cpp
DEP_CPP_MDIAP=\
	".\ChildFrm.h"\
	".\MainFrm.h"\
	".\MDIApp.h"\
	".\MDIDoc.h"\
	".\MDIView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDIApp.obj" : $(SOURCE) $(DEP_CPP_MDIAP) "$(INTDIR)"\
 "$(INTDIR)\MDIApp.pch"


SOURCE=.\MDIApp.rc
DEP_RSC_MDIAPP=\
	".\res\MDIApp.ico"\
	".\res\MDIApp.rc2"\
	".\res\MDIDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\MDIApp.res" : $(SOURCE) $(DEP_RSC_MDIAPP) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MDIDoc.cpp
DEP_CPP_MDIDO=\
	".\MDIApp.h"\
	".\MDIDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDIDoc.obj" : $(SOURCE) $(DEP_CPP_MDIDO) "$(INTDIR)"\
 "$(INTDIR)\MDIApp.pch"


SOURCE=.\MDIView.cpp
DEP_CPP_MDIVI=\
	".\MDIApp.h"\
	".\MDIDoc.h"\
	".\MDIView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDIView.obj" : $(SOURCE) $(DEP_CPP_MDIVI) "$(INTDIR)"\
 "$(INTDIR)\MDIApp.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "MDIApp - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDIApp.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDIApp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MDIApp - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDIApp.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDIApp.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ChildFrm.h
SOURCE=.\MainFrm.h
SOURCE=.\MDIApp.h
SOURCE=.\MDIDoc.h
SOURCE=.\MDIView.h
SOURCE=.\StdAfx.h
SOURCE=.\res\MDIApp.ico
SOURCE=.\res\MDIApp.rc2
SOURCE=.\res\MDIDoc.ico
SOURCE=.\res\Toolbar.bmp

!ENDIF 

