@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by KLOG.HPJ. >"help\klog.hm"
echo. >>"help\klog.hm"
echo // Commands (ID_* and IDM_*) >>"help\klog.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"help\klog.hm"
echo. >>"help\klog.hm"
echo // Prompts (IDP_*) >>"help\klog.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"help\klog.hm"
echo. >>"help\klog.hm"
echo // Resources (IDR_*) >>"help\klog.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"help\klog.hm"
echo. >>"help\klog.hm"
echo // Dialogs (IDD_*) >>"help\klog.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"help\klog.hm"
echo. >>"help\klog.hm"
echo // Frame Controls (IDW_*) >>"help\klog.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"help\klog.hm"
REM -- Make help for Project KLOG

echo Building RTF file
xsltproc -o help/klog.rtf shared-code/kinhelp.xsl help/klog.xml
echo Building Win32 Help files
start /wait hcrtf -x "help\klog.hpj"
echo.
if exist Debug\nul copy "help\klog.hlp" Debug
if exist Debug\nul copy "help\klog.cnt" Debug
if exist Release\nul copy "help\klog.hlp" Release
if exist Release\nul copy "help\klog.cnt" Release
if exist Releast\nul copy "help\klog.hlp" Releast
if exist Releast\nul copy "help\klog.cnt" Releast
echo.

