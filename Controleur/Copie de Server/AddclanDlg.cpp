// AddclanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "AddclanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddclanDlg dialog


CAddclanDlg::CAddclanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddclanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddclanDlg)
	m_strLeader = _T("");
	m_strClanname = _T("");
	m_nID = 0;
	m_strPwd = _T("");
	//}}AFX_DATA_INIT
}


void CAddclanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddclanDlg)
	DDX_Text(pDX, IDC_LEADERUIN_EDIT, m_strLeader);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strClanname);
	DDX_Text(pDX, IDC_CLANID_EDIT, m_nID);
	DDX_Text(pDX, IDC_PWD_EDIT, m_strPwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddclanDlg, CDialog)
	//{{AFX_MSG_MAP(CAddclanDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddclanDlg message handlers

void CAddclanDlg::OnOK()
{
	UpdateData(TRUE);

	// Check infos
	if (m_strClanname == "" || m_strLeader == "" || m_strPwd == "")
	{
		MessageBox("You must fill all the areas.", "Add a new clan", MB_ICONEXCLAMATION);
		return;
	}

	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Sauve les infos
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->OnAddclanSave();
}

void CAddclanDlg::OnCancel()
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Vire celle la
	DestroyWindow();
}

BOOL CAddclanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(TRUE);
	m_nID = ((CServerDlg*) AfxGetApp()->m_pMainWnd)->m_nTotalclan;	
	m_strClanname = _T("");
	m_strLeader = _T("");
	m_strPwd = _T("");
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
