// ICQ Clan.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "MainFrame.h"
#include "WBC_Crypte.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICQClanApp

BEGIN_MESSAGE_MAP(CICQClanApp, CWinApp)
	//{{AFX_MSG_MAP(CICQClanApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CICQClanApp construction

CICQClanApp::CICQClanApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CICQClanApp object

CICQClanApp theApp;
CString m_strUIN;
CString m_strPwd;

/////////////////////////////////////////////////////////////////////////////
// CICQClanApp initialization

BOOL CICQClanApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Teste si c un nouvel utilisateur
	int	nReturn;
	if (AfxGetApp()->GetProfileString("USER1", "UIN") == "")
	{
		CRegWelcomePP ppRegWelcome;
		CRegNewPP	ppRegNew;
		CRegOldPP	ppRegOld;

		pPSWizard = new CPropertySheet;
		ppRegWelcome.m_psp.dwFlags -= PSP_HASHELP;
		ppRegNew.m_psp.dwFlags -= PSP_HASHELP;
		ppRegOld.m_psp.dwFlags -= PSP_HASHELP;
		pPSWizard->m_psh.dwFlags -= PSH_HASHELP;
		pPSWizard->AddPage( &ppRegWelcome );
		pPSWizard->AddPage( &ppRegNew );
		pPSWizard->AddPage( &ppRegOld );
		pPSWizard->SetWizardMode();
		nReturn = pPSWizard->DoModal();
		delete pPSWizard;
	}
	else
		nReturn = ID_WIZFINISH;

	if (nReturn == ID_WIZFINISH)
	{
		// Charge l'UIN et Pwd du user
		m_strUIN = AfxGetApp()->GetProfileString("USER1", "UIN");
		m_strPwd = AfxGetApp()->GetProfileString("USER1", "Pwd");
		// Si le pwd est sauvegardé
		if (m_strPwd != "")
		{
			// Décrypte
			CWBC_Crypte wbc;
			m_strPwd = wbc.Decrypter(m_strPwd, atoi(m_strUIN));
		}
		else
		{
			// Demande Pwd
			CInputDlg dlgPwd(NULL, "Enter Password", "Password :", "", "OK", FALSE, '#');
			if (dlgPwd.DoModal() != IDOK)
				return TRUE;
		}

		// Lance MainFrame
		CMainFrame* pMainFrame = new CMainFrame;
		if (!pMainFrame->LoadFrame(IDR_POPUP_MENU))
			return FALSE;
		m_pMainWnd = pMainFrame;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return TRUE;
}
