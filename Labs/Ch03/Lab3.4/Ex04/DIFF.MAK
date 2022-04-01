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
!MESSAGE "diff - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "diff - Win32 Debug" (based on "Win32 (x86) Application")
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
	-@erase "$(INTDIR)\DlgFilex.obj"
	-@erase "$(INTDIR)\DlgOpenF.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Progress.obj"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Diff.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
F90_OBJS=.\Release/
F90_PROJ=/I "Debug/" /Fo"Debug/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\diff.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Diff.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Diff.pdb" /machine:I386 /out:"$(OUTDIR)\Diff.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Diff.obj" \
	"$(INTDIR)\diff.res" \
	"$(INTDIR)\diffdoc.obj" \
	"$(INTDIR)\Diffview.obj" \
	"$(INTDIR)\DlgFilex.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
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
	-@erase "$(INTDIR)\DlgFilex.obj"
	-@erase "$(INTDIR)\DlgOpenF.obj"
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
F90_OBJS=.\Debug/
F90_PROJ=/I "Debug/" /Fo"Debug/" 

.for{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

.f90{$(F90_OBJS)}.obj:
   $(F90) $(F90_PROJ) $<  

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
	"$(INTDIR)\DlgFilex.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
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
	".\diffview.h"\
	".\Mainfrm.h"\
	".\Progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\Diff.obj" : $(SOURCE) $(DEP_CPP_DIFF_) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


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
	".\diffview.h"\
	".\DlgOpenF.h"\
	".\Mainfrm.h"\
	".\Progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\diffdoc.obj" : $(SOURCE) $(DEP_CPP_DIFFD) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Diffview.cpp
DEP_CPP_DIFFV=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\diffview.h"\
	".\Mainfrm.h"\
	".\Progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\Diffview.obj" : $(SOURCE) $(DEP_CPP_DIFFV) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\DlgFilex.cpp
DEP_CPP_DLGFI=\
	".\Diff.h"\
	".\dlgfilex.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\DlgFilex.obj" : $(SOURCE) $(DEP_CPP_DLGFI) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\DlgOpenF.cpp
DEP_CPP_DLGOP=\
	".\Diff.h"\
	".\dlgfilex.h"\
	".\DlgOpenF.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\DlgOpenF.obj" : $(SOURCE) $(DEP_CPP_DLGOP) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Mainfrm.cpp
DEP_CPP_MAINF=\
	".\Diff.h"\
	".\diffdoc.h"\
	".\diffview.h"\
	".\Mainfrm.h"\
	".\Progress.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Progress.cpp
DEP_CPP_PROGR=\
	".\Diff.h"\
	".\Progress.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\Progress.obj" : $(SOURCE) $(DEP_CPP_PROGR) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Splitter.cpp
DEP_CPP_SPLIT=\
	".\Diff.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

"$(INTDIR)\Splitter.obj" : $(SOURCE) $(DEP_CPP_SPLIT) "$(INTDIR)"\
 "$(INTDIR)\Diff.pch"


SOURCE=.\Stdafx.cpp
DEP_CPP_STDAF=\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "diff - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Diff.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "diff - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Diff.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Diff.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

