#if !defined(AFX_USERINFODLG_H__A8B67661_10A7_11D4_B5FF_004095463EFD__INCLUDED_)
#define AFX_USERINFODLG_H__A8B67661_10A7_11D4_B5FF_004095463EFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg dialog

class CUserInfoDlg : public CDialog
{
// Construction
public:
	CUserInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserInfoDlg)
	enum { IDD = IDD_USERINFO_DIALOG };
	CString	m_strFirstname;
	CString	m_strIP;
	CString	m_strLastonline;
	CString	m_strName;
	CString	m_strNick;
	CString	m_strPwd;
	UINT	m_nUIN;
	CString	m_strState;
	CString	m_strSocketid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserInfoDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void OnCancel();
	void OnOK();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERINFODLG_H__A8B67661_10A7_11D4_B5FF_004095463EFD__INCLUDED_)
