# Microsoft Developer Studio Generated NMAKE File, Based on TreeWimg.dsp
!IF "$(CFG)" == ""
CFG=TreeWimg - Win32 Release
!MESSAGE No configuration specified. Defaulting to TreeWimg - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "TreeWimg - Win32 Release" && "$(CFG)" !=\
 "TreeWimg - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TreeWimg.mak" CFG="TreeWimg - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TreeWimg - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "TreeWimg - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "TreeWimg - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TreeWimg.exe"

!ELSE 

ALL : "$(OUTDIR)\TreeWimg.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimgDoc.obj"
	-@erase "$(INTDIR)\TimgView.obj"
	-@erase "$(INTDIR)\TreeWimg.obj"
	-@erase "$(INTDIR)\TreeWimg.pch"
	-@erase "$(INTDIR)\TreeWimg.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\TreeWimg.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TreeWimg.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TreeWimg.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TreeWimg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\TreeWimg.pdb" /machine:I386 /out:"$(OUTDIR)\TreeWimg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimgDoc.obj" \
	"$(INTDIR)\TimgView.obj" \
	"$(INTDIR)\TreeWimg.obj" \
	"$(INTDIR)\TreeWimg.res"

"$(OUTDIR)\TreeWimg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TreeWimg - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\TreeWimg.exe"

!ELSE 

ALL : "$(OUTDIR)\TreeWimg.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TimgDoc.obj"
	-@erase "$(INTDIR)\TimgView.obj"
	-@erase "$(INTDIR)\TreeWimg.obj"
	-@erase "$(INTDIR)\TreeWimg.pch"
	-@erase "$(INTDIR)\TreeWimg.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\TreeWimg.exe"
	-@erase "$(OUTDIR)\TreeWimg.ilk"
	-@erase "$(OUTDIR)\TreeWimg.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TreeWimg.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\TreeWimg.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TreeWimg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\TreeWimg.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\TreeWimg.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TimgDoc.obj" \
	"$(INTDIR)\TimgView.obj" \
	"$(INTDIR)\TreeWimg.obj" \
	"$(INTDIR)\TreeWimg.res"

"$(OUTDIR)\TreeWimg.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "TreeWimg - Win32 Release" || "$(CFG)" ==\
 "TreeWimg - Win32 Debug"
SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TreeWimg.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\TreeWimg.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "TreeWimg - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TreeWimg.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TreeWimg.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TreeWimg - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\TreeWimg.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TreeWimg.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TimgDoc.cpp
DEP_CPP_TIMGD=\
	".\StdAfx.h"\
	".\TimgDoc.h"\
	".\TreeWimg.h"\
	

"$(INTDIR)\TimgDoc.obj" : $(SOURCE) $(DEP_CPP_TIMGD) "$(INTDIR)"\
 "$(INTDIR)\TreeWimg.pch"


SOURCE=.\TimgView.cpp
DEP_CPP_TIMGV=\
	".\StdAfx.h"\
	".\TimgDoc.h"\
	".\TimgView.h"\
	".\TreeWimg.h"\
	

"$(INTDIR)\TimgView.obj" : $(SOURCE) $(DEP_CPP_TIMGV) "$(INTDIR)"\
 "$(INTDIR)\TreeWimg.pch"


SOURCE=.\TreeWimg.cpp
DEP_CPP_TREEW=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TimgDoc.h"\
	".\TimgView.h"\
	".\TreeWimg.h"\
	

"$(INTDIR)\TreeWimg.obj" : $(SOURCE) $(DEP_CPP_TREEW) "$(INTDIR)"\
 "$(INTDIR)\TreeWimg.pch"


SOURCE=.\TreeWimg.rc
DEP_RSC_TREEWI=\
	".\res\amph_sel.bmp"\
	".\res\amphibia.bmp"\
	".\res\bird.bmp"\
	".\res\bird_sel.bmp"\
	".\res\fish.bmp"\
	".\res\fish_sel.bmp"\
	".\res\mammal.bmp"\
	".\res\mammal_s.bmp"\
	".\res\rept_sel.bmp"\
	".\res\reptile.bmp"\
	".\res\Toolbar.bmp"\
	".\res\TreeDoc.ico"\
	".\res\TreeWimg.ico"\
	".\res\TreeWimg.rc2"\
	

"$(INTDIR)\TreeWimg.res" : $(SOURCE) $(DEP_RSC_TREEWI) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MainFrm.h
SOURCE=.\StdAfx.h
SOURCE=.\TimgDoc.h
SOURCE=.\TimgView.h
SOURCE=.\TreeWimg.h
SOURCE=.\res\amph_sel.bmp
SOURCE=.\res\amphibia.bmp
SOURCE=.\res\bird.bmp
SOURCE=.\res\bird_sel.bmp
SOURCE=.\res\fish.bmp
SOURCE=.\res\fish_sel.bmp
SOURCE=.\res\mammal.bmp
SOURCE=.\res\mammal_s.bmp
SOURCE=.\res\rept_sel.bmp
SOURCE=.\res\reptile.bmp
SOURCE=.\res\Toolbar.bmp
SOURCE=.\res\TreeDoc.ico
SOURCE=.\res\TreeWimg.ico
SOURCE=.\res\TreeWimg.rc2

!ENDIF 

