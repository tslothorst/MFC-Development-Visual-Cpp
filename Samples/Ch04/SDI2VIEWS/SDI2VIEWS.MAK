# Microsoft Developer Studio Generated NMAKE File, Based on SDI2Views.dsp
!IF "$(CFG)" == ""
CFG=SDI2Views - Win32 Debug
!MESSAGE No configuration specified. Defaulting to SDI2Views - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "SDI2Views - Win32 Release" && "$(CFG)" !=\
 "SDI2Views - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SDI2Views.mak" CFG="SDI2Views - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SDI2Views - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "SDI2Views - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "SDI2Views - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\SDI2Views.exe"

!ELSE 

ALL : "$(OUTDIR)\SDI2Views.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SDI2Views.obj"
	-@erase "$(INTDIR)\SDI2Views.pch"
	-@erase "$(INTDIR)\SDI2Views.res"
	-@erase "$(INTDIR)\SDI2ViewsDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\SDI2Views.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\SDI2Views.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SDI2Views.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SDI2Views.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\SDI2Views.pdb" /machine:I386 /out:"$(OUTDIR)\SDI2Views.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SDI2Views.obj" \
	"$(INTDIR)\SDI2Views.res" \
	"$(INTDIR)\SDI2ViewsDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\SDI2Views.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "SDI2Views - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\SDI2Views.exe"

!ELSE 

ALL : "$(OUTDIR)\SDI2Views.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\DefaultView.obj"
	-@erase "$(INTDIR)\ItalicsView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\SDI2Views.obj"
	-@erase "$(INTDIR)\SDI2Views.pch"
	-@erase "$(INTDIR)\SDI2Views.res"
	-@erase "$(INTDIR)\SDI2ViewsDoc.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\SDI2Views.exe"
	-@erase "$(OUTDIR)\SDI2Views.ilk"
	-@erase "$(OUTDIR)\SDI2Views.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\SDI2Views.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\SDI2Views.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\SDI2Views.bsc" /n 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\SDI2Views.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\SDI2Views.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DefaultView.obj" \
	"$(INTDIR)\ItalicsView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\SDI2Views.obj" \
	"$(INTDIR)\SDI2Views.res" \
	"$(INTDIR)\SDI2ViewsDoc.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\SDI2Views.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "SDI2Views - Win32 Release" || "$(CFG)" ==\
 "SDI2Views - Win32 Debug"
SOURCE=.\DefaultView.cpp
DEP_CPP_DEFAU=\
	".\DefaultView.h"\
	".\SDI2Views.h"\
	".\SDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\DefaultView.obj" : $(SOURCE) $(DEP_CPP_DEFAU) "$(INTDIR)"\
 "$(INTDIR)\SDI2Views.pch"


SOURCE=.\ItalicsView.cpp
DEP_CPP_ITALI=\
	".\ItalicsView.h"\
	".\SDI2Views.h"\
	".\SDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ItalicsView.obj" : $(SOURCE) $(DEP_CPP_ITALI) "$(INTDIR)"\
 "$(INTDIR)\SDI2Views.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\DefaultView.h"\
	".\ItalicsView.h"\
	".\MainFrm.h"\
	".\SDI2Views.h"\
	".\SDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\SDI2Views.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\SDI2Views.cpp
DEP_CPP_SDI2V=\
	".\DefaultView.h"\
	".\ItalicsView.h"\
	".\MainFrm.h"\
	".\SDI2Views.h"\
	".\SDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\SDI2Views.obj" : $(SOURCE) $(DEP_CPP_SDI2V) "$(INTDIR)"\
 "$(INTDIR)\SDI2Views.pch"


SOURCE=.\SDI2Views.rc
DEP_RSC_SDI2VI=\
	".\res\SDI2Views.ico"\
	".\res\SDI2Views.rc2"\
	".\res\SDI2ViewsDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\SDI2Views.res" : $(SOURCE) $(DEP_RSC_SDI2VI) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\SDI2ViewsDoc.cpp
DEP_CPP_SDI2VIE=\
	".\SDI2Views.h"\
	".\SDI2ViewsDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\SDI2ViewsDoc.obj" : $(SOURCE) $(DEP_CPP_SDI2VIE) "$(INTDIR)"\
 "$(INTDIR)\SDI2Views.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "SDI2Views - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\SDI2Views.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SDI2Views.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "SDI2Views - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\SDI2Views.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\SDI2Views.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\DefaultView.h
SOURCE=.\ItalicsView.h
SOURCE=.\MainFrm.h
SOURCE=.\Resource.h
SOURCE=.\SDI2Views.h
SOURCE=.\SDI2ViewsDoc.h
SOURCE=.\StdAfx.h
SOURCE=.\res\SDI2Views.ico
SOURCE=.\res\SDI2Views.rc2
SOURCE=.\res\SDI2ViewsDoc.ico
SOURCE=.\res\Toolbar.bmp

!ENDIF 

