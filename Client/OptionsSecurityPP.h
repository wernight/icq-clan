#if !defined(AFX_OPTIONSSECURITYPP_H__AECA7307_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
#define AFX_OPTIONSSECURITYPP_H__AECA7307_335F_11D4_B5FF_F9ED453D3953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsSecurityPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsSecurityPP dialog

class COptionsSecurityPP : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsSecurityPP)

// Construction
public:
	COptionsSecurityPP();
	~COptionsSecurityPP();

// Dialog Data
	//{{AFX_DATA(COptionsSecurityPP)
	enum { IDD = IDD_OPTIONS_SECURITY };
	CString	m_strPwd;
	CString	m_strPwd2;
	BOOL	m_bSavePwd;
	BOOL	m_bShowIP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsSecurityPP)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsSecurityPP)
	virtual BOOL OnInitDialog();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSSECURITYPP_H__AECA7307_335F_11D4_B5FF_F9ED453D3953__INCLUDED_)
