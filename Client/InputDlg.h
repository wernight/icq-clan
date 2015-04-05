#if !defined(AFX_INPUTDLG_H__F4261401_49ED_11D4_B5FF_9D22ADD52050__INCLUDED_)
#define AFX_INPUTDLG_H__F4261401_49ED_11D4_B5FF_9D22ADD52050__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog

class CInputDlg : public CDialog
{
// Construction
public:
	CString m_strInput;
	CInputDlg(CWnd* pParent = NULL, CString strTitre = "", CString strLabel = "", CString strDefault = "", CString strOK = "OK", BOOL bInputNumber = FALSE, char cPasswordChar = 0);

// Dialog Data
	//{{AFX_DATA(CInputDlg)
	enum { IDD = IDD_ENTERPWD_DIALOG };
	CEdit	m_ctlInputStr;
	CEdit	m_ctlInputNum;
	CString	m_strLabel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_strTitre;
	CString m_strOK;
	char	m_cPasswordChar;
	BOOL	m_bInputNumber;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__F4261401_49ED_11D4_B5FF_9D22ADD52050__INCLUDED_)
