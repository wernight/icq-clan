#if !defined(AFX_USERDETAILSDLG_H__AECA7309_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
#define AFX_USERDETAILSDLG_H__AECA7309_335F_11D4_B5FF_F9ED453D3953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserdetailsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserdetailsDlg dialog

class CUserdetailsDlg : public CDialog
{
// Construction
public:
	CUserdetailsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserdetailsDlg)
	enum { IDD = IDD_USERDETAILS_DIALOG };
	CString	m_strFirstname;
	CString	m_strName;
	CString	m_strNick;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserdetailsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserdetailsDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDETAILSDLG_H__AECA7309_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
