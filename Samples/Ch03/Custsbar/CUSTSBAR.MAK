# Microsoft Developer Studio Generated NMAKE File, Based on CustSBar.dsp
!IF "$(CFG)" == ""
CFG=CustSBar - Win32 Release
!MESSAGE No configuration specified. Defaulting to CustSBar - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "CustSBar - Win32 Release" && "$(CFG)" !=\
 "CustSBar - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CustSBar.mak" CFG="CustSBar - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CustSBar - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CustSBar - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "CustSBar - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CustSBar.exe"

!ELSE 

ALL : "$(OUTDIR)\CustSBar.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\CustSBar.obj"
	-@erase "$(INTDIR)\CustSBar.pch"
	-@erase "$(INTDIR)\CustSBar.res"
	-@erase "$(INTDIR)\CustSDoc.obj"
	-@erase "$(INTDIR)\CustView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MyStatBa.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\CustSBar.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\CustSBar.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CustSBar.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CustSBar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\CustSBar.pdb" /machine:I386 /out:"$(OUTDIR)\CustSBar.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CustSBar.obj" \
	"$(INTDIR)\CustSBar.res" \
	"$(INTDIR)\CustSDoc.obj" \
	"$(INTDIR)\CustView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MyStatBa.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CustSBar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CustSBar - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\CustSBar.exe"

!ELSE 

ALL : "$(OUTDIR)\CustSBar.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\CustSBar.obj"
	-@erase "$(INTDIR)\CustSBar.pch"
	-@erase "$(INTDIR)\CustSBar.res"
	-@erase "$(INTDIR)\CustSDoc.obj"
	-@erase "$(INTDIR)\CustView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MyStatBa.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\CustSBar.exe"
	-@erase "$(OUTDIR)\CustSBar.ilk"
	-@erase "$(OUTDIR)\CustSBar.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\CustSBar.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CustSBar.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CustSBar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\CustSBar.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\CustSBar.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CustSBar.obj" \
	"$(INTDIR)\CustSBar.res" \
	"$(INTDIR)\CustSDoc.obj" \
	"$(INTDIR)\CustView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MyStatBa.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\CustSBar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "CustSBar - Win32 Release" || "$(CFG)" ==\
 "CustSBar - Win32 Debug"
SOURCE=.\CustSBar.cpp
DEP_CPP_CUSTS=\
	".\CustSBar.h"\
	".\CustSDoc.h"\
	".\CustView.h"\
	".\MainFrm.h"\
	".\MyStatBa.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CustSBar.obj" : $(SOURCE) $(DEP_CPP_CUSTS) "$(INTDIR)"\
 "$(INTDIR)\CustSBar.pch"


SOURCE=.\CustSBar.rc
DEP_RSC_CUSTSB=\
	".\res\bitmap1.bmp"\
	".\res\bmp00001.bmp"\
	".\res\bmp00002.bmp"\
	".\res\CustDoc.ico"\
	".\res\CustSBar.ico"\
	".\res\CustSBar.rc2"\
	".\res\idm_redb.bmp"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\CustSBar.res" : $(SOURCE) $(DEP_RSC_CUSTSB) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CustSDoc.cpp
DEP_CPP_CUSTSD=\
	".\CustSBar.h"\
	".\CustSDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CustSDoc.obj" : $(SOURCE) $(DEP_CPP_CUSTSD) "$(INTDIR)"\
 "$(INTDIR)\CustSBar.pch"


SOURCE=.\CustView.cpp
DEP_CPP_CUSTV=\
	".\CustSBar.h"\
	".\CustSDoc.h"\
	".\CustView.h"\
	".\MainFrm.h"\
	".\MyStatBa.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\CustView.obj" : $(SOURCE) $(DEP_CPP_CUSTV) "$(INTDIR)"\
 "$(INTDIR)\CustSBar.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\CustSBar.h"\
	".\MainFrm.h"\
	".\MyStatBa.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\CustSBar.pch"


SOURCE=.\MyStatBa.cpp
DEP_CPP_MYSTA=\
	".\CustSBar.h"\
	".\CustSDoc.h"\
	".\MainFrm.h"\
	".\MyStatBa.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MyStatBa.obj" : $(SOURCE) $(DEP_CPP_MYSTA) "$(INTDIR)"\
 "$(INTDIR)\CustSBar.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "CustSBar - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\CustSBar.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CustSBar.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CustSBar - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\CustSBar.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CustSBar.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

