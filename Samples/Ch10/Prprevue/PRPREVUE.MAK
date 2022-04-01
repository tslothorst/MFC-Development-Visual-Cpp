# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=PrPrevue - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to PrPrevue - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "PrPrevue - Win32 Release" && "$(CFG)" !=\
 "PrPrevue - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "PrPrevue.mak" CFG="PrPrevue - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PrPrevue - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PrPrevue - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "PrPrevue - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PrPrevue - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\PrPrevue.exe"

CLEAN : 
	-@erase ".\Release\PrPrevue.exe"
	-@erase ".\Release\Dialogs.obj"
	-@erase ".\Release\PrPrevue.pch"
	-@erase ".\Release\PrinView.obj"
	-@erase ".\Release\PrPrevue.obj"
	-@erase ".\Release\PrintDoc.obj"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\PrPrevue.res"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PrPrevue.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PrPrevue.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PrPrevue.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/PrPrevue.pdb" /machine:I386 /out:"$(OUTDIR)/PrPrevue.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Dialogs.obj" \
	"$(INTDIR)/PrinView.obj" \
	"$(INTDIR)/PrPrevue.obj" \
	"$(INTDIR)/PrintDoc.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/PrPrevue.res"

"$(OUTDIR)\PrPrevue.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "PrPrevue - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\PrPrevue.exe"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\PrPrevue.pch"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\PrPrevue.exe"
	-@erase ".\Debug\PrPrevue.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\PrinView.obj"
	-@erase ".\Debug\Dialogs.obj"
	-@erase ".\Debug\PrintDoc.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\PrPrevue.res"
	-@erase ".\Debug\PrPrevue.ilk"
	-@erase ".\Debug\PrPrevue.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PrPrevue.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/PrPrevue.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PrPrevue.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/PrPrevue.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/PrPrevue.exe" 
LINK32_OBJS= \
	"$(INTDIR)/PrPrevue.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/PrinView.obj" \
	"$(INTDIR)/Dialogs.obj" \
	"$(INTDIR)/PrintDoc.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/PrPrevue.res"

"$(OUTDIR)\PrPrevue.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

################################################################################
# Begin Target

# Name "PrPrevue - Win32 Release"
# Name "PrPrevue - Win32 Debug"

!IF  "$(CFG)" == "PrPrevue - Win32 Release"

!ELSEIF  "$(CFG)" == "PrPrevue - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\PrPrevue.cpp
DEP_CPP_PRPRE=\
	".\StdAfx.h"\
	".\PrPrevue.h"\
	".\MainFrm.h"\
	".\printdoc.h"\
	".\prinview.h"\
	

"$(INTDIR)\PrPrevue.obj" : $(SOURCE) $(DEP_CPP_PRPRE) "$(INTDIR)"\
 "$(INTDIR)\PrPrevue.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "PrPrevue - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PrPrevue.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PrPrevue.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "PrPrevue - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/PrPrevue.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\PrPrevue.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\PrPrevue.h"\
	".\MainFrm.h"\
	".\printdoc.h"\
	".\prinview.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\PrPrevue.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PrPrevue.rc

!IF  "$(CFG)" == "PrPrevue - Win32 Release"

DEP_RSC_PRPREV=\
	".\res\PrPrevue.ico"\
	".\res\PrPrevueDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\PrPrevue.rc2"\
	

"$(INTDIR)\PrPrevue.res" : $(SOURCE) $(DEP_RSC_PRPREV) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "PrPrevue - Win32 Debug"

DEP_RSC_PRPREV=\
	".\res\PrPrevue.ico"\
	".\res\PrintDoc.ico"\
	".\res\Toolbar.bmp"\
	".\res\PrPrevue.rc2"\
	

"$(INTDIR)\PrPrevue.res" : $(SOURCE) $(DEP_RSC_PRPREV) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PrintDoc.cpp
DEP_CPP_PRINT=\
	".\StdAfx.h"\
	".\PrPrevue.h"\
	".\printdoc.h"\
	

"$(INTDIR)\PrintDoc.obj" : $(SOURCE) $(DEP_CPP_PRINT) "$(INTDIR)"\
 "$(INTDIR)\PrPrevue.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialogs.cpp
DEP_CPP_DIALO=\
	".\StdAfx.h"\
	".\PrPrevue.h"\
	".\dialogs.h"\
	

"$(INTDIR)\Dialogs.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"\
 "$(INTDIR)\PrPrevue.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PrinView.cpp
DEP_CPP_PRINV=\
	".\StdAfx.h"\
	".\PrPrevue.h"\
	".\printdoc.h"\
	".\prinview.h"\
	".\dialogs.h"\
	

"$(INTDIR)\PrinView.obj" : $(SOURCE) $(DEP_CPP_PRINV) "$(INTDIR)"\
 "$(INTDIR)\PrPrevue.pch"


# End Source File
# End Target
# End Project
################################################################################
