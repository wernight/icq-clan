#if !defined(AFX_ADDCLANDLG_H__3CC1CDE1_3F98_11D4_B5FF_A53B8A602850__INCLUDED_)
#define AFX_ADDCLANDLG_H__3CC1CDE1_3F98_11D4_B5FF_A53B8A602850__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddClanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddClanDlg dialog

class CAddClanDlg : public CDialog
{
// Construction
public:
	CAddClanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddClanDlg)
	enum { IDD = IDD_ADDCLAN_DIALOG };
	CString	m_strID;
	CString	m_strClan;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddClanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddClanDlg)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCLANDLG_H__3CC1CDE1_3F98_11D4_B5FF_A53B8A602850__INCLUDED_)
