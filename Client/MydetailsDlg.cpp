// MydetailsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "MydetailsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMydetailsDlg dialog


CMydetailsDlg::CMydetailsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMydetailsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMydetailsDlg)
	m_strFirstname = _T("");
	m_strName = _T("");
	m_strNick = _T("");
	m_nUIN = 0;
	//}}AFX_DATA_INIT
}


void CMydetailsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMydetailsDlg)
	DDX_Text(pDX, IDC_FIRSTNAME_EDIT, m_strFirstname);
	DDV_MaxChars(pDX, m_strFirstname, 20);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_NICK_EDIT, m_strNick);
	DDV_MaxChars(pDX, m_strNick, 20);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMydetailsDlg, CDialog)
	//{{AFX_MSG_MAP(CMydetailsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMydetailsDlg message handlers

void CMydetailsDlg::OnOK() 
{
	// Enregistre
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileString("USER1", "Nick", m_strNick);
	AfxGetApp()->WriteProfileString("USER1", "Name", m_strName);
	AfxGetApp()->WriteProfileString("USER1", "Firstname", m_strFirstname);
	
	CDialog::OnOK();
}
