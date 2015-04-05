#if !defined(AFX_MAINFRAME_H__5F66EFC6_1832_11D4_B5FF_8CE770713053__INCLUDED_)
#define AFX_MAINFRAME_H__5F66EFC6_1832_11D4_B5FF_8CE770713053__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainFrame.h : header file
//
#include "SystemTray.h"	// Added by ClassView
#include "ICQ ClanDlg.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CMainFrame frame

class CMainFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CMainFrame)
protected:
	CSystemTray m_TrayIcon;

// Attributes
public:

// Operations
public:
	CMainFrame();           // protected constructor used by dynamic creation

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMainFrame();

	// Generated message map functions
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMinimizeicqclan();
	afx_msg void OnOpenicqclan();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CICQClanDlg dlg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRAME_H__5F66EFC6_1832_11D4_B5FF_8CE770713053__INCLUDED_)
