#if !defined(AFX_REGOLDPP_H__D9388F7C_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
#define AFX_REGOLDPP_H__D9388F7C_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegOldPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegOldPP dialog

class CRegOldPP : public CPropertyPage
{
	DECLARE_DYNCREATE(CRegOldPP)

// Construction
public:
	CRegOldPP();
	~CRegOldPP();

// Dialog Data
	//{{AFX_DATA(CRegOldPP)
	enum { IDD = IDD_REG_OLD };
	CString	m_strPwd;
	UINT	m_nUIN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRegOldPP)
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
	//{{AFX_MSG(CRegOldPP)
	afx_msg void OnChangeEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGOLDPP_H__D9388F7C_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
