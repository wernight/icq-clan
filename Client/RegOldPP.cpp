// RegOldPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "RegOldPP.h"
#include "WBC_Crypte.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegOldPP property page

IMPLEMENT_DYNCREATE(CRegOldPP, CPropertyPage)

CRegOldPP::CRegOldPP() : CPropertyPage(CRegOldPP::IDD)
{
	//{{AFX_DATA_INIT(CRegOldPP)
	m_strPwd = _T("");
	m_nUIN = 0;
	//}}AFX_DATA_INIT
}

CRegOldPP::~CRegOldPP()
{
}

void CRegOldPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegOldPP)
	DDX_Text(pDX, IDC_OLDPWD_EDIT, m_strPwd);
	DDV_MaxChars(pDX, m_strPwd, 20);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	DDV_MinMaxUInt(pDX, m_nUIN, 0, 999999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegOldPP, CPropertyPage)
	//{{AFX_MSG_MAP(CRegOldPP)
	ON_EN_CHANGE(IDC_UIN_EDIT, OnChangeEdit)
	ON_EN_CHANGE(IDC_OLDPWD_EDIT, OnChangeEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegOldPP message handlers

BOOL CRegOldPP::OnWizardFinish() 
{
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileInt("USER1", "UIN", m_nUIN);
	CWBC_Crypte wbc;
	AfxGetApp()->WriteProfileString("USER1", "Pwd", wbc.Crypter(m_strPwd, m_nUIN));
	
	return CPropertyPage::OnWizardFinish();
}

LRESULT CRegOldPP::OnWizardBack() 
{
	((CICQClanApp*) AfxGetApp())->pPSWizard->SetActivePage( 0 );
	
	return CPropertyPage::OnWizardBack();
}

void CRegOldPP::OnChangeEdit() 
{
	UpdateData(TRUE);
	if (m_strPwd != "" && m_nUIN > 0 && m_nUIN < 999999)
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	else
		((CICQClanApp*) AfxGetApp())->pPSWizard->SetWizardButtons(PSWIZB_BACK);
}

BOOL CRegOldPP::OnSetActive() 
{
	OnChangeEdit();
	
	return CPropertyPage::OnSetActive();
}
