// UserClansDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Controleur.h"
#include "UserClansDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserClansDlg dialog


CUserClansDlg::CUserClansDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserClansDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserClansDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserClansDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserClansDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserClansDlg, CDialog)
	//{{AFX_MSG_MAP(CUserClansDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserClansDlg message handlers
