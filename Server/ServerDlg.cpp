/************************************************************************************\
|                                                                                    |
|        II       CCCC      QQQ               _                                      |
|        II     CC         Q   Q            /    /|                                  |
|        II    C          Q     Q          |     |/   -i  /|/|                       |
|        II     CC         Q  QQ            \ __/ \__|_|_| | |_                      |
|        II       CCCC      QQQQ                       `                             |
|                               Q                                                    |
|                                                                                    |
|   ICQ Clan                                                                         |
|   Copyright (c) 2000 Werner BEROUX (known as WBC or Wernight)                      |
|   All rights reserved                                                              |
|                                                                                    |
|   Web site:     www.alc-wbc.com                                                    |
|   E-Mail:       wbc@alc-wbc.com                                                    |
|   ICQ UIN:      14542366                                                           |
|   ICQ Clan UIN: 0                                                                  |
|                                                                                    |
\************************************************************************************/
// ServerDlg.cpp : implementation file
//


// cState Correspondance
//----------------------------
//Bits 1-3 : Etat choisit par le user (pour afficher sa disponibilitée par une icone si y'a pas de jeux en cours).
//	0	.....000	Vient de créé un socket: Demande les infos (si 0 est envoyé comme état, ca veut dire "Déconnecté")
//	1	.....001	Invisible
//	2	.....010	Not Avaible
//	3	.....011	Occupired
//	4	.....100	Away
//	5	.....101	Avaible/Connect
//	6	.....110	Ready to play
//Bits 4-4 : Timeout
//	0	....0...	Time-out: Tout est ok
//	8	....1...	Time-out: Attention timeout la fois d'après
//Bits 5-7 : Jeux joué (pour afficher à côté du user l'icone du jeux)
//	0	.000....	Jeux: aucun
//	16	.001....	Jeux: Half-Life
//	32	.010....	Jeux: Counter-Strike (spétial car c'est un mod de Half-Life)
//	48	.011....	Jeux: Quake 3

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "AutoBuildCount.h"

#define CHILD_LEFT	384
#define CHILD_TOP	25

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CServerDlg::CServerDlg(CWnd* pParent) : CDialog(CServerDlg::IDD)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_strEmail = _T("wbc@alc-wbc.com");
	m_strICQ = _T("14542366");
	m_strServer = _T("");
	m_strWeb = _T("www.alc-wbc.com");
	m_nPort = PORTLOCAL;
	m_nOnline = 0;
	m_nTotaluser = 0;
	m_strSpeed = _T("");
	m_nTotalclan = 0;
	//}}AFX_DATA_INIT
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Text(pDX, IDC_EMAIL_EDIT, m_strEmail);
	DDV_MaxChars(pDX, m_strEmail, 30);
	DDX_Text(pDX, IDC_ICQ_EDIT, m_strICQ);
	DDV_MaxChars(pDX, m_strICQ, 20);
	DDX_Text(pDX, IDC_SERVER_EDIT, m_strServer);
	DDV_MaxChars(pDX, m_strServer, 50);
	DDX_Text(pDX, IDC_WEB_EDIT, m_strWeb);
	DDV_MaxChars(pDX, m_strWeb, 30);
	DDX_Text(pDX, IDC_PORT_EDIT, m_nPort);
	DDX_Text(pDX, IDC_ONLINEUSERS_EDIT, m_nOnline);
	DDX_Text(pDX, IDC_TOTALUSERS_EDIT, m_nTotaluser);
	DDX_Text(pDX, IDC_SPEED_STATIC, m_strSpeed);
	DDX_Text(pDX, IDC_TOTALCLANS_EDIT, m_nTotalclan);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_HIDE_BUTTON, OnHideButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// Déconnecte
void CServerDlg::Deconnecter(CICQClanSocket *pSocket)
{
	try
	{
		int				i, j;
		CString			str[5];
		CICQClanSocket	*pSocketTmp;

		/* A CHANGER ******\
		| CHANGER LA SUITE |
		\******************/
		// Envoi l'information aux users qui l'ont sur leur liste
		// Clan par Clan
		for (i=0, str[1]="0"; str[2]=AfxGetApp()->GetProfileString("u"+str[0], "c"+str[1], ""); str[1].Format("%d", ++i))
		{
			// Check le clan
			if (AfxGetApp()->GetProfileString("c"+str[2], "Name", "") == "" ||
				AfxGetApp()->GetProfileString("c"+str[2], "u0", "") == "")
				continue;

			// User du clan par user du clan
			for (j=0, str[3]="0"; str[4]=AfxGetApp()->GetProfileString("c"+str[2], "u"+str[3], ""); str[3].Format("%d", ++j))
				GetSocketFromUIN(atoi(str[4]))->Send("u\4" + str[2] + "\4" + str[4] + "\40");
		}

		// Change la chaine
		if (pSocket == pLastSocket)
		{
			pLastSocket = pSocket->pPrev;
			pLastSocket->pNext = NULL;
		}
		else
			pSocket->pPrev->pNext = pSocket->pNext;
		
		// Déconnecte
		pSocket->Close();
		delete pSocket;

		// Enlève 1 au total online
		m_nOnline--;
		UpdateData(FALSE);
	}
	catch (...)
	{
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
	
	// Efface les sockets
	CICQClanSocket *pSocket;
	pSocket = pFirstSocket;
	do
	{
		pFirstSocket = pFirstSocket->pNext;
		delete pSocket;
		pSocket = pFirstSocket;
	} while (pFirstSocket);
}

BOOL CServerDlg::OnInitDialog() 
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

	// Build #
	CString strOldVersionText, strNewVersionText;
	GetDlgItem(IDC_BUILD_TEXT)->GetWindowText( strOldVersionText );
	strNewVersionText.Format(strOldVersionText, BUILDCOUNT_NUM );
	GetDlgItem(IDC_BUILD_TEXT)->SetWindowText( strNewVersionText );

	// Charge
	nNextuin = AfxGetApp()->GetProfileInt("Exit state", "NextUIN", 100);
	m_nTotaluser = AfxGetApp()->GetProfileInt("Exit state", "Total user", 0);
	m_nTotalclan = AfxGetApp()->GetProfileInt("Exit state", "Total clan", 0);

	// Créé un socket d'attente de connexion
	pFirstSocket = new CICQClanSocket();
	pLastSocket = pFirstSocket;
	pLastSocket->pNext = NULL;
	
	if ( !pFirstSocket->Create(PORTLOCAL, SOCK_STREAM, GetLocalHost()) )
	{
		pFirstSocket->Close();
		MessageBox("Unable to create à socket");
	}
	else if (pFirstSocket->Listen(20) != 0)
	{
		// Affiche les infos du serveur
		pFirstSocket->GetSockName(m_strServer, m_nPort);
		// Animation pr montrer run
		SetTimer(0, 500, NULL);
	}

	// Timer de timeout toutes les 2 min.
	// -> Déconnection d'un gars après 4 minutes
	SetTimer(1, 2*60000, NULL);
	
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CServerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if (pWnd->GetDlgCtrlID() == IDC_WEB_EDIT ||
		pWnd->GetDlgCtrlID() == IDC_EMAIL_EDIT)
		pDC->SetTextColor( RGB(0,0,255) );
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CServerDlg::PreTranslateMessage(MSG* pMsg) 
{
	// Web
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

BOOL CServerDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
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

// Donne le socket ID correspondant à un UIN dont le user est online
// ou renvoi NULL si le user n'est pas connecté
inline CICQClanSocket* CServerDlg::GetSocketFromUIN(UINT nUIN)
{
	try
	{
		// Si introuvable ?
		if (pFirstSocket == pLastSocket)
			return NULL;

		CICQClanSocket *pSocket;

		// Cherche
		for (pSocket=pFirstSocket->pNext; pSocket && pSocket->nUIN!=nUIN; pSocket=pSocket->pNext)
		{ }

		// Renvoi le résultat
		return pSocket;
	}
	catch (...)
	{
	}
}

void CServerDlg::OnTimer(UINT nIDEvent) 
{
	static int		nSpeedPos = 0;
	CString			strPos = "-\\|/";

	switch (nIDEvent)
	{
	case 0:	// Animation pr montrer le run
		++nSpeedPos %= 4;
		m_strSpeed = strPos.Mid(nSpeedPos,1);
		UpdateData(FALSE);
		break;
	case 1:	// Time-out
		// Teste timeout
		CICQClanSocket *pSocket;
TimeoutStart:
		for (pSocket=pFirstSocket->pNext; pSocket; pSocket=pSocket->pNext)
		{
			// Si timeout
			if ((pSocket->cState & 8) == 8)
			{
				Deconnecter(pSocket);
				goto TimeoutStart;
			}
			// Sinon: Averti & Place en Time-out la fois d'après
			else
			{
				pSocket->cState |= 8;
				pSocket->Send("PING?");
			}

			// Si Fin
			if (pSocket == pLastSocket)
				break;
		}		
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}

// Cache
void CServerDlg::OnHideButton() 
{
	ShowWindow(SW_HIDE);
	KillTimer(0);
}

void CServerDlg::OnAccept()
{
	try
	{
		CICQClanSocket *pSocket = new CICQClanSocket;

		// Si n'a pas créer un socket
		if (!pSocket)
			return;

		// Essaye d'Accepter
		// Si impossible d'accepter
		if (!pFirstSocket->Accept(*pSocket))
		{
			delete pSocket;
			return;
		}

		// Accepté -> Change la chaine
		pLastSocket->pNext = pSocket;
		pSocket->pPrev = pLastSocket;
		pLastSocket = pSocket;
		pLastSocket->pNext = NULL;

		// Affiche
		m_nOnline++;
		UpdateData(FALSE);
	}
	catch (...)
	{
	}
}

void CServerDlg::OnReceive(CICQClanSocket *pSocket)
{
	try
	{
		static CString	strOverflowData = "";
		CString		str[7],
					strData,
					strDataLine;
		int			i, j, t,
					nBufferLen,
					nReturnPos;

		// Reçoit les données
		nBufferLen = pSocket->Receive(strData.GetBuffer(1024), 1024, NULL);
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
			pSocket->cState &= ~8;

			// Traite les données
			nReturnPos = -1;
			while (TRUE)
			{
				// Donne ligne par ligne strData
				strData = strData.Mid(nReturnPos+1);
				nReturnPos = strData.Find("\n", 0);
				if (nReturnPos == -1)
					break;
				strDataLine = strData.Left(nReturnPos);

				// Donne les paramètres de la ligne
				for (i=0, t=0; (j=strDataLine.Find('\4', i)) != -1 && t<7; t++, i=j+1)
					str[t] = strDataLine.Mid(i, j-i);
				str[t] = strDataLine.Mid(i);

				// Déconnexion
				if (str[0] == "Disconnect")
					Deconnecter(pSocket);
				// New User :
				//  1) Nickname
				//  2) Name
				//  3) Firstname
				//  4) Pwd
				//  Puis utilisation des str :
				//  5) UIN suivant (libre)
				//  6) Dernier on-line
				else if (str[0] == "NU" && str[1] != "" && str[2] != "" && str[3] != "" && str[4] != "")
				{
					// Cherche l'UIN d'après
					do
					{
						str[5].Format("%d", nNextuin);
						nNextuin++;
					} while (AfxGetApp()->GetProfileString(str[5], "Nick") != "");
					
					// Enregistre new user
					AfxGetApp()->WriteProfileString("u"+str[5], "Nick", str[1]);
					AfxGetApp()->WriteProfileString("u"+str[5], "Name", str[2]);
					AfxGetApp()->WriteProfileString("u"+str[5], "FirstName", str[3]);
					AfxGetApp()->WriteProfileString("u"+str[5], "Pwd", str[4]);
	
					// Dernier on-line
					str[6].ReleaseBuffer( GetDateFormat(LOCALE_NEUTRAL, 0, NULL, "dd/MM/yy", str[6].GetBuffer(10), 10) );
					AfxGetApp()->WriteProfileString("u"+str[5], "LastOnline", str[6]);

					// Envoi: User Identification Number
					pSocket->Send("UIN\4" + str[5]);

					// Déconnecte
					Deconnecter(pSocket);

					// Total user
					m_nTotaluser++;
					UpdateData(FALSE);

					// Enregistre
					AfxGetApp()->WriteProfileInt("Exit state", "NextUIN", nNextuin);
					AfxGetApp()->WriteProfileInt("Exit state", "Total user", m_nTotaluser);
				}
				// Old User (enregistré) :
				//  1) UIN
				//  2) Pwd
				//  3) State
				//  Puis utilisation des str :
				//  4) Dernier on-line
				//  5) String contenant la val de i
				//  6) ID du clan (utilisé dans la boucle)
				//  7) String contenant la val de j
				//  8) ID du user (utilisé dans la boucle)
				//  9) State du user
				else if (str[0] == "OU" && str[1] != "" && str[2] != "" && str[3] != "")
				{
					// Si le pwd n'est pas bon: Erreur
					if (AfxGetApp()->GetProfileString("u"+str[1], "Pwd") != str[2])
					{
						pSocket->Send("MID\4 1006");
						goto NextMsg;
					}
					// Si UIN déjà connecté: Erreur
					if (!GetSocketFromUIN( atoi(str[1]) ))
					{
						pSocket->Send("MID\4 1001");
						goto NextMsg;
					}

					// Sinon c bon

					// Enregistre UIN
					pSocket->nUIN = atoi(str[1]);

					// Si mode est bon met dans le mode
					int nState = atoi(str[3]);
					pSocket->cState &= ~7;
					if (nState >= 1 && nState <= 6)
						pSocket->cState |= nState;
					// Sinon met en Connecté
					else
						pSocket->cState |= 6;
					// Envoi l'état
					pSocket->Send("cs\4" + str[3]);

					// Dernier on-line
					str[4].ReleaseBuffer( GetDateFormat(LOCALE_NEUTRAL, 0, NULL, "dd/MM/yy", str[4].GetBuffer(10), 10) );
					AfxGetApp()->WriteProfileString("u"+str[1], "LastOnline", str[4]);

					// Envoi la liste des users et tout
					// Prend clan après clan (dans la liste des clans du new user)
					CICQClanSocket *pSocketTmp;
					for (i=0, str[5]="0"; str[6]=AfxGetApp()->GetProfileString("u"+str[1], "c"+str[5], ""); str[5].Format("%d", ++i))
					{
						// Check le clan
						if (AfxGetApp()->GetProfileString("c"+str[6], "Name", "") == "" ||
							AfxGetApp()->GetProfileString("c"+str[6], "u0", "") == "")
							continue;

						// Envoi ses Users
						for (j=0, str[7]="0"; str[8]=AfxGetApp()->GetProfileString("c"+str[6], "u"+str[7], ""); str[7].Format("%d", ++j))
						{
							// Socket correspondant au user de la boucle
							pSocketTmp = GetSocketFromUIN(atoi(str[8]));
							// Si pas connecté, n'envoi rien à personne
							if (pSocketTmp != NULL)
							{
								// Si il n'est pas invisible
								// Envoi la présence du user au new user
								if (pSocketTmp->cState > 1)
								{
									str[9].Format("%d", pSocketTmp->cState);
									pSocket->Send("us\4" + str[6] + "\4" + str[8] + "\4" + str[9]);
								}
								// Si il n'est pas invisible
								// Envoi la présence du new user au user
								if (pSocket->cState > 1)
									pSocketTmp->Send("us\4" + str[6] + "\4" + str[1] + "\4" + str[3]);
							}
						}
					}
				}
				// Change State :
				//  1) State
				else if (str[0] == "CS" && str[1] != "")
				{
					// Si mode est bon met dans le mode
					int nState = atoi(str[2]);
					if (nState < 1 || nState > 6)
					{
						pSocket->cState &= ~7;

						// Change le mode
						pSocket->cState |= nState;

						/* A FINIR ************\
						| ENVOYER LE CHGEMENT  |
						| AUX USERS QUI LE     |
						| CONNAISSENT          |
						\**********************/

						// Envoi la confirmation
						pSocket->Send("cs\4" + str[2]);
					}
				}
				// Add Clan :
				//  1) Clan pwd (si pwd = "", alors pas d'ajout possible)
				//  2) Clan ID
				//  Puis utilisation des str :
				//  3) ID, correspondant à i dans les boucles
				//  4) UIN ou ClanID correspondant à l'ID (str[3])
				//  5) UIN du user qui demande à ajouter le clan
				//  6) UIN d'un ancien user du clan (à envoyer au nouveau user)
				else if (str[0] == "AC" && str[1] != "" && str[2] != "")
				{
					// Teste le pwd du clan
					// Si str[1] == "" alors tester si le user à déjà ajouté le clan
					if ((str[1] == AfxGetApp()->GetProfileString(str[2], "Pwd") &&
						AfxGetApp()->GetProfileString(str[2], "Pwd") != "") ||
						(str[1] == ""))
					{
						// Donne l'ID du clan suivant du user (libre)
						str[5].Format("%d", pSocket->nUIN);
						for (i=0, str[3]="0"; (str[4] = AfxGetApp()->GetProfileString("u"+str[5], "c"+str[3])) != ""; str[3].Format("%d", ++i))
						{
							// Si le clan est déjà enregistré
							if (str[5].MakeUpper == str[4].MakeUpper)
							{
								// Si Le user n'a pas donné le pwd mais si il l'as donné avant
								if (str[1] == "")
									str[1] = AfxGetApp()->GetProfileString(str[2], "Pwd");
								i = -1;
								break;
							}
						}

						// Si str[1] == "" à cette ligne, alors le user n'est jamais ajouté
						// ce clan dans sa liste -> REFUS
						if (str[1] == "")
							goto FinAC;

						// Si il n'est pas encore enregistré
						// Enregistre clan pr user
						if (i != -1)
							AfxGetApp()->WriteProfileString("u"+str[5], "c"+str[3], str[2]);

						// Donne l'ID du user suivant du clan
						for (i=0, str[3]="0"; (str[4] = AfxGetApp()->GetProfileString("c"+str[2], "u" + str[3])) != ""; str[3].Format("%d", ++i))
						{
							// Si le user est déjà enregistré
							if (str[2].MakeUpper == str[3].MakeUpper)
							{
								i = -1;
								break;
							}
						}

						// Si il n'est pas encore enregistré
						// Enregistre user pr clan
						if (i != -1)
							AfxGetApp()->WriteProfileString("c"+str[2], "u"+str[2], str[5]);

						// Envoi les infos du clan (ID, Nom) au nouveau user
						pSocket->Send("ci\4"+str[2]+"\4"+AfxGetApp()->GetProfileString(str[2], "Name"));

						// Envoi les infos des anciens users (ID clan, ID, Nom) au nouveau user
						for (i=0, str[3]="0"; (str[6] = AfxGetApp()->GetProfileString("c"+str[2], "u" + str[3])) != ""; str[3].Format("%d", ++i))
							pSocket->Send("ui\4"+str[2]+"\4"+str[6]+"\4"+AfxGetApp()->GetProfileString("u"+str[6], "Nick"));

						// Envoi System Message: OK
						pSocket->Send("MID\4 1004\4"+AfxGetApp()->GetProfileString(str[2], "Name"));
					}
					else
						pSocket->Send("MID\4 1005\4"+AfxGetApp()->GetProfileString(str[2], "Name"));
FinAC:;
				}
				// Message :
				//  1) Sent to UIN
				//  2) Message
				else if (str[0] == "M" && str[1] != "" && str[2] != "")
				{
					str[3].Format("%d", pSocket->nUIN);
					GetSocketFromUIN( atoi(str[1]) )->Send("M\4" + str[3] + "\4" + str[2]);
				}
NextMsg:;
			}
		}
	}
	catch (...)
	{
	}
}

// Renvoi le host local
CString CServerDlg::GetLocalHost()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	char name[255];
	CString ip;
	PHOSTENT hostinfo;
	wVersionRequested = MAKEWORD( 2, 0 );

	if ( WSAStartup( wVersionRequested, &wsaData ) == 0 )
	{
		if( gethostname ( name, sizeof(name)) == 0)
			if((hostinfo = gethostbyname(name)) != NULL)
			{
				ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
				return ip;
			}

		WSACleanup( );
	}

	// Erreur ?
	return "";
}
