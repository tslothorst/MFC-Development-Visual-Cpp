# Microsoft Developer Studio Generated NMAKE File, Based on OwnDraw.dsp
!IF "$(CFG)" == ""
CFG=OwnDraw - Win32 Release
!MESSAGE No configuration specified. Defaulting to OwnDraw - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "OwnDraw - Win32 Release" && "$(CFG)" !=\
 "OwnDraw - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OwnDraw.mak" CFG="OwnDraw - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OwnDraw - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "OwnDraw - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "OwnDraw - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\OwnDraw.exe"

!ELSE 

ALL : "$(OUTDIR)\OwnDraw.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BMapMenu.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OdraView.obj"
	-@erase "$(INTDIR)\OdrawDoc.obj"
	-@erase "$(INTDIR)\ODrawMnu.obj"
	-@erase "$(INTDIR)\OwnDraw.obj"
	-@erase "$(INTDIR)\OwnDraw.pch"
	-@erase "$(INTDIR)\OwnDraw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\OwnDraw.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\OwnDraw.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\OwnDraw.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\OwnDraw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\OwnDraw.pdb" /machine:I386 /out:"$(OUTDIR)\OwnDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BMapMenu.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OdraView.obj" \
	"$(INTDIR)\OdrawDoc.obj" \
	"$(INTDIR)\ODrawMnu.obj" \
	"$(INTDIR)\OwnDraw.obj" \
	"$(INTDIR)\OwnDraw.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\OwnDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\OwnDraw.exe"

!ELSE 

ALL : "$(OUTDIR)\OwnDraw.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\BMapMenu.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OdraView.obj"
	-@erase "$(INTDIR)\OdrawDoc.obj"
	-@erase "$(INTDIR)\ODrawMnu.obj"
	-@erase "$(INTDIR)\OwnDraw.obj"
	-@erase "$(INTDIR)\OwnDraw.pch"
	-@erase "$(INTDIR)\OwnDraw.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\OwnDraw.exe"
	-@erase "$(OUTDIR)\OwnDraw.ilk"
	-@erase "$(OUTDIR)\OwnDraw.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\OwnDraw.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\OwnDraw.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\OwnDraw.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\OwnDraw.pdb" /debug /machine:I386 /out:"$(OUTDIR)\OwnDraw.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BMapMenu.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OdraView.obj" \
	"$(INTDIR)\OdrawDoc.obj" \
	"$(INTDIR)\ODrawMnu.obj" \
	"$(INTDIR)\OwnDraw.obj" \
	"$(INTDIR)\OwnDraw.res" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\OwnDraw.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "OwnDraw - Win32 Release" || "$(CFG)" ==\
 "OwnDraw - Win32 Debug"
SOURCE=.\BMapMenu.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\BMapMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_BMAPM=\
	".\BMapMenu.H"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\BMapMenu.obj" : $(SOURCE) $(DEP_CPP_BMAPM) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_MAINF=\
	".\BMapMenu.H"\
	".\MainFrm.h"\
	".\ODraView.h"\
	".\ODrawDoc.h"\
	".\ODrawMnu.h"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\OdraView.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\OdraView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_ODRAV=\
	".\ODraView.h"\
	".\ODrawDoc.h"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\OdraView.obj" : $(SOURCE) $(DEP_CPP_ODRAV) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\OdrawDoc.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\OdrawDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_ODRAW=\
	".\ODrawDoc.h"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\OdrawDoc.obj" : $(SOURCE) $(DEP_CPP_ODRAW) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\ODrawMnu.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\ODrawMnu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_ODRAWM=\
	".\ODrawMnu.h"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ODrawMnu.obj" : $(SOURCE) $(DEP_CPP_ODRAWM) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\OwnDraw.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\OwnDraw.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\OwnDraw.pch"


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_OWNDR=\
	".\BMapMenu.H"\
	".\MainFrm.h"\
	".\ODraView.h"\
	".\ODrawDoc.h"\
	".\ODrawMnu.h"\
	".\OwnDraw.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\OwnDraw.obj" : $(SOURCE) $(DEP_CPP_OWNDR) "$(INTDIR)"\
 "$(INTDIR)\OwnDraw.pch"


!ENDIF 

SOURCE=.\OwnDraw.rc

!IF  "$(CFG)" == "OwnDraw - Win32 Release"


"$(INTDIR)\OwnDraw.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_RSC_OWNDRA=\
	".\res\bitmap1.bmp"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\bmp00003.bmp"\
	".\res\ODrawDoc.ico"\
	".\res\OwnDraw.ico"\
	".\res\OwnDraw.rc2"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\OwnDraw.res" : $(SOURCE) $(DEP_RSC_OWNDRA) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "OwnDraw - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\OwnDraw.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\OwnDraw.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "OwnDraw - Win32 Debug"

DEP_CPP_STDAF=\
	".\StdAfx.h"\
	
CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\OwnDraw.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\OwnDraw.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

