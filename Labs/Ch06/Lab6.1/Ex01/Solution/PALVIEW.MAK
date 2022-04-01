# Microsoft Developer Studio Generated NMAKE File, Based on PalView.dsp
!IF "$(CFG)" == ""
CFG=PalView - Win32 Debug
!MESSAGE No configuration specified. Defaulting to PalView - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PalView - Win32 Release" && "$(CFG)" !=\
 "PalView - Win32 Debug" && "$(CFG)" != "PalView - Win32 Unicode Debug" &&\
 "$(CFG)" != "PalView - Win32 Unicode Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PalView.mak" CFG="PalView - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PalView - Win32 Release" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "PalView - Win32 Debug" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "PalView - Win32 Unicode Debug" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE "PalView - Win32 Unicode Release" (based on\
 "Win32 (x86) Win32 Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "PalView - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dib.obj"
	-@erase "$(INTDIR)\Dibpal.obj"
	-@erase "$(INTDIR)\PalView.obj"
	-@erase "$(INTDIR)\PalView.pch"
	-@erase "$(INTDIR)\PalView.res"
	-@erase "$(INTDIR)\PalView.tlb"
	-@erase "$(INTDIR)\PalViewCtl.obj"
	-@erase "$(INTDIR)\PalViewPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\PalView.exp"
	-@erase "$(OUTDIR)\PalView.lib"
	-@erase "$(OUTDIR)\PalView.ocx"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\PalView.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PalView.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PalView.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\PalView.pdb" /machine:I386 /def:".\PalView.def"\
 /out:"$(OUTDIR)\PalView.ocx" /implib:"$(OUTDIR)\PalView.lib" 
DEF_FILE= \
	".\PalView.def"
LINK32_OBJS= \
	"$(INTDIR)\Dib.obj" \
	"$(INTDIR)\Dibpal.obj" \
	"$(INTDIR)\PalView.obj" \
	"$(INTDIR)\PalView.res" \
	"$(INTDIR)\PalViewCtl.obj" \
	"$(INTDIR)\PalViewPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PalView.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Release
TargetPath=.\Release\PalView.ocx
InputPath=.\Release\PalView.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dib.obj"
	-@erase "$(INTDIR)\Dibpal.obj"
	-@erase "$(INTDIR)\PalView.obj"
	-@erase "$(INTDIR)\PalView.pch"
	-@erase "$(INTDIR)\PalView.res"
	-@erase "$(INTDIR)\PalView.tlb"
	-@erase "$(INTDIR)\PalViewCtl.obj"
	-@erase "$(INTDIR)\PalViewPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\PalView.exp"
	-@erase "$(OUTDIR)\PalView.ilk"
	-@erase "$(OUTDIR)\PalView.lib"
	-@erase "$(OUTDIR)\PalView.ocx"
	-@erase "$(OUTDIR)\PalView.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\PalView.pch" /Yu"stdafx.h"\
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PalView.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PalView.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\PalView.pdb" /debug /machine:I386 /def:".\PalView.def"\
 /out:"$(OUTDIR)\PalView.ocx" /implib:"$(OUTDIR)\PalView.lib" /pdbtype:sept 
DEF_FILE= \
	".\PalView.def"
LINK32_OBJS= \
	"$(INTDIR)\Dib.obj" \
	"$(INTDIR)\Dibpal.obj" \
	"$(INTDIR)\PalView.obj" \
	"$(INTDIR)\PalView.res" \
	"$(INTDIR)\PalViewCtl.obj" \
	"$(INTDIR)\PalViewPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PalView.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\PalView.ocx
InputPath=.\Debug\PalView.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dib.obj"
	-@erase "$(INTDIR)\Dibpal.obj"
	-@erase "$(INTDIR)\PalView.obj"
	-@erase "$(INTDIR)\PalView.pch"
	-@erase "$(INTDIR)\PalView.res"
	-@erase "$(INTDIR)\PalView.tlb"
	-@erase "$(INTDIR)\PalViewCtl.obj"
	-@erase "$(INTDIR)\PalViewPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(OUTDIR)\PalView.exp"
	-@erase "$(OUTDIR)\PalView.ilk"
	-@erase "$(OUTDIR)\PalView.lib"
	-@erase "$(OUTDIR)\PalView.ocx"
	-@erase "$(OUTDIR)\PalView.pdb"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PalView.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\DebugU/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PalView.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PalView.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes\
 /pdb:"$(OUTDIR)\PalView.pdb" /debug /machine:I386 /def:".\PalView.def"\
 /out:"$(OUTDIR)\PalView.ocx" /implib:"$(OUTDIR)\PalView.lib" /pdbtype:sept 
DEF_FILE= \
	".\PalView.def"
LINK32_OBJS= \
	"$(INTDIR)\Dib.obj" \
	"$(INTDIR)\Dibpal.obj" \
	"$(INTDIR)\PalView.obj" \
	"$(INTDIR)\PalView.res" \
	"$(INTDIR)\PalViewCtl.obj" \
	"$(INTDIR)\PalViewPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PalView.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\PalView.ocx
InputPath=.\DebugU\PalView.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"

OUTDIR=.\ReleaseU
INTDIR=.\ReleaseU
# Begin Custom Macros
OutDir=.\ReleaseU
# End Custom Macros

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ELSE 

ALL : "$(OUTDIR)\PalView.ocx" "$(OutDir)\regsvr32.trg"

!ENDIF 

CLEAN :
	-@erase "$(INTDIR)\Dib.obj"
	-@erase "$(INTDIR)\Dibpal.obj"
	-@erase "$(INTDIR)\PalView.obj"
	-@erase "$(INTDIR)\PalView.pch"
	-@erase "$(INTDIR)\PalView.res"
	-@erase "$(INTDIR)\PalView.tlb"
	-@erase "$(INTDIR)\PalViewCtl.obj"
	-@erase "$(INTDIR)\PalViewPpg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(OUTDIR)\PalView.exp"
	-@erase "$(OUTDIR)\PalView.lib"
	-@erase "$(OUTDIR)\PalView.ocx"
	-@erase "$(OutDir)\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PalView.pch"\
 /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
CPP_OBJS=.\ReleaseU/
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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\PalView.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\PalView.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no\
 /pdb:"$(OUTDIR)\PalView.pdb" /machine:I386 /def:".\PalView.def"\
 /out:"$(OUTDIR)\PalView.ocx" /implib:"$(OUTDIR)\PalView.lib" 
DEF_FILE= \
	".\PalView.def"
LINK32_OBJS= \
	"$(INTDIR)\Dib.obj" \
	"$(INTDIR)\Dibpal.obj" \
	"$(INTDIR)\PalView.obj" \
	"$(INTDIR)\PalView.res" \
	"$(INTDIR)\PalViewCtl.obj" \
	"$(INTDIR)\PalViewPpg.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\PalView.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseU
TargetPath=.\ReleaseU\PalView.ocx
InputPath=.\ReleaseU\PalView.ocx
SOURCE=$(InputPath)

"$(OutDir)\regsvr32.trg"	 : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	

!ENDIF 


!IF "$(CFG)" == "PalView - Win32 Release" || "$(CFG)" ==\
 "PalView - Win32 Debug" || "$(CFG)" == "PalView - Win32 Unicode Debug" ||\
 "$(CFG)" == "PalView - Win32 Unicode Release"
SOURCE=.\Dib.cpp
DEP_CPP_DIB_C=\
	".\dib.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"


"$(INTDIR)\Dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"


"$(INTDIR)\Dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"


"$(INTDIR)\Dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"


"$(INTDIR)\Dib.obj" : $(SOURCE) $(DEP_CPP_DIB_C) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ENDIF 

SOURCE=.\Dibpal.cpp
DEP_CPP_DIBPA=\
	".\dib.h"\
	".\dibpal.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"


"$(INTDIR)\Dibpal.obj" : $(SOURCE) $(DEP_CPP_DIBPA) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"


"$(INTDIR)\Dibpal.obj" : $(SOURCE) $(DEP_CPP_DIBPA) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"


"$(INTDIR)\Dibpal.obj" : $(SOURCE) $(DEP_CPP_DIBPA) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"


"$(INTDIR)\Dibpal.obj" : $(SOURCE) $(DEP_CPP_DIBPA) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ENDIF 

SOURCE=.\PalView.cpp
DEP_CPP_PALVI=\
	".\PalView.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"


"$(INTDIR)\PalView.obj" : $(SOURCE) $(DEP_CPP_PALVI) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"


"$(INTDIR)\PalView.obj" : $(SOURCE) $(DEP_CPP_PALVI) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"


"$(INTDIR)\PalView.obj" : $(SOURCE) $(DEP_CPP_PALVI) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"


"$(INTDIR)\PalView.obj" : $(SOURCE) $(DEP_CPP_PALVI) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ENDIF 

SOURCE=.\PalView.def
SOURCE=.\PalView.odl

!IF  "$(CFG)" == "PalView - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\PalView.tlb" /mktyplib203\
 /win32 

"$(OUTDIR)\PalView.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\PalView.tlb" /mktyplib203\
 /win32 

"$(OUTDIR)\PalView.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\PalView.tlb" /mktyplib203\
 /win32 

"$(OUTDIR)\PalView.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\PalView.tlb" /mktyplib203\
 /win32 

"$(OUTDIR)\PalView.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\PalView.rc

!IF  "$(CFG)" == "PalView - Win32 Release"

DEP_RSC_PALVIE=\
	".\PalView.ico"\
	".\PalViewCtl.bmp"\
	
NODEP_RSC_PALVIE=\
	".\Release\PalView.tlb"\
	

"$(INTDIR)\PalView.res" : $(SOURCE) $(DEP_RSC_PALVIE) "$(INTDIR)"\
 "$(INTDIR)\PalView.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\PalView.res" /i "Release" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"

DEP_RSC_PALVIE=\
	".\Debug\PalView.tlb"\
	".\PalView.ico"\
	".\PalViewCtl.bmp"\
	

"$(INTDIR)\PalView.res" : $(SOURCE) $(DEP_RSC_PALVIE) "$(INTDIR)"\
 "$(INTDIR)\PalView.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\PalView.res" /i "Debug" /d "_DEBUG" /d "_AFXDLL"\
 $(SOURCE)


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"

DEP_RSC_PALVIE=\
	".\PalView.ico"\
	".\PalViewCtl.bmp"\
	
NODEP_RSC_PALVIE=\
	".\DebugU\PalView.tlb"\
	

"$(INTDIR)\PalView.res" : $(SOURCE) $(DEP_RSC_PALVIE) "$(INTDIR)"\
 "$(INTDIR)\PalView.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\PalView.res" /i "DebugU" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"

DEP_RSC_PALVIE=\
	".\PalView.ico"\
	".\PalViewCtl.bmp"\
	
NODEP_RSC_PALVIE=\
	".\ReleaseU\PalView.tlb"\
	

"$(INTDIR)\PalView.res" : $(SOURCE) $(DEP_RSC_PALVIE) "$(INTDIR)"\
 "$(INTDIR)\PalView.tlb"
	$(RSC) /l 0x409 /fo"$(INTDIR)\PalView.res" /i "ReleaseU" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\PalViewCtl.cpp
DEP_CPP_PALVIEW=\
	".\dib.h"\
	".\dibpal.h"\
	".\PalView.h"\
	".\PalViewCtl.h"\
	".\PalViewPpg.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"


"$(INTDIR)\PalViewCtl.obj" : $(SOURCE) $(DEP_CPP_PALVIEW) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"


"$(INTDIR)\PalViewCtl.obj" : $(SOURCE) $(DEP_CPP_PALVIEW) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"


"$(INTDIR)\PalViewCtl.obj" : $(SOURCE) $(DEP_CPP_PALVIEW) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"


"$(INTDIR)\PalViewCtl.obj" : $(SOURCE) $(DEP_CPP_PALVIEW) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ENDIF 

SOURCE=.\PalViewPpg.cpp
DEP_CPP_PALVIEWP=\
	".\PalView.h"\
	".\PalViewPpg.h"\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"


"$(INTDIR)\PalViewPpg.obj" : $(SOURCE) $(DEP_CPP_PALVIEWP) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"


"$(INTDIR)\PalViewPpg.obj" : $(SOURCE) $(DEP_CPP_PALVIEWP) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"


"$(INTDIR)\PalViewPpg.obj" : $(SOURCE) $(DEP_CPP_PALVIEWP) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"


"$(INTDIR)\PalViewPpg.obj" : $(SOURCE) $(DEP_CPP_PALVIEWP) "$(INTDIR)"\
 "$(INTDIR)\PalView.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PalView - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\PalView.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PalView.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\PalView.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PalView.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE"\
 /Fp"$(INTDIR)\PalView.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD\
 /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PalView.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "PalView - Win32 Unicode Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\PalView.pch"\
 /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\PalView.pch" : $(SOURCE) $(DEP_CPP_STDAF)\
 "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\dib.h
SOURCE=.\dibpal.h
SOURCE=.\PalView.h
SOURCE=.\PalViewCtl.h
SOURCE=.\PalViewPpg.h
SOURCE=.\Resource.h
SOURCE=.\StdAfx.h
SOURCE=.\PalView.ico
SOURCE=.\PalViewCtl.bmp
SOURCE=.\ReadMe.txt

!ENDIF 

