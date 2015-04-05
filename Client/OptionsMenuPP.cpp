// OptionsMenuPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "OptionsMenuPP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsMenuPP property page

IMPLEMENT_DYNCREATE(COptionsMenuPP, CPropertyPage)

COptionsMenuPP::COptionsMenuPP() : CPropertyPage(COptionsMenuPP::IDD)
{
	//{{AFX_DATA_INIT(COptionsMenuPP)
	m_bCloseonexit = FALSE;
	m_nRate = 0;
	m_nSpeed1 = 0;
	m_nSpeed2 = 0;
	//}}AFX_DATA_INIT
}

COptionsMenuPP::~COptionsMenuPP()
{
}

void COptionsMenuPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsMenuPP)
	DDX_Check(pDX, IDC_MENU_CLOSEONEXIT_CHECK, m_bCloseonexit);
	DDX_Text(pDX, IDC_MENU_RATE_EDIT, m_nRate);
	DDV_MinMaxUInt(pDX, m_nRate, 1, 1000);
	DDX_Text(pDX, IDC_MENU_SPEED1_EDIT, m_nSpeed1);
	DDV_MinMaxUInt(pDX, m_nSpeed1, 1, 100);
	DDX_Text(pDX, IDC_MENU_SPEED2_EDIT, m_nSpeed2);
	DDV_MinMaxUInt(pDX, m_nSpeed2, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsMenuPP, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsMenuPP)
	ON_EN_CHANGE(IDC_MENU_SPEED2_EDIT, OnChange)
	ON_EN_CHANGE(IDC_MENU_SPEED1_EDIT, OnChange)
	ON_EN_CHANGE(IDC_MENU_RATE_EDIT, OnChange)
	ON_BN_CLICKED(IDC_MENU_CLOSEONEXIT_CHECK, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsMenuPP message handlers

void COptionsMenuPP::OnOK() 
{
	// Enregistre ini
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileInt("Options", "Menu Speed1", m_nSpeed1);
	AfxGetApp()->WriteProfileInt("Options", "Menu Speed2", m_nSpeed2);
	AfxGetApp()->WriteProfileInt("Options", "Menu Rate", m_nRate);
	AfxGetApp()->WriteProfileInt("Options", "Menu CloseOnExit", m_bCloseonexit);

	CPropertyPage::OnOK();

	CancelToClose();
}

BOOL COptionsMenuPP::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// Charge ini
	m_nSpeed1 = AfxGetApp()->GetProfileInt("Options", "Menu Speed1", 3);
	m_nSpeed2 = AfxGetApp()->GetProfileInt("Options", "Menu Speed2", 7);
	m_nRate = AfxGetApp()->GetProfileInt("Options", "Menu Rate", 40);
	m_bCloseonexit = AfxGetApp()->GetProfileInt("Options", "Menu CloseOnExit", 0) != 0;
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsMenuPP::OnChange() 
{
	SetModified(TRUE);
}
