// ReceiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "ReceiveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg dialog


CReceiveDlg::CReceiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReceiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReceiveDlg)
	m_strClan = _T("");
	m_strTxt = _T("");
	m_nUIN = 0;
	//}}AFX_DATA_INIT
}


void CReceiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReceiveDlg)
	DDX_Text(pDX, IDC_CLAN_EDIT, m_strClan);
	DDX_Text(pDX, IDC_TXT_EDIT, m_strTxt);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	//}}AFX_DATA_MAP
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MSG);
}


BEGIN_MESSAGE_MAP(CReceiveDlg, CDialog)
	//{{AFX_MSG_MAP(CReceiveDlg)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg message handlers

void CReceiveDlg::OnSize(UINT nType, int cx, int cy) 
{
	static bool	bFirst = TRUE;
	CRect		rect,
				rect2;

	CDialog::OnSize(nType, cx, cy);
	
	// Normal (pas Réduit, ni Agrandit)
	if ((nType & SIZE_RESTORED) == SIZE_RESTORED && !bFirst)
	{
		GetDlgItem(IDC_UIN_EDIT)->GetWindowRect(&rect);
		ScreenToClient(rect);
		GetDlgItem(IDC_UIN_EDIT)->MoveWindow(rect.left, rect.top, (cx-90)/2, rect.Height(), TRUE);
		
		GetDlgItem(IDC_UIN_EDIT)->GetWindowRect(&rect);
		GetDlgItem(IDC_CLAN_STATIC)->GetWindowRect(&rect2);
		ScreenToClient(rect);
		ScreenToClient(rect2);
		GetDlgItem(IDC_CLAN_STATIC)->MoveWindow(rect.right + 4, rect2.top, rect2.Width(), rect2.Height(), TRUE);

		GetDlgItem(IDC_CLAN_STATIC)->GetWindowRect(&rect);
		ScreenToClient(rect);
		GetDlgItem(IDC_CLAN_EDIT)->MoveWindow(rect.right + 2, rect2.top, (cx-90.0)/2.0+0.5, rect.Height(), TRUE);

		GetDlgItem(IDC_GRPBOX_STATIC)->GetWindowRect(&rect);
		ScreenToClient(rect);
		GetDlgItem(IDC_GRPBOX_STATIC)->MoveWindow(rect.left, rect.top, cx-6, rect.Height(), TRUE);
		
		GetDlgItem(IDC_TXT_EDIT)->GetWindowRect(&rect);
		ScreenToClient(rect);
		GetDlgItem(IDC_TXT_EDIT)->MoveWindow(rect.left, rect.top, cx-6, cy-85, TRUE);

		GetDlgItem(IDOK)->GetWindowRect(&rect);
		ScreenToClient(rect);
		GetDlgItem(IDCANCEL)->MoveWindow(3, cy-rect.Height()-3, rect.Width(), rect.Height(), TRUE);

		GetDlgItem(IDOK)->MoveWindow(cx-rect.Width()-3, cy-rect.Height()-3, rect.Width(), rect.Height(), TRUE);
	}
	bFirst = FALSE;
}

BOOL CReceiveDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReceiveDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CReceiveDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
