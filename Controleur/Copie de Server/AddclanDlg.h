#if !defined(AFX_ADDCLANDLG_H__1D191F49_08DC_11D4_B5FF_004095463EFD__INCLUDED_)
#define AFX_ADDCLANDLG_H__1D191F49_08DC_11D4_B5FF_004095463EFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddclanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddclanDlg dialog

class CAddclanDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	void OnOK();
	CAddclanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddclanDlg)
	enum { IDD = IDD_ADDCLAN_DIALOG };
	CString	m_strLeader;
	CString	m_strClanname;
	UINT	m_nID;
	CString	m_strPwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddclanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddclanDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCLANDLG_H__1D191F49_08DC_11D4_B5FF_004095463EFD__INCLUDED_)
