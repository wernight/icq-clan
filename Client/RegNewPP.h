#if !defined(AFX_REGNEWPP_H__D9388F7B_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
#define AFX_REGNEWPP_H__D9388F7B_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegNewPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegNewPP dialog

class CRegNewPP : public CPropertyPage
{
	DECLARE_DYNCREATE(CRegNewPP)

// Construction
public:
	CRegNewPP();
	~CRegNewPP();

// Dialog Data
	//{{AFX_DATA(CRegNewPP)
	enum { IDD = IDD_REG_NEW };
	CString	m_strName;
	CString	m_strNick;
	CString	m_strPwd;
	CString	m_strPwd2;
	CString	m_strFirstname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRegNewPP)
	public:
	virtual BOOL OnWizardFinish();
	virtual LRESULT OnWizardBack();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRegNewPP)
	afx_msg void OnChangeEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGNEWPP_H__D9388F7B_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
