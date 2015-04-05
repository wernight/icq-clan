; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Controleur.h"

ClassCount=9
Class1=CControleurApp
Class2=CControleurDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_USERCLANS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_CONTROLEUR_DIALOG
Resource4=IDD_ADDCLAN_DIALOG
Resource5=IDD_USERINFO_DIALOG (English (U.S.))
Resource6=IDD_SMINPUT_DIALOG
Resource7=IDD_MAIN_DIALOG
Resource8=IDD_CLANINFO_DIALOG
Class4=CMainDlg
Class5=CAddClanDlg
Class6=CClanInfoDlg
Class7=CSMInputDlg
Class8=CUserClansDlg
Class9=CUserInfoDlg
Resource9=IDD_ABOUTBOX

[CLS:CControleurApp]
Type=0
HeaderFile=Controleur.h
ImplementationFile=Controleur.cpp
Filter=N

[CLS:CControleurDlg]
Type=0
HeaderFile=ControleurDlg.h
ImplementationFile=ControleurDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CControleurDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ControleurDlg.h
ImplementationFile=ControleurDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_BUILD_TEXT,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308480

[DLG:IDD_CONTROLEUR_DIALOG]
Type=1
Class=CControleurDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_IP_EDIT,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PWD_EDIT,edit,1350631584

[DLG:IDD_ADDCLAN_DIALOG]
Type=1
Class=CAddClanDlg
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME_EDIT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=1031,edit,1350631552
Control6=IDOK,button,1342242816
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CLANID_EDIT,edit,1350641792
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LEADERUIN_EDIT,edit,1350639744

[DLG:IDD_CLANINFO_DIALOG]
Type=1
Class=CClanInfoDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_LIST1,listbox,1352728835
Control5=IDC_STATIC,static,1342308864
Control6=IDC_CLANNAME_EDIT,edit,1350633600
Control7=IDC_STATIC,static,1342308864
Control8=IDC_CLANID_EDIT,edit,1350641792
Control9=IDC_STATIC,static,1342308864
Control10=1031,edit,1350631552
Control11=IDC_STATIC,static,1342308864
Control12=IDC_LEADER_EDIT,edit,1350639744

[DLG:IDD_SMINPUT_DIALOG]
Type=1
Class=CSMInputDlg
ControlCount=4
Control1=IDC_STATIC,button,1342177287
Control2=IDC_INPUT_EDIT,edit,1350635652
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[DLG:IDD_USERCLANS_DIALOG]
Type=1
Class=CUserClansDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=65535,button,1342177287
Control3=IDC_LIST1,listbox,1352728835
Control4=65535,static,1342308864
Control5=IDC_UIN_EDIT,edit,1350641792

[DLG:IDD_USERINFO_DIALOG (English (U.S.))]
Type=1
Class=CUserInfoDlg
ControlCount=21
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_UIN_EDIT,edit,1350641792
Control4=IDC_STATIC,static,1342308864
Control5=IDC_SOCKETID_EDIT,edit,1350641792
Control6=IDC_STATIC,static,1342308864
Control7=1033,edit,1350633600
Control8=IDC_STATIC,static,1342308864
Control9=IDC_NICK_EDIT,edit,1350631552
Control10=IDC_STATIC,static,1342308864
Control11=IDC_NAME_EDIT,edit,1350631552
Control12=IDC_STATIC,static,1342308864
Control13=IDC_FIRSTNAME_EDIT,edit,1350631552
Control14=IDC_STATIC,static,1342308864
Control15=1031,edit,1350631552
Control16=IDC_STATIC,static,1342308864
Control17=IDC_LASTONLINE_EDIT,edit,1350631552
Control18=IDOK,button,1342242816
Control19=IDCANCEL,button,1342242816
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATE_EDIT,edit,1350633600

[DLG:IDD_MAIN_DIALOG]
Type=1
Class=CMainDlg
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_CLANTOTAL_EDIT,edit,1350641792
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308864
Control6=IDC_CLANID_EDIT,edit,1350639744
Control7=IDC_DELCLAN_BUTTON,button,1342242816
Control8=IDC_CLANINFOS_BUTTON,button,1342242816
Control9=IDC_MSGCLAN_BUTTON,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308864
Control12=IDC_TOTAL_EDIT,edit,1350641792
Control13=IDC_STATIC,static,1342308864
Control14=IDC_ONLINE_EDIT,edit,1350641792
Control15=IDC_STATIC,static,1342308864
Control16=IDC_NEXTUIN_EDIT,edit,1350639744
Control17=IDC_SETNEXTUIN_BUTTON,button,1342242816
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308864
Control20=IDC_UIN_EDIT,edit,1350639744
Control21=IDC_DELUSER_BUTTON,button,1342242816
Control22=IDC_GETINFOS_BUTTON,button,1342242816
Control23=IDC_USERSCLANLIST_BUTTON,button,1342242816
Control24=IDC_MSGUSER_BUTTON,button,1342242816
Control25=IDC_STATIC,button,1342177287
Control26=IDCANCEL,button,1342242816

[CLS:CMainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainDlg

[CLS:CAddClanDlg]
Type=0
HeaderFile=AddClanDlg.h
ImplementationFile=AddClanDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CClanInfoDlg]
Type=0
HeaderFile=ClanInfoDlg.h
ImplementationFile=ClanInfoDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CSMInputDlg]
Type=0
HeaderFile=SMInputDlg.h
ImplementationFile=SMInputDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CUserClansDlg]
Type=0
HeaderFile=UserClansDlg.h
ImplementationFile=UserClansDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CUserInfoDlg]
Type=0
HeaderFile=UserInfoDlg.h
ImplementationFile=UserInfoDlg.cpp
BaseClass=CDialog
Filter=D

