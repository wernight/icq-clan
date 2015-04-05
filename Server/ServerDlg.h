#if !defined(AFX_SERVERDLG_H__266946C1_2C26_11D4_B5FF_444553540000__INCLUDED_)
#define AFX_SERVERDLG_H__266946C1_2C26_11D4_B5FF_444553540000__INCLUDED_

#define SOCKET_MAX	500
#define PORTLOCAL	6002

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerDlg.h : header file
//
#include "ICQClanSocket.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	void OnReceive(CICQClanSocket *pSocket);
	void OnAccept();
	UINT nNextuin;
	CServerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strEmail;
	CString	m_strICQ;
	CString	m_strServer;
	CString	m_strWeb;
	UINT	m_nPort;
	UINT	m_nOnline;
	UINT	m_nTotaluser;
	CString	m_strSpeed;
	UINT	m_nTotalclan;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual void OnCancel();
	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	afx_msg void OnDestroy();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnHideButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString GetLocalHost();
	inline CICQClanSocket* GetSocketFromUIN(UINT nUIN);
	void Deconnecter(CICQClanSocket *pSocket);
	CICQClanSocket *pFirstSocket;	// Fisrt = Connexion waiting socket
	CICQClanSocket *pLastSocket;	// Last = Next socket for Accept
	CFont Font;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__266946C1_2C26_11D4_B5FF_444553540000__INCLUDED_)
