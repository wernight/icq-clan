// Patcher.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Patcher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define HL	"hl-ori.exe"
#define Q3	"q3-ori.exe"

/////////////////////////////////////////////////////////////////////////////
// CPatcherApp

BEGIN_MESSAGE_MAP(CPatcherApp, CWinApp)
	//{{AFX_MSG_MAP(CPatcherApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPatcherApp construction

CPatcherApp::CPatcherApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPatcherApp object

CPatcherApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPatcherApp initialization

BOOL CPatcherApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CString str;
	CString strCmdLine = m_lpCmdLine;
	CString strWinDir;
	STARTUPINFO st;
	PROCESS_INFORMATION pi;

	// Donne le répertoire de Windows
	strWinDir.ReleaseBuffer( ::GetWindowsDirectory(strWinDir.GetBuffer(500), 500) );
	if (strWinDir.Right(1) != "\\")
		strWinDir += "\\";

	// Envoi les param à ICQ Clan
	WritePrivateProfileString("Running", "Half-Life", str, strWinDir + "ICQ Clan.ini");

	// Lance le jeux
	str = HL + strCmdLine;

	ZeroMemory(&st,sizeof(STARTUPINFO));
	st.cb = sizeof(STARTUPINFO);
	// ici on informe le système qu'on redirige la sortie
	st.dwFlags = STARTF_USESTDHANDLES ;
	// Quelques autre param.
	st.lpTitle = "NETSTAT";
	st.wShowWindow = SW_HIDE;
	// Lance l'app.
	CreateProcess(NULL,
				  (LPTSTR) (LPCTSTR) str,
				  NULL,
				  NULL,
				  true,
				  DETACHED_PROCESS,
				  NULL,
				  NULL,
				  &st,
				  &pi);

	// Attend qu'elle soit terminée
	WaitForSingleObject(pi.hProcess, INFINITE);

	// Envoi les param à ICQ Clan
	WritePrivateProfileString("Running", "Half-Life", "", strWinDir + "ICQ Clan.ini");

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
