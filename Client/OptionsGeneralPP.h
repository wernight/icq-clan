#if !defined(AFX_OPTIONSGENERALPP_H__D9388F70_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
#define AFX_OPTIONSGENERALPP_H__D9388F70_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsGeneralPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsGeneralPP dialog

class COptionsGeneralPP : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsGeneralPP)

// Construction
public:
	COptionsGeneralPP();
	~COptionsGeneralPP();

// Dialog Data
	//{{AFX_DATA(COptionsGeneralPP)
	enum { IDD = IDD_OPTIONS_GENERAL };
	BOOL	m_bAlwaystop;
	CString	m_strServeur;
	UINT	m_nPort;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsGeneralPP)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsGeneralPP)
	afx_msg void OnChange();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSGENERALPP_H__D9388F70_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
