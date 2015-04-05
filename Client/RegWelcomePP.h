#if !defined(AFX_REGWELCOMEPP_H__D60BB7AE_1F94_11D4_B5FF_AB8C4ADF3253__INCLUDED_)
#define AFX_REGWELCOMEPP_H__D60BB7AE_1F94_11D4_B5FF_AB8C4ADF3253__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegWelcomePP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegWelcomePP dialog

class CRegWelcomePP : public CPropertyPage
{
	DECLARE_DYNCREATE(CRegWelcomePP)

// Construction
public:
	CRegWelcomePP();
	~CRegWelcomePP();

// Dialog Data
	//{{AFX_DATA(CRegWelcomePP)
	enum { IDD = IDD_REG_WELCOME };
	int		m_nChoice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRegWelcomePP)
	public:
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRegWelcomePP)
	afx_msg void OnCheckRadio();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGWELCOMEPP_H__D60BB7AE_1F94_11D4_B5FF_AB8C4ADF3253__INCLUDED_)
