// RegNewPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "RegNewPP.h"
#include "WBC_Crypte.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegNewPP property page

IMPLEMENT_DYNCREATE(CRegNewPP, CPropertyPage)

CRegNewPP::CRegNewPP() : CPropertyPage(CRegNewPP::IDD)
{
	//{{AFX_DATA_INIT(CRegNewPP)
	m_strName = _T("");
	m_strNick = _T("");
	m_strPwd = _T("");
	m_strPwd2 = _T("");
	m_strFirstname = _T("");
	//}}AFX_DATA_INIT
}

CRegNewPP::~CRegNewPP()
{
}

void CRegNewPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegNewPP)
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_NICK_EDIT, m_strNick);
	DDV_MaxChars(pDX, m_strNick, 20);
	DDX_Text(pDX, IDC_PWD_EDIT, m_strPwd);
	DDV_MaxChars(pDX, m_strPwd, 20);
	DDX_Text(pDX, IDC_PWD2_EDIT, m_strPwd2);
	DDV_MaxChars(pDX, m_strPwd2, 20);
	DDX_Text(pDX, IDC_FIRSTNAME_EDIT, m_strFirstname);
	DDV_MaxChars(pDX, m_strFirstname, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegNewPP, CPropertyPage)
	//{{AFX_MSG_MAP(CRegNewPP)
	ON_EN_CHANGE(IDC_NAME_EDIT, OnChangeEdit)
	ON_EN_CHANGE(IDC_NICK_EDIT, OnChangeEdit)
	ON_EN_CHANGE(IDC_PWD_EDIT, OnChangeEdit)
	ON_EN_CHANGE(IDC_PWD2_EDIT, OnChangeEdit)
	ON_EN_CHANGE(IDC_FIRSTNAME_EDIT, OnChangeEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegNewPP message handlers

BOOL CRegNewPP::OnWizardFinish() 
{
	CString str;
	CSocket	socket;

	UpdateData(TRUE);

	// Connecte
	str.LoadString(IDS_DEFAULT_SERVEUR);
	if (!socket.Connect(AfxGetApp()->GetProfileString("Options", "Serveur", str), AfxGetApp()->GetProfileInt("Options", "ServeurPort", ID_SRVPORT)))
	{
		MessageBox("Error, unable to connect to ICQ Clan servers\nPlease try later or download the newest ICQ Clan");
		return FALSE;
	}

	// Envoi les infos
	str =	"NU\4" +
			m_strNick + "\4" +
			m_strName + "\4" +
			m_strFirstname + "\4" +
			m_strPwd;
	socket.Send(str, str.GetLength());

	// Attend la réponse
	for (int i=0; i<50; i++)
	{
		Sleep(200);
		str.ReleaseBuffer( socket.Receive(str.GetBuffer(20), 20, MSG_PEEK) );
		if (!str.IsEmpty())
		{
			// Attend un peu (on sais jamais)
			// reçoit l'UIN
			Sleep(200);
			str.ReleaseBuffer( socket.Receive(str.GetBuffer(20), 20, 0) );

			// C l'UIN ? Erreur ?
			if (str.Left(4) != "UIN\4")
			{
				MessageBox("Error, the informations returned are wrong.\nPlease try again.");
				return FALSE;
			}

			// Enregistre
			AfxGetApp()->WriteProfileString("USER1", "UIN", str.Mid(4));
			AfxGetApp()->WriteProfileString("USER1", "Nick", m_strNick);
			AfxGetApp()->WriteProfileString("USER1", "Name", m_strName);
			AfxGetApp()->WriteProfileString("USER1", "Firstname",m_strFirstname);
			CWBC_Crypte wbc;
			AfxGetApp()->WriteProfileString("USER1", "Pwd", wbc.Crypter(m_strPwd, atoi(str.Mid(4))));
			return CPropertyPage::OnWizardFinish();
		}
	}

	// Erreur: Timeout
	MessageBox("Error, the server didn't respond: Time-out.");
	return FALSE;
}

LRESULT CRegNewPP::OnWizardBack() 
{
	((CICQClanApp*) AfxGetApp())->pPSWizard->SetActivePage( 0 );
	
	return CPropertyPage::OnWizardBack();
}

void CRegNewPP::OnChangeEdit() 
{
	UpdateData(TRUE);
	if (m_strPwd != m_strPwd2 ||
		m_strNick == "" || m_strName == "" || m_strFirstname == "" || m_strPwd == "")
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(PSWIZB_BACK);
	else
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
}

BOOL CRegNewPP::OnSetActive() 
{
	OnChangeEdit();
	
	return CPropertyPage::OnSetActive();
}
