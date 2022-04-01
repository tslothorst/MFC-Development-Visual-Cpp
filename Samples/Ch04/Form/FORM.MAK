# Microsoft Developer Studio Generated NMAKE File, Based on Form.dsp
!IF "$(CFG)" == ""
CFG=Form - Win32 Release
!MESSAGE No configuration specified. Defaulting to Form - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Form - Win32 Release" && "$(CFG)" != "Form - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Form.mak" CFG="Form - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Form - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "Form - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Form - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Form.exe"

!ELSE 

ALL : "$(OUTDIR)\Form.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Form.obj"
	-@erase "$(INTDIR)\Form.pch"
	-@erase "$(INTDIR)\Form.res"
	-@erase "$(INTDIR)\FormDoc.obj"
	-@erase "$(INTDIR)\FormView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Form.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Form.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Form.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Form.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\Form.pdb" /machine:I386 /out:"$(OUTDIR)\Form.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Form.obj" \
	"$(INTDIR)\Form.res" \
	"$(INTDIR)\FormDoc.obj" \
	"$(INTDIR)\FormView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Form.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Form - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Form.exe"

!ELSE 

ALL : "$(OUTDIR)\Form.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Form.obj"
	-@erase "$(INTDIR)\Form.pch"
	-@erase "$(INTDIR)\Form.res"
	-@erase "$(INTDIR)\FormDoc.obj"
	-@erase "$(INTDIR)\FormView.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Form.exe"
	-@erase "$(OUTDIR)\Form.ilk"
	-@erase "$(OUTDIR)\Form.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Form.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Form.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Form.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\Form.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Form.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Form.obj" \
	"$(INTDIR)\Form.res" \
	"$(INTDIR)\FormDoc.obj" \
	"$(INTDIR)\FormView.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Form.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "Form - Win32 Release" || "$(CFG)" == "Form - Win32 Debug"
SOURCE=.\Form.cpp
DEP_CPP_FORM_=\
	".\Form.h"\
	".\FormDoc.h"\
	".\FormView.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Form.obj" : $(SOURCE) $(DEP_CPP_FORM_) "$(INTDIR)"\
 "$(INTDIR)\Form.pch"


SOURCE=.\Form.rc
DEP_RSC_FORM_R=\
	".\res\Form.ico"\
	".\res\Form.rc2"\
	".\res\FormDoc.ico"\
	".\res\Toolbar.bmp"\
	

"$(INTDIR)\Form.res" : $(SOURCE) $(DEP_RSC_FORM_R) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\FormDoc.cpp
DEP_CPP_FORMD=\
	".\Form.h"\
	".\FormDoc.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\FormDoc.obj" : $(SOURCE) $(DEP_CPP_FORMD) "$(INTDIR)"\
 "$(INTDIR)\Form.pch"


SOURCE=.\FormView.cpp
DEP_CPP_FORMV=\
	".\Form.h"\
	".\FormDoc.h"\
	".\FormView.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\FormView.obj" : $(SOURCE) $(DEP_CPP_FORMV) "$(INTDIR)"\
 "$(INTDIR)\Form.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\Form.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Form.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Form - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Form.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Form.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Form - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Form.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Form.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Form.h
SOURCE=.\FormDoc.h
SOURCE=.\FormView.h
SOURCE=.\MainFrm.h
SOURCE=.\StdAfx.h
SOURCE=.\res\Form.ico
SOURCE=.\res\Form.rc2
SOURCE=.\res\FormDoc.ico
SOURCE=.\res\Toolbar.bmp

!ENDIF 

