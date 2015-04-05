#if !defined(AFX_MYDETAILSDLG_H__AECA7308_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
#define AFX_MYDETAILSDLG_H__AECA7308_335F_11D4_B5FF_F9ED453D3953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MydetailsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMydetailsDlg dialog

class CMydetailsDlg : public CDialog
{
// Construction
public:
	CMydetailsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMydetailsDlg)
	enum { IDD = IDD_MYDETAILS_DIALOG };
	CString	m_strFirstname;
	CString	m_strName;
	CString	m_strNick;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMydetailsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMydetailsDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDETAILSDLG_H__AECA7308_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
