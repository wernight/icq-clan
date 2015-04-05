# Microsoft Developer Studio Project File - Name="ICQ Clan" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ICQ Clan - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ICQ Clan.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ICQ Clan.mak" CFG="ICQ Clan - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ICQ Clan - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ICQ Clan - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ICQ Clan - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "ICQ Clan - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ICQ Clan - Win32 Release"
# Name "ICQ Clan - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddClanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CBmpMenu.cpp
# End Source File
# Begin Source File

SOURCE=".\ICQ Clan.cpp"
# End Source File
# Begin Source File

SOURCE=".\ICQ Clan.rc"
# End Source File
# Begin Source File

SOURCE=".\ICQ ClanDlg.cpp"
# End Source File
# Begin Source File

SOURCE=.\ICQClanSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\InputDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuItem.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\MydetailsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsGamePP.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsGeneralPP.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsMenuPP.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsSecurityPP.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsSkinPP.cpp
# End Source File
# Begin Source File

SOURCE=.\ReceiveDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegNewPP.cpp
# End Source File
# Begin Source File

SOURCE=.\RegOldPP.cpp
# End Source File
# Begin Source File

SOURCE=.\RegWelcomePP.cpp
# End Source File
# Begin Source File

SOURCE=.\ResizingDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\SendDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SkinButton.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SystemTray.cpp
# End Source File
# Begin Source File

SOURCE=.\UserDetailsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WBC_Crypte.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddClanDlg.h
# End Source File
# Begin Source File

SOURCE=.\AutoBuildCount.h
# End Source File
# Begin Source File

SOURCE=.\CBmpMenu.h
# End Source File
# Begin Source File

SOURCE=".\ICQ Clan.h"
# End Source File
# Begin Source File

SOURCE=".\ICQ ClanDlg.h"
# End Source File
# Begin Source File

SOURCE=.\ICQClanSocket.h
# End Source File
# Begin Source File

SOURCE=.\InputDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrame.h
# End Source File
# Begin Source File

SOURCE=.\MenuItem.h
# End Source File
# Begin Source File

SOURCE=.\MenuStatic.h
# End Source File
# Begin Source File

SOURCE=.\MydetailsDlg.h
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\OptionsGamePP.h
# End Source File
# Begin Source File

SOURCE=.\OptionsGeneralPP.h
# End Source File
# Begin Source File

SOURCE=.\OptionsMenuPP.h
# End Source File
# Begin Source File

SOURCE=.\OptionsSecurityPP.h
# End Source File
# Begin Source File

SOURCE=.\OptionsSkinPP.h
# End Source File
# Begin Source File

SOURCE=.\ReceiveDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegNewPP.h
# End Source File
# Begin Source File

SOURCE=.\RegOldPP.h
# End Source File
# Begin Source File

SOURCE=.\RegWelcomePP.h
# End Source File
# Begin Source File

SOURCE=.\ResizingDialog.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SendDlg.h
# End Source File
# Begin Source File

SOURCE=.\SkinButton.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SystemTray.h
# End Source File
# Begin Source File

SOURCE=.\UserDetailsDlg.h
# End Source File
# Begin Source File

SOURCE=.\WBC_Crypte.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\game_hl.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=".\res\ICQ Clan.ico"
# End Source File
# Begin Source File

SOURCE=".\res\ICQ Clan.rc2"
# End Source File
# Begin Source File

SOURCE=.\res\lien.cur
# End Source File
# Begin Source File

SOURCE=".\res\Main Menu.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\mainmenu.bmp
# End Source File
# Begin Source File

SOURCE=.\res\msg_icon.ico
# End Source File
# Begin Source File

SOURCE=".\res\My details.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Options.bmp
# End Source File
# Begin Source File

SOURCE=.\res\state_aw.ico
# End Source File
# Begin Source File

SOURCE=.\res\state_bu.ico
# End Source File
# Begin Source File

SOURCE=.\res\state_in.ico
# End Source File
# Begin Source File

SOURCE=.\res\state_na.ico
# End Source File
# Begin Source File

SOURCE=.\res\state_of.ico
# End Source File
# Begin Source File

SOURCE=.\res\state_on.ico
# End Source File
# Begin Source File

SOURCE=.\res\Wizard.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\History.txt
# End Source File
# Begin Source File

SOURCE=.\res\ICQ.avi
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\WBC.avi
# End Source File
# End Target
# End Project
