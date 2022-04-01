# Microsoft Developer Studio Generated NMAKE File, Based on splitter.dsp
!IF "$(CFG)" == ""
CFG=splitter - Win32 Release
!MESSAGE No configuration specified. Defaulting to splitter - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "splitter - Win32 Release" && "$(CFG)" !=\
 "splitter - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "splitter.mak" CFG="splitter - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "splitter - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "splitter - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "splitter - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\splitter.exe"

!ELSE 

ALL : "$(OUTDIR)\splitter.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ItalView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SplitDoc.obj"
	-@erase "$(INTDIR)\splitter.obj"
	-@erase "$(INTDIR)\splitter.pch"
	-@erase "$(INTDIR)\splitter.res"
	-@erase "$(INTDIR)\SpltView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\splitter.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\splitter.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\splitter.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\splitter.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\splitter.pdb" /machine:I386 /out:"$(OUTDIR)\splitter.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ItalView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SplitDoc.obj" \
	"$(INTDIR)\splitter.obj" \
	"$(INTDIR)\splitter.res" \
	"$(INTDIR)\SpltView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\splitter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "splitter - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\splitter.exe"

!ELSE 

ALL : "$(OUTDIR)\splitter.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ItalView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SplitDoc.obj"
	-@erase "$(INTDIR)\splitter.obj"
	-@erase "$(INTDIR)\splitter.pch"
	-@erase "$(INTDIR)\splitter.res"
	-@erase "$(INTDIR)\SpltView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\splitter.exe"
	-@erase "$(OUTDIR)\splitter.ilk"
	-@erase "$(OUTDIR)\splitter.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\splitter.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\splitter.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\splitter.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\splitter.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\splitter.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ItalView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SplitDoc.obj" \
	"$(INTDIR)\splitter.obj" \
	"$(INTDIR)\splitter.res" \
	"$(INTDIR)\SpltView.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\splitter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "splitter - Win32 Release" || "$(CFG)" ==\
 "splitter - Win32 Debug"
SOURCE=.\ItalView.cpp
DEP_CPP_ITALV=\
	".\ItalView.h"\
	".\SplitDoc.h"\
	".\splitter.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ItalView.obj" : $(SOURCE) $(DEP_CPP_ITALV) "$(INTDIR)"\
 "$(INTDIR)\splitter.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\ItalView.h"\
	".\MainFrm.h"\
	".\SplitDoc.h"\
	".\splitter.h"\
	".\spltView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\splitter.pch"


SOURCE=.\SplitDoc.cpp
DEP_CPP_SPLIT=\
	".\SplitDoc.h"\
	".\splitter.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\SplitDoc.obj" : $(SOURCE) $(DEP_CPP_SPLIT) "$(INTDIR)"\
 "$(INTDIR)\splitter.pch"


SOURCE=.\splitter.cpp
DEP_CPP_SPLITT=\
	".\ItalView.h"\
	".\MainFrm.h"\
	".\SplitDoc.h"\
	".\splitter.h"\
	".\spltView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\splitter.obj" : $(SOURCE) $(DEP_CPP_SPLITT) "$(INTDIR)"\
 "$(INTDIR)\splitter.pch"


SOURCE=.\splitter.rc
DEP_RSC_SPLITTE=\
	".\res\splitDoc.ico"\
	".\res\splitter.ico"\
	".\res\splitter.rc2"\
	

"$(INTDIR)\splitter.res" : $(SOURCE) $(DEP_RSC_SPLITTE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\SpltView.cpp
DEP_CPP_SPLTV=\
	".\SplitDoc.h"\
	".\splitter.h"\
	".\spltView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\SpltView.obj" : $(SOURCE) $(DEP_CPP_SPLTV) "$(INTDIR)"\
 "$(INTDIR)\splitter.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "splitter - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\splitter.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\splitter.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "splitter - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\splitter.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\splitter.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ItalView.h
SOURCE=.\MainFrm.h
SOURCE=.\SplitDoc.h
SOURCE=.\splitter.h
SOURCE=.\spltView.h
SOURCE=.\StdAfx.h
SOURCE=.\res\splitDoc.ico
SOURCE=.\res\splitter.ico
SOURCE=.\res\splitter.rc2

!ENDIF 

