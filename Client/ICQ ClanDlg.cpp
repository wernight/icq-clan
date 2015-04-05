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
// ICQ ClanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "ICQ ClanDlg.h"
#include "AddClanDlg.h"
#include "MainFrame.h"
#include "InputDlg.h"
#include "WBC_Crypte.h"
#include "CBmpMenu.h"
#include "AutoBuildCount.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#else
#endif

extern CString m_strUIN;
extern CString m_strPwd;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CAnimateCtrl	m_ctlAni2;
	CAnimateCtrl	m_ctlAni;
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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	static UINT Thread(void* pParam);
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
	DDX_Control(pDX, IDC_ANIMATE2, m_ctlAni2);
	DDX_Control(pDX, IDC_ANIMATE1, m_ctlAni);
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
// CICQClanDlg dialog

CICQClanDlg::CICQClanDlg(CWnd* pParent /*=NULL*/)
	: CResizingDialog(CICQClanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CICQClanDlg)
	m_nState = -1;
	//}}AFX_DATA_INIT
	CDWordArray c_info;
	SetControlInfo(IDC_MENU,		RESIZE_HOR | RESIZE_VER, 1, 1);
	SetControlInfo(IDC_ADD_BUTTON,	ANCHORE_BOTTOM | RESIZE_HOR, 0.5, 1);
	SetControlInfo(IDC_SYS_BUTTON,	ANCHORE_BOTTOM | ANCHORE_RIGHT | RESIZE_HOR, 0.5, 1);
	SetControlInfo(IDC_MAIN_BUTTON,	ANCHORE_BOTTOM, 1, 1);
	SetControlInfo(IDC_STATUS_COMBO,ANCHORE_BOTTOM | RESIZE_HOR, 1, 1);
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_socket = new CICQClanSocket(this, 0);
	m_bConnected = FALSE;

	// Charge l'image close
/*	CString strSkinPath = AfxGetApp()->GetProfileString("Options", "Skin", "");
	CString strFile;
	strFile.ReleaseBuffer( ::GetPrivateProfileString("Window", "TitleImage", "", strFile.GetBuffer(255), 255, strSkinPath+"Skin.ini") );
	pBmpTitle = NULL;
	if (strFile != "")
	{
		HBITMAP hBitmap = NULL; 
		hBitmap = (HBITMAP)LoadImage(NULL, strSkinPath+strFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
		pBmpTitle = new CBitmap;
		pBmpTitle->Attach(hBitmap);
	}*/
}

void CICQClanDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizingDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CICQClanDlg)
	DDX_Control(pDX, IDC_MENU, m_ctlMenu);
	DDX_Control(pDX, IDC_ADD_BUTTON, m_ctlAdd);
	DDX_Control(pDX, IDC_SYS_BUTTON, m_ctlSys);
	DDX_Control(pDX, IDC_MAIN_BUTTON, m_ctlMain);
	DDX_Control(pDX, IDC_STATUS_COMBO, m_ctlState);
	DDX_CBIndex(pDX, IDC_STATUS_COMBO, m_nState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CICQClanDlg, CResizingDialog)
	//{{AFX_MSG_MAP(CICQClanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_STATUS_COMBO, OnSelchangeStatusCombo)
	ON_BN_CLICKED(IDC_ADD_BUTTON, OnAddButton)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_MAIN_BUTTON, OnMainButton)
	ON_COMMAND(ID_MAINMENU_SHUTDOWN, OnMainmenuShutdown)
	ON_BN_CLICKED(IDC_SYS_BUTTON, OnSysButton)
	ON_COMMAND(ID_MAINMENU_OPTIONS, OnMainmenuOptions)
	ON_COMMAND(ID_MAINMENU_HELP_ABOUT, OnMainmenuHelpAbout)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_MAINMENU_USERINFOS, OnMainmenuUserinfos)
	ON_COMMAND(ID_MAINMENU_CEATEACLAN, OnMainmenuCeateaclan)
	ON_COMMAND(ID_MAINMENU_CLANLEADEROPTIONS_CLANDETAILS, OnMainmenuClanleaderoptionsClandetails)
	ON_COMMAND(ID_MAINMENU_CLANLEADEROPTIONS_DELETETHECLAN, OnMainmenuClanleaderoptionsDeletetheclan)
	ON_COMMAND(ID_MAINMENU_CLANLEADEROPTIONS_KICKCLANUSER, OnMainmenuClanleaderoptionsKickclanuser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICQClanDlg message handlers

BOOL CICQClanDlg::OnInitDialog()
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

	// Ini les options
	ppOptionsGeneral.m_psp.dwFlags -= PSP_HASHELP;
	ppOptionsSecurity.m_psp.dwFlags -= PSP_HASHELP;
	ppOptionsMenu.m_psp.dwFlags -= PSP_HASHELP;
	ppOptionsGame.m_psp.dwFlags -= PSP_HASHELP;
	ppOptionsSkin.m_psp.dwFlags -= PSP_HASHELP;
	psOptions.m_psh.dwFlags -= PSH_HASHELP;
	psOptions.AddPage( &ppOptionsGeneral );
	psOptions.AddPage( &ppOptionsSecurity );
	psOptions.AddPage( &ppOptionsMenu );
	psOptions.AddPage( &ppOptionsGame );
	psOptions.AddPage( &ppOptionsSkin );

	// Créé socket
	for (UINT i=ID_SRVPORT; i<AfxGetApp()->GetProfileInt("Options", "ServeurPort", ID_SRVPORT)+100; i++)
		if (!m_socket->Create())
			m_socket->Close();
		else
			goto SocketOK;

	// Erreur lors de la création du socket
	MessageBox("Error while trying to create a socket.");
	OnCancel();
	return TRUE;
SocketOK:

	// Charge les infos
	// Place au top ?
	if (AfxGetApp()->GetProfileInt("Options", "AlwaysTop", FALSE))
		SetWindowPos(&wndTopMost, 0,0, 0,0, NULL);
	// Positon
	SetWindowPos(NULL,
				 AfxGetApp()->GetProfileInt("USER1", "Pos_x", 100),
				 AfxGetApp()->GetProfileInt("USER1", "Pos_y", 100),
				 AfxGetApp()->GetProfileInt("USER1", "Pos_nx", 185),
				 AfxGetApp()->GetProfileInt("USER1", "Pos_ny", 350),
				 SWP_NOZORDER);
	this->SetWindowText( m_strUIN );

	// Charge les boutons
	m_ctlMenu.AddItem("Clan FORCE");
	m_ctlMenu.AddItem("Demons:");
	m_ctlMenu.AddSubItem("[FORCE]Wernight", 0);
	m_ctlMenu.AddSubItem("[FORCE]Prezo", 0);
	m_ctlMenu.AddSubItem("[FORCE]Sp@rks", 0);
	m_ctlMenu.AddSubItem("[FORCE]IanSolo", 0);
	m_ctlMenu.AddSubItem("[FORCE]Commodore", 0);
	m_ctlMenu.AddSubItem("[FORCE]Poussin", 0);
	m_ctlMenu.AddSubItem("[FORCE]Spy", 0);
	m_ctlMenu.AddSubItem("[FORCE]D@rkbert", 0);
	m_ctlMenu.AddSubItem("[FORCE]Bob", 0);
	m_ctlMenu.AddSubItem("Gorgio", 1);
	m_ctlMenu.AddSubItem("Anges", 1);
	m_ctlMenu.AddItem("Alphabet");
	m_ctlMenu.AddSubItem("A", 2);
	m_ctlMenu.AddSubItem("B", 2);
	m_ctlMenu.AddSubItem("C", 2);
	m_ctlMenu.AddSubItem("D", 2);
	m_ctlMenu.AddSubItem("E", 2);
	m_ctlMenu.AddSubItem("F", 2);
	m_ctlMenu.AddSubItem("G", 2);
	m_ctlMenu.AddSubItem("H", 2);
	m_ctlMenu.AddSubItem("I", 2);
	m_ctlMenu.AddSubItem("J", 2);
	m_ctlMenu.AddSubItem("K", 2);
	m_ctlMenu.AddSubItem("L", 2);
	m_ctlMenu.AddSubItem("M", 2);
	m_ctlMenu.AddSubItem("N", 2);
	m_ctlMenu.AddSubItem("\\__--[FIN]--__/", 2);

	m_nState = 6;
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CICQClanDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CICQClanDlg::OnPaint() 
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
/*		CClientDC dc(this);
		CFont	font;
		CDC		dcmem,
				dcbmp;
		CBitmap	bmpmem,
				*pOldbmp,
				*pOldbmpmem;
		CString	str;
		CRect	rectWin;
		register int i;

		// DC mem
		GetWindowRect(&rectWin);
		dcmem.CreateCompatibleDC(&dc);
		bmpmem.CreateCompatibleBitmap(&dc, rectWin.Width(), rectWin.Height());
		pOldbmpmem = dcmem.SelectObject(&bmpmem);
		dcmem.FillSolidRect(0, 0, rectWin.Width(), rectWin.Height(), RGB(192,192,192));

		dcbmp.CreateCompatibleDC(&dc);

		dcmem.BitBlt(0, 0, rectWin.Width(), rectWin.Height(), &dc, 0, 0, SRCCOPY);

		// Applique l'image en tenant compte de la couche alpha
		if (pBmpTitle != NULL)
		{
			pOldbmp = dcbmp.SelectObject(pBmpTitle);
			for (i=0; i<rectWin.Width()-2; i++)
				dcmem.BitBlt(1+i, 1, rectWin.Width()-2, 15, &dcbmp, i*400/(rectWin.Width()-2), 0, SRCCOPY);
			GetDlgItem(IDC_CLOSE_BUTTON)->Invalidate(FALSE);
			dcbmp.SelectObject(pOldbmp);
		}

		// Affiche le titre (texte)
		font.CreateFont(-8, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
						ANSI_CHARSET, OUT_DEVICE_PRECIS, CLIP_CHARACTER_PRECIS,
						DEFAULT_QUALITY, FF_SWISS, "MS Sans Serif");
		dcmem.SelectObject(&font);
		dcmem.SetBkMode(TRANSPARENT);
		dcmem.SetTextColor( RGB(255,255,255) );
		str.ReleaseBuffer( GetWindowText(str.GetBuffer(20), 20) );
		dcmem.TextOut(5,2, str);

		// Affiche
		dc.BitBlt(0, 0, rectWin.Width(), rectWin.Height(), &dcmem, 0, 0, SRCCOPY);

		// Clear mem
		dcmem.SelectObject(pOldbmpmem);
		dcmem.DeleteDC();
		dcbmp.DeleteDC();
*/
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CICQClanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CICQClanDlg::OnReceive()
{
	static CString	strOverflowData = "";
	CString		str[10],
				strData,
				strDataLine;
	int			i, j, t,
				nBufferLen,
				nReturnPos = -1;

	// Connecté
	m_bConnected = TRUE;

	// Reçoit les données
	nBufferLen = m_socket->Receive(strData.GetBuffer(1024), 1024, NULL);
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
		// Traite les données
		while (TRUE)
		{
			// Donne ligne par ligne strData
			strData = strData.Mid(nReturnPos+1);
			nReturnPos = strData.Find("\n", 0);
			if (nReturnPos == -1)
				break;
			strDataLine = strData.Left(nReturnPos);

			// Donne les paramètres de la ligne
			for (i=0, t=0; (j=strDataLine.Find('\4', i)) != -1 && t<10; t++, i=j+1)
				str[t] = strDataLine.Mid(i, j-i);
			str[t] = strDataLine.Mid(i);

			// Test timeout
			if (str[0] == "PING?")
				m_socket->Send("PONG!");
			// System Message :
			//  1) Message
			else if (str[0] == "SM" && str[1] != "")
			{
				m_strSM.InsertAfter( m_strSM.FindIndex(m_strSM.GetCount()-1), str[1]);
				GetDlgItem(IDC_SYS_BUTTON)->EnableWindow(TRUE);
			}
			// (system) Message ID:
			//  1) ID du message
			//  2) Param 1
			//  3) Param 2
			//  4) ...
			//  7) Param 6
			//  Puis utilisation des str :
			//  8) String correspondant au ID
			//  9) Message complet fini.
			else if (str[0] == "MID")
			{
				try
				{
					// Opération spéciale selon le message
					switch (atoi(str[1]))
					{
					case 1006:	// Wrong Password
						m_strPwd = "";
						break;
					}

					// Affiche le message
					str[8].LoadString( atoi(str[1]) );
					str[9].Format( str[8], str[1], str[2], str[3], str[4], str[5], str[6], str[7]);
					m_strSM.InsertAfter( m_strSM.FindIndex(m_strSM.GetCount()-1), str[9]);
					GetDlgItem(IDC_SYS_BUTTON)->EnableWindow(TRUE);
				}
				catch (CMemoryException)
				{}
			}
			// Message :
			//  1) Msg origin UIN
			//  2) Message
			else if (str[0] == "m" && str[1] != "" && str[2] != "")
			{
				// Cherche si l'UIN est ds la liste ou pas
				// ...
			}
			// Changement d'état confirmé
			//  1) Nouvel état
			else if (str[0] == "cs" && str[1] != "")
			{
				// Affiche l'état
				UpdateData( TRUE );
				m_nState = atoi( str[1] );
				UpdateData( FALSE );

				// Si on doit sauvegarder le pwd: le fait
				if (AfxGetApp()->GetProfileString("USER1", "Pwd") != "")
				{
					CWBC_Crypte wbc;
					AfxGetApp()->WriteProfileString("USER1", "Pwd", wbc.Crypter(m_strPwd, atoi(m_strUIN)));
				}
			}
			/* A FINIR **************\
			| Clan Infos             |
			| ci(ID, Name)           |
			| User Infos             |
			| ui(Clan ID, UIN, Name) |
			| User state             |
			| us(Clan ID, UIN, State)|
			\************************/
		}
	}		
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CenterWindow();
	
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

	// Animation WBC
	m_ctlAni.Open(IDR_AVI_WBC);

	AfxBeginThread(Thread, this);
	
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

// Envoi au serveur le nouvel état
void CICQClanDlg::OnSelchangeStatusCombo() 
{
//	AfxBeginThread(SetState, this);
	SetState();
}

void CICQClanDlg::SetState()
{
	static int	nLastState = 6;
	CString strServer,
			strState,
			str;

	// Connecté à internet ?
/*	if (::InetIsOffline(0))
	{
		MessageBox("You must be connected to internet.", "Connection to the server", MB_ICONEXCLAMATION);
		return;
	}*/

	UpdateData(TRUE);
	strServer .LoadString(IDS_DEFAULT_SERVEUR);
	strServer = AfxGetApp()->GetProfileString("Options", "Serveur", strServer);
	strState.Format("%d", 7 - m_nState);

	// Si pas encore connecté
	if (nLastState == 6)
	{
		// Connecte
		if (!m_bConnected)
		{
			if (!m_socket->Connect(strServer, AfxGetApp()->GetProfileInt("Options", "ServeurPort", ID_SRVPORT)))
			{
				MessageBox("Error while trying to connect to the server.", "ICQ Clan");
				m_nState = 6;
				UpdateData(FALSE);
				return;
			}
			m_bConnected = TRUE;
		}
		// Demande pwd s'il le faut
		if (m_strPwd == "")
		{
			CInputDlg dlgPwd(NULL, "Enter Password", "Password :", "", "OK", FALSE, '#');
			if (dlgPwd.DoModal() != IDOK)
				return;
			else
				m_strPwd = dlgPwd.m_strInput;
		}
		// Donne les infos de connexion
		str =	"OU\4" +
				m_strUIN + "\4" +
				m_strPwd + "\4" +
				strState;
	}
	// Sinon: Change l'état
	else if (m_nState == 6)
	{
		m_socket->Send("Disconnect");
		m_socket->Close();
		m_socket->Create();
		m_bConnected = FALSE;
	}
	else
		str = "CS\4" + strState;

	// Envoi infos
	m_socket->Send(str);
	nLastState = m_nState;
}

// Add a clan
void CICQClanDlg::OnAddButton()
{
	// Doit-être connecté
	if (m_nState == 6)
	{
		MessageBox("You must be connected.", "Add a clan", MB_ICONWARNING);
		return;
	}

	// OK
	CAddClanDlg dlg;
	if (dlg.DoModal() == IDOK)
		m_socket->Send("AC\4" + dlg.m_strClan + "\4" + dlg.m_strID);
}

void CICQClanDlg::OnOK()
{
}

void CICQClanDlg::OnCancel()
{
	this->ShowWindow(SW_HIDE);
}

void CICQClanDlg::OnDestroy() 
{
/*	// Postion
	CRect rect;
	GetWindowRect(&rect);
	AfxGetApp()->WriteProfileInt("USER1", "Pos_x", rect.left),
	AfxGetApp()->WriteProfileInt("USER1", "Pos_y", rect.top),
	AfxGetApp()->WriteProfileInt("USER1", "Pos_nx", rect.Width()),
	AfxGetApp()->WriteProfileInt("USER1", "Pos_ny", rect.Height()),
*/
	CResizingDialog::OnOK();

	delete m_socket;

	CDialog::OnDestroy();
}

void CICQClanDlg::OnMainButton() 
{
	CString strPath,
			str;
	CRect	rect;
	HBITMAP	hBitmap;
	
	// Répertoire du skin
	strPath = AfxGetApp()->GetProfileString("Options", "Skin", "");

	// Charge l'image de bordure
	str.ReleaseBuffer( ::GetPrivateProfileString("Other", "ICQClanMainPopupMenuImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	hBitmap = NULL;
	if (str != "")
		hBitmap = (HBITMAP)LoadImage(NULL, strPath + str, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
	// Charge le bmp par défaut si y'en a pas
	if (!hBitmap)
		hBitmap = LoadBitmap(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDB_MAINMENU));

	UpdateData();

	CBmpMenu oMenu(22, FALSE, hBitmap, FALSE);

	oMenu.LoadMenu(IDR_MAIN_MENU);

	CBitmap bmp0;
	bmp0.LoadBitmap(IDB_MAINMENU_CREATECLAN);
	CBitmap bmp1;
	bmp1.LoadBitmap(IDB_MAINMENU_LEADER);
	CBitmap bmp10;
	bmp10.LoadBitmap(IDB_MAINMENU_CLANDETAILS);
	CBitmap bmp11;
	bmp11.LoadBitmap(IDB_MAINMENU_DELUSER);
	CBitmap bmp12;
	bmp12.LoadBitmap(IDB_MAINMENU_DELCLAN);
	CBitmap bmp3;
	bmp3.LoadBitmap(IDB_MAINMENU_USER);
	CBitmap bmp4;
	bmp4.LoadBitmap(IDB_MAINMENU_OPTIONS);
	CBitmap bmp6;
	bmp6.LoadBitmap(IDB_MAINMENU_HELP);
	CBitmap bmp61;
	bmp61.LoadBitmap(IDB_MAINMENU_ABOUT);
	CBitmap bmp7;
	bmp7.LoadBitmap(IDB_MAINMENU_TRAY);

	oMenu.SetMenuItemBitmaps(0, MF_BYPOSITION, &bmp0, &bmp0);
	oMenu.SetMenuItemBitmaps(1, MF_BYPOSITION, &bmp1, &bmp1);
	oMenu.GetSubMenu(1)->SetMenuItemBitmaps(0, MF_BYPOSITION, &bmp10, &bmp10);
	oMenu.GetSubMenu(1)->SetMenuItemBitmaps(1, MF_BYPOSITION, &bmp11, &bmp11);
	oMenu.GetSubMenu(1)->SetMenuItemBitmaps(2, MF_BYPOSITION, &bmp12, &bmp12);
	oMenu.SetMenuItemBitmaps(3, MF_BYPOSITION, &bmp3, &bmp3);
	oMenu.SetMenuItemBitmaps(4, MF_BYPOSITION, &bmp4, &bmp4);
	oMenu.SetMenuItemBitmaps(6, MF_BYPOSITION, &bmp6, &bmp6);
	oMenu.GetSubMenu(6)->SetMenuItemBitmaps(0, MF_BYPOSITION, &bmp61, &bmp61);
	oMenu.SetMenuItemBitmaps(7, MF_BYPOSITION, &bmp7, &bmp7);

	// Donne la pos
	GetDlgItem(IDC_MAIN_BUTTON)->GetWindowRect(&rect);

	// Affiche
	oMenu.TrackPopupMenu(0, rect.left-6, rect.top-109, this);
}

void CICQClanDlg::OnMainmenuShutdown() 
{
	OnCancel();
}

void CICQClanDlg::OnSysButton() 
{
	POSITION pos;

	// Affiche le msg
	if (!dlgReceive)
		dlgReceive.Create(IDD_RECEIVE_DIALOG, this);
	pos = m_strSM.FindIndex(0);
	dlgReceive.m_nUIN = 0;
	if (pos)
	{
		dlgReceive.m_strTxt = m_strSM.GetAt(pos);
		m_strSM.RemoveAt(pos);
	}
	GetDlgItem(IDC_SYS_BUTTON)->EnableWindow( !m_strSM.IsEmpty() );
	dlgReceive.ShowWindow(SW_SHOW);
}

// Menu / Options
void CICQClanDlg::OnMainmenuOptions() 
{
/*	// Si le user est connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	// Si le pwd n'est pas sauvegardé
	if (AfxGetApp()->GetProfileString("USER1", "Pwd") == "")
	{
		// Demande le pwd
		CEnterPwdDlg dlgPwd;
OptionRequestPwd:
		if (dlgPwd.DoModal() != IDOK)
			return;
		// L'user est connecté -> m_strPwd est bon -> vérifit le pwd donné
		if (dlgPwd.m_strPwd != m_strPwd)
		{
			MessageBox("Wrong password.", "Options", MB_ICONINFORMATION);
			goto OptionRequestPwd;
		}
	}*/
	// Affiche les options
	psOptions.DoModal();
}

// Menu / Help / About
void CICQClanDlg::OnMainmenuHelpAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CICQClanDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// Déplace
//	if (point.y <= 16)
//		PostMessage( WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM( point.x, point.y));
	
	CDialog::OnLButtonDown(nFlags, point);
}

UINT CAboutDlg::Thread(void *pParam)
{
	CAboutDlg	*pdlg = (CAboutDlg*) pParam;
	CClientDC	dc(pdlg);
	CDC			dcMem,
				dcScr;
	CBitmap		bmpMem,
				bmpScr,
				*pOldbmpMem,
				*pOldbmpScr;
	CRect		rect,
				rectCtl[5],
				rectTmp;
	int			i,
				j,
				k;

	pdlg->GetWindowRect(&rect);

	// Créé DC mem
	dcMem.CreateCompatibleDC(&dc);
	bmpMem.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	pOldbmpMem = dcMem.SelectObject(&bmpMem);

	// Créé DC mem avec la copie de l'écran
	dcScr.CreateCompatibleDC(&dc);
	bmpScr.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	pOldbmpScr = dcScr.SelectObject(&bmpScr);
	::Sleep(10);
	dcScr.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);

	// Cache
	dc.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(192,192,192));
	dcMem.FillSolidRect(0, 0, rect.Width(), rect.Height(), RGB(192,192,192));

	::Sleep(1500);

	// Affiche l'animation
	for (i=0; i<=rect.Width()+60; i+=10)
	{
		// Place le img des controles
		dcMem.BitBlt(0, 0, i, rect.Height(), &dcScr, 0, 0, SRCCOPY);

		// Fait la transition
		for (j=0; j<60; j++)
			for (k=0; k<j*rect.Height()/30; k++)
				dcMem.SetPixel(i-60+j, rand() * rect.Height() / RAND_MAX, RGB(192,192,192));

		// Affiche à l'écran
		dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);

		// Attend
		::Sleep(30);
	}

	// Affiche à l'écran
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcScr, 0, 0, SRCCOPY);

	// Clear la mem
	dcScr.SelectObject(pOldbmpMem);
	dcMem.DeleteDC();
	dcScr.SelectObject(pOldbmpScr);
	dcScr.DeleteDC();

	// Lance la video
	pdlg->m_ctlAni.Play(0, -1, -1);
	pdlg->m_ctlAni2.Open(IDR_AVI_ICQ);
	pdlg->m_ctlAni2.Play(0, -1, 1);

	return 0;
}

void CICQClanDlg::OnMainmenuUserinfos() 
{
	// Si pas connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	// Affiche
	CMydetailsDlg dlg;
	dlg.m_nUIN = AfxGetApp()->GetProfileInt("USER1", "UIN", -1);
	dlg.m_strNick = AfxGetApp()->GetProfileString("USER1", "Nick", "");
	dlg.m_strName = AfxGetApp()->GetProfileString("USER1", "Name", "");
	dlg.m_strFirstname = AfxGetApp()->GetProfileString("USER1", "Firstname", "");
	dlg.DoModal();
}

void CICQClanDlg::OnMainmenuCeateaclan() 
{
	// Si pas connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	CInputDlg dlg(NULL, "Create a Clan", "Clan Name :", "", "Create");
	if (dlg.DoModal() == IDOK)
	{
		/* ENVOYER ICI LES INFOS */
	}
}

void CICQClanDlg::OnMainmenuClanleaderoptionsClandetails() 
{
	// Si pas connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	// Clan ID
	CInputDlg dlg(NULL, "Clan options", "Clan ID :", "", "OK", TRUE);
	if (dlg.DoModal() != IDOK)
		return;

	// Change options
	CInputDlg dlg2(NULL, "Clan options", "Leader UIN :", "", "Save", TRUE);
	if (dlg2.DoModal() != IDOK)
		return;

	// Confirme
	if (AfxMessageBox("Be sur of the NEW LEADER UIN.\nIf you change it, you will not be able to come back.\nOnly the NEW leader will be able to do that.", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
	{
		/* ENVOYER ICI LES INFOS */
	}
}

void CICQClanDlg::OnMainmenuClanleaderoptionsDeletetheclan() 
{
	// Si pas connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	// Clan ID
	CInputDlg dlg(NULL, "Delete the clan", "Clan ID :", "", "OK", TRUE);
	if (dlg.DoModal() != IDOK)
		return;

	// Clan Name
	CInputDlg dlg2(NULL, "Delete the clan", "Clan Name :", "", "Delete");
	if (dlg2.DoModal() != IDOK)
		return;

	// Confirme
	if (AfxMessageBox("By doing this you will DELETE the CLAN and all the clan's members will be KICKED.", MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK)
	{
		/* ENVOYER ICI LES INFOS */
	}
}

void CICQClanDlg::OnMainmenuClanleaderoptionsKickclanuser() 
{
	// Si pas connecté
	if (!m_bConnected)
	{
		MessageBox("You must connected.", "Options", MB_ICONINFORMATION);
		return;
	}

	// Clan ID
	CInputDlg dlg(NULL, "Kick a member", "Clan ID :", "", "OK", TRUE);
	if (dlg.DoModal() != IDOK)
		return;

	// Member ID
	CInputDlg dlg2(NULL, "Kick a member", "Member UIN :", "", "Kick", TRUE);
	if (dlg2.DoModal() != IDOK)
		return;

	// Confirme
	if (AfxMessageBox("Are you sure you want to KICK this member from your clan ?", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		/* ENVOYER ICI LES INFOS */
	}
}
