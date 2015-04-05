// ICQ ClanDlg.h : header file
//

#if !defined(AFX_ICQCLANDLG_H__8D55C927_0355_11D4_A414_444553540000__INCLUDED_)
#define AFX_ICQCLANDLG_H__8D55C927_0355_11D4_A414_444553540000__INCLUDED_

#include "ICQClanSocket.h"	// Added by ClassView
#include "SendDlg.h"	// Added by ClassView
#include "ReceiveDlg.h"	// Added by ClassView
#include "SkinButton.h"	// Added by ClassView
#include "MenuStatic.h"	// Added by ClassView
#include "OptionsGeneralPP.h"
#include "OptionsSecurityPP.h"
#include "OptionsMenuPP.h"
#include "OptionsGamePP.h"
#include "OptionsSkinPP.h"
#include "MyDetailsDlg.h"
#include "ResizingDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CICQClanDlg dialog

class CICQClanDlg : public CResizingDialog
{
// Construction
public:
	BOOL m_bConnected;
	CICQClanSocket *m_socket;
	void OnCancel();
	void OnOK();
	void OnReceive();
	CICQClanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CICQClanDlg)
	enum { IDD = IDD_ICQCLAN_DIALOG };
	CMenuStatic	m_ctlMenu;
	CSkinButton	m_ctlAdd;
	CSkinButton	m_ctlSys;
	CSkinButton	m_ctlMain;
	CComboBox	m_ctlState;
	int		m_nState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICQClanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CICQClanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeStatusCombo();
	afx_msg void OnAddButton();
	afx_msg void OnDestroy();
	afx_msg void OnMainButton();
	afx_msg void OnMainmenuShutdown();
	afx_msg void OnSysButton();
	afx_msg void OnMainmenuOptions();
	afx_msg void OnMainmenuHelpAbout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMainmenuUserinfos();
	afx_msg void OnMainmenuCeateaclan();
	afx_msg void OnMainmenuClanleaderoptionsClandetails();
	afx_msg void OnMainmenuClanleaderoptionsDeletetheclan();
	afx_msg void OnMainmenuClanleaderoptionsKickclanuser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBitmap* pBmpTitle;
	CPropertySheet psOptions; 
	COptionsGeneralPP ppOptionsGeneral;
	COptionsSecurityPP ppOptionsSecurity;
	COptionsMenuPP ppOptionsMenu;
	COptionsGamePP ppOptionsGame;
	COptionsSkinPP ppOptionsSkin;
	CStringList m_strSM;
	CReceiveDlg dlgReceive;
	CSendDlg dlgSend;
	void SetState();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICQCLANDLG_H__8D55C927_0355_11D4_A414_444553540000__INCLUDED_)
