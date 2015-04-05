; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSminputDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=9
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDD_USERINFO_DIALOG (English (U.S.))
Resource2=IDR_MAINFRAME
Class4=CICQClanSocket
Resource3=IDD_ADDCLAN_DIALOG
Resource4=IDD_USERCLANS_DIALOG
Resource5=IDD_PROPPAGE_MEDIUM (English (U.S.))
Resource6=IDD_PROPPAGE_LARGE (English (U.S.))
Class5=CAddclanDlg
Resource7=IDD_DIALOGBAR (English (U.S.))
Resource8=IDD_ABOUTBOX
Class6=CUserInfoDlg
Class7=CClaninfoDlg
Resource9=IDD_SERVER_DIALOG
Class8=CUsersclanlistDlg
Resource10=IDD_CLANINFO_DIALOG
Class9=CSminputDlg
Resource11=IDD_SMINPUT_DIALOG

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
LastObject=CServerDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=10
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_WEB_EDIT,edit,1342244992
Control6=IDC_ICQ_EDIT,edit,1342244992
Control7=IDC_EMAIL_EDIT,edit,1342244992
Control8=IDC_STATIC,static,1342308864
Control9=IDC_STATIC,static,1342308864
Control10=IDC_STATIC,static,1342308864

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308864
Control3=IDC_CLANTOTAL_EDIT,edit,1350641792
Control4=IDC_CLAN_LIST,listbox,1352729859
Control5=IDC_ADDCLAN_BUTTON,button,1342242816
Control6=IDC_DELCLAN_BUTTON,button,1476460544
Control7=IDC_MSGCLAN_BUTTON,button,1476460544
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308864
Control10=IDC_TOTAL_EDIT,edit,1350641792
Control11=IDC_STATIC,static,1342308864
Control12=IDC_ONLINE_EDIT,edit,1350641792
Control13=IDC_STATIC,static,1342308864
Control14=IDC_NEXTUIN_EDIT,edit,1350639744
Control15=IDC_SETNEXTUIN_BUTTON,button,1342242816
Control16=IDC_MSG_BUTTON,button,1342242816
Control17=IDCANCEL,button,1342242816
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308864
Control20=IDC_UIN_EDIT,edit,1350639744
Control21=IDC_DELUSER_BUTTON,button,1342242816
Control22=IDC_GETINFOS_BUTTON,button,1342242816
Control23=IDC_MSGUSER_BUTTON,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_CLANINFOS_BUTTON,button,1476460544
Control26=IDC_USERSCLANLIST_BUTTON,button,1342242816

[CLS:CICQClanSocket]
Type=0
HeaderFile=ICQClanSocket.h
ImplementationFile=ICQClanSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CICQClanSocket

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PROPPAGE_MEDIUM (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_ADDCLAN_DIALOG]
Type=1
Class=CAddclanDlg
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME_EDIT,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_PWD_EDIT,edit,1350631552
Control6=IDOK,button,1342242816
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CLANID_EDIT,edit,1350641792
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LEADERUIN_EDIT,edit,1350639744

[CLS:CAddclanDlg]
Type=0
HeaderFile=AddclanDlg.h
ImplementationFile=AddclanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CLANID_EDIT

[DLG:IDD_PROPPAGE_LARGE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

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
Control7=IDC_IP_EDIT,edit,1350633600
Control8=IDC_STATIC,static,1342308864
Control9=IDC_NICK_EDIT,edit,1350631552
Control10=IDC_STATIC,static,1342308864
Control11=IDC_NAME_EDIT,edit,1350631552
Control12=IDC_STATIC,static,1342308864
Control13=IDC_FIRSTNAME_EDIT,edit,1350631552
Control14=IDC_STATIC,static,1342308864
Control15=IDC_PWD_EDIT,edit,1350631552
Control16=IDC_STATIC,static,1342308864
Control17=IDC_LASTONLINE_EDIT,edit,1350631552
Control18=IDOK,button,1342242816
Control19=IDCANCEL,button,1342242816
Control20=IDC_STATIC,static,1342308864
Control21=IDC_STATE_EDIT,edit,1350633600

[DLG:IDD_CLANINFO_DIALOG]
Type=1
Class=CClaninfoDlg
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
Control10=IDC_PWD_EDIT,edit,1350631552
Control11=IDC_STATIC,static,1342308864
Control12=IDC_LEADER_EDIT,edit,1350639744

[CLS:CUserInfoDlg]
Type=0
HeaderFile=UserInfoDlg.h
ImplementationFile=UserInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CUserInfoDlg
VirtualFilter=dWC

[CLS:CClaninfoDlg]
Type=0
HeaderFile=ClaninfoDlg.h
ImplementationFile=ClaninfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_USERCLANS_DIALOG]
Type=1
Class=CUsersclanlistDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=65535,button,1342177287
Control3=IDC_LIST1,listbox,1352728835
Control4=65535,static,1342308864
Control5=IDC_UIN_EDIT,edit,1350641792

[CLS:CUsersclanlistDlg]
Type=0
HeaderFile=UsersclanlistDlg.h
ImplementationFile=UsersclanlistDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=65535
VirtualFilter=dWC

[DLG:IDD_SMINPUT_DIALOG]
Type=1
Class=CSminputDlg
ControlCount=4
Control1=IDC_STATIC,button,1342177287
Control2=IDC_INPUT_EDIT,edit,1350635652
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CSminputDlg]
Type=0
HeaderFile=SminputDlg.h
ImplementationFile=SminputDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSminputDlg
VirtualFilter=dWC

