#if !defined(AFX_OPTIONSGAMEPP_H__F806C961_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_)
#define AFX_OPTIONSGAMEPP_H__F806C961_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsGamePP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsGamePP dialog

class COptionsGamePP : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsGamePP)

// Construction
public:
	COptionsGamePP();
	~COptionsGamePP();

// Dialog Data
	//{{AFX_DATA(COptionsGamePP)
	enum { IDD = IDD_OPTIONS_GAME };
	CString	m_strHL;
	CString	m_strQ3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsGamePP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsGamePP)
	afx_msg void OnQ3Button();
	afx_msg void OnHlButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSGAMEPP_H__F806C961_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_)
