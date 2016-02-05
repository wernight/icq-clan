#if !defined(AFX_USERSCLANLISTDLG_H__9AD48B01_18FD_11D4_B5FF_9ED35C2A3953__INCLUDED_)
#define AFX_USERSCLANLISTDLG_H__9AD48B01_18FD_11D4_B5FF_9ED35C2A3953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UsersclanlistDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUsersclanlistDlg dialog

class CUsersclanlistDlg : public CDialog
{
// Construction
public:
	CUsersclanlistDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUsersclanlistDlg)
	enum { IDD = IDD_USERCLANS_DIALOG };
	CListBox	m_ctlList;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUsersclanlistDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUsersclanlistDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSCLANLISTDLG_H__9AD48B01_18FD_11D4_B5FF_9ED35C2A3953__INCLUDED_)
