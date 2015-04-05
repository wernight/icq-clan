// SminputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "SminputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSminputDlg dialog


CSminputDlg::CSminputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSminputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSminputDlg)
	m_strInput = _T("");
	//}}AFX_DATA_INIT
}


void CSminputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSminputDlg)
	DDX_Text(pDX, IDC_INPUT_EDIT, m_strInput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSminputDlg, CDialog)
	//{{AFX_MSG_MAP(CSminputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSminputDlg message handlers

void CSminputDlg::OnOK() 
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Sauve les infos
	UpdateData(TRUE);
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->OnSendSM();
}

void CSminputDlg::OnCancel() 
{
	// Indique qu'un nouvelle fenêtre peut-être affichée
	((CServerDlg*) AfxGetApp()->m_pMainWnd)->bCanshowdlg = TRUE;

	// Vire celle la
	DestroyWindow();
}
