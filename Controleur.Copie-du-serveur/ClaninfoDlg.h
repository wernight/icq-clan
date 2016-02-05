#if !defined(AFX_CLANINFODLG_H__4C382B26_1865_11D4_B5FF_AECC2788EF50__INCLUDED_)
#define AFX_CLANINFODLG_H__4C382B26_1865_11D4_B5FF_AECC2788EF50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClaninfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClaninfoDlg dialog

class CClaninfoDlg : public CDialog
{
// Construction
public:
	CClaninfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClaninfoDlg)
	enum { IDD = IDD_CLANINFO_DIALOG };
	CListBox	m_ctlList;
	CString	m_strClanname;
	CString	m_strLeader;
	CString	m_strID;
	CString	m_strPwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClaninfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClaninfoDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLANINFODLG_H__4C382B26_1865_11D4_B5FF_AECC2788EF50__INCLUDED_)
