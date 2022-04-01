# Microsoft Developer Studio Generated NMAKE File, Based on MDI2ViewsB.dsp
!IF "$(CFG)" == ""
CFG=MDI2ViewsB - Win32 Debug
!MESSAGE No configuration specified. Defaulting to MDI2ViewsB - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "MDI2ViewsB - Win32 Release" && "$(CFG)" !=\
 "MDI2ViewsB - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDI2ViewsB.mak" CFG="MDI2ViewsB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDI2ViewsB - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MDI2ViewsB - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "MDI2ViewsB - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDI2ViewsB.exe"

!ELSE 

ALL : "$(OUTDIR)\MDI2ViewsB.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDI2ViewsB.obj"
	-@erase "$(INTDIR)\MDI2ViewsB.pch"
	-@erase "$(INTDIR)\MDI2ViewsB.res"
	-@erase "$(INTDIR)\MDI2ViewsBDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\MDI2ViewsB.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2ViewsB.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDI2ViewsB.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDI2ViewsB.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\MDI2ViewsB.pdb" /machine:I386 /out:"$(OUTDIR)\MDI2ViewsB.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDI2ViewsB.obj" \
	"$(INTDIR)\MDI2ViewsB.res" \
	"$(INTDIR)\MDI2ViewsBDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDI2ViewsB.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "MDI2ViewsB - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MDI2ViewsB.exe"

!ELSE 

ALL : "$(OUTDIR)\MDI2ViewsB.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MDI2ViewsB.obj"
	-@erase "$(INTDIR)\MDI2ViewsB.pch"
	-@erase "$(INTDIR)\MDI2ViewsB.res"
	-@erase "$(INTDIR)\MDI2ViewsBDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\MDI2ViewsB.exe"
	-@erase "$(OUTDIR)\MDI2ViewsB.ilk"
	-@erase "$(OUTDIR)\MDI2ViewsB.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2ViewsB.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MDI2ViewsB.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MDI2ViewsB.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\MDI2ViewsB.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\MDI2ViewsB.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MDI2ViewsB.obj" \
	"$(INTDIR)\MDI2ViewsB.res" \
	"$(INTDIR)\MDI2ViewsBDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\MDI2ViewsB.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "MDI2ViewsB - Win32 Release" || "$(CFG)" ==\
 "MDI2ViewsB - Win32 Debug"
SOURCE=.\ChildFrm.cpp
DEP_CPP_CHILD=\
	".\ChildFrm.h"\
	".\MDI2ViewsB.h"\
	".\MDI2ViewsBDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ChildFrm.obj" : $(SOURCE) $(DEP_CPP_CHILD) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\DefaultView.cpp
DEP_CPP_DEFAU=\
	".\DefaultView.h"\
	".\MDI2ViewsB.h"\
	".\MDI2ViewsBDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DefaultView.obj" : $(SOURCE) $(DEP_CPP_DEFAU) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\ItalicsView.cpp
DEP_CPP_ITALI=\
	".\ItalicsView.h"\
	".\MDI2ViewsB.h"\
	".\MDI2ViewsBDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ItalicsView.obj" : $(SOURCE) $(DEP_CPP_ITALI) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\MDI2ViewsB.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\MDI2ViewsB.cpp
DEP_CPP_MDI2V=\
	".\ChildFrm.h"\
	".\DefaultView.h"\
	".\ItalicsView.h"\
	".\MainFrm.h"\
	".\MDI2ViewsB.h"\
	".\MDI2ViewsBDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDI2ViewsB.obj" : $(SOURCE) $(DEP_CPP_MDI2V) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\MDI2ViewsB.rc
DEP_RSC_MDI2VI=\
	".\res\idr_mdi2.ico"\
	".\res\MDI2ViewsB.rc2"\
	".\res\Toolbar.bmp"\
	
NODEP_RSC_MDI2VI=\
	".\res\MDI2ViewsB.ico"\
	".\res\MDI2ViewsBDoc.ico"\
	

"$(INTDIR)\MDI2ViewsB.res" : $(SOURCE) $(DEP_RSC_MDI2VI) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MDI2ViewsBDoc.cpp
DEP_CPP_MDI2VIE=\
	".\MDI2ViewsB.h"\
	".\MDI2ViewsBDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MDI2ViewsBDoc.obj" : $(SOURCE) $(DEP_CPP_MDI2VIE) "$(INTDIR)"\
 "$(INTDIR)\MDI2ViewsB.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "MDI2ViewsB - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2ViewsB.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDI2ViewsB.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "MDI2ViewsB - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\MDI2ViewsB.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\MDI2ViewsB.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

