// ControleurDlg.h : header file
//

#if !defined(AFX_CONTROLEURDLG_H__4B739575_2839_11D4_B5FF_B69A92510653__INCLUDED_)
#define AFX_CONTROLEURDLG_H__4B739575_2839_11D4_B5FF_B69A92510653__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CControleurDlg dialog

class CControleurDlg : public CDialog
{
// Construction
public:
	CControleurDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControleurDlg)
	enum { IDD = IDD_CONTROLEUR_DIALOG };
	CString	m_strIP;
	CString	m_strPwd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControleurDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CControleurDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLEURDLG_H__4B739575_2839_11D4_B5FF_B69A92510653__INCLUDED_)
