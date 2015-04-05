// AddClanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Controleur.h"
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
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddClanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddClanDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddClanDlg, CDialog)
	//{{AFX_MSG_MAP(CAddClanDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddClanDlg message handlers
