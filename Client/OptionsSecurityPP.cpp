// OptionsSecurityPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "OptionsSecurityPP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsSecurityPP property page

IMPLEMENT_DYNCREATE(COptionsSecurityPP, CPropertyPage)

COptionsSecurityPP::COptionsSecurityPP() : CPropertyPage(COptionsSecurityPP::IDD)
{
	//{{AFX_DATA_INIT(COptionsSecurityPP)
	m_strPwd = _T("");
	m_strPwd2 = _T("");
	m_bSavePwd = FALSE;
	m_bShowIP = FALSE;
	//}}AFX_DATA_INIT
}

COptionsSecurityPP::~COptionsSecurityPP()
{
}

void COptionsSecurityPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsSecurityPP)
	DDX_Text(pDX, IDC_PWD_EDIT, m_strPwd);
	DDV_MaxChars(pDX, m_strPwd, 20);
	DDX_Text(pDX, IDC_PWD2_EDIT, m_strPwd2);
	DDV_MaxChars(pDX, m_strPwd2, 20);
	DDX_Check(pDX, IDC_SAVEPWD_CHECK, m_bSavePwd);
	DDX_Check(pDX, IDC_IP_CHECK, m_bShowIP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsSecurityPP, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsSecurityPP)
	ON_BN_CLICKED(IDC_IP_CHECK, OnChange)
	ON_EN_CHANGE(IDC_PWD_EDIT, OnChange)
	ON_EN_CHANGE(IDC_PWD2_EDIT, OnChange)
	ON_BN_CLICKED(IDC_SAVEPWD_CHECK, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsSecurityPP message handlers

BOOL COptionsSecurityPP::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// Charge ini
	UpdateData(FALSE);

	OnChange();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsSecurityPP::OnOK() 
{
	// Enregistre ini
	UpdateData(TRUE);
	
	CPropertyPage::OnOK();

	CancelToClose();
}

void COptionsSecurityPP::OnChange() 
{
	SetModified(TRUE);

	// Si "Save pwd" -> Enable to modif pwd
	UpdateData( TRUE );
	GetDlgItem(IDC_PWD_EDIT)->EnableWindow( m_bSavePwd );
	GetDlgItem(IDC_PWD2_EDIT)->EnableWindow( m_bSavePwd );
}
