#if !defined(AFX_USERCLANSDLG_H__E6019705_2B57_11D4_B5FF_F8DA4FF63753__INCLUDED_)
#define AFX_USERCLANSDLG_H__E6019705_2B57_11D4_B5FF_F8DA4FF63753__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserClansDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserClansDlg dialog

class CUserClansDlg : public CDialog
{
// Construction
public:
	CUserClansDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserClansDlg)
	enum { IDD = IDD_USERCLANS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserClansDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserClansDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERCLANSDLG_H__E6019705_2B57_11D4_B5FF_F8DA4FF63753__INCLUDED_)
