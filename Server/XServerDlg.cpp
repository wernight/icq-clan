// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"

#define CHILD_LEFT	384
#define CHILD_TOP	25

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CServerDlg::CServerDlg() : CDialog(CServerDlg::IDD)
{
	//{{AFX_DATA_INIT(CServerDlg)
	m_strEmail = _T("wbc@alc-wbc.com");
	m_strICQ = _T("14542366");
	m_strWeb = _T("www.alc-wbc.com");
	m_strRun = _T("1001101101101010");
	m_strServer = _T("");
	//}}AFX_DATA_INIT
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Text(pDX, IDC_EMAIL_EDIT, m_strEmail);
	DDX_Text(pDX, IDC_ICQ_EDIT, m_strICQ);
	DDX_Text(pDX, IDC_WEB_EDIT, m_strWeb);
	DDX_Text(pDX, IDC_RUN_STATIC, m_strRun);
	DDX_Text(pDX, IDC_SERVER_EDIT, m_strServer);
	DDV_MaxChars(pDX, m_strServer, 50);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
	//{{AFX_MSG_MAP(CServerDlg)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// Déconnecte
void CServerDlg::Deconnecter(DWORD dwSocketid)
{
/*	try
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
	catch (...)
	{
	}*/
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

	// Animation pr montrer run
	SetTimer(0, 100, NULL);

	// Charge
	nNextuin = AfxGetApp()->GetProfileInt("Exit state", "NextUIN", 100);
	nTotaluser = AfxGetApp()->GetProfileInt("Exit state", "Total", 0);

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

/*	// Charge la liste de clans
	for (i=0; ;i++)
	{
		str.Format("%d", i);
		str = AfxGetApp()->GetProfileString("Clan list", "Clan"+str);
		if (str == "")
			break;
		m_ctlClan.AddString(str);
	}
	m_nTotalclan = m_ctlClan.GetCount();
*/
	// Timer de timeout toutes les 5 min.
	SetTimer(1, 60000*5, NULL);
	
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

// Donne le socket ID correspondant à un UIN dont le user est online.
inline UINT CServerDlg::GetSocketFromUIN(UINT nSearchUIN)
{
	register UINT i;
	for (i=0; i<nTotaluser; i++)
		if (nUIN[i] == nSearchUIN)
			return i;
	return SOCKET_MAX;
}

void CServerDlg::OnTimer(UINT nIDEvent) 
{
	switch (nIDEvent)
	{
	case 0:	// Animation pr montrer le run
		m_strRun = m_strRun.Mid(1) + (char) ('0' + rand() * 2 / RAND_MAX);
		UpdateData(FALSE);
		break;
	case 1:	// Time-out
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
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}
