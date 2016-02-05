// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "AddclanDlg.h"
#include "UserInfoDlg.h"

#define CHILD_LEFT	384
#define CHILD_TOP	25

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strEmail;
	CString	m_strICQ;
	CString	m_strWeb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont Font;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_strEmail = _T("wbc@alc-wbc.com");
	m_strICQ = _T("14542366");
	m_strWeb = _T("www.alc-wbc.com");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_EMAIL_EDIT, m_strEmail);
	DDX_Text(pDX, IDC_ICQ_EDIT, m_strICQ);
	DDX_Text(pDX, IDC_WEB_EDIT, m_strWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_nSeluin = 0;
	m_nOnline = 0;
	m_nTotaluser = 0;
	m_nTotalclan = 0;
	m_nNextuin = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_socketConn = new CICQClanSocket(this, 0);
	bCanshowdlg = TRUE;
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_CLAN_LIST, m_ctlClan);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nSeluin);
	DDX_Text(pDX, IDC_ONLINE_EDIT, m_nOnline);
	DDX_Text(pDX, IDC_TOTAL_EDIT, m_nTotaluser);
	DDX_Text(pDX, IDC_CLANTOTAL_EDIT, m_nTotalclan);
	DDX_Text(pDX, IDC_NEXTUIN_EDIT, m_nNextuin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_CLAN_LIST, OnSelchangeClanList)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_GETINFOS_BUTTON, OnGetinfosButton)
	ON_BN_CLICKED(IDC_ADDCLAN_BUTTON, OnAddclanButton)
	ON_BN_CLICKED(IDC_SETNEXTUIN_BUTTON, OnSetnextuinButton)
	ON_BN_CLICKED(IDC_DELCLAN_BUTTON, OnDelclanButton)
	ON_BN_CLICKED(IDC_CLANINFOS_BUTTON, OnClaninfosButton)
	ON_EN_CHANGE(IDC_NEXTUIN_EDIT, OnChangeNextuinEdit)
	ON_BN_CLICKED(IDC_USERSCLANLIST_BUTTON, OnUsersclanlistButton)
	ON_BN_CLICKED(IDC_MSGUSER_BUTTON, OnMsguserButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Charge
	m_nNextuin = AfxGetApp()->GetProfileInt("Exit state", "NextUIN", 100);
	m_nTotaluser = AfxGetApp()->GetProfileInt("Exit state", "Total", 0);

	// Créé un socket d'attente de connexion
	if ( !m_socketConn->Create(PORTLOCAL, SOCK_STREAM) )
	{
		m_socketConn->Close();
		MessageBox("Unable to create à socket");
	}
	else
		m_socketConn->Listen();

	// Créé les sockets, etc.
	register int	i;
	for (i=0; i<SOCKET_MAX; i++)
	{
		m_socket[i] = new CICQClanSocket(this, i);

		// SocketID	Correspondance
		//----------------------------
		//Bits 1-4
		//	0		Déconnecté
		//	1		Vient de créé un socket: Demande les infos
		//	2		Invisible
		//	3		Not Avaible
		//	4		Occupired
		//	5		Away
		//	6		Avaible/Connect
		//	7		Ready to play
		//	8		Nouvel Utilisateur: A entré le nick
		//	9		Nouvel Utilisateur: A entré le nom
		//	10		Nouvel Utilisateur: A entré le prénom (après doit envoyer pwd)
		//  11		Utilisateur enregistré: A entré le UIN
		//  12		Utilisateur enregistré: A entré le Pwd (après doit envoyer état)
		//Bits 5
		//	Augmente le temps depuis que l'UIN n'a pas envoyé d'infos.
		cState[i] = 0;
		nUIN[i] = -1;
	}

	// Total
	CString str;
	str.Format("%d", m_nTotaluser);
	GetDlgItem(IDC_TOTAL_EDIT)->SetWindowText(str);

	// Total online
	GetDlgItem(IDC_ONLINE_EDIT)->SetWindowText("0");

	// Next UIN
	str.Format("%d", m_nNextuin);
	GetDlgItem(IDC_NEXTUIN_EDIT)->SetWindowText(str);
	
	// Charge la liste de clans
	for (i=0; ;i++)
	{
		str.Format("%d", i);
		str = AfxGetApp()->GetProfileString("Clan list", "Clan"+str);
		if (str == "")
			break;
		m_ctlClan.AddString(str);
	}
	m_nTotalclan = m_ctlClan.GetCount();

	// Timer de timeout toutes les 5 min.
	SetTimer(1, 60000*5, NULL);
	
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerDlg::OnAccept()
{
	try
	{
		DWORD	dwSocketid;

		// Accepte
		for (int i=0; i<SOCKET_MAX; i++)
			if (cState[i] == 0)
			{
				dwSocketid = i;			// Donne l'ID
				cState[dwSocketid] = 1;	// En mode: Demande d'infos
				m_socketConn->Accept(*m_socket[dwSocketid]);
				break;
			}
	}
	catch (int)
	{
	}
}

void CServerDlg::OnReceive(DWORD dwSocketid)
{
	try
	{

		static CString	strOverflowData = "";
		CString		str[5],
					strData,
					strDataLine;
		int			i, t,
					nBufferLen,
					nReturnPos = -1;

		// Reçoit les données
		nBufferLen = m_socket[dwSocketid]->Receive(strData.GetBuffer(1024), 1024, NULL);
		strData.ReleaseBuffer(nBufferLen);
		strData = strOverflowData + strData;

		// Si y'a encore des données
		if (nBufferLen == 1024)
		{
			for (i=nBufferLen-1; i>=0; i--)
				if (strData.GetAt(i) == '\n')
					break;
			strOverflowData = strData.Mid(i+1);
		}
		else
			strOverflowData = "";

		if (nBufferLen > 0)
		{
			// Timeout = 0
			cState[dwSocketid] &= ~16;

			// Traite les données
			while (TRUE)
			{
				// Donne ligne par ligne strData
				strData = strData.Mid(nReturnPos+1);
				nReturnPos = strData.Find("\n", 0);
				if (nReturnPos == -1)
					break;
				strDataLine = strData.Left(nReturnPos);

				// Déconnexion
				if (strDataLine == "Disconnect")
					Deconnecter(dwSocketid);
				// Nouvel Utilisateur
				else if (strDataLine.Left(2) == "NU")
				{
					// Si info vides: Error
					if (strDataLine.Mid(2) == "")
					{
						m_socket[dwSocketid]->Send("Error");
						break;
					}

					switch (cState[dwSocketid] & 15)
					{
					case 1:
						str[0] = strDataLine.Mid(2);
						cState[dwSocketid] -= 15;
						cState[dwSocketid] |= 8;
						break;
					case 8:
						str[1] = strDataLine.Mid(2);
						cState[dwSocketid] -= 15;
						cState[dwSocketid] |= 9;
						break;
					case 9:
						str[2] = strDataLine.Mid(2);
						cState[dwSocketid] -= 15;
						cState[dwSocketid] |= 10;
						break;
					case 10:
						str[3] = strDataLine.Mid(2);

						// Nouvel UIN
						while (TRUE)
						{
							m_nNextuin++;
							if (AfxGetApp()->GetProfileString(str[4], "Nick") == "")
								break;
						}
						str[4].Format("%d", m_nNextuin);
						m_nNextuin++;
						GetDlgItem(IDC_NEXTUIN_EDIT)->SetWindowText(str[4]);
						
						// Enregistre new user
						AfxGetApp()->WriteProfileString(str[4], "Nick", str[0]);
						AfxGetApp()->WriteProfileString(str[4], "Name", str[1]);
						AfxGetApp()->WriteProfileString(str[4], "FirstName", str[2]);
						AfxGetApp()->WriteProfileString(str[4], "Pwd", str[3]);
		
						// Dernier on-line
						str[2].ReleaseBuffer( GetDateFormat(LOCALE_NEUTRAL, 0, NULL, "dd/MM/yy", str[2].GetBuffer(10), 10) );
						AfxGetApp()->WriteProfileString(str[0], "LastOnline", str[2]);

						// Envoi: User Identification Number
						m_socket[dwSocketid]->Send("UIN" + str[4]);

						// Déconnecte
						Deconnecter(dwSocketid);

						// Total user
						m_nTotaluser++;
						str[4].Format("%d", m_nTotaluser);
						GetDlgItem(IDC_TOTAL_EDIT)->SetWindowText(str[4]);

						// Enregistre
						AfxGetApp()->WriteProfileInt("Exit state", "NextUIN", m_nNextuin);
						AfxGetApp()->WriteProfileInt("Exit state", "Total", m_nTotaluser);

						break;
					}
				}
				// Old User (enregistré)
				else if (strDataLine.Left(2) == "OU")
				{
					// User envoi UIN
					switch (cState[dwSocketid] & 15)
					{
					case 1:
						str[0] = strDataLine.Mid(2);
						cState[dwSocketid] -= 15;
						cState[dwSocketid] |= 11;
						break;
					// User envoi Pwd
					case 11:
						str[1] = strDataLine.Mid(2);
						cState[dwSocketid] -= 15;
						cState[dwSocketid] |= 12;
						break;
					// User envoi état
					case 12:
						// Si le pwd est bon
						if (AfxGetApp()->GetProfileString(str[0], "Pwd") == str[1])
						{
							// Enregistre UIN
							nUIN[dwSocketid] = atoi(str[0]);

							// Si mode est bon met dans le mode
							cState[dwSocketid] -= 15;
							if (atoi(strDataLine.Mid(2)) > 1 &&
								atoi(strDataLine.Mid(2)) < 8)
								cState[dwSocketid] |= atoi(strDataLine.Mid(2));
							// Sinon met en Connecté
							else
								cState[dwSocketid] |= 6;

							// Dernier on-line
							str[2].ReleaseBuffer( GetDateFormat(LOCALE_NEUTRAL, 0, NULL, "dd/MM/yy", str[2].GetBuffer(10), 10) );
							AfxGetApp()->WriteProfileString(str[0], "LastOnline", str[2]);

							// Total online
							m_nOnline++;
							UpdateData(FALSE);
						}
						break;
					}
				}
				// Change State
				else if (strDataLine.Left(2) == "CS")
				{
					int nSeppos = strDataLine.Find(":", 2);
					// Teste si c le bon user
					if ((UINT)atol(strDataLine.Mid(2, nSeppos-2)) == nUIN[dwSocketid])
					{
						int nState = atoi(strDataLine.Mid(nSeppos+1));
						cState[dwSocketid] &= ~15;
						// Si mode est bon met dans le mode
						if (nState > 1 && nState < 8)
							cState[dwSocketid] |= nState;
						// Sinon met en Connecté
						else
							cState[dwSocketid] |= 6;
					}
				}
				// User veut: Add Clan
				else if (strDataLine.Left(2) == "AC:")
				{
					int nSeppos = strDataLine.Find(":", 2);
					str[0] = strDataLine.Mid(2, nSeppos-2);
					// Teste si le pwd est bon
					if (strDataLine.Mid(nSeppos+1) == AfxGetApp()->GetProfileString(str[0], "Pwd") )
					{
						// Donne le clan suivant de l'user
						// et vérif si le clan n'est pas en double
						str[2] = "0";
						for (int i=1; (str[4] = AfxGetApp()->GetProfileString(str[1], "Clan" + str[2])) != ""; i++)
						{
							str[2].Format("%d", i);
							if (str[4].MakeUpper == str[0].MakeUpper)
							{
								m_socket[dwSocketid]->Send("SM:Clan \"" + str[0] + "\" is already in your list.");
								break;
							}
						}

						// Enregistre clan pr user
						str[1].Format("%d", nUIN[dwSocketid]);
						AfxGetApp()->WriteProfileString(str[1], "Clan" + str[2], str[0]);

						// Donne le user suivant du clan
						// et vérif si l'user n'est pas en double
						str[2] = "0";
						for (i=1; (str[4] = AfxGetApp()->GetProfileString(str[0], "User" + str[2])) != ""; i++)
						{
							str[2].Format("%d", i);
							if (str[4].MakeUpper == str[1].MakeUpper)
							{
								m_socket[dwSocketid]->Send("SM:You are already in the clan \"" + str[0] + "\".");
								break;
							}
						}

						// Enregistre user pr clan
						str[1].Format("%d", nUIN[dwSocketid]);
						AfxGetApp()->WriteProfileString(str[0], "User" + str[2], str[1]);

						// Envoi System Message
						m_socket[dwSocketid]->Send("SM:You are in the clan \"" + str[0] + "\".");
					}
				}
				// Message
				else if (strDataLine.Left(2) == "M:")
				{
					t = strDataLine.Find(":", 2);
					if (t > 2)
					{
						str[0].Format("%d", nUIN[dwSocketid]);
						m_socket[GetSocketFromUIN( atoi(strDataLine.Mid(2, t-3)) )]->Send("M:" + str[0] + ":" + strDataLine.Mid(t+1));
					}
				}
			}
		}
	}
	catch (int)
	{
	}
}

void CServerDlg::OnSelchangeClanList() 
{
	// Enable boutons
	GetDlgItem(IDC_DELCLAN_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_CLANINFOS_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_MSGCLAN_BUTTON)->EnableWindow(TRUE);
}

void CServerDlg::OnTimer(UINT nIDEvent) 
{
	DWORD	dwSocketid;

	// Teste timeout
	for (dwSocketid=0; dwSocketid<SOCKET_MAX; dwSocketid++)
	{
		// Si timeout
		if ((cState[dwSocketid] & 16) == 16)
			Deconnecter(dwSocketid);
		// Demande si online
		else
		{
			cState[dwSocketid] |= 16;
			m_socket[dwSocketid]->Send("?");
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

// Déconnecte
void CServerDlg::Deconnecter(DWORD dwSocketid)
{
	try
	{
		// Déconnecte
		m_socket[dwSocketid]->Close();
		
		if (cState[dwSocketid] != 0)
		{
			cState[dwSocketid] = 0;
			nUIN[dwSocketid] = -1;

			// Enlève 1 au total online
			UpdateData(TRUE);
			m_nOnline--;
			UpdateData(FALSE);
		}
	}
	catch (int)
	{
	}
}

void CServerDlg::OnOK()
{
	// ENTER
	switch (GetFocus()->GetDlgCtrlID())
	{
	case IDC_UIN_EDIT:
		OnGetinfosButton();
		break;
	case IDC_NEXTUIN_EDIT:
		OnSetnextuinButton();
		break;
	}
}

void CServerDlg::OnCancel()
{
	// Quitte le programme
	if (MessageBox("If you continue you will disconnect every connected user to this server.\nAre you sure you want to close the program ?", "Close Server", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
		CDialog::OnOK();
}

void CServerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	m_socketConn->Close();
	delete m_socketConn;
	
	for (int i=0; i<SOCKET_MAX; i++)
		if (cState[i] != 0)
		{
			m_socket[i]->Close();
			delete m_socket[i];
		}
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Fonte
	Font.CreateFont(-8, NULL,
					NULL,
					NULL,
					FW_NORMAL, FALSE, TRUE, FALSE,
					DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS,
					DEFAULT_QUALITY,
					DEFAULT_PITCH | FF_SWISS,
					"MS Sans Serif");
	GetDlgItem(IDC_WEB_EDIT)->SetFont(&Font, FALSE);
	GetDlgItem(IDC_EMAIL_EDIT)->SetFont(&Font, FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->GetDlgCtrlID() == IDC_WEB_EDIT ||
		pWnd->GetDlgCtrlID() == IDC_EMAIL_EDIT)
		pDC->SetTextColor( RGB(0,0,255) );
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->hwnd == GetDlgItem(IDC_WEB_EDIT)->m_hWnd &&
		pMsg->message == WM_LBUTTONDOWN)
		ShellExecute(GetActiveWindow()->m_hWnd,
					 "open",
					 m_strWeb,
					 NULL,
					 NULL,
					 SW_SHOWNORMAL);

	// E-Mail
	if (pMsg->hwnd == GetDlgItem(IDC_EMAIL_EDIT)->m_hWnd &&
		pMsg->message == WM_LBUTTONDOWN)
		ShellExecute(GetActiveWindow()->m_hWnd,
					 "open",
					 "mailto:" + m_strEmail,
					 NULL,
					 NULL,
					 SW_SHOWNORMAL);
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// Change le curseur
	int nWndID = pWnd->GetDlgCtrlID();
	if (nWndID == IDC_WEB_EDIT || nWndID == IDC_EMAIL_EDIT)
	{
		::SetCursor(AfxGetApp()->LoadCursor(IDC_LIEN));
		return TRUE;
	}
	else
		return CDialog::OnSetCursor(pWnd, nHitTest, message);	
}

// Affiche les infos d'un utilisateur précis
void CServerDlg::OnGetinfosButton() 
{
	CString str,
			strSocket,
			strUIN;
	register int i;

	if (bCanshowdlg)
	{
		UpdateData(TRUE);

		strUIN.Format("%d", m_nSeluin);

		// Si l'utilisateur n'existe pas
		if (AfxGetApp()->GetProfileString(strUIN, "Nick") == "")
		{
			MessageBox("The user does NOT exist.", "ICQ Clan", MB_ICONWARNING);
			return;
		}

		// Affiche
		bCanshowdlg = FALSE;
		dlgUserinfo.Create(IDD_USERINFO_DIALOG, this);
		dlgUserinfo.SetWindowPos(NULL, CHILD_LEFT, CHILD_TOP, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

		// Cherche l'état du user
		i = GetSocketFromUIN(m_nSeluin);
		if (i == SOCKET_MAX)
		{
			// Socket ID
			strSocket = "None";
			// State
			str = "Disconnect";
		}
		else
		{
			// Socket ID
			strSocket.Format("%d", i);
			// State
			switch (cState[i])
			{
			case 0:
				str = "Disconnect";
				break;
			case 1:
				str = "Asking infos";
				break;
			case 2:
				str = "Invisible";
				break;
			case 3:
				str = "Not Avaible";
				break;
			case 4:
				str = "Occupired";
				break;
			case 5:
				str = "Away";
				break;
			case 6:
				str = "Avaible/Connect";
				break;
			case 7:
				str = "Ready to play";
				break;
			case 8:
				str = "New U. Nick";
				break;
			case 9:
				str = "New U. Name";
				break;
			case 10:
				str = "New U. Firstname";
				break;
			case 11:
				str = "Old U. UIN";
				break;
			case 12:
				str = "Old U. Password";
				break;
			default:
				str = "Error";
				break;
			}
		}

		// Affiche les infos
		dlgUserinfo.m_nUIN	= m_nSeluin;
		dlgUserinfo.m_strSocketid	= strSocket;
		dlgUserinfo.m_strState	= str;
		dlgUserinfo.m_strNick	= AfxGetApp()->GetProfileString(strUIN, "Nick");
		dlgUserinfo.m_strName	= AfxGetApp()->GetProfileString(strUIN, "Name");
		dlgUserinfo.m_strFirstname	= AfxGetApp()->GetProfileString(strUIN, "FirstName");
		dlgUserinfo.m_strPwd	= AfxGetApp()->GetProfileString(strUIN, "Pwd");
		dlgUserinfo.m_strLastonline	= AfxGetApp()->GetProfileString(strUIN, "LastOnline");
		dlgUserinfo.UpdateData(FALSE);
	}
}

// Enregistre les infos d'un utilisateur précis
void CServerDlg::OnGetinfosSave()
{
	CString	strUIN;
	
	strUIN.Format("%d", dlgUserinfo.m_nUIN);

	AfxGetApp()->WriteProfileString(strUIN, "Nick", dlgUserinfo.m_strNick);
	AfxGetApp()->WriteProfileString(strUIN, "Name", dlgUserinfo.m_strName);
	AfxGetApp()->WriteProfileString(strUIN, "FirstName", dlgUserinfo.m_strFirstname);
	AfxGetApp()->WriteProfileString(strUIN, "Pwd", dlgUserinfo.m_strPwd);
	AfxGetApp()->WriteProfileString(strUIN, "LastOnline", dlgUserinfo.m_strLastonline);

	dlgUserinfo.DestroyWindow();
}

// Ajoute un clan
void CServerDlg::OnAddclanButton() 
{
	if (bCanshowdlg)
	{
		bCanshowdlg = FALSE;
		dlgAddclan.Create(IDD_ADDCLAN_DIALOG, this);
		dlgAddclan.SetWindowPos(NULL, CHILD_LEFT, CHILD_TOP, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	}
}

// Définit le prochaine UIN
void CServerDlg::OnSetnextuinButton() 
{
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileInt("Exit state", "NextUIN", m_nNextuin );
}

// Efface un clan
void CServerDlg::OnDelclanButton() 
{
	CString str,
			strNext,
			strClanName;
	int		i,
			nCurItem;
	
	UpdateData(TRUE);

	// Cherche infos du clan
	nCurItem = m_ctlClan.GetCurSel();
	m_ctlClan.GetText(nCurItem, strClanName);
	str.Format("%d", nCurItem);

	// Teste si l'ID du clan est bon
	if (AfxGetApp()->GetProfileString("Clan list", "Clan" + str) == "")
	{
		MessageBox("Error: Invalid clan ID\nTo resolve the problem edit \"ICQCLAN SERVER.INI\" and check the number of clans.", "Error");
		return;
	}
			
	// Efface le clan de la liste des clans
	AfxGetApp()->WriteProfileString("Clan list", "Clan" + AfxGetApp()->GetProfileString(strClanName, "ID"), NULL);

	// Efface les users du clan
	strNext = "0";
	for (i=1; AfxGetApp()->GetProfileString(strClanName, "User" + strNext) != ""; i++)
	{
		strNext.Format("%d", i);
		AfxGetApp()->WriteProfileString(strClanName, "User" + strNext, NULL);
	}

	// Efface le clan
	AfxGetApp()->WriteProfileString(strClanName, "Leader", NULL);
	AfxGetApp()->WriteProfileString(strClanName, NULL, NULL);

	// Affiche total de clans
	m_nTotalclan--;
	UpdateData(FALSE);

	// Efface clan de la liste
	m_ctlClan.DeleteString(nCurItem);

	GetDlgItem(IDC_DELCLAN_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_CLANINFOS_BUTTON)->EnableWindow(FALSE);
}

// Donne le socket ID correspondant à un UIN dont le user est online.
inline UINT CServerDlg::GetSocketFromUIN(UINT nSearchUIN)
{
	register UINT i;
	for (i=0; i<m_nTotaluser; i++)
		if (nUIN[i] == nSearchUIN)
			return i;
	return SOCKET_MAX;
}

// Ajoute un clan
void CServerDlg::OnAddclanSave()
{
	CString str[2];
	
	// Donne l'ID du clan suivant
	if (m_nTotalclan == 0)
		str[1] = "0";
	else
	{
		str[0].Format("%d", m_nTotalclan - 1);
		str[1].Format("%d", m_nTotalclan);

		// Teste si l'ID du clan est bon
		if (AfxGetApp()->GetProfileString("Clan list", "Clan" + str[0]) == "" ||
			AfxGetApp()->GetProfileString("Clan list", "Clan" + str[1]) != "")
		{
			MessageBox("Error: Invalid next clan ID\nTo resolve the problem edit \"ICQCLAN SERVER.INI\" and check the number of clan.", "Error");
			return;
		}
	}
			
	// Enregistre le clan
	AfxGetApp()->WriteProfileString("Clan list", "Clan" + str[1], dlgAddclan.m_strClanname);
	AfxGetApp()->WriteProfileString(dlgAddclan.m_strClanname, "ID", str[1]);
	AfxGetApp()->WriteProfileString(dlgAddclan.m_strClanname, "Leader", dlgAddclan.m_strLeader);
	AfxGetApp()->WriteProfileString(dlgAddclan.m_strClanname, "Pwd", dlgAddclan.m_strPwd);

	// Affiche total de clans
	m_nTotalclan++;
	UpdateData(FALSE);

	// Ajoute clan à la liste
	m_ctlClan.AddString(dlgAddclan.m_strClanname);

	// Vire la fenêtre
	dlgAddclan.DestroyWindow();
}

// Affiche les infos du clan
void CServerDlg::OnClaninfosButton() 
{
	CString	str,
			strClan,
			strNext;
	UINT	nCursel;

	// Affiche
	if (!bCanshowdlg)
		return;
	bCanshowdlg = FALSE;
	dlgClaninfo.Create(IDD_CLANINFO_DIALOG, this);
	dlgClaninfo.SetWindowPos(NULL, CHILD_LEFT, CHILD_TOP, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

	// Charges les infos générales
	nCursel = m_ctlClan.GetCurSel();
	m_ctlClan.GetText(nCursel, strClan);
	dlgClaninfo.m_strClanname = strClan;
	dlgClaninfo.m_strID = AfxGetApp()->GetProfileString(strClan, "ID");
	dlgClaninfo.m_strLeader = AfxGetApp()->GetProfileString(strClan, "Leader");
	dlgClaninfo.m_strPwd = AfxGetApp()->GetProfileString(strClan, "Pwd");

	// Charges les user du clan
	strNext = "0";
	for (int i=1; (str = AfxGetApp()->GetProfileString(strClan, "User" + strNext)) != ""; i++)
	{
		dlgClaninfo.m_ctlList.AddString(str);
		strNext.Format("%d", i);
	}

	dlgClaninfo.UpdateData(FALSE);
}

// Sauvegarde les infos du clan
void CServerDlg::OnClaninfoSave()
{
	AfxGetApp()->WriteProfileString(dlgClaninfo.m_strClanname, "Leader", dlgClaninfo.m_strLeader);
	AfxGetApp()->WriteProfileString(dlgClaninfo.m_strClanname, "Pwd", dlgClaninfo.m_strPwd);
	dlgClaninfo.DestroyWindow();
}

void CServerDlg::OnChangeNextuinEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	static b = TRUE;
	if (b)
	{
		b = FALSE;
		return;
	}
	
	MessageBox("By changing this you can perturb the entire database.", "Warning", MB_ICONINFORMATION);
}

void CServerDlg::OnUsersclanlistButton() 
{
	CString	str,
			strUser,
			strNext;

	if (bCanshowdlg)
	{
		// Affiche
		bCanshowdlg = FALSE;
		dlgUsersclanlist.Create(IDD_USERCLANS_DIALOG, this);
		dlgUsersclanlist.SetWindowPos(NULL, CHILD_LEFT, CHILD_TOP, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

		// UIN
		UpdateData(TRUE);
		dlgUsersclanlist.m_nUIN = m_nSeluin;
		strUser.Format("%d", m_nSeluin);

		// List des clan
		strNext = "0";
		for (int i=1; (str = AfxGetApp()->GetProfileString(strUser, "Clan" + strNext)) != ""; i++)
		{
			dlgUsersclanlist.m_ctlList.AddString(str);
			strNext.Format("%d", i);
		}

		dlgUsersclanlist.UpdateData(FALSE);
	}
}

void CServerDlg::OnMsguserButton() 
{
	// Affiche Input
	if (!bCanshowdlg)
		return;
	bCanshowdlg = FALSE;
	dlgSminput.Create(IDD_SMINPUT_DIALOG, this);
	dlgSminput.SetWindowPos(NULL, CHILD_LEFT, CHILD_TOP, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	// Dit à qui l'envoyer
	strSendSMTo.Format("u%d", m_nSeluin);
}

// Envoi un SM à/aux user(s) donnés
void CServerDlg::OnSendSM()
{
	switch (strSendSMTo.GetAt(1))
	{
	// User sinple
	case 'u':
		m_socket[GetSocketFromUIN( atoi(strSendSMTo.Mid(1)) )]->Send("SM:" + dlgSminput.m_strInput);
		break;
	// Clan
	case 'c':
		break;
	// Tous
	case 't':
		break;
	}

	// Vire le dlg
	dlgSminput.DestroyWindow();
}
