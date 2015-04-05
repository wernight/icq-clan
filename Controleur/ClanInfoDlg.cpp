// ClanInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Controleur.h"
#include "ClanInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClanInfoDlg dialog


CClanInfoDlg::CClanInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClanInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClanInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CClanInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClanInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClanInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CClanInfoDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClanInfoDlg message handlers
