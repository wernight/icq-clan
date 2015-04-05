// UserdetailsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "UserdetailsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserdetailsDlg dialog


CUserdetailsDlg::CUserdetailsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserdetailsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserdetailsDlg)
	m_strFirstname = _T("");
	m_strName = _T("");
	m_strNick = _T("");
	m_nUIN = 0;
	//}}AFX_DATA_INIT
}


void CUserdetailsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserdetailsDlg)
	DDX_Text(pDX, IDC_FIRSTNAME_EDIT, m_strFirstname);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_NICK_EDIT, m_strNick);
	DDX_Text(pDX, IDC_UIN_EDIT, m_nUIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserdetailsDlg, CDialog)
	//{{AFX_MSG_MAP(CUserdetailsDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserdetailsDlg message handlers
