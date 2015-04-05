// UserInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "UserInfoDlg.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg dialog


CUserInfoDlg::CUserInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserInfoDlg)
	m_strFirstname = _T("");
	m_strIP = _T("");
	m_strLastonline = _T("");
	m_strName = _T("");
	m_strNick = _T("");
	m_strPwd = _T("");
	m_nUIN = 0;
	m_strState = _T("");
	m_strSocketid = _T("");
	//}}AFX_DATA_INIT
}


void CUserInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserInfoDlg)
	DDX_Text(pDX, IDC_FIRSTNAME_EDIT, m_strFirstname);
	DDX_Text(pDX, IDC_IP_EDIT, m_strIP);
	DDX_Text(pDX, IDC_LASTONLINE_EDIT, m_strLastonline);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_NICK_EDIT, m_strNick);
	DDX_Text(pDX, IDC_PWD_EDIT, m_strPwd);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	DDX_Text(pDX, IDC_STATE_EDIT, m_strState);
	DDX_Text(pDX, IDC_SOCKETID_EDIT, m_strSocketid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CUserInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg message handlers

BOOL CUserInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserInfoDlg::OnOK()
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Sauve les infos
	UpdateData(TRUE);
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->OnGetinfosSave();
}

void CUserInfoDlg::OnCancel()
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Vire celle la
	DestroyWindow();
}
