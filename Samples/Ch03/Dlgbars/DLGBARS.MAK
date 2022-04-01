# Microsoft Developer Studio Generated NMAKE File, Based on DlgBars.dsp
!IF "$(CFG)" == ""
CFG=DlgBars - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to DlgBars - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "DlgBars - Win32 Release" && "$(CFG)" !=\
 "DlgBars - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "DlgBars.mak" CFG="DlgBars - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DlgBars - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DlgBars - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "DlgBars - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DlgBars.exe"

CLEAN : 
	-@erase "$(INTDIR)\DlgBars.obj"
	-@erase "$(INTDIR)\DlgBars.pch"
	-@erase "$(INTDIR)\DlgBars.res"
	-@erase "$(INTDIR)\DlgBarsDoc.obj"
	-@erase "$(INTDIR)\DlgBarsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\DlgBars.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DlgBars.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DlgBars.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DlgBars.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\DlgBars.pdb" /machine:I386 /out:"$(OUTDIR)\DlgBars.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgBars.obj" \
	"$(INTDIR)\DlgBars.res" \
	"$(INTDIR)\DlgBarsDoc.obj" \
	"$(INTDIR)\DlgBarsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DlgBars.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DlgBars - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DlgBars.exe"

CLEAN : 
	-@erase "$(INTDIR)\DlgBars.obj"
	-@erase "$(INTDIR)\DlgBars.pch"
	-@erase "$(INTDIR)\DlgBars.res"
	-@erase "$(INTDIR)\DlgBarsDoc.obj"
	-@erase "$(INTDIR)\DlgBarsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\DlgBars.exe"
	-@erase "$(OUTDIR)\DlgBars.ilk"
	-@erase "$(OUTDIR)\DlgBars.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DlgBars.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\DlgBars.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DlgBars.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\DlgBars.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DlgBars.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgBars.obj" \
	"$(INTDIR)\DlgBars.res" \
	"$(INTDIR)\DlgBarsDoc.obj" \
	"$(INTDIR)\DlgBarsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\DlgBars.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "DlgBars - Win32 Release" || "$(CFG)" ==\
 "DlgBars - Win32 Debug"
SOURCE=.\DlgBars.cpp
DEP_CPP_DLGBA=\
	".\DlgBars.h"\
	".\DlgBarsDoc.h"\
	".\DlgBarsView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DlgBars.obj" : $(SOURCE) $(DEP_CPP_DLGBA) "$(INTDIR)"\
 "$(INTDIR)\DlgBars.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\DlgBars.rc
DEP_RSC_DLGBAR=\
	".\res\blue.ico"\
	".\res\DlgBars.ico"\
	".\res\DlgBars.rc2"\
	".\res\DlgBarsDoc.ico"\
	".\res\red.ico"\
	

"$(INTDIR)\DlgBars.res" : $(SOURCE) $(DEP_RSC_DLGBAR) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\DlgBarsDoc.cpp
DEP_CPP_DLGBARS=\
	".\DlgBars.h"\
	".\DlgBarsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DlgBarsDoc.obj" : $(SOURCE) $(DEP_CPP_DLGBARS) "$(INTDIR)"\
 "$(INTDIR)\DlgBars.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\DlgBarsView.cpp
DEP_CPP_DLGBARSV=\
	".\DlgBars.h"\
	".\DlgBarsDoc.h"\
	".\DlgBarsView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DlgBarsView.obj" : $(SOURCE) $(DEP_CPP_DLGBARSV) "$(INTDIR)"\
 "$(INTDIR)\DlgBars.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\DlgBars.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\DlgBars.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "DlgBars - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DlgBars.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DlgBars.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DlgBars - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\DlgBars.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DlgBars.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DlgBars.h
SOURCE=.\DlgBarsDoc.h
SOURCE=.\DlgBarsView.h
SOURCE=.\MainFrm.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\res\blue.ico
SOURCE=.\res\DlgBars.ico
SOURCE=.\res\DlgBars.rc2
SOURCE=.\res\DlgBarsDoc.ico
SOURCE=.\res\red.ico

!ENDIF 

