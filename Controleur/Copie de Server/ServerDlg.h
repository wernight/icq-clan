// ServerDlg.h : header file
//

#if !defined(AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_)
#define AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_

#define SOCKET_MAX	500
#define PORTLOCAL	6002

#include "ICQClanSocket.h"	// Added by ClassView
#include "AddclanDlg.h"	// Added by ClassView
#include "UserInfoDlg.h"	// Added by ClassView
#include "ClaninfoDlg.h"	// Added by ClassView
#include "UsersclanlistDlg.h"	// Added by ClassView
#include "SminputDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

class CServerDlg : public CDialog
{
// Construction
public:
	void OnSendSM();
	void OnClaninfoSave();
	bool bCanshowdlg;
	void OnGetinfosSave();
	void OnAddclanSave();
	void OnReceive(DWORD dwSocketid);
	void OnAccept();
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CListBox	m_ctlClan;
	UINT	m_nSeluin;
	UINT	m_nOnline;
	UINT	m_nTotaluser;
	UINT	m_nTotalclan;
	UINT	m_nNextuin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeClanList();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnGetinfosButton();
	afx_msg void OnAddclanButton();
	afx_msg void OnSetnextuinButton();
	afx_msg void OnDelclanButton();
	afx_msg void OnClaninfosButton();
	afx_msg void OnChangeNextuinEdit();
	afx_msg void OnUsersclanlistButton();
	afx_msg void OnMsguserButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CString strSendSMTo;
	CSminputDlg dlgSminput;
	CUsersclanlistDlg dlgUsersclanlist;
	CClaninfoDlg dlgClaninfo;
	CUserInfoDlg dlgUserinfo;
	CAddclanDlg dlgAddclan;
	inline UINT GetSocketFromUIN(UINT nSearchUIN);
	void OnCancel();
	void OnOK();
	void Deconnecter(DWORD dwSocketid);
	char cState[SOCKET_MAX];
	unsigned int nUIN[SOCKET_MAX];
	CICQClanSocket *m_socket[SOCKET_MAX];
	CICQClanSocket *m_socketConn;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__8D55C93D_0355_11D4_A414_444553540000__INCLUDED_)
