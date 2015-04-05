// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog


CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/, CString strTitre /*=""*/, CString strLabel /*=""*/, CString strDefault /*=""*/, CString strOK /*="OK"*/, BOOL bInputNumber /*=FALSE*/, char cPasswordChar /*=0*/) 
: CDialog(CInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputDlg)
	m_strLabel = strLabel;
	//}}AFX_DATA_INIT
	m_strTitre = strTitre;
	m_strOK = strOK;
	m_cPasswordChar = cPasswordChar;
	m_bInputNumber = bInputNumber;
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_Control(pDX, IDC_INPUTSTR_EDIT, m_ctlInputStr);
	DDX_Control(pDX, IDC_INPUTNUM_EDIT, m_ctlInputNum);
	DDX_Text(pDX, IDC_LBL, m_strLabel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
	ON_EN_CHANGE(IDC_INPUTNUM_EDIT, OnChange)
	ON_EN_CHANGE(IDC_INPUTSTR_EDIT, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers

void CInputDlg::OnOK() 
{
	UpdateData(TRUE);

	// Donne le input
	if (m_bInputNumber)
		m_ctlInputNum.GetWindowText( m_strInput );
	else
		m_ctlInputStr.GetWindowText( m_strInput );

	// Check
	if (m_strInput != "")
		CDialog::OnOK();
}

BOOL CInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Change des options
	SetWindowText( m_strTitre );
	GetDlgItem(IDOK)->SetWindowText( m_strOK );
	if (m_bInputNumber)
	{
		m_ctlInputNum.SetPasswordChar( m_cPasswordChar );
		m_ctlInputNum.ShowWindow( SW_SHOW );
	}
	else
	{
		m_ctlInputStr.SetPasswordChar( m_cPasswordChar );
		m_ctlInputStr.ShowWindow( SW_SHOW );
	}
	UpdateData( FALSE );

	OnChange();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInputDlg::OnChange() 
{
	// Donne le input
	if (m_bInputNumber)
		m_ctlInputNum.GetWindowText( m_strInput );
	else
		m_ctlInputStr.GetWindowText( m_strInput );

	// Check
	GetDlgItem(IDOK)->EnableWindow( !m_strInput.IsEmpty() );
}
