#if !defined(AFX_SKINBUTTON_H__CC1FF681_1A11_11D4_B5FF_AEA7FD80EC50__INCLUDED_)
#define AFX_SKINBUTTON_H__CC1FF681_1A11_11D4_B5FF_AEA7FD80EC50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkinButton window

class CSkinButton : public CButton
{
// Construction
public:
	CSkinButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSkinButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	bool bIni;
	CString m_strCaption;
	int nButtonWidth1;
	int nButtonWidth2;
	int nButtonWidth2Mode;
	int nButtonWidth3;
	int nButtonSpriteWidth;
	CBitmap *pBmpSkin;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINBUTTON_H__CC1FF681_1A11_11D4_B5FF_AEA7FD80EC50__INCLUDED_)
