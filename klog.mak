# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Install - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Install - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "KLog - Win32 Release" && "$(CFG)" != "KLog - Win32 Debug" &&\
 "$(CFG)" != "KLog - Win32 Static Release" && "$(CFG)" !=\
 "Install - Win32 Debug" && "$(CFG)" != "Install - Win32 Pure" && "$(CFG)" !=\
 "Install - Win32 Canned" && "$(CFG)" != "Install - Win32 Static"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "klog.mak" CFG="Install - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "KLog - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "KLog - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "KLog - Win32 Static Release" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Pure" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Canned" (based on "Win32 (x86) Application")
!MESSAGE "Install - Win32 Static" (based on "Win32 (x86) Application")
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
# PROP Target_Last_Scanned "Install - Win32 Static"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "KLog - Win32 Release"

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
# Begin Custom Macros
OutDir=.\Release
TargetName=klog
# End Custom Macros

ALL : "$(OUTDIR)\klog.exe" "$(OUTDIR)\klog.ex_" "$(OUTDIR)\klog.hlp"\
 "$(OUTDIR)\klog.cnt" "$(OUTDIR)\klog.hl_" "$(OUTDIR)\klog.cn_"

CLEAN : 
	-@erase "$(INTDIR)\klog.cn_"
	-@erase "$(INTDIR)\klog.cnt"
	-@erase "$(INTDIR)\klog.hl_"
	-@erase "$(INTDIR)\klog.hlp"
	-@erase "$(INTDIR)\KLog.obj"
	-@erase "$(INTDIR)\klog.pch"
	-@erase "$(INTDIR)\KLog.res"
	-@erase "$(INTDIR)\KLogDlg.obj"
	-@erase "$(INTDIR)\LogPattern.obj"
	-@erase "$(INTDIR)\LogPatternLocal.obj"
	-@erase "$(INTDIR)\LogPatternReserved.obj"
	-@erase "$(INTDIR)\LogPatternUnix.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SyslogSocket.obj"
	-@erase "$(INTDIR)\Trayer.obj"
	-@erase "$(INTDIR)\WarnBlocking.obj"
	-@erase "$(OUTDIR)\klog.ex_"
	-@erase "$(OUTDIR)\klog.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/klog.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/KLog.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/klog.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/klog.pdb" /machine:I386 /out:"$(OUTDIR)/klog.exe" 
LINK32_OBJS= \
	"$(INTDIR)\KLog.obj" \
	"$(INTDIR)\KLog.res" \
	"$(INTDIR)\KLogDlg.obj" \
	"$(INTDIR)\LogPattern.obj" \
	"$(INTDIR)\LogPatternLocal.obj" \
	"$(INTDIR)\LogPatternReserved.obj" \
	"$(INTDIR)\LogPatternUnix.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SyslogSocket.obj" \
	"$(INTDIR)\Trayer.obj" \
	"$(INTDIR)\WarnBlocking.obj"

"$(OUTDIR)\klog.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Release
TargetName=klog
InputPath=.\Release\klog.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"

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
# Begin Custom Macros
OutDir=.\Debug
TargetName=klog
# End Custom Macros

ALL : "$(OUTDIR)\klog.exe" "$(OUTDIR)\klog.ex_" "$(OUTDIR)\klog.hlp"\
 "$(OUTDIR)\klog.cnt" "$(OUTDIR)\klog.hl_" "$(OUTDIR)\klog.cn_"

CLEAN : 
	-@erase "$(INTDIR)\klog.cn_"
	-@erase "$(INTDIR)\klog.cnt"
	-@erase "$(INTDIR)\klog.hl_"
	-@erase "$(INTDIR)\klog.hlp"
	-@erase "$(INTDIR)\KLog.obj"
	-@erase "$(INTDIR)\klog.pch"
	-@erase "$(INTDIR)\KLog.res"
	-@erase "$(INTDIR)\KLogDlg.obj"
	-@erase "$(INTDIR)\LogPattern.obj"
	-@erase "$(INTDIR)\LogPatternLocal.obj"
	-@erase "$(INTDIR)\LogPatternReserved.obj"
	-@erase "$(INTDIR)\LogPatternUnix.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SyslogSocket.obj"
	-@erase "$(INTDIR)\Trayer.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WarnBlocking.obj"
	-@erase "$(OUTDIR)\klog.ex_"
	-@erase "$(OUTDIR)\klog.exe"
	-@erase "$(OUTDIR)\klog.ilk"
	-@erase "$(OUTDIR)\klog.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/klog.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/KLog.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/klog.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/klog.pdb" /debug /machine:I386 /out:"$(OUTDIR)/klog.exe" 
LINK32_OBJS= \
	"$(INTDIR)\KLog.obj" \
	"$(INTDIR)\KLog.res" \
	"$(INTDIR)\KLogDlg.obj" \
	"$(INTDIR)\LogPattern.obj" \
	"$(INTDIR)\LogPatternLocal.obj" \
	"$(INTDIR)\LogPatternReserved.obj" \
	"$(INTDIR)\LogPatternUnix.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SyslogSocket.obj" \
	"$(INTDIR)\Trayer.obj" \
	"$(INTDIR)\WarnBlocking.obj"

"$(OUTDIR)\klog.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Debug
TargetName=klog
InputPath=.\Debug\klog.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "KLog___W"
# PROP BASE Intermediate_Dir "KLog___W"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Releast"
# PROP Intermediate_Dir "Releast"
# PROP Target_Dir ""
OUTDIR=.\Releast
INTDIR=.\Releast
# Begin Custom Macros
OutDir=.\Releast
TargetName=klog
# End Custom Macros

ALL : "$(OUTDIR)\klog.exe" "$(OUTDIR)\klog.hlp" "$(OUTDIR)\klog.cnt"\
 "$(OUTDIR)\klog.hl_" "$(OUTDIR)\klog.cn_" "$(OUTDIR)\klog.ex_"

CLEAN : 
	-@erase "$(INTDIR)\klog.cn_"
	-@erase "$(INTDIR)\klog.cnt"
	-@erase "$(INTDIR)\klog.hl_"
	-@erase "$(INTDIR)\klog.hlp"
	-@erase "$(INTDIR)\KLog.obj"
	-@erase "$(INTDIR)\klog.pch"
	-@erase "$(INTDIR)\KLog.res"
	-@erase "$(INTDIR)\KLogDlg.obj"
	-@erase "$(INTDIR)\LogPattern.obj"
	-@erase "$(INTDIR)\LogPatternLocal.obj"
	-@erase "$(INTDIR)\LogPatternReserved.obj"
	-@erase "$(INTDIR)\LogPatternUnix.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\SyslogSocket.obj"
	-@erase "$(INTDIR)\Trayer.obj"
	-@erase "$(INTDIR)\WarnBlocking.obj"
	-@erase "$(OUTDIR)\klog.ex_"
	-@erase "$(OUTDIR)\klog.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_MBCS" /Fp"$(INTDIR)/klog.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Releast/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/KLog.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/klog.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/klog.pdb" /machine:I386 /out:"$(OUTDIR)/klog.exe" 
LINK32_OBJS= \
	"$(INTDIR)\KLog.obj" \
	"$(INTDIR)\KLog.res" \
	"$(INTDIR)\KLogDlg.obj" \
	"$(INTDIR)\LogPattern.obj" \
	"$(INTDIR)\LogPatternLocal.obj" \
	"$(INTDIR)\LogPatternReserved.obj" \
	"$(INTDIR)\LogPatternUnix.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\SyslogSocket.obj" \
	"$(INTDIR)\Trayer.obj" \
	"$(INTDIR)\WarnBlocking.obj"

"$(OUTDIR)\klog.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

# Begin Custom Build
OutDir=.\Releast
TargetName=klog
InputPath=.\Releast\klog.exe
SOURCE=$(InputPath)

"$(OutDir)\$(TargetName).ex_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   compress $(OutDir)\$(TargetName).exe $(OutDir)\$(TargetName).ex_

# End Custom Build

!ELSEIF  "$(CFG)" == "Install - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Install\Debug"
# PROP BASE Intermediate_Dir "Install\Debug"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Install\Debug"
# PROP Intermediate_Dir "Install\Debug"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Debug
INTDIR=.\Install\Debug

ALL : "KLog - Win32 Debug" "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\Install.exe"
	-@erase "$(OUTDIR)\Install.ilk"
	-@erase "$(OUTDIR)\Install.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib version.lib advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib shell32.lib version.lib\
 advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Install.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Install\Pure"
# PROP BASE Intermediate_Dir "Install\Pure"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Install\Pure"
# PROP Intermediate_Dir "Install\Pure"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Pure
INTDIR=.\Install\Pure

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/Install.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Pure/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib version.lib advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib shell32.lib version.lib\
 advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Install\Canned"
# PROP BASE Intermediate_Dir "Install\Canned"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Install\Canned"
# PROP Intermediate_Dir "Install\Canned"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Canned
INTDIR=.\Install\Canned

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "K_ANNED" /YX /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /D "K_ANNED" /Fp"$(INTDIR)/Install.pch" /YX\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Canned/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL" /d "K_ANNED"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" /d "_AFXDLL" /d\
 "K_ANNED" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib version.lib advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib shell32.lib version.lib\
 advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Install\Static"
# PROP BASE Intermediate_Dir "Install\Static"
# PROP BASE Target_Dir "Install"
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Install\Static"
# PROP Intermediate_Dir "Install\Static"
# PROP Target_Dir "Install"
OUTDIR=.\Install\Static
INTDIR=.\Install\Static

ALL : "$(OUTDIR)\Install.exe"

CLEAN : 
	-@erase "$(INTDIR)\install.obj"
	-@erase "$(INTDIR)\Install.res"
	-@erase "$(OUTDIR)\Install.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "STATI_K" /YX /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /D "STATI_K" /Fp"$(INTDIR)/Install.pch" /YX\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Install\Static/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL" /d "STATI_K"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Install.res" /d "NDEBUG" /d "_AFXDLL" /d\
 "STATI_K" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Install.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib version.lib advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib shell32.lib version.lib\
 advapi32.lib uuid.lib ole32.lib /nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Install.pdb" /machine:I386 /out:"$(OUTDIR)/Install.exe" 
LINK32_OBJS= \
	"$(INTDIR)\install.obj" \
	"$(INTDIR)\Install.res"

"$(OUTDIR)\Install.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "KLog - Win32 Release"
# Name "KLog - Win32 Debug"
# Name "KLog - Win32 Static Release"

!IF  "$(CFG)" == "KLog - Win32 Release"

!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"

!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\KLog.cpp
DEP_CPP_KLOG_=\
	".\KLog.h"\
	".\KLogDlg.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\KLog.obj" : $(SOURCE) $(DEP_CPP_KLOG_) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\KLog.obj" : $(SOURCE) $(DEP_CPP_KLOG_) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\KLog.obj" : $(SOURCE) $(DEP_CPP_KLOG_) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\KLogDlg.cpp
DEP_CPP_KLOGD=\
	".\KLog.h"\
	".\KLogDlg.h"\
	".\LogPattern.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	".\Trayer.h"\
	".\WarnBlocking.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\KLogDlg.obj" : $(SOURCE) $(DEP_CPP_KLOGD) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\KLogDlg.obj" : $(SOURCE) $(DEP_CPP_KLOGD) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\KLogDlg.obj" : $(SOURCE) $(DEP_CPP_KLOGD) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/klog.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c\
 $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\klog.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/klog.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\klog.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS"\
 /Fp"$(INTDIR)/klog.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\klog.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\klog.rc
DEP_RSC_KLOG_R=\
	".\res\fear.wav"\
	".\res\glass.wav"\
	".\res\kick.wav"\
	".\res\klog-icon.ico"\
	".\res\klog-triggered-icon.ico"\
	".\res\KLog.ico"\
	".\res\klog.rc2"\
	".\res\log-pattern.ico"\
	".\res\meow.wav"\
	".\shared-data\browse-icon.ico"\
	".\shared-data\klever-background.bmp"\
	".\shared-data\play-icon.ico"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\KLog.res" : $(SOURCE) $(DEP_RSC_KLOG_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\KLog.res" : $(SOURCE) $(DEP_RSC_KLOG_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\KLog.res" : $(SOURCE) $(DEP_RSC_KLOG_R) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\help\klog.hpj

!IF  "$(CFG)" == "KLog - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=.\Release
ProjDir=.
TargetName=klog
InputPath=.\help\klog.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=.\Debug
ProjDir=.
TargetName=klog
InputPath=.\help\klog.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"

# Begin Custom Build - Making help file...
OutDir=.\Releast
ProjDir=.
TargetName=klog
InputPath=.\help\klog.hpj

BuildCmds= \
	"$(ProjDir)\makehelp.bat" \
	compress $(OutDir)\$(TargetName).hlp $(OutDir)\$(TargetName).hl_ \
	compress $(OutDir)\$(TargetName).cnt $(OutDir)\$(TargetName).cn_ \
	

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).hl_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(OutDir)\$(TargetName).cn_" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SyslogSocket.cpp
DEP_CPP_SYSLO=\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\SyslogSocket.obj" : $(SOURCE) $(DEP_CPP_SYSLO) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\SyslogSocket.obj" : $(SOURCE) $(DEP_CPP_SYSLO) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\SyslogSocket.obj" : $(SOURCE) $(DEP_CPP_SYSLO) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Trayer.cpp
DEP_CPP_TRAYE=\
	".\KLog.h"\
	".\KLogDlg.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	".\Trayer.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\Trayer.obj" : $(SOURCE) $(DEP_CPP_TRAYE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\Trayer.obj" : $(SOURCE) $(DEP_CPP_TRAYE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\Trayer.obj" : $(SOURCE) $(DEP_CPP_TRAYE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LogPattern.cpp
DEP_CPP_LOGPA=\
	".\KLog.h"\
	".\LogPattern.h"\
	".\LogPatternLocal.h"\
	".\LogPatternReserved.h"\
	".\LogPatternUnix.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\LogPattern.obj" : $(SOURCE) $(DEP_CPP_LOGPA) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\LogPattern.obj" : $(SOURCE) $(DEP_CPP_LOGPA) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\LogPattern.obj" : $(SOURCE) $(DEP_CPP_LOGPA) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LogPatternUnix.cpp
DEP_CPP_LOGPAT=\
	".\KLog.h"\
	".\LogPattern.h"\
	".\LogPatternUnix.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\LogPatternUnix.obj" : $(SOURCE) $(DEP_CPP_LOGPAT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\LogPatternUnix.obj" : $(SOURCE) $(DEP_CPP_LOGPAT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\LogPatternUnix.obj" : $(SOURCE) $(DEP_CPP_LOGPAT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LogPatternReserved.cpp
DEP_CPP_LOGPATT=\
	".\KLog.h"\
	".\LogPattern.h"\
	".\LogPatternReserved.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\LogPatternReserved.obj" : $(SOURCE) $(DEP_CPP_LOGPATT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\LogPatternReserved.obj" : $(SOURCE) $(DEP_CPP_LOGPATT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\LogPatternReserved.obj" : $(SOURCE) $(DEP_CPP_LOGPATT) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\LogPatternLocal.cpp
DEP_CPP_LOGPATTE=\
	".\KLog.h"\
	".\LogPattern.h"\
	".\LogPatternLocal.h"\
	".\stdafx.h"\
	".\SyslogSocket.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\LogPatternLocal.obj" : $(SOURCE) $(DEP_CPP_LOGPATTE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\LogPatternLocal.obj" : $(SOURCE) $(DEP_CPP_LOGPATTE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\LogPatternLocal.obj" : $(SOURCE) $(DEP_CPP_LOGPATTE) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WarnBlocking.cpp
DEP_CPP_WARNB=\
	".\KLog.h"\
	".\stdafx.h"\
	".\WarnBlocking.h"\
	

!IF  "$(CFG)" == "KLog - Win32 Release"


"$(INTDIR)\WarnBlocking.obj" : $(SOURCE) $(DEP_CPP_WARNB) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Debug"


"$(INTDIR)\WarnBlocking.obj" : $(SOURCE) $(DEP_CPP_WARNB) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ELSEIF  "$(CFG)" == "KLog - Win32 Static Release"


"$(INTDIR)\WarnBlocking.obj" : $(SOURCE) $(DEP_CPP_WARNB) "$(INTDIR)"\
 "$(INTDIR)\klog.pch"


!ENDIF 

# End Source File
# End Target
################################################################################
# Begin Target

# Name "Install - Win32 Debug"
# Name "Install - Win32 Pure"
# Name "Install - Win32 Canned"
# Name "Install - Win32 Static"

!IF  "$(CFG)" == "Install - Win32 Debug"

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Install\Install.rc
DEP_RSC_INSTA=\
	".\Install\custom.rch"\
	".\shared-data\install-icon.ico"\
	

!IF  "$(CFG)" == "Install - Win32 Debug"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "_DEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Pure"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG" /d\
 "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Canned"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG" /d\
 "_AFXDLL" /d "K_ANNED" $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Static"


"$(INTDIR)\Install.res" : $(SOURCE) $(DEP_RSC_INSTA) "$(INTDIR)"
   $(RSC) /l 0x409 /fo"$(INTDIR)/Install.res" /i "Install" /d "NDEBUG" /d\
 "_AFXDLL" /d "STATI_K" $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Install\install.cpp
DEP_CPP_INSTAL=\
	".\shared-code\install.h"\
	

!IF  "$(CFG)" == "Install - Win32 Debug"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Pure"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Canned"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "Install - Win32 Static"


"$(INTDIR)\install.obj" : $(SOURCE) $(DEP_CPP_INSTAL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Project Dependency

# Project_Dep_Name "KLog"

!IF  "$(CFG)" == "Install - Win32 Debug"

"KLog - Win32 Debug" : 
   $(MAKE) /$(MAKEFLAGS) /F ".\klog.mak" CFG="KLog - Win32 Debug" 

!ELSEIF  "$(CFG)" == "Install - Win32 Pure"

!ELSEIF  "$(CFG)" == "Install - Win32 Canned"

!ELSEIF  "$(CFG)" == "Install - Win32 Static"

!ENDIF 

# End Project Dependency
# End Target
# End Project
################################################################################
