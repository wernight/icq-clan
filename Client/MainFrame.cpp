// MainFrame.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "MainFrame.h"

#define	WM_ICON_NOTIFY			WM_USER+10

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}


BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_MINIMIZEICQCLAN, OnMinimizeicqclan)
	ON_COMMAND(ID_OPENICQCLAN, OnOpenicqclan)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Create the tray icon
	if (!m_TrayIcon.Create(NULL,                            // Parent window
                           WM_ICON_NOTIFY,                  // Icon notify message to use
                           _T("ICQ Clan"),					// tooltip
                           AfxGetApp()->LoadIcon(IDR_MAINFRAME),  // Icon to use
                           IDR_POPUP_MENU))                 // ID of tray icon
		return -1;

	// Créé dlg ICQ Clan
	dlg.Create(IDD_ICQCLAN_DIALOG, this);
	dlg.ShowWindow(SW_SHOW);
	
	return 0;
}

void CMainFrame::OnMinimizeicqclan() 
{
	// Si dlg invisible
	if (dlg.IsWindowVisible())
		dlg.ShowWindow(SW_HIDE);
}

void CMainFrame::OnOpenicqclan() 
{
	// Si dlg Visible
	if (!dlg.IsWindowVisible())
		dlg.ShowWindow(SW_SHOW);
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
}
