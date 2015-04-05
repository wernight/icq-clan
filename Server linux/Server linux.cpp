/************************************************************************
*  Serveur linux pour ICQ Clan											*
*  Copyright (c) W. BEROUX 2000											*
*																		*
*  Ce prgramme console dans VC++ est compilé sous linux après.			*
*  Il faut surement changer les header, et d'autres trucs lors			*
*  de la préparation à la compilation sous linux.						*
*																		*
************************************************************************/
#ifdef WIN32_
#include <sys/types.h>
#include <sys/socket.h>
#endif

#include <stdio.h>

#define SOCKET_MAX	500
#define PORTLOCAL	6002


/////////////////////////////////////////////////////////////////////////////
// Prototypes & déclarations
//

unsigned int nOnline;
unsigned int nTotaluser;
unsigned int nTotalclan;
unsigned int nNextuin;
unsigned int nUIN[SOCKET_MAX];
char cState[SOCKET_MAX];
int socketConn;
int socket[SOCKET_MAX];

inline unsigned int GetSocketFromUIN(unsigned int nSearchUIN);
bool Init();


/////////////////////////////////////////////////////////////////////////////
// Début de l'application.
//

int main(int argc, char* argv[])
{
	// Infos
	printf("ICQ Clan Server v8/05/00 alpha\nCopyright (c) W. BEROUX 2000\nAll right reserved.\n\n");

	// Initialise
	if (!Init())
		return 1;

	return 0;
}


// Donne le socket ID correspondant à un UIN dont le user est online.
inline unsigned int GetSocketFromUIN(unsigned int nSearchUIN)
{
/*	register unsigned int i;
	for (i=0; i<m_nTotaluser; i++)
		if (nUIN[i] == nSearchUIN)
			return i;
	return SOCKET_MAX;*/
}

bool Init()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 0);

	err = WSAStartup( wVersionRequested, &wsaData );
	if (err != 0)
	{
		// Dis au user qu'il ne peut pas trouver de Socket utilisable
		printf("Impossible de trouver un socket utilisable.");
		return FALSE;
	}
 
	// Confirme que la DLL WinSock supporte la version 2.0.
	if (LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 0)
	{
		// Dis au user qu'il ne peut pas trouver de Socket utilisable
		printf("Socket v2.0 introuvable."
		WSACleanup();
		return FALSE; 
	}
 
	// Créé un socket d'attente de connexion
	socketConn = socket(123, SOCK_STREAM);
	if (socketConn == INVALID_SOCKET)//!m_socketConn->Create(PORTLOCAL, SOCK_STREAM) )
	{
		printf("Impossible de créer un socket");
		return FALSE; 
	}
}
	// Place le socket en attend de conn°
/*	socketConn->Listen();

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
}


void OnAccept()
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

void OnReceive(DWORD dwSocketid)
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

void OnTimer(UINT nIDEvent) 
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
void Deconnecter(DWORD dwSocketid)
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
*/