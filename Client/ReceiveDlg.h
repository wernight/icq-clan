#if !defined(AFX_RECEIVEDLG_H__A6573241_19BE_11D4_B5FF_9176326F1F53__INCLUDED_)
#define AFX_RECEIVEDLG_H__A6573241_19BE_11D4_B5FF_9176326F1F53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReceiveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReceiveDlg dialog

class CReceiveDlg : public CDialog
{
// Construction
public:
	CReceiveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReceiveDlg)
	enum { IDD = IDD_RECEIVE_DIALOG };
	CString	m_strClan;
	CString	m_strTxt;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReceiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReceiveDlg)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECEIVEDLG_H__A6573241_19BE_11D4_B5FF_9176326F1F53__INCLUDED_)
