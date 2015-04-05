; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ICQ Clan.h"

ClassCount=21
Class1=CICQClanApp
Class2=CICQClanDlg
Class3=CAboutDlg

ResourceCount=29
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_OPTIONS_MENU (English (U.S.))
Resource4=IDD_ICQCLAN_DIALOG (English (U.S.) - SDF)
Resource5=IDD_REG_OLD (English (U.S.))
Class4=CRegOldPP
Resource6=IDD_OPTIONS_SKIN (English (U.S.))
Resource7=IDD_FORMVIEW (English (U.S.))
Class5=CRegWelcomePP
Class6=CRegNewPP
Class7=CICQClanSocket
Resource8=IDD_OLE_PROPPAGE_LARGE (English (U.S.))
Resource9=IDD_OPTIONS_SECURITY (English (U.S.))
Resource10=IDD_ADDCLAN_DIALOG (English (U.S.))
Class8=CUserdetailsDlg
Resource11=IDD_CLANDETAILS_DIALOG (English (U.S.))
Class9=CMainFrame
Resource12=IDD_MYDETAILS_DIALOG (English (U.S.))
Resource13=IDD_PROPPAGE_LARGE (English (U.S.))
Resource14=IDD_REG_NEW (English (U.S.))
Resource15=IDD_ABOUTBOX (English (U.S.))
Resource16=IDD_OLDUSER_DIALOG (English (U.S.))
Class10=CReceiveDlg
Class11=CSendDlg
Resource17=IDD_REG_WELCOME (English (U.S.))
Class12=CMenuStatic
Resource18=IDD_ADDCLAN_DIALOG
Class13=CSkinButton
Resource19=IDD_ICQCLAN_DIALOG (English (U.S.))
Resource20=IDD_OPTIONS_GAME (English (U.S.))
Resource21=IDR_POPUP_MENU (English (U.S.))
Class14=COptionsGeneralPP
Class15=COptionsMenuPP
Class16=COptionsSkinPP
Resource22=IDD_SEND_DIALOG (English (U.S.))
Resource23=IDR_MAIN_MENU (English (U.S.))
Class17=COptionsSecurityPP
Resource24=IDD_OPTIONS_GENERAL (English (U.S.))
Resource25=IDD_USERDETAILS_DIALOG (English (U.S.))
Class18=CMydetailsDlg
Class19=CAddClanDlg
Resource26=IDD_ENTERPWD_DIALOG (English (U.S.))
Class20=COptionsGamePP
Resource27=IDD_NEWUSER_DIALOG (English (U.S.))
Class21=CInputDlg
Resource28=IDD_RECEIVE_DIALOG (English (U.S.))
Resource29=IDR_MENU1 (English (U.S.))

[CLS:CICQClanApp]
Type=0
HeaderFile=ICQ Clan.h
ImplementationFile=ICQ Clan.cpp
Filter=N
LastObject=CICQClanApp

[CLS:CICQClanDlg]
Type=0
HeaderFile=ICQ ClanDlg.h
ImplementationFile=ICQ ClanDlg.cpp
Filter=D
LastObject=CICQClanDlg
BaseClass=CResizingDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ICQ ClanDlg.h
ImplementationFile=ICQ ClanDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_ICQCLAN_DIALOG (English (U.S.))]
Type=1
Class=CICQClanDlg
ControlCount=5
Control1=IDC_STATUS_COMBO,combobox,1344339971
Control2=IDC_ADD_BUTTON,button,1342242827
Control3=IDC_SYS_BUTTON,button,1476460555
Control4=IDC_MAIN_BUTTON,button,1342242827
Control5=IDC_MENU,static,1350566144

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=14
Control1=IDOK,button,1342373889
Control2=IDC_1_STATIC,static,1342177283
Control3=IDC_BUILD_TEXT,static,1342308480
Control4=IDC_2_STATIC,static,1342308352
Control5=IDC_3_STATIC,static,1342308864
Control6=IDC_WEB_EDIT,edit,1342244992
Control7=IDC_4_STATIC,static,1342308864
Control8=IDC_EMAIL_EDIT,edit,1342244992
Control9=IDC_5_STATIC,static,1342308864
Control10=IDC_ICQ_EDIT,edit,1342244992
Control11=IDC_STATIC,static,1342308353
Control12=IDC_ANIMATE1,SysAnimate32,1350631424
Control13=IDC_ANIMATE2,SysAnimate32,1342242818
Control14=IDC_STATIC,static,1342308480

[CLS:CICQClanSocket]
Type=0
HeaderFile=ICQClanSocket.h
ImplementationFile=ICQClanSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CICQClanSocket

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrame.h
ImplementationFile=MainFrame.cpp
BaseClass=CFrameWnd
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CReceiveDlg]
Type=0
HeaderFile=ReceiveDlg.h
ImplementationFile=ReceiveDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReceiveDlg
VirtualFilter=dWC

[CLS:CSendDlg]
Type=0
HeaderFile=SendDlg.h
ImplementationFile=SendDlg.cpp
BaseClass=CResizingDialog
Filter=D
LastObject=CSendDlg
VirtualFilter=dWC

[CLS:CSkinButton]
Type=0
HeaderFile=SkinButton.h
ImplementationFile=SkinButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CSkinButton

[CLS:CMenuStatic]
Type=0
HeaderFile=MenuStatic.h
ImplementationFile=MenuStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CMenuStatic

[DLG:IDD_OLE_PROPPAGE_LARGE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[CLS:COptionsGeneralPP]
Type=0
HeaderFile=OptionsGeneralPP.h
ImplementationFile=OptionsGeneralPP.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=COptionsGeneralPP
VirtualFilter=idWC

[CLS:COptionsMenuPP]
Type=0
HeaderFile=OptionsMenuPP.h
ImplementationFile=OptionsMenuPP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=COptionsMenuPP

[CLS:COptionsSkinPP]
Type=0
HeaderFile=OptionsSkinPP.h
ImplementationFile=OptionsSkinPP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_AUTOR_EDIT

[DLG:IDD_REG_WELCOME (English (U.S.))]
Type=1
Class=CRegWelcomePP
ControlCount=6
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_NEW_RADIO,button,1342308361
Control6=IDC_OLD_RADIO,button,1342177289

[DLG:IDD_REG_NEW (English (U.S.))]
Type=1
Class=CRegNewPP
ControlCount=13
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308864
Control5=IDC_NICK_EDIT,edit,1350631552
Control6=IDC_STATIC,static,1342308864
Control7=IDC_NAME_EDIT,edit,1350631552
Control8=IDC_STATIC,static,1342308864
Control9=IDC_FIRSTNAME_EDIT,edit,1350631552
Control10=IDC_STATIC,static,1342308864
Control11=IDC_PWD_EDIT,edit,1350631584
Control12=IDC_STATIC,static,1342308864
Control13=IDC_PWD2_EDIT,edit,1350631584

[DLG:IDD_PROPPAGE_LARGE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_REG_OLD (English (U.S.))]
Type=1
Class=CRegOldPP
ControlCount=7
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308864
Control5=IDC_UIN_EDIT,edit,1350639744
Control6=IDC_STATIC,static,1342308864
Control7=IDC_OLDPWD_EDIT,edit,1350631584

[CLS:CRegNewPP]
Type=0
HeaderFile=RegNewPP.h
ImplementationFile=RegNewPP.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CRegNewPP
VirtualFilter=idWC

[CLS:CRegOldPP]
Type=0
HeaderFile=RegOldPP.h
ImplementationFile=RegOldPP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CRegOldPP

[CLS:CRegWelcomePP]
Type=0
HeaderFile=RegWelcomePP.h
ImplementationFile=RegWelcomePP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CRegWelcomePP

[DLG:IDD_ICQCLAN_DIALOG (English (U.S.) - SDF)]
Type=1
Class=CICQClanDlg
ControlCount=5
Control1=IDC_STATUS_COMBO,combobox,1344339971
Control2=IDC_ADD_BUTTON,button,1342242827
Control3=IDC_SYS_BUTTON,button,1476460555
Control4=IDC_MAIN_BUTTON,button,1342242827
Control5=IDC_MENU,static,1350566144

[DLG:IDD_OLDUSER_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_UIN_EDIT,edit,1350639744
Control4=IDC_STATIC,static,1342308864
Control5=IDC_OLDPWD_EDIT,edit,1350631584
Control6=IDC_BUTTON2,button,1342242817
Control7=IDC_BUTTON1,button,1342242816

[DLG:IDD_NEWUSER_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_NICK_EDIT,edit,1350631552
Control4=IDC_STATIC,static,1342308864
Control5=IDC_NAME_EDIT,edit,1350631552
Control6=IDC_STATIC,static,1342308864
Control7=IDC_FIRSTNAME_EDIT,edit,1350631552
Control8=IDC_STATIC,static,1342308864
Control9=IDC_PWD_EDIT,edit,1350631584
Control10=IDC_STATIC,static,1342308864
Control11=IDC_PWD_EDIT2,edit,1350631584
Control12=IDC_BUTTON2,button,1342242816
Control13=IDC_BUTTON1,button,1342242817

[DLG:IDD_CLANDETAILS_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_LEADER_EDIT,edit,1350639744

[DLG:IDD_USERDETAILS_DIALOG (English (U.S.))]
Type=1
Class=CUserdetailsDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=65535,static,1342308864
Control4=IDC_UIN_EDIT,edit,1350641792
Control5=65535,static,1342308864
Control6=IDC_NICK_EDIT,edit,1350633600
Control7=65535,static,1342308864
Control8=IDC_NAME_EDIT,edit,1350633600
Control9=65535,static,1342308864
Control10=IDC_FIRSTNAME_EDIT,edit,1350633600
Control11=65535,static,1342177294

[DLG:IDD_SEND_DIALOG (English (U.S.))]
Type=1
Class=CSendDlg
ControlCount=8
Control1=IDC_GRPBOX_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_UIN_EDIT,edit,1350641792
Control4=IDC_CLAN_STATIC,static,1342308864
Control5=IDC_CLAN_EDIT,edit,1350633600
Control6=IDC_TXT_EDIT,edit,1350635652
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[DLG:IDD_RECEIVE_DIALOG (English (U.S.))]
Type=1
Class=CReceiveDlg
ControlCount=8
Control1=IDC_GRPBOX_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_UIN_EDIT,edit,1350641792
Control4=IDC_CLAN_STATIC,static,1342308864
Control5=IDC_CLAN_EDIT,edit,1350633600
Control6=IDC_TXT_EDIT,edit,1350637700
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[DLG:IDD_OPTIONS_MENU (English (U.S.))]
Type=1
Class=COptionsMenuPP
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308864
Control3=IDC_MENU_SPEED1_EDIT,edit,1350639744
Control4=IDC_STATIC,static,1342308864
Control5=IDC_MENU_SPEED2_EDIT,edit,1350639744
Control6=IDC_STATIC,static,1342308864
Control7=IDC_MENU_RATE_EDIT,edit,1350639744
Control8=IDC_MENU_CLOSEONEXIT_CHECK,button,1342242819

[DLG:IDD_OPTIONS_GENERAL (English (U.S.))]
Type=1
Class=COptionsGeneralPP
ControlCount=7
Control1=IDC_STATIC,static,1342177294
Control2=IDC_ALWAYSTOP_CHECK,button,1342242819
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308864
Control5=IDC_SERVER_EDIT,edit,1350631552
Control6=IDC_STATIC,static,1342308864
Control7=IDC_PORT_EDIT,edit,1350639744

[DLG:IDD_OPTIONS_SKIN (English (U.S.))]
Type=1
Class=COptionsSkinPP
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_SKIN_BUTTON,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308864
Control5=IDC_NAME_EDIT,edit,1350633600
Control6=IDC_STATIC,static,1342308864
Control7=IDC_AUTOR_EDIT,edit,1350633600
Control8=IDC_NFO_EDIT,edit,1350633668

[MNU:IDR_POPUP_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_OPENICQCLAN
Command2=ID_MINIMIZEICQCLAN
Command3=ID_APP_EXIT
CommandCount=3

[MNU:IDR_MAIN_MENU (English (U.S.))]
Type=1
Class=?
Command1=ID_MAINMENU_CEATEACLAN
Command2=ID_MAINMENU_CLANLEADEROPTIONS_CLANDETAILS
Command3=ID_MAINMENU_CLANLEADEROPTIONS_KICKCLANUSER
Command4=ID_MAINMENU_CLANLEADEROPTIONS_DELETETHECLAN
Command5=ID_MAINMENU_USERINFOS
Command6=ID_MAINMENU_OPTIONS
Command7=ID_MAINMENU_HELP_ABOUT
Command8=ID_MAINMENU_SHUTDOWN
CommandCount=8

[MNU:IDR_MENU1 (English (U.S.))]
Type=1
Class=?
Command1=ID_USERCONTECTMENU_SENDAMESSAGE
Command2=ID_USERCONTECTMENU_JOINTHEGAME
CommandCount=2

[DLG:IDD_MYDETAILS_DIALOG (English (U.S.))]
Type=1
Class=CMydetailsDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308864
Control4=IDC_UIN_EDIT,edit,1350641792
Control5=IDC_STATIC,static,1342308864
Control6=IDC_NICK_EDIT,edit,1350631552
Control7=IDC_STATIC,static,1342308864
Control8=IDC_NAME_EDIT,edit,1350631552
Control9=IDC_STATIC,static,1342308864
Control10=IDC_FIRSTNAME_EDIT,edit,1350631552
Control11=IDC_STATIC,static,1342177294

[DLG:IDD_OPTIONS_SECURITY (English (U.S.))]
Type=1
Class=COptionsSecurityPP
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308864
Control4=IDC_PWD_EDIT,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_PWD2_EDIT,edit,1350631552
Control7=IDC_SAVEPWD_CHECK,button,1342242819
Control8=IDC_IP_CHECK,button,1342242819

[CLS:COptionsSecurityPP]
Type=0
HeaderFile=OptionsSecurityPP.h
ImplementationFile=OptionsSecurityPP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=COptionsSecurityPP

[CLS:CMydetailsDlg]
Type=0
HeaderFile=MydetailsDlg.h
ImplementationFile=MydetailsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMydetailsDlg

[CLS:CUserdetailsDlg]
Type=0
HeaderFile=UserdetailsDlg.h
ImplementationFile=UserdetailsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=65535
VirtualFilter=dWC

[DLG:IDD_ADDCLAN_DIALOG (English (U.S.))]
Type=1
Class=CAddClanDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308864
Control2=IDC_CLAN_EDIT,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CAddClanDlg]
Type=0
HeaderFile=AddClanDlg.h
ImplementationFile=AddClanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddClanDlg

[DLG:IDD_ENTERPWD_DIALOG (English (U.S.))]
Type=1
Class=CInputDlg
ControlCount=5
Control1=IDC_LBL,static,1342308864
Control2=IDC_INPUTSTR_EDIT,edit,1082196096
Control3=IDC_INPUTNUM_EDIT,edit,1082204288
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816

[DLG:IDD_OPTIONS_GAME (English (U.S.))]
Type=1
Class=COptionsGamePP
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308864
Control4=IDC_HL_EDIT,edit,1350633600
Control5=IDC_HL_BUTTON,button,1342242816
Control6=IDC_STATIC,static,1342308864
Control7=IDC_Q3_EDIT,edit,1350633600
Control8=IDC_Q3_BUTTON,button,1342242816

[CLS:COptionsGamePP]
Type=0
HeaderFile=OptionsGamePP.h
ImplementationFile=OptionsGamePP.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_HL_BUTTON

[CLS:CInputDlg]
Type=0
HeaderFile=InputDlg.h
ImplementationFile=InputDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CInputDlg

[DLG:IDD_ADDCLAN_DIALOG]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_NAME_EDIT,edit,1350631552
Control4=IDC_STATIC,static,1342308864
Control5=IDC_CIN_EDIT,edit,1350639744
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816

