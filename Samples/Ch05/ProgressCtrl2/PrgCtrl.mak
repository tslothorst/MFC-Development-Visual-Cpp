# Microsoft Developer Studio Generated NMAKE File, Based on PrgCtrl.dsp
!IF "$(CFG)" == ""
CFG=PrgCtrl - Win32 Release
!MESSAGE No configuration specified. Defaulting to PrgCtrl - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "PrgCtrl - Win32 Release" && "$(CFG)" != "PrgCtrl - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PrgCtrl.mak" CFG="PrgCtrl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PrgCtrl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PrgCtrl - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PrgCtrl.exe" "$(OUTDIR)\PrgCtrl.bsc"

!ELSE 

ALL : "$(OUTDIR)\PrgCtrl.exe" "$(OUTDIR)\PrgCtrl.bsc"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\PrgCtrl.obj"
	-@erase "$(INTDIR)\PrgCtrl.pch"
	-@erase "$(INTDIR)\PrgCtrl.res"
	-@erase "$(INTDIR)\PrgCtrl.sbr"
	-@erase "$(INTDIR)\PrgCtrldoc.obj"
	-@erase "$(INTDIR)\PrgCtrldoc.sbr"
	-@erase "$(INTDIR)\PrgCtrlview.obj"
	-@erase "$(INTDIR)\PrgCtrlview.sbr"
	-@erase "$(INTDIR)\DlgOpenF.obj"
	-@erase "$(INTDIR)\DlgOpenF.sbr"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Mainfrm.sbr"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Splitter.sbr"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\Stdafx.sbr"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\PrgCtrl.bsc"
	-@erase "$(OUTDIR)\PrgCtrl.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PrgCtrl.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\Release/
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PrgCtrl.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PrgCtrl.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\PrgCtrl.sbr" \
	"$(INTDIR)\PrgCtrldoc.sbr" \
	"$(INTDIR)\PrgCtrlview.sbr" \
	"$(INTDIR)\DlgOpenF.sbr" \
	"$(INTDIR)\Mainfrm.sbr" \
	"$(INTDIR)\Splitter.sbr" \
	"$(INTDIR)\Stdafx.sbr"

"$(OUTDIR)\PrgCtrl.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\PrgCtrl.pdb" /machine:I386 /out:"$(OUTDIR)\PrgCtrl.exe" 
LINK32_OBJS= \
	"$(INTDIR)\PrgCtrl.obj" \
	"$(INTDIR)\PrgCtrl.res" \
	"$(INTDIR)\PrgCtrldoc.obj" \
	"$(INTDIR)\PrgCtrlview.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\PrgCtrl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PrgCtrl.exe"

!ELSE 

ALL : "$(OUTDIR)\PrgCtrl.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\PrgCtrl.obj"
	-@erase "$(INTDIR)\PrgCtrl.pch"
	-@erase "$(INTDIR)\PrgCtrl.res"
	-@erase "$(INTDIR)\PrgCtrldoc.obj"
	-@erase "$(INTDIR)\PrgCtrlview.obj"
	-@erase "$(INTDIR)\DlgOpenF.obj"
	-@erase "$(INTDIR)\Mainfrm.obj"
	-@erase "$(INTDIR)\Splitter.obj"
	-@erase "$(INTDIR)\Stdafx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\PrgCtrl.exe"
	-@erase "$(OUTDIR)\PrgCtrl.ilk"
	-@erase "$(OUTDIR)\PrgCtrl.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=fl32.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\PrgCtrl.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PrgCtrl.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PrgCtrl.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\PrgCtrl.pdb" /debug /machine:I386 /out:"$(OUTDIR)\PrgCtrl.exe" 
LINK32_OBJS= \
	"$(INTDIR)\PrgCtrl.obj" \
	"$(INTDIR)\PrgCtrl.res" \
	"$(INTDIR)\PrgCtrldoc.obj" \
	"$(INTDIR)\PrgCtrlview.obj" \
	"$(INTDIR)\DlgOpenF.obj" \
	"$(INTDIR)\Mainfrm.obj" \
	"$(INTDIR)\Splitter.obj" \
	"$(INTDIR)\Stdafx.obj"

"$(OUTDIR)\PrgCtrl.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "PrgCtrl - Win32 Release" || "$(CFG)" == "PrgCtrl - Win32 Debug"
SOURCE=.\PrgCtrl.cpp
DEP_CPP_DIFF_=\
	".\PrgCtrl.h"\
	".\PrgCtrldoc.h"\
	".\PrgCtrlview.h"\
	".\Mainfrm.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\PrgCtrl.obj"	"$(INTDIR)\PrgCtrl.sbr" : $(SOURCE) $(DEP_CPP_DIFF_)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\PrgCtrl.obj" : $(SOURCE) $(DEP_CPP_DIFF_) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\PrgCtrl.rc
DEP_RSC_DIFF_R=\
	".\Res\PrgCtrl.ico"\
	".\Res\PrgCtrl.rc2"\
	".\Res\PrgCtrldoc.ico"\
	".\Res\Toolbar.bmp"\
	

"$(INTDIR)\PrgCtrl.res" : $(SOURCE) $(DEP_RSC_DIFF_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PrgCtrldoc.cpp
DEP_CPP_DIFFD=\
	".\PrgCtrl.h"\
	".\PrgCtrldoc.h"\
	".\PrgCtrlview.h"\
	".\DlgOpenF.h"\
	".\Mainfrm.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\PrgCtrldoc.obj"	"$(INTDIR)\PrgCtrldoc.sbr" : $(SOURCE) $(DEP_CPP_DIFFD)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\PrgCtrldoc.obj" : $(SOURCE) $(DEP_CPP_DIFFD) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\PrgCtrlview.cpp
DEP_CPP_DIFFV=\
	".\PrgCtrl.h"\
	".\PrgCtrldoc.h"\
	".\PrgCtrlview.h"\
	".\Mainfrm.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\PrgCtrlview.obj"	"$(INTDIR)\PrgCtrlview.sbr" : $(SOURCE) $(DEP_CPP_DIFFV)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\PrgCtrlview.obj" : $(SOURCE) $(DEP_CPP_DIFFV) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\DlgOpenF.cpp
DEP_CPP_DLGOP=\
	".\PrgCtrl.h"\
	".\DlgOpenF.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\DlgOpenF.obj"	"$(INTDIR)\DlgOpenF.sbr" : $(SOURCE) $(DEP_CPP_DLGOP)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\DlgOpenF.obj" : $(SOURCE) $(DEP_CPP_DLGOP) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\Mainfrm.cpp
DEP_CPP_MAINF=\
	".\PrgCtrl.h"\
	".\PrgCtrldoc.h"\
	".\PrgCtrlview.h"\
	".\Mainfrm.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\Mainfrm.obj"	"$(INTDIR)\Mainfrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\Mainfrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\Splitter.cpp
DEP_CPP_SPLIT=\
	".\PrgCtrl.h"\
	".\Splitter.h"\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"


"$(INTDIR)\Splitter.obj"	"$(INTDIR)\Splitter.sbr" : $(SOURCE) $(DEP_CPP_SPLIT)\
 "$(INTDIR)" "$(INTDIR)\PrgCtrl.pch"


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"


"$(INTDIR)\Splitter.obj" : $(SOURCE) $(DEP_CPP_SPLIT) "$(INTDIR)"\
 "$(INTDIR)\PrgCtrl.pch"


!ENDIF 

SOURCE=.\Stdafx.cpp
DEP_CPP_STDAF=\
	".\Stdafx.h"\
	

!IF  "$(CFG)" == "PrgCtrl - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\PrgCtrl.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\Stdafx.sbr"	"$(INTDIR)\PrgCtrl.pch" : $(SOURCE)\
 $(DEP_CPP_STDAF) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PrgCtrl - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\PrgCtrl.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\Stdafx.obj"	"$(INTDIR)\PrgCtrl.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

