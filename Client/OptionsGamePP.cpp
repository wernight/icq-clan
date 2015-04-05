// OptionsGamePP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "OptionsGamePP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsGamePP property page

IMPLEMENT_DYNCREATE(COptionsGamePP, CPropertyPage)

COptionsGamePP::COptionsGamePP() : CPropertyPage(COptionsGamePP::IDD)
{
	//{{AFX_DATA_INIT(COptionsGamePP)
	m_strHL = _T("");
	m_strQ3 = _T("");
	//}}AFX_DATA_INIT
}

COptionsGamePP::~COptionsGamePP()
{
}

void COptionsGamePP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsGamePP)
	DDX_Text(pDX, IDC_HL_EDIT, m_strHL);
	DDX_Text(pDX, IDC_Q3_EDIT, m_strQ3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsGamePP, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsGamePP)
	ON_BN_CLICKED(IDC_Q3_BUTTON, OnQ3Button)
	ON_BN_CLICKED(IDC_HL_BUTTON, OnHlButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsGamePP message handlers

void COptionsGamePP::OnQ3Button() 
{
	// TODO: Add your control notification handler code here
	
}

void COptionsGamePP::OnHlButton() 
{
	// TODO: Add your control notification handler code here
	
}
