; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=3
Class1=CServerApp
Class2=CICQClanSocket

ResourceCount=10
Resource1=IDD_USERINFO_DIALOG (English (U.S.))
Resource2=IDR_MAINFRAME
Resource3=IDD_ADDCLAN_DIALOG
Resource4=IDD_USERCLANS_DIALOG
Resource5=IDD_PROPPAGE_MEDIUM (English (U.S.))
Resource6=IDD_PROPPAGE_LARGE (English (U.S.))
Resource7=IDD_DIALOGBAR (English (U.S.))
Resource8=IDD_SMINPUT_DIALOG
Resource9=IDD_CLANINFO_DIALOG
Class3=CServerDlg
Resource10=IDD_ABOUTBOX

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N

[DLG:IDD_ABOUTBOX]
Type=1
Class=CServerDlg
ControlCount=27
Control1=IDCANCEL,button,1342373888
Control2=IDC_HIDE_BUTTON,button,1342373888
Control3=IDC_STATIC,static,1342177283
Control4=IDC_BUILD_TEXT,static,1342308480
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_WEB_EDIT,edit,1342244992
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EMAIL_EDIT,edit,1342244992
Control11=IDC_STATIC,static,1342308352
Control12=IDC_ICQ_EDIT,edit,1342244992
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308353
Control15=IDC_STATIC,static,1342308864
Control16=IDC_SERVER_EDIT,edit,1342244992
Control17=IDC_STATIC,static,1342308864
Control18=IDC_PORT_EDIT,edit,1342253184
Control19=IDC_STATIC,static,1342308864
Control20=IDC_TOTALUSERS_EDIT,edit,1342253184
Control21=IDC_STATIC,static,1342308864
Control22=IDC_ONLINEUSERS_EDIT,edit,1342253184
Control23=IDC_STATIC,static,1342308864
Control24=IDC_SPEED_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308864
Control26=IDC_TOTALCLANS_EDIT,edit,1342253184
Control27=IDC_STATIC,static,1342308480

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
Class=?
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

[DLG:IDD_PROPPAGE_LARGE (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_USERINFO_DIALOG (English (U.S.))]
Type=1
Class=?
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
Class=?
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

[DLG:IDD_USERCLANS_DIALOG]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342242817
Control2=65535,button,1342177287
Control3=IDC_LIST1,listbox,1352728835
Control4=65535,static,1342308864
Control5=IDC_UIN_EDIT,edit,1350641792

[DLG:IDD_SMINPUT_DIALOG]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,button,1342177287
Control2=IDC_INPUT_EDIT,edit,1350635652
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CServerDlg

