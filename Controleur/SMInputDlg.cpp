// SMInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Controleur.h"
#include "SMInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSMInputDlg dialog


CSMInputDlg::CSMInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSMInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSMInputDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSMInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSMInputDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSMInputDlg, CDialog)
	//{{AFX_MSG_MAP(CSMInputDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSMInputDlg message handlers
