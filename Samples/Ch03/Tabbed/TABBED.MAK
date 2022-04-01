# Microsoft Developer Studio Generated NMAKE File, Based on Tabbed.dsp
!IF "$(CFG)" == ""
CFG=Tabbed - Win32 Release
!MESSAGE No configuration specified.  Defaulting to Tabbed - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Tabbed - Win32 Release" && "$(CFG)" != "Tabbed - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tabbed.mak" CFG="Tabbed - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tabbed - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Tabbed - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Tabbed - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Tabbed.exe"

CLEAN : 
	-@erase "$(INTDIR)\ClrLstBx.obj"
	-@erase "$(INTDIR)\ColorTab.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PhrasTab.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Tabbed.obj"
	-@erase "$(INTDIR)\Tabbed.pch"
	-@erase "$(INTDIR)\Tabbed.res"
	-@erase "$(INTDIR)\TabbeDoc.obj"
	-@erase "$(INTDIR)\TabbView.obj"
	-@erase "$(INTDIR)\XtraFunc.obj"
	-@erase "$(OUTDIR)\Tabbed.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Tabbed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Tabbed.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Tabbed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Tabbed.pdb" /machine:I386 /out:"$(OUTDIR)/Tabbed.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ClrLstBx.obj" \
	"$(INTDIR)\ColorTab.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PhrasTab.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tabbed.obj" \
	"$(INTDIR)\Tabbed.res" \
	"$(INTDIR)\TabbeDoc.obj" \
	"$(INTDIR)\TabbView.obj" \
	"$(INTDIR)\XtraFunc.obj"

"$(OUTDIR)\Tabbed.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Tabbed - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Tabbed.exe"

CLEAN : 
	-@erase "$(INTDIR)\ClrLstBx.obj"
	-@erase "$(INTDIR)\ColorTab.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\PhrasTab.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Tabbed.obj"
	-@erase "$(INTDIR)\Tabbed.pch"
	-@erase "$(INTDIR)\Tabbed.res"
	-@erase "$(INTDIR)\TabbeDoc.obj"
	-@erase "$(INTDIR)\TabbView.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(INTDIR)\XtraFunc.obj"
	-@erase "$(OUTDIR)\Tabbed.exe"
	-@erase "$(OUTDIR)\Tabbed.ilk"
	-@erase "$(OUTDIR)\Tabbed.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Tabbed.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Tabbed.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Tabbed.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Tabbed.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Tabbed.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ClrLstBx.obj" \
	"$(INTDIR)\ColorTab.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\PhrasTab.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Tabbed.obj" \
	"$(INTDIR)\Tabbed.res" \
	"$(INTDIR)\TabbeDoc.obj" \
	"$(INTDIR)\TabbView.obj" \
	"$(INTDIR)\XtraFunc.obj"

"$(OUTDIR)\Tabbed.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  


!IF "$(CFG)" == "Tabbed - Win32 Release" || "$(CFG)" == "Tabbed - Win32 Debug"
SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Tabbed - Win32 Release"


BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Tabbed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c $(SOURCE)

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Tabbed.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Tabbed - Win32 Debug"


BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Tabbed.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c $(SOURCE)

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Tabbed.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\ClrLstBx.cpp
DEP_CPP_CLRLS=\
	".\ClrLstBx.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	

"$(INTDIR)\ClrLstBx.obj" : $(SOURCE) $(DEP_CPP_CLRLS) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\ColorTab.cpp
DEP_CPP_COLOR=\
	".\ClrLstBx.h"\
	".\ColorTab.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	".\XtraFunc.h"\
	

"$(INTDIR)\ColorTab.obj" : $(SOURCE) $(DEP_CPP_COLOR) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\PhrasTab.cpp
DEP_CPP_PHRAS=\
	".\PhrasTab.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	

"$(INTDIR)\PhrasTab.obj" : $(SOURCE) $(DEP_CPP_PHRAS) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Tabbed.cpp
DEP_CPP_TABBE=\
	".\MainFrm.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	".\TabbeDoc.h"\
	".\TabbView.h"\
	

"$(INTDIR)\Tabbed.obj" : $(SOURCE) $(DEP_CPP_TABBE) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\TabbeDoc.cpp
DEP_CPP_TABBED=\
	".\StdAfx.h"\
	".\Tabbed.h"\
	".\TabbeDoc.h"\
	

"$(INTDIR)\TabbeDoc.obj" : $(SOURCE) $(DEP_CPP_TABBED) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\TabbView.cpp
DEP_CPP_TABBV=\
	".\ClrLstBx.h"\
	".\ColorTab.h"\
	".\PhrasTab.h"\
	".\StdAfx.h"\
	".\Tabbed.h"\
	".\TabbeDoc.h"\
	".\TabbView.h"\
	

"$(INTDIR)\TabbView.obj" : $(SOURCE) $(DEP_CPP_TABBV) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\XtraFunc.cpp
DEP_CPP_XTRAF=\
	".\StdAfx.h"\
	".\XtraFunc.h"\
	

"$(INTDIR)\XtraFunc.obj" : $(SOURCE) $(DEP_CPP_XTRAF) "$(INTDIR)"\
 "$(INTDIR)\Tabbed.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Tabbed.rc
DEP_RSC_TABBED_=\
	".\res\Tabbed.ico"\
	".\res\Tabbed.rc2"\
	".\res\TabbeDoc.ico"\
	

"$(INTDIR)\Tabbed.res" : $(SOURCE) $(DEP_RSC_TABBED_) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\StdAfx.h
SOURCE=.\Tabbed.h
SOURCE=.\MainFrm.h
SOURCE=.\ClrLstBx.h
SOURCE=.\ColorTab.h
SOURCE=.\XtraFunc.h
SOURCE=.\PhrasTab.h
SOURCE=.\TabbeDoc.h
SOURCE=.\TabbView.h
SOURCE=.\res\Tabbed.ico
SOURCE=.\res\TabbeDoc.ico
SOURCE=.\res\Tabbed.rc2

!ENDIF 

