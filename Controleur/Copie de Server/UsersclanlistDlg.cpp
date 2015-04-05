// UsersclanlistDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "UsersclanlistDlg.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUsersclanlistDlg dialog


CUsersclanlistDlg::CUsersclanlistDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUsersclanlistDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUsersclanlistDlg)
	m_nUIN = 0;
	//}}AFX_DATA_INIT
}


void CUsersclanlistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUsersclanlistDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUsersclanlistDlg, CDialog)
	//{{AFX_MSG_MAP(CUsersclanlistDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsersclanlistDlg message handlers

void CUsersclanlistDlg::OnOK() 
{
	OnCancel();
}

void CUsersclanlistDlg::OnCancel() 
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Vire celle la
	DestroyWindow();
}
