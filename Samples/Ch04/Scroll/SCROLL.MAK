# Microsoft Developer Studio Generated NMAKE File, Based on Scroll.dsp
!IF "$(CFG)" == ""
CFG=Scroll - Win32 Release
!MESSAGE No configuration specified. Defaulting to Scroll - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Scroll - Win32 Release" && "$(CFG)" != "Scroll - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Scroll.mak" CFG="Scroll - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Scroll - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "Scroll - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Scroll - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Scroll.exe"

!ELSE 

ALL : "$(OUTDIR)\Scroll.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\ScrolDoc.obj"
	-@erase "$(INTDIR)\Scroll.obj"
	-@erase "$(INTDIR)\Scroll.pch"
	-@erase "$(INTDIR)\Scroll.res"
	-@erase "$(INTDIR)\ScroView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Scroll.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Scroll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Scroll.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Scroll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Scroll.pdb" /machine:I386 /out:"$(OUTDIR)\Scroll.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\ScrolDoc.obj" \
	"$(INTDIR)\Scroll.obj" \
	"$(INTDIR)\Scroll.res" \
	"$(INTDIR)\ScroView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Scroll.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Scroll - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Scroll.exe"

!ELSE 

ALL : "$(OUTDIR)\Scroll.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\ScrolDoc.obj"
	-@erase "$(INTDIR)\Scroll.obj"
	-@erase "$(INTDIR)\Scroll.pch"
	-@erase "$(INTDIR)\Scroll.res"
	-@erase "$(INTDIR)\ScroView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Scroll.exe"
	-@erase "$(OUTDIR)\Scroll.ilk"
	-@erase "$(OUTDIR)\Scroll.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Scroll.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Scroll.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Scroll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Scroll.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Scroll.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\ScrolDoc.obj" \
	"$(INTDIR)\Scroll.obj" \
	"$(INTDIR)\Scroll.res" \
	"$(INTDIR)\ScroView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Scroll.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "Scroll - Win32 Release" || "$(CFG)" == "Scroll - Win32 Debug"
SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\Scroll.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Scroll.pch"


SOURCE=.\ScrolDoc.cpp
DEP_CPP_SCROL=\
	".\ScrolDoc.h"\
	".\Scroll.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ScrolDoc.obj" : $(SOURCE) $(DEP_CPP_SCROL) "$(INTDIR)"\
 "$(INTDIR)\Scroll.pch"


SOURCE=.\Scroll.cpp
DEP_CPP_SCROLL=\
	".\MainFrm.h"\
	".\ScrolDoc.h"\
	".\Scroll.h"\
	".\ScroView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Scroll.obj" : $(SOURCE) $(DEP_CPP_SCROLL) "$(INTDIR)"\
 "$(INTDIR)\Scroll.pch"


SOURCE=.\Scroll.rc
DEP_RSC_SCROLL_=\
	".\res\ScrolDoc.ico"\
	".\res\Scroll.ico"\
	".\res\Scroll.rc2"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\Scroll.res" : $(SOURCE) $(DEP_RSC_SCROLL_) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ScroView.cpp
DEP_CPP_SCROV=\
	".\ScrolDoc.h"\
	".\Scroll.h"\
	".\ScroView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ScroView.obj" : $(SOURCE) $(DEP_CPP_SCROV) "$(INTDIR)"\
 "$(INTDIR)\Scroll.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Scroll - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Scroll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Scroll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Scroll - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Scroll.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Scroll.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\MainFrm.h
SOURCE=.\ScrolDoc.h
SOURCE=.\Scroll.h
SOURCE=.\ScroView.h
SOURCE=.\StdAfx.h
SOURCE=.\res\ScrolDoc.ico
SOURCE=.\res\Scroll.ico
SOURCE=.\res\Scroll.rc2
SOURCE=.\res\Toolbar.bmp

!ENDIF 

