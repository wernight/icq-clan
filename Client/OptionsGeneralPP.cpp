// OptionsGeneralPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "OptionsGeneralPP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsGeneralPP property page

IMPLEMENT_DYNCREATE(COptionsGeneralPP, CPropertyPage)

COptionsGeneralPP::COptionsGeneralPP() : CPropertyPage(COptionsGeneralPP::IDD)
{
	//{{AFX_DATA_INIT(COptionsGeneralPP)
	m_bAlwaystop = FALSE;
	m_strServeur = _T("");
	m_nPort = 0;
	//}}AFX_DATA_INIT
}

COptionsGeneralPP::~COptionsGeneralPP()
{
}

void COptionsGeneralPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsGeneralPP)
	DDX_Check(pDX, IDC_ALWAYSTOP_CHECK, m_bAlwaystop);
	DDX_Text(pDX, IDC_SERVER_EDIT, m_strServeur);
	DDV_MaxChars(pDX, m_strServeur, 20);
	DDX_Text(pDX, IDC_PORT_EDIT, m_nPort);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsGeneralPP, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsGeneralPP)
	ON_BN_CLICKED(IDC_ALWAYSTOP_CHECK, OnChange)
	ON_EN_CHANGE(IDC_SERVER_EDIT, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsGeneralPP message handlers

void COptionsGeneralPP::OnOK() 
{
	// Enregistre ini
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileInt("Options", "AlwaysTop", m_bAlwaystop);
	AfxGetApp()->WriteProfileString("Options", "Serveur", m_strServeur);
	AfxGetApp()->WriteProfileInt("Options", "ServeurPort", m_nPort);
	CancelToClose();
	
	CPropertyPage::OnOK();
}

void COptionsGeneralPP::OnChange() 
{
	SetModified(TRUE);
}

BOOL COptionsGeneralPP::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// Charge ini
	CString str;
	str.LoadString(IDS_DEFAULT_SERVEUR);
	m_bAlwaystop = AfxGetApp()->GetProfileInt("Options", "AlwaysTop", FALSE);
	m_strServeur = AfxGetApp()->GetProfileString("Options", "Serveur", str);
	m_nPort = AfxGetApp()->GetProfileInt("Options", "ServeurPort", AfxGetApp()->GetProfileInt("Options", "ServeurPort", ID_SRVPORT));
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
