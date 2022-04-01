# Microsoft Developer Studio Generated NMAKE File, Based on Diff.dsp
!IF "$(CFG)" == ""
CFG=Diff - Win32 Release
!MESSAGE No configuration specified. Defaulting to Diff - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Diff - Win32 Release" && "$(CFG)" != "Diff - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Diff.mak" CFG="Diff - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Diff - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "Diff - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Diff - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Diff.exe"

!ELSE 

ALL : "$(OUTDIR)\Diff.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Diff.obj"
	-@erase "$(INTDIR)\Diff.pch"
	-@erase "$(INTDIR)\Diff.res"
	-@erase "$(INTDIR)\DiffDoc.obj"
	-@erase "$(INTDIR)\DiffView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Diff.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Diff.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Diff.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Diff.pdb" /machine:I386 /out:"$(OUTDIR)\Diff.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Diff.obj" \
	"$(INTDIR)\Diff.res" \
	"$(INTDIR)\DiffDoc.obj" \
	"$(INTDIR)\DiffView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Diff.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Diff - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Diff.exe"

!ELSE 

ALL : "$(OUTDIR)\Diff.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Diff.obj"
	-@erase "$(INTDIR)\Diff.pch"
	-@erase "$(INTDIR)\Diff.res"
	-@erase "$(INTDIR)\DiffDoc.obj"
	-@erase "$(INTDIR)\DiffView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Diff.exe"
	-@erase "$(OUTDIR)\Diff.ilk"
	-@erase "$(OUTDIR)\Diff.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Diff.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Diff.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Diff.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Diff.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Diff.obj" \
	"$(INTDIR)\Diff.res" \
	"$(INTDIR)\DiffDoc.obj" \
	"$(INTDIR)\DiffView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Diff.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "Diff - Win32 Release" || "$(CFG)" == "Diff - Win32 Debug"
SOURCE=.\Diff.cpp
DEP_CPP_DIFF_=\
	".\Diff.h"\
	".\DiffDoc.h"\
	".\DiffView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Diff.obj" : $(SOURCE) $(DEP_CPP_DIFF_) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Diff.rc
DEP_RSC_DIFF_R=\
	".\res\Diff.ico"\
	".\res\Diff.rc2"\
	".\res\DiffDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\Diff.res" : $(SOURCE) $(DEP_RSC_DIFF_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DiffDoc.cpp
DEP_CPP_DIFFD=\
	".\Diff.h"\
	".\DiffDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DiffDoc.obj" : $(SOURCE) $(DEP_CPP_DIFFD) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\DiffView.cpp
DEP_CPP_DIFFV=\
	".\Diff.h"\
	".\DiffDoc.h"\
	".\DiffView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DiffView.obj" : $(SOURCE) $(DEP_CPP_DIFFV) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\Diff.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Diff - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Diff.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Diff - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Diff.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Diff.h
SOURCE=.\DiffDoc.h
SOURCE=.\DiffView.h
SOURCE=.\MainFrm.h
SOURCE=.\StdAfx.h

!ENDIF 

