#if !defined(AFX_OPTIONSSKINPP_H__D9388F72_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
#define AFX_OPTIONSSKINPP_H__D9388F72_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsSkinPP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsSkinPP dialog

class COptionsSkinPP : public CPropertyPage
{
	DECLARE_DYNCREATE(COptionsSkinPP)

// Construction
public:
	COptionsSkinPP();
	~COptionsSkinPP();

// Dialog Data
	//{{AFX_DATA(COptionsSkinPP)
	enum { IDD = IDD_OPTIONS_SKIN };
	CString	m_strAutor;
	CString	m_strName;
	CString	m_strNfo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(COptionsSkinPP)
	public:
	virtual void OnOK();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(COptionsSkinPP)
	virtual BOOL OnInitDialog();
	afx_msg void OnSkinButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void UpdateSkinInfo();
	CString strSkinFile;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSSKINPP_H__D9388F72_1F59_11D4_B5FF_90CD3D610D53__INCLUDED_)
