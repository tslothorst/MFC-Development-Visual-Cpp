# Microsoft Developer Studio Generated NMAKE File, Based on MDI2Views.dsp
!IF "$(CFG)" == ""
CFG=MDI2Views - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MDI2Views - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MDI2Views - Win32 Release" && "$(CFG)" !=\
 "MDI2Views - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDI2Views.mak" CFG="MDI2Views - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDI2Views - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MDI2Views - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "MDI2Views - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDI2Views.exe"

!ELSE 

ALL : "$(OUTDIR)\MDI2Views.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDI2Views.obj"
	-@erase "$(INTDIR)\MDI2Views.pch"
	-@erase "$(INTDIR)\MDI2Views.res"
	-@erase "$(INTDIR)\MDI2ViewsDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\MDI2Views.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2Views.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDI2Views.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDI2Views.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\MDI2Views.pdb" /machine:I386 /out:"$(OUTDIR)\MDI2Views.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDI2Views.obj" \
	"$(INTDIR)\MDI2Views.res" \
	"$(INTDIR)\MDI2ViewsDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDI2Views.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MDI2Views - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDI2Views.exe"

!ELSE 

ALL : "$(OUTDIR)\MDI2Views.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDI2Views.obj"
	-@erase "$(INTDIR)\MDI2Views.pch"
	-@erase "$(INTDIR)\MDI2Views.res"
	-@erase "$(INTDIR)\MDI2ViewsDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\MDI2Views.exe"
	-@erase "$(OUTDIR)\MDI2Views.ilk"
	-@erase "$(OUTDIR)\MDI2Views.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2Views.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDI2Views.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDI2Views.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\MDI2Views.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\MDI2Views.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDI2Views.obj" \
	"$(INTDIR)\MDI2Views.res" \
	"$(INTDIR)\MDI2ViewsDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDI2Views.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "MDI2Views - Win32 Release" || "$(CFG)" ==\
 "MDI2Views - Win32 Debug"
SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\DefaultView.cpp
DEP_CPP_DEFAU=\
	".\DefaultView.h"\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DefaultView.obj" : $(SOURCE) $(DEP_CPP_DEFAU) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\ItalicsView.cpp
DEP_CPP_ITALI=\
	".\ItalicsView.h"\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ItalicsView.obj" : $(SOURCE) $(DEP_CPP_ITALI) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\ChildFrm.h"\
	".\ItalicsView.h"\
	".\MainFrm.h"\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\MDI2Views.cpp
DEP_CPP_MDI2V=\
	".\ChildFrm.h"\
	".\DefaultView.h"\
	".\MainFrm.h"\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDI2Views.obj" : $(SOURCE) $(DEP_CPP_MDI2V) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\MDI2Views.rc
DEP_RSC_MDI2VI=\
	".\res\MDI2Views.ico"\
	".\res\MDI2Views.rc2"\
	".\res\MDI2ViewsDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\MDI2Views.res" : $(SOURCE) $(DEP_RSC_MDI2VI) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MDI2ViewsDoc.cpp
DEP_CPP_MDI2VIE=\
	".\MDI2Views.h"\
	".\MDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDI2ViewsDoc.obj" : $(SOURCE) $(DEP_CPP_MDI2VIE) "$(INTDIR)"\
 "$(INTDIR)\MDI2Views.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "MDI2Views - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2Views.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDI2Views.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MDI2Views - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2Views.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDI2Views.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

