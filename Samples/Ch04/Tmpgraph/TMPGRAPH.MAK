# Microsoft Developer Studio Generated NMAKE File, Based on TmpGraph.dsp
!IF "$(CFG)" == ""
CFG=TmpGraph - Win32 Release
!MESSAGE No configuration specified. Defaulting to TmpGraph - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TmpGraph - Win32 Release" && "$(CFG)" !=\
 "TmpGraph - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TmpGraph.mak" CFG="TmpGraph - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TmpGraph - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "TmpGraph - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "TmpGraph - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TmpGraph.exe"

!ELSE 

ALL : "$(OUTDIR)\TmpGraph.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\GrafView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NumbView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TGrafDoc.obj"
	-@erase "$(INTDIR)\TmpGraph.obj"
	-@erase "$(INTDIR)\TmpGraph.pch"
	-@erase "$(INTDIR)\TmpGraph.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\TmpGraph.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TmpGraph.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TmpGraph.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TmpGraph.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\TmpGraph.pdb" /machine:I386 /out:"$(OUTDIR)\TmpGraph.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\GrafView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NumbView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TGrafDoc.obj" \
	"$(INTDIR)\TmpGraph.obj" \
	"$(INTDIR)\TmpGraph.res"

"$(OUTDIR)\TmpGraph.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TmpGraph - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TmpGraph.exe"

!ELSE 

ALL : "$(OUTDIR)\TmpGraph.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\GrafView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NumbView.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TGrafDoc.obj"
	-@erase "$(INTDIR)\TmpGraph.obj"
	-@erase "$(INTDIR)\TmpGraph.pch"
	-@erase "$(INTDIR)\TmpGraph.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\TmpGraph.exe"
	-@erase "$(OUTDIR)\TmpGraph.ilk"
	-@erase "$(OUTDIR)\TmpGraph.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TmpGraph.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TmpGraph.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TmpGraph.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\TmpGraph.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\TmpGraph.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\GrafView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NumbView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TGrafDoc.obj" \
	"$(INTDIR)\TmpGraph.obj" \
	"$(INTDIR)\TmpGraph.res"

"$(OUTDIR)\TmpGraph.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "TmpGraph - Win32 Release" || "$(CFG)" ==\
 "TmpGraph - Win32 Debug"
SOURCE=.\Dialogs.cpp
DEP_CPP_DIALO=\
	".\Dialogs.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\GrafView.cpp
DEP_CPP_GRAFV=\
	".\GrafView.h"\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\GrafView.obj" : $(SOURCE) $(DEP_CPP_GRAFV) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\Dialogs.h"\
	".\GrafView.h"\
	".\MainFrm.h"\
	".\NumbView.h"\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\NumbView.cpp
DEP_CPP_NUMBV=\
	".\NumbView.h"\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\NumbView.obj" : $(SOURCE) $(DEP_CPP_NUMBV) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "TmpGraph - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TmpGraph.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TmpGraph.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TmpGraph - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TmpGraph.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TmpGraph.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TGrafDoc.cpp
DEP_CPP_TGRAF=\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\TGrafDoc.obj" : $(SOURCE) $(DEP_CPP_TGRAF) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\TmpGraph.cpp
DEP_CPP_TMPGR=\
	".\Dialogs.h"\
	".\GrafView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TGrafDoc.h"\
	".\TmpGraph.h"\
	

"$(INTDIR)\TmpGraph.obj" : $(SOURCE) $(DEP_CPP_TMPGR) "$(INTDIR)"\
 "$(INTDIR)\TmpGraph.pch"


SOURCE=.\TmpGraph.rc
DEP_RSC_TMPGRA=\
	".\res\TGrafDoc.ico"\
	".\res\TmpGraph.ico"\
	".\res\TmpGraph.rc2"\
	

"$(INTDIR)\TmpGraph.res" : $(SOURCE) $(DEP_RSC_TMPGRA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\Dialogs.h
SOURCE=.\GrafView.h
SOURCE=.\MainFrm.h
SOURCE=.\NumbView.h
SOURCE=.\StdAfx.h
SOURCE=.\TGrafDoc.h
SOURCE=.\TmpGraph.h
SOURCE=.\res\TGrafDoc.ico
SOURCE=.\res\TmpGraph.ico
SOURCE=.\res\TmpGraph.rc2

!ENDIF 

