// SendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "SendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendDlg dialog


CSendDlg::CSendDlg(CWnd* pParent /*=NULL*/)
	: CResizingDialog(CSendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendDlg)
	m_strClan = _T("");
	m_strTxt = _T("");
	m_nUIN = 0;
	//}}AFX_DATA_INIT
	SetControlInfo(IDC_GRPBOX_STATIC,	RESIZE_HOR, 1.0, 1.0);
	SetControlInfo(IDC_UIN_EDIT,		RESIZE_HOR, 1.0/3.0, 1.0);
	SetControlInfo(IDC_CLAN_STATIC,		RESIZE_HOR | ANCHORE_RIGHT, 1.0/3.0, 1.0);
	SetControlInfo(IDC_CLAN_EDIT,		RESIZE_HOR | ANCHORE_RIGHT , 1.0/3.0, 1.0);
	SetControlInfo(IDC_TXT_EDIT,		RESIZE_BOTH, 1.0, 1.0);
	SetControlInfo(IDCANCEL,			ANCHORE_BOTTOM, 1.0, 1.0);
	SetControlInfo(IDOK,				ANCHORE_BOTTOM | ANCHORE_RIGHT, 1.0, 1.0);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MSG);
}


void CSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizingDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendDlg)
	DDX_Text(pDX, IDC_CLAN_EDIT, m_strClan);
	DDV_MaxChars(pDX, m_strClan, 20);
	DDX_Text(pDX, IDC_TXT_EDIT, m_strTxt);
	DDV_MaxChars(pDX, m_strTxt, 20);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendDlg, CResizingDialog)
	//{{AFX_MSG_MAP(CSendDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendDlg message handlers

BOOL CSendDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendDlg::OnOK() 
{
	CResizingDialog::OnOK();
}

void CSendDlg::OnCancel() 
{
	CResizingDialog::OnCancel();
}
