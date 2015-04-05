#if !defined(AFX_SENDDLG_H__A6573242_19BE_11D4_B5FF_9176326F1F53__INCLUDED_)
#define AFX_SENDDLG_H__A6573242_19BE_11D4_B5FF_9176326F1F53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendDlg.h : header file
//
#include "ResizingDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CSendDlg dialog

class CSendDlg : public CResizingDialog
{
// Construction
public:
	CSendDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSendDlg)
	enum { IDD = IDD_SEND_DIALOG };
	CString	m_strClan;
	CString	m_strTxt;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDDLG_H__A6573242_19BE_11D4_B5FF_9176326F1F53__INCLUDED_)
