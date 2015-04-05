// AddClanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "AddClanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddClanDlg dialog


CAddClanDlg::CAddClanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddClanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddClanDlg)
	m_strID = _T("");
	m_strClan = _T("");
	//}}AFX_DATA_INIT
}


void CAddClanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddClanDlg)
	DDX_Text(pDX, IDC_CIN_EDIT, m_strID);
	DDV_MaxChars(pDX, m_strID, 20);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strClan);
	DDV_MaxChars(pDX, m_strClan, 20);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddClanDlg, CDialog)
	//{{AFX_MSG_MAP(CAddClanDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddClanDlg message handlers

void CAddClanDlg::OnCancel() 
{
	CDialog::OnCancel();
}

void CAddClanDlg::OnOK() 
{
	// Check les infos
	UpdateData(TRUE);
	if (m_strClan == "" || m_strID == "")
	{
		MessageBox("Error: You must fill every area.", "Add a clan", MB_ICONWARNING);
		return;
	}
	
	CDialog::OnOK();
}
