# Microsoft Developer Studio Generated NMAKE File, Based on Diff.dsp
!IF "$(CFG)" == ""
CFG=diff - Win32 Release
!MESSAGE No configuration specified. Defaulting to diff - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "diff - Win32 Release" && "$(CFG)" != "diff - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Diff.mak" CFG="diff - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "diff - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "diff - Win32 Debug" (based on "Win32 (x86) Win32 Application")
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

!IF  "$(CFG)" == "diff - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Diff.exe" "$(OUTDIR)\Diff.bsc"

!ELSE 

ALL : "$(OUTDIR)\Diff.exe" "$(OUTDIR)\Diff.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Diff.obj"
	-@erase "$(INTDIR)\Diff.pch"
	-@erase "$(INTDIR)\diff.res"
	-@erase "$(INTDIR)\Diff.sbr"
	-@erase "$(INTDIR)\diffdoc.obj"
	-@erase "$(INTDIR)\diffdoc.sbr"
	-@erase "$(INTDIR)\Diffview.obj"
	-@erase "$(INTDIR)\Diffview.sbr"
	-@erase "$(INTDIR)\DlgOpenF.obj"
	-@erase "$(INTDIR)\DlgOpenF.sbr"
	-@erase "$(INTDIR)\FileOpenEx.obj"
	-@erase "$(INTDIR)\FileOpenEx.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Progress.obj"
	-@erase "$(INTDIR)\Progress.sbr"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Splitter.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Diff.bsc"
	-@erase "$(OUTDIR)\Diff.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Diff.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\diff.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Diff.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Diff.sbr" \
	"$(INTDIR)\diffdoc.sbr" \
	"$(INTDIR)\Diffview.sbr" \
	"$(INTDIR)\DlgOpenF.sbr" \
	"$(INTDIR)\FileOpenEx.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Progress.sbr" \
	"$(INTDIR)\Splitter.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\Diff.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Diff.pdb" /machine:I386 /out:"$(OUTDIR)\Diff.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Diff.obj" \
	"$(INTDIR)\diff.res" \
	"$(INTDIR)\diffdoc.obj" \
	"$(INTDIR)\Diffview.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
	"$(INTDIR)\FileOpenEx.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Progress.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\Diff.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "diff - Win32 Debug"

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
	-@erase "$(INTDIR)\diff.res"
	-@erase "$(INTDIR)\diffdoc.obj"
	-@erase "$(INTDIR)\Diffview.obj"
	-@erase "$(INTDIR)\DlgOpenF.obj"
	-@erase "$(INTDIR)\FileOpenEx.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Progress.obj"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Diff.exe"
	-@erase "$(OUTDIR)\Diff.ilk"
	-@erase "$(OUTDIR)\Diff.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\diff.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Diff.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Diff.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Diff.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Diff.obj" \
	"$(INTDIR)\diff.res" \
	"$(INTDIR)\diffdoc.obj" \
	"$(INTDIR)\Diffview.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
	"$(INTDIR)\FileOpenEx.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Progress.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\Diff.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "diff - Win32 Release" || "$(CFG)" == "diff - Win32 Debug"
SOURCE=.\Diff.cpp
DEP_CPP_DIFF_=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\Diffview.h"\
	".\Mainfrm.h"\
	".\progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\Diff.obj"	"$(INTDIR)\Diff.sbr" : $(SOURCE) $(DEP_CPP_DIFF_)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\Diff.obj" : $(SOURCE) $(DEP_CPP_DIFF_) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\diff.rc
DEP_RSC_DIFF_R=\
	".\Res\Diff.ico"\
	".\Res\Diff.rc2"\
	".\Res\Diffdoc.ico"\
	".\Res\Toolbar.bmp"\
	

"$(INTDIR)\diff.res" : $(SOURCE) $(DEP_RSC_DIFF_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\diffdoc.cpp
DEP_CPP_DIFFD=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\Diffview.h"\
	".\DlgOpenF.h"\
	".\Mainfrm.h"\
	".\progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\diffdoc.obj"	"$(INTDIR)\diffdoc.sbr" : $(SOURCE) $(DEP_CPP_DIFFD)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\diffdoc.obj" : $(SOURCE) $(DEP_CPP_DIFFD) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\Diffview.cpp
DEP_CPP_DIFFV=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\Diffview.h"\
	".\Mainfrm.h"\
	".\progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\Diffview.obj"	"$(INTDIR)\Diffview.sbr" : $(SOURCE) $(DEP_CPP_DIFFV)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\Diffview.obj" : $(SOURCE) $(DEP_CPP_DIFFV) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\DlgOpenF.cpp
DEP_CPP_DLGOP=\
	".\Diff.h"\
	".\DlgOpenF.h"\
	".\FileOpenEx.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\DlgOpenF.obj"	"$(INTDIR)\DlgOpenF.sbr" : $(SOURCE) $(DEP_CPP_DLGOP)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\DlgOpenF.obj" : $(SOURCE) $(DEP_CPP_DLGOP) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\FileOpenEx.cpp
DEP_CPP_FILEO=\
	".\Diff.h"\
	".\FileOpenEx.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\FileOpenEx.obj"	"$(INTDIR)\FileOpenEx.sbr" : $(SOURCE)\
 $(DEP_CPP_FILEO) "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\FileOpenEx.obj" : $(SOURCE) $(DEP_CPP_FILEO) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\Mainfrm.cpp
DEP_CPP_MAINF=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\Diffview.h"\
	".\Mainfrm.h"\
	".\progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\Mainfrm.obj"	"$(INTDIR)\Mainfrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\Progress.cpp
DEP_CPP_PROGR=\
	".\Diff.h"\
	".\progress.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\Progress.obj"	"$(INTDIR)\Progress.sbr" : $(SOURCE) $(DEP_CPP_PROGR)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\Progress.obj" : $(SOURCE) $(DEP_CPP_PROGR) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\Readme.txt
SOURCE=.\Splitter.cpp
DEP_CPP_SPLIT=\
	".\Diff.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"


"$(INTDIR)\Splitter.obj"	"$(INTDIR)\Splitter.sbr" : $(SOURCE) $(DEP_CPP_SPLIT)\
 "$(INTDIR)" "$(INTDIR)\Diff.pch"


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"


"$(INTDIR)\Splitter.obj" : $(SOURCE) $(DEP_CPP_SPLIT) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


!ENDIF 

SOURCE=.\Stdafx.cpp

!IF  "$(CFG)" == "diff - Win32 Release"

DEP_CPP_STDAF=\
	".\Stdafx.h"\
	
CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\Diff.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Diff.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Diff.h
SOURCE=.\diffdoc.h
SOURCE=.\Diffview.h
SOURCE=.\DlgOpenF.h
SOURCE=.\FileOpenEx.h
SOURCE=.\Mainfrm.h
SOURCE=.\progress.h
SOURCE=.\Splitter.h
SOURCE=.\Stdafx.h
SOURCE=.\Res\Diff.ico
SOURCE=.\Res\Diff.rc2
SOURCE=.\Res\Diffdoc.ico
SOURCE=.\Res\Toolbar.bmp

!ENDIF 

