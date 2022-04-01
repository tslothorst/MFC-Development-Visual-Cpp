# Microsoft Developer Studio Generated NMAKE File, Based on DynaMenu.dsp
!IF "$(CFG)" == ""
CFG=DynaMenu - Win32 Release
!MESSAGE No configuration specified. Defaulting to DynaMenu - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "DynaMenu - Win32 Release" && "$(CFG)" !=\
 "DynaMenu - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DynaMenu.mak" CFG="DynaMenu - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DynaMenu - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DynaMenu - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "DynaMenu - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DynaMenu.exe"

!ELSE 

ALL : "$(OUTDIR)\DynaMenu.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DynaMDoc.obj"
	-@erase "$(INTDIR)\DynaMenu.obj"
	-@erase "$(INTDIR)\DynaMenu.pch"
	-@erase "$(INTDIR)\DynaMenu.res"
	-@erase "$(INTDIR)\DynaView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DynaMenu.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DynaMenu.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DynaMenu.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DynaMenu.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\DynaMenu.pdb" /machine:I386 /out:"$(OUTDIR)\DynaMenu.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DynaMDoc.obj" \
	"$(INTDIR)\DynaMenu.obj" \
	"$(INTDIR)\DynaMenu.res" \
	"$(INTDIR)\DynaView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DynaMenu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DynaMenu - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\DynaMenu.exe"

!ELSE 

ALL : "$(OUTDIR)\DynaMenu.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DynaMDoc.obj"
	-@erase "$(INTDIR)\DynaMenu.obj"
	-@erase "$(INTDIR)\DynaMenu.pch"
	-@erase "$(INTDIR)\DynaMenu.res"
	-@erase "$(INTDIR)\DynaView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DynaMenu.exe"
	-@erase "$(OUTDIR)\DynaMenu.ilk"
	-@erase "$(OUTDIR)\DynaMenu.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DynaMenu.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DynaMenu.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DynaMenu.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\DynaMenu.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\DynaMenu.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DynaMDoc.obj" \
	"$(INTDIR)\DynaMenu.obj" \
	"$(INTDIR)\DynaMenu.res" \
	"$(INTDIR)\DynaView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DynaMenu.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "DynaMenu - Win32 Release" || "$(CFG)" ==\
 "DynaMenu - Win32 Debug"
SOURCE=.\DynaMDoc.cpp
DEP_CPP_DYNAM=\
	".\DynaMDoc.h"\
	".\DynaMenu.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DynaMDoc.obj" : $(SOURCE) $(DEP_CPP_DYNAM) "$(INTDIR)"\
 "$(INTDIR)\DynaMenu.pch"


SOURCE=.\DynaMenu.cpp
DEP_CPP_DYNAME=\
	".\DynaMDoc.h"\
	".\DynaMenu.h"\
	".\DynaView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DynaMenu.obj" : $(SOURCE) $(DEP_CPP_DYNAME) "$(INTDIR)"\
 "$(INTDIR)\DynaMenu.pch"


SOURCE=.\DynaMenu.rc
DEP_RSC_DYNAMEN=\
	".\res\DynaMDoc.ico"\
	".\res\DynaMenu.ico"\
	".\res\DynaMenu.rc2"\
	

"$(INTDIR)\DynaMenu.res" : $(SOURCE) $(DEP_RSC_DYNAMEN) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DynaView.cpp
DEP_CPP_DYNAV=\
	".\DynaMDoc.h"\
	".\DynaMenu.h"\
	".\DynaView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DynaView.obj" : $(SOURCE) $(DEP_CPP_DYNAV) "$(INTDIR)"\
 "$(INTDIR)\DynaMenu.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\DynaMenu.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\DynaMenu.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "DynaMenu - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DynaMenu.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DynaMenu.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DynaMenu - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DynaMenu.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DynaMenu.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

