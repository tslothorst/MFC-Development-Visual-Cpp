# Microsoft Developer Studio Generated NMAKE File, Based on Clock.dsp
!IF "$(CFG)" == ""
CFG=Clock - Win32 Release
!MESSAGE No configuration specified. Defaulting to Clock - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Clock - Win32 Release" && "$(CFG)" != "Clock - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Clock.mak" CFG="Clock - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Clock - Win32 Release" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "Clock - Win32 Debug" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Clock - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Clock.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\Clock.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlarmPpg.obj"
	-@erase "$(INTDIR)\Clock.obj"
	-@erase "$(INTDIR)\Clock.pch"
	-@erase "$(INTDIR)\Clock.res"
	-@erase "$(INTDIR)\Clock.tlb"
	-@erase "$(INTDIR)\ClockCtl.obj"
	-@erase "$(INTDIR)\ClockPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\Clock.exp"
	-@erase "$(OUTDIR)\Clock.lib"
	-@erase "$(OUTDIR)\Clock.ocx"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_WINDLL" /D "_AFXDLL" /Fp"$(INTDIR)\Clock.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Clock.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Clock.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib /nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\Clock.pdb" /machine:I386 /def:".\Clock.def"\
 /out:"$(OUTDIR)\Clock.ocx" /implib:"$(OUTDIR)\Clock.lib" 
DEF_FILE= \
	".\Clock.def"
LINK32_OBJS= \
	"$(INTDIR)\AlarmPpg.obj" \
	"$(INTDIR)\Clock.obj" \
	"$(INTDIR)\Clock.res" \
	"$(INTDIR)\ClockCtl.obj" \
	"$(INTDIR)\ClockPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Clock.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Release
TargetPath=.\Release\Clock.ocx
InputPath=.\Release\Clock.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "Clock - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\Clock.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\Clock.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\AlarmPpg.obj"
	-@erase "$(INTDIR)\Clock.obj"
	-@erase "$(INTDIR)\Clock.pch"
	-@erase "$(INTDIR)\Clock.res"
	-@erase "$(INTDIR)\Clock.tlb"
	-@erase "$(INTDIR)\ClockCtl.obj"
	-@erase "$(INTDIR)\ClockPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\Clock.exp"
	-@erase "$(OUTDIR)\Clock.ilk"
	-@erase "$(OUTDIR)\Clock.lib"
	-@erase "$(OUTDIR)\Clock.ocx"
	-@erase "$(OUTDIR)\Clock.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_MBCS" /D "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\Clock.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Clock.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Clock.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=winmm.lib /nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\Clock.pdb" /debug /machine:I386 /def:".\Clock.def"\
 /out:"$(OUTDIR)\Clock.ocx" /implib:"$(OUTDIR)\Clock.lib" 
DEF_FILE= \
	".\Clock.def"
LINK32_OBJS= \
	"$(INTDIR)\AlarmPpg.obj" \
	"$(INTDIR)\Clock.obj" \
	"$(INTDIR)\Clock.res" \
	"$(INTDIR)\ClockCtl.obj" \
	"$(INTDIR)\ClockPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\Clock.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\.\Debug
TargetPath=.\Debug\Clock.ocx
InputPath=.\Debug\Clock.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 


!IF "$(CFG)" == "Clock - Win32 Release" || "$(CFG)" == "Clock - Win32 Debug"
SOURCE=.\AlarmPpg.cpp
DEP_CPP_ALARM=\
	".\alarmppg.h"\
	".\Clock.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\AlarmPpg.obj" : $(SOURCE) $(DEP_CPP_ALARM) "$(INTDIR)"\
 "$(INTDIR)\Clock.pch"


SOURCE=.\Clock.cpp
DEP_CPP_CLOCK=\
	".\Clock.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Clock.obj" : $(SOURCE) $(DEP_CPP_CLOCK) "$(INTDIR)"\
 "$(INTDIR)\Clock.pch"


SOURCE=.\Clock.def
SOURCE=.\Clock.odl

!IF  "$(CFG)" == "Clock - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\Clock.tlb" /mktyplib203 /win32\
 

"$(OUTDIR)\Clock.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Clock - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\Clock.tlb" /mktyplib203 /win32\
 

"$(OUTDIR)\Clock.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Clock.rc

!IF  "$(CFG)" == "Clock - Win32 Release"

DEP_RSC_CLOCK_=\
	".\Clock.ico"\
	".\ClockCtl.bmp"\
	
NODEP_RSC_CLOCK_=\
	".\Release\Clock.tlb"\
	

"$(INTDIR)\Clock.res" : $(SOURCE) $(DEP_RSC_CLOCK_) "$(INTDIR)"\
 "$(INTDIR)\Clock.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Clock.res" /i ".\Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Clock - Win32 Debug"

DEP_RSC_CLOCK_=\
	".\Clock.ico"\
	".\ClockCtl.bmp"\
	
NODEP_RSC_CLOCK_=\
	".\Debug\Clock.tlb"\
	

"$(INTDIR)\Clock.res" : $(SOURCE) $(DEP_RSC_CLOCK_) "$(INTDIR)"\
 "$(INTDIR)\Clock.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Clock.res" /i ".\Debug" /d "_DEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ENDIF 

SOURCE=.\ClockCtl.cpp
DEP_CPP_CLOCKC=\
	".\alarmppg.h"\
	".\Clock.h"\
	".\ClockCtl.h"\
	".\ClockPpg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ClockCtl.obj" : $(SOURCE) $(DEP_CPP_CLOCKC) "$(INTDIR)"\
 "$(INTDIR)\Clock.pch"


SOURCE=.\ClockPpg.cpp
DEP_CPP_CLOCKP=\
	".\Clock.h"\
	".\ClockPpg.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\ClockPpg.obj" : $(SOURCE) $(DEP_CPP_CLOCKP) "$(INTDIR)"\
 "$(INTDIR)\Clock.pch"


SOURCE=.\ReadMe.txt
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Clock - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /D "_USRDLL" /D "_WINDLL" /D "_AFXDLL" /Fp"$(INTDIR)\Clock.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Clock.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Clock - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_AFXDLL" /Fp"$(INTDIR)\Clock.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Clock.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\alarmppg.h
SOURCE=.\Clock.h
SOURCE=.\ClockCtl.h
SOURCE=.\ClockPpg.h
SOURCE=.\StdAfx.h
SOURCE=.\Clock.ico
SOURCE=.\ClockCtl.bmp

!ENDIF 

