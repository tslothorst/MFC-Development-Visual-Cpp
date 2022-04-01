# Microsoft Developer Studio Generated NMAKE File, Based on Modeless.dsp
!IF "$(CFG)" == ""
CFG=Modeless - Win32 Release
!MESSAGE No configuration specified.  Defaulting to Modeless - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "Modeless - Win32 Release" && "$(CFG)" !=\
 "Modeless - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Modeless.mak" CFG="Modeless - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Modeless - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Modeless - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Modeless - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Modeless.exe"

CLEAN : 
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MdlesDoc.obj"
	-@erase "$(INTDIR)\MlesView.obj"
	-@erase "$(INTDIR)\Modeless.obj"
	-@erase "$(INTDIR)\Modeless.pch"
	-@erase "$(INTDIR)\Modeless.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\XrtaFunc.obj"
	-@erase "$(OUTDIR)\Modeless.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Modeless.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Release/
CPP_SBRS=.
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Modeless.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Modeless.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Modeless.pdb" /machine:I386 /out:"$(OUTDIR)/Modeless.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MdlesDoc.obj" \
	"$(INTDIR)\MlesView.obj" \
	"$(INTDIR)\Modeless.obj" \
	"$(INTDIR)\Modeless.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XrtaFunc.obj"

"$(OUTDIR)\Modeless.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Modeless - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Modeless.exe"

CLEAN : 
	-@erase "$(INTDIR)\Dialogs.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MdlesDoc.obj"
	-@erase "$(INTDIR)\MlesView.obj"
	-@erase "$(INTDIR)\Modeless.obj"
	-@erase "$(INTDIR)\Modeless.pch"
	-@erase "$(INTDIR)\Modeless.res"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc50.idb"
	-@erase "$(INTDIR)\vc50.pdb"
	-@erase "$(INTDIR)\XrtaFunc.obj"
	-@erase "$(OUTDIR)\Modeless.exe"
	-@erase "$(OUTDIR)\Modeless.ilk"
	-@erase "$(OUTDIR)\Modeless.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Modeless.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /FD /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Modeless.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Modeless.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Modeless.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/Modeless.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Dialogs.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MdlesDoc.obj" \
	"$(INTDIR)\MlesView.obj" \
	"$(INTDIR)\Modeless.obj" \
	"$(INTDIR)\Modeless.res" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\XrtaFunc.obj"

"$(OUTDIR)\Modeless.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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


!IF "$(CFG)" == "Modeless - Win32 Release" || "$(CFG)" ==\
 "Modeless - Win32 Debug"
SOURCE=.\Modeless.cpp
DEP_CPP_MODEL=\
	".\Dialogs.H"\
	".\MainFrm.h"\
	".\MdlesDoc.h"\
	".\MlesView.h"\
	".\Modeless.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\Modeless.obj" : $(SOURCE) $(DEP_CPP_MODEL) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Modeless - Win32 Release"


BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Modeless.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /FD /c $(SOURCE)

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Modeless.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Modeless - Win32 Debug"


BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Modeless.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /FD /c $(SOURCE)

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Modeless.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\MainFrm.h"\
	".\Modeless.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Modeless.rc
DEP_RSC_MODELE=\
	".\Res\Mdlesdoc.ico"\
	".\Res\Modeless.ico"\
	".\Res\Modeless.rc2"\
	

"$(INTDIR)\Modeless.res" : $(SOURCE) $(DEP_RSC_MODELE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MdlesDoc.cpp
DEP_CPP_MDLES=\
	".\MdlesDoc.h"\
	".\Modeless.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MdlesDoc.obj" : $(SOURCE) $(DEP_CPP_MDLES) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\MlesView.cpp
DEP_CPP_MLESV=\
	".\Dialogs.H"\
	".\MdlesDoc.h"\
	".\MlesView.h"\
	".\Modeless.h"\
	".\StdAfx.h"\
	

"$(INTDIR)\MlesView.obj" : $(SOURCE) $(DEP_CPP_MLESV) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\XrtaFunc.cpp
DEP_CPP_XRTAF=\
	".\StdAfx.h"\
	".\XtraFunc.h"\
	

"$(INTDIR)\XrtaFunc.obj" : $(SOURCE) $(DEP_CPP_XRTAF) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\Dialogs.cpp
DEP_CPP_DIALO=\
	".\Dialogs.H"\
	".\Modeless.h"\
	".\StdAfx.h"\
	".\XtraFunc.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\Modeless.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.h
SOURCE=.\Modeless.h
SOURCE=.\MainFrm.h
SOURCE=.\Dialogs.H
SOURCE=.\MdlesDoc.h
SOURCE=.\MlesView.h
SOURCE=.\XtraFunc.h
SOURCE=.\Res\Modeless.ico
SOURCE=.\Res\Mdlesdoc.ico
SOURCE=.\Res\Modeless.rc2

!ENDIF 

