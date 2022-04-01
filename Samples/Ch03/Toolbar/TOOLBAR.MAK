# Microsoft Developer Studio Generated NMAKE File, Based on ToolBar.dsp
!IF "$(CFG)" == ""
CFG=Toolbar - Win32 Release
!MESSAGE No configuration specified. Defaulting to Toolbar - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Toolbar - Win32 Release" && "$(CFG)" !=\
 "Toolbar - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ToolBar.mak" CFG="Toolbar - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Toolbar - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Toolbar - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Toolbar - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ToolBar.exe"

!ELSE 

ALL : "$(OUTDIR)\ToolBar.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TBarDoc.obj"
	-@erase "$(INTDIR)\TBarView.obj"
	-@erase "$(INTDIR)\Toolbar.obj"
	-@erase "$(INTDIR)\ToolBar.pch"
	-@erase "$(INTDIR)\Toolbar.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\ToolBar.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ToolBar.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Toolbar.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ToolBar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\ToolBar.pdb" /machine:I386 /out:"$(OUTDIR)\ToolBar.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TBarDoc.obj" \
	"$(INTDIR)\TBarView.obj" \
	"$(INTDIR)\Toolbar.obj" \
	"$(INTDIR)\Toolbar.res"

"$(OUTDIR)\ToolBar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Toolbar - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\ToolBar.exe"

!ELSE 

ALL : "$(OUTDIR)\ToolBar.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TBarDoc.obj"
	-@erase "$(INTDIR)\TBarView.obj"
	-@erase "$(INTDIR)\Toolbar.obj"
	-@erase "$(INTDIR)\ToolBar.pch"
	-@erase "$(INTDIR)\Toolbar.res"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\ToolBar.exe"
	-@erase "$(OUTDIR)\ToolBar.ilk"
	-@erase "$(OUTDIR)\ToolBar.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ToolBar.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Toolbar.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ToolBar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\ToolBar.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ToolBar.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TBarDoc.obj" \
	"$(INTDIR)\TBarView.obj" \
	"$(INTDIR)\Toolbar.obj" \
	"$(INTDIR)\Toolbar.res"

"$(OUTDIR)\ToolBar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "Toolbar - Win32 Release" || "$(CFG)" ==\
 "Toolbar - Win32 Debug"
SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\Toolbar.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\ToolBar.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Toolbar - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ToolBar.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ToolBar.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Toolbar - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ToolBar.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ToolBar.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TBarDoc.cpp
DEP_CPP_TBARD=\
	".\StdAfx.h"\
	".\TbarDoc.h"\
	".\Toolbar.h"\
	

"$(INTDIR)\TBarDoc.obj" : $(SOURCE) $(DEP_CPP_TBARD) "$(INTDIR)"\
 "$(INTDIR)\ToolBar.pch"


SOURCE=.\TBarView.cpp
DEP_CPP_TBARV=\
	".\StdAfx.h"\
	".\TbarDoc.h"\
	".\TbarView.h"\
	".\Toolbar.h"\
	

"$(INTDIR)\TBarView.obj" : $(SOURCE) $(DEP_CPP_TBARV) "$(INTDIR)"\
 "$(INTDIR)\ToolBar.pch"


SOURCE=.\Toolbar.cpp
DEP_CPP_TOOLB=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\TbarDoc.h"\
	".\TbarView.h"\
	".\Toolbar.h"\
	

"$(INTDIR)\Toolbar.obj" : $(SOURCE) $(DEP_CPP_TOOLB) "$(INTDIR)"\
 "$(INTDIR)\ToolBar.pch"


SOURCE=.\Toolbar.rc
DEP_RSC_TOOLBA=\
	".\res\TbarDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\Toolbar.ico"\
	".\res\Toolbar.rc2"\
	".\res\toolbar1.bmp"\
	

"$(INTDIR)\Toolbar.res" : $(SOURCE) $(DEP_RSC_TOOLBA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

