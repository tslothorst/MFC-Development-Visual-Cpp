# Microsoft Developer Studio Generated NMAKE File, Based on IC_2.DSP
!IF "$(CFG)" == ""
CFG=IC_2 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to IC_2 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "IC_2 - Win32 Release" && "$(CFG)" != "IC_2 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "IC_2.MAK" CFG="IC_2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "IC_2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "IC_2 - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "IC_2 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\IC_2.exe"

!ELSE 

ALL : "$(OUTDIR)\IC_2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\IC_2.obj"
	-@erase "$(INTDIR)\IC_2.pch"
	-@erase "$(INTDIR)\IC_2.res"
	-@erase "$(INTDIR)\IC_2Doc.obj"
	-@erase "$(INTDIR)\IC_2View.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\URLDialog.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\IC_2.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\IC_2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\IC_2.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\IC_2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\IC_2.pdb" /machine:I386 /out:"$(OUTDIR)\IC_2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IC_2.obj" \
	"$(INTDIR)\IC_2.res" \
	"$(INTDIR)\IC_2Doc.obj" \
	"$(INTDIR)\IC_2View.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\URLDialog.obj"

"$(OUTDIR)\IC_2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "IC_2 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\IC_2.exe"

!ELSE 

ALL : "$(OUTDIR)\IC_2.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\IC_2.obj"
	-@erase "$(INTDIR)\IC_2.pch"
	-@erase "$(INTDIR)\IC_2.res"
	-@erase "$(INTDIR)\IC_2Doc.obj"
	-@erase "$(INTDIR)\IC_2View.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\URLDialog.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\IC_2.exe"
	-@erase "$(OUTDIR)\IC_2.ilk"
	-@erase "$(OUTDIR)\IC_2.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\IC_2.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\IC_2.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\IC_2.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\IC_2.pdb" /debug /machine:I386 /out:"$(OUTDIR)\IC_2.exe" 
LINK32_OBJS= \
	"$(INTDIR)\IC_2.obj" \
	"$(INTDIR)\IC_2.res" \
	"$(INTDIR)\IC_2Doc.obj" \
	"$(INTDIR)\IC_2View.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\URLDialog.obj"

"$(OUTDIR)\IC_2.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "IC_2 - Win32 Release" || "$(CFG)" == "IC_2 - Win32 Debug"
SOURCE=.\IC_2.cpp
DEP_CPP_IC_2_=\
	".\IC_2.h"\
	".\IC_2Doc.h"\
	".\IC_2View.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\IC_2.obj" : $(SOURCE) $(DEP_CPP_IC_2_) "$(INTDIR)"\
 "$(INTDIR)\IC_2.pch"


SOURCE=.\IC_2.rc
DEP_RSC_IC_2_R=\
	".\res\IC_2.ico"\
	".\res\IC_2.rc2"\
	".\res\IC_2Doc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\IC_2.res" : $(SOURCE) $(DEP_RSC_IC_2_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\IC_2Doc.cpp
DEP_CPP_IC_2D=\
	".\IC_2.h"\
	".\IC_2Doc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\IC_2Doc.obj" : $(SOURCE) $(DEP_CPP_IC_2D) "$(INTDIR)"\
 "$(INTDIR)\IC_2.pch"


SOURCE=.\IC_2View.cpp
DEP_CPP_IC_2V=\
	".\IC_2.h"\
	".\IC_2Doc.h"\
	".\IC_2View.h"\
	".\StdAfx.h"\
	".\URLDialog.h"\
	

"$(INTDIR)\IC_2View.obj" : $(SOURCE) $(DEP_CPP_IC_2V) "$(INTDIR)"\
 "$(INTDIR)\IC_2.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\IC_2.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\IC_2.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "IC_2 - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\IC_2.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\IC_2.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "IC_2 - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\IC_2.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\IC_2.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\URLDialog.cpp
DEP_CPP_URLDI=\
	".\IC_2.h"\
	".\StdAfx.h"\
	".\URLDialog.h"\
	

"$(INTDIR)\URLDialog.obj" : $(SOURCE) $(DEP_CPP_URLDI) "$(INTDIR)"\
 "$(INTDIR)\IC_2.pch"



!ENDIF 

