// ClaninfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClaninfoDlg.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClaninfoDlg dialog


CClaninfoDlg::CClaninfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClaninfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClaninfoDlg)
	m_strClanname = _T("");
	m_strLeader = _T("");
	m_strID = _T("");
	m_strPwd = _T("");
	//}}AFX_DATA_INIT
}


void CClaninfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClaninfoDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_CLANNAME_EDIT, m_strClanname);
	DDX_Text(pDX, IDC_LEADER_EDIT, m_strLeader);
	DDX_Text(pDX, IDC_CLANID_EDIT, m_strID);
	DDX_Text(pDX, IDC_PWD_EDIT, m_strPwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClaninfoDlg, CDialog)
	//{{AFX_MSG_MAP(CClaninfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClaninfoDlg message handlers

void CClaninfoDlg::OnOK() 
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Sauve les infos
	UpdateData(TRUE);
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->OnClaninfoSave();
}

void CClaninfoDlg::OnCancel() 
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Vire celle la
	DestroyWindow();
}
