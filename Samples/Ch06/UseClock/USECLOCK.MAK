# Microsoft Developer Studio Generated NMAKE File, Based on UseClock.dsp
!IF "$(CFG)" == ""
CFG=UseClock - Win32 Debug
!MESSAGE No configuration specified. Defaulting to UseClock - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "UseClock - Win32 Release" && "$(CFG)" !=\
 "UseClock - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UseClock.mak" CFG="UseClock - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UseClock - Win32 Release" (based on "Win32 (x86) Win32 Application")
!MESSAGE "UseClock - Win32 Debug" (based on "Win32 (x86) Win32 Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "UseClock - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\UseClock.exe"

!ELSE 

ALL : "$(OUTDIR)\UseClock.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\clock.obj"
	-@erase "$(INTDIR)\ClockPropertiesDlg.obj"
	-@erase "$(INTDIR)\HoursMinutesDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UseClock.obj"
	-@erase "$(INTDIR)\UseClock.pch"
	-@erase "$(INTDIR)\UseClock.res"
	-@erase "$(INTDIR)\UseClockDoc.obj"
	-@erase "$(INTDIR)\UseClockView.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\UseClock.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\UseClock.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\UseClock.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\UseClock.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)\UseClock.pdb" /machine:I386 /out:"$(OUTDIR)\UseClock.exe" 
LINK32_OBJS= \
	"$(INTDIR)\clock.obj" \
	"$(INTDIR)\ClockPropertiesDlg.obj" \
	"$(INTDIR)\HoursMinutesDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UseClock.obj" \
	"$(INTDIR)\UseClock.res" \
	"$(INTDIR)\UseClockDoc.obj" \
	"$(INTDIR)\UseClockView.obj"

"$(OUTDIR)\UseClock.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "UseClock - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\UseClock.exe"

!ELSE 

ALL : "$(OUTDIR)\UseClock.exe"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\clock.obj"
	-@erase "$(INTDIR)\ClockPropertiesDlg.obj"
	-@erase "$(INTDIR)\HoursMinutesDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UseClock.obj"
	-@erase "$(INTDIR)\UseClock.pch"
	-@erase "$(INTDIR)\UseClock.res"
	-@erase "$(INTDIR)\UseClockDoc.obj"
	-@erase "$(INTDIR)\UseClockView.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\UseClock.exe"
	-@erase "$(OUTDIR)\UseClock.ilk"
	-@erase "$(OUTDIR)\UseClock.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /Fp"$(INTDIR)\UseClock.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\"\
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
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o NUL /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\UseClock.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\UseClock.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)\UseClock.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)\UseClock.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\clock.obj" \
	"$(INTDIR)\ClockPropertiesDlg.obj" \
	"$(INTDIR)\HoursMinutesDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UseClock.obj" \
	"$(INTDIR)\UseClock.res" \
	"$(INTDIR)\UseClockDoc.obj" \
	"$(INTDIR)\UseClockView.obj"

"$(OUTDIR)\UseClock.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(CFG)" == "UseClock - Win32 Release" || "$(CFG)" ==\
 "UseClock - Win32 Debug"
SOURCE=.\clock.cpp
DEP_CPP_CLOCK=\
	".\clock.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\clock.obj" : $(SOURCE) $(DEP_CPP_CLOCK) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\ClockPropertiesDlg.cpp
DEP_CPP_CLOCKP=\
	".\ClockPropertiesDlg.h"\
	".\StdAfx.h"\
	".\UseClock.h"\
	

"$(INTDIR)\ClockPropertiesDlg.obj" : $(SOURCE) $(DEP_CPP_CLOCKP) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\HoursMinutesDlg.cpp
DEP_CPP_HOURS=\
	".\HoursMinutesDlg.h"\
	".\StdAfx.h"\
	".\UseClock.h"\
	

"$(INTDIR)\HoursMinutesDlg.obj" : $(SOURCE) $(DEP_CPP_HOURS) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\UseClock.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "UseClock - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /Fp"$(INTDIR)\UseClock.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\"\
 /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\UseClock.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "UseClock - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_AFXDLL" /Fp"$(INTDIR)\UseClock.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\UseClock.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UseClock.cpp
DEP_CPP_USECL=\
	".\clock.h"\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\UseClock.h"\
	".\UseClockDoc.h"\
	".\UseClockView.h"\
	

"$(INTDIR)\UseClock.obj" : $(SOURCE) $(DEP_CPP_USECL) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\UseClock.rc
DEP_RSC_USECLO=\
	".\res\UseClock.ico"\
	".\res\UseClock.rc2"\
	".\res\UseClockDoc.ico"\
	

"$(INTDIR)\UseClock.res" : $(SOURCE) $(DEP_RSC_USECLO) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\UseClockDoc.cpp
DEP_CPP_USECLOC=\
	".\StdAfx.h"\
	".\UseClock.h"\
	".\UseClockDoc.h"\
	

"$(INTDIR)\UseClockDoc.obj" : $(SOURCE) $(DEP_CPP_USECLOC) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\UseClockView.cpp
DEP_CPP_USECLOCK=\
	".\clock.h"\
	".\ClockPropertiesDlg.h"\
	".\HoursMinutesDlg.h"\
	".\StdAfx.h"\
	".\UseClock.h"\
	".\UseClockDoc.h"\
	".\UseClockView.h"\
	

"$(INTDIR)\UseClockView.obj" : $(SOURCE) $(DEP_CPP_USECLOCK) "$(INTDIR)"\
 "$(INTDIR)\UseClock.pch"


SOURCE=.\clock.h
SOURCE=.\ClockPropertiesDlg.h
SOURCE=.\HoursMinutesDlg.h
SOURCE=.\MainFrm.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\UseClock.h
SOURCE=.\UseClockDoc.h
SOURCE=.\UseClockView.h
SOURCE=.\res\UseClock.ico
SOURCE=.\res\UseClock.rc2
SOURCE=.\res\UseClockDoc.ico
SOURCE=.\ReadMe.txt

!ENDIF 

