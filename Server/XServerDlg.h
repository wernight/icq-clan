// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_)
#define AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_

#define SOCKET_MAX	500
#define PORTLOCAL	6002

#include "ICQClanSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog used for App About

class CServerDlg : public CDialog
{
public:
	UINT nNextuin;
	UINT nTotaluser;
	CServerDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strEmail;
	CString	m_strICQ;
	CString	m_strWeb;
	CString	m_strRun;
	CString	m_strServer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual void OnCancel();
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	inline UINT GetSocketFromUIN(UINT nSearchUIN);
	void Deconnecter(DWORD dwSocketid);
	char cState[SOCKET_MAX];
	unsigned int nUIN[SOCKET_MAX];
	CICQClanSocket *m_socket[SOCKET_MAX];
	CICQClanSocket *m_socketConn;
	CFont Font;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_)
