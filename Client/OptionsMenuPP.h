#if !defined(AFX_OPTIONSMENUPP_H__D9388F71_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
#define AFX_OPTIONSMENUPP_H__D9388F71_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsMenuPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsMenuPP dialog

class COptionsMenuPP : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsMenuPP)

// Construction
public:
	COptionsMenuPP();
	~COptionsMenuPP();

// Dialog Data
	//{{AFX_DATA(COptionsMenuPP)
	enum { IDD = IDD_OPTIONS_MENU };
	BOOL	m_bCloseonexit;
	UINT	m_nRate;
	UINT	m_nSpeed1;
	UINT	m_nSpeed2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsMenuPP)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsMenuPP)
	virtual BOOL OnInitDialog();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSMENUPP_H__D9388F71_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
