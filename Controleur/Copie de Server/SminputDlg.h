#if !defined(AFX_SMINPUTDLG_H__DECF3AE1_192E_11D4_B5FF_9ED35C2A3953__INCLUDED_)
#define AFX_SMINPUTDLG_H__DECF3AE1_192E_11D4_B5FF_9ED35C2A3953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SminputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSminputDlg dialog

class CSminputDlg : public CDialog
{
// Construction
public:
	CSminputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSminputDlg)
	enum { IDD = IDD_SMINPUT_DIALOG };
	CString	m_strInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSminputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSminputDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMINPUTDLG_H__DECF3AE1_192E_11D4_B5FF_9ED35C2A3953__INCLUDED_)
