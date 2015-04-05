// RegWelcomePP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "RegWelcomePP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegWelcomePP property page

IMPLEMENT_DYNCREATE(CRegWelcomePP, CPropertyPage)

CRegWelcomePP::CRegWelcomePP() : CPropertyPage(CRegWelcomePP::IDD)
{
	//{{AFX_DATA_INIT(CRegWelcomePP)
	m_nChoice = -1;
	//}}AFX_DATA_INIT
}

CRegWelcomePP::~CRegWelcomePP()
{
}

void CRegWelcomePP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegWelcomePP)
	DDX_Radio(pDX, IDC_NEW_RADIO, m_nChoice);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegWelcomePP, CPropertyPage)
	//{{AFX_MSG_MAP(CRegWelcomePP)
	ON_BN_CLICKED(IDC_NEW_RADIO, OnCheckRadio)
	ON_BN_CLICKED(IDC_OLD_RADIO, OnCheckRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegWelcomePP message handlers

LRESULT CRegWelcomePP::OnWizardNext() 
{
	UpdateData(TRUE);
	((CICQClanApp*) AfxGetApp())->pPSWizard->SetActivePage( m_nChoice );
	
	return CPropertyPage::OnWizardNext();
}

void CRegWelcomePP::OnCheckRadio() 
{
	UpdateData(TRUE);
	if (m_nChoice != -1)
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(PSWIZB_NEXT);
	else
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(0);
}

BOOL CRegWelcomePP::OnSetActive() 
{
	OnCheckRadio();
	
	return CPropertyPage::OnSetActive();
}
