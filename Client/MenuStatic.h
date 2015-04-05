#if !defined(AFX_MENUSTATIC_H__5074FA61_1AEA_11D4_B5FF_444553540000__INCLUDED_)
#define AFX_MENUSTATIC_H__5074FA61_1AEA_11D4_B5FF_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MenuStatic.h : header file
//
#include "MenuItem.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CMenuStatic window

class CMenuStatic : public CStatic
{
// Construction
public:
	CMenuStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetSubItem(int nIndex, int nSub);
	int GetSubItemCount(int nIndex);
	void RemoveSubAt(int nIndex, int nSub);
	void RemoveAllSub(int nIndex);
	void InsertSubAfter(CString str, int nIndex, int nSub);
	void AddSubItem(CString str, int nIndex);
	void RemoveAll();
	void RemoveItem(int nIndex);
	BOOL InsertAfter(CString str, int nIndex);
	BOOL AddItem(CString str);
	virtual ~CMenuStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMenuStatic)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	int nMenuHeight;
	CFont fontMenu;
	CFont fontSubMenu;
	COLORREF colorBkground;
	COLORREF colorMenuUnsel;
	COLORREF colorMenuSel;
	COLORREF colorMenuUnselShadow;
	COLORREF colorMenuSelShadow;
	COLORREF colorSubMenuUnsel;
	COLORREF colorSubMenuSel;
	COLORREF colorSubMenuUnselShadow;
	COLORREF colorSubMenuSelShadow;
	CBitmap* pBmpBkground;
	CBitmap* pBmpUnselMenu;
	CBitmap* pBmpSelMenu;
	CBitmap* pBmpSelSubMenu;
	CBitmap* pBmpUnselSubMenu;
	bool bCloseOnMenuExit;
	int nBkgroundMode;
	int nMenuUnselWidth1;
	int nMenuUnselWidth2;
	int nMenuUnselWidth2Mode;
	int nMenuUnselWidth3;
	int nMenuSelWidth1;
	int nMenuSelWidth2;
	int nMenuSelWidth2Mode;
	int nMenuSelWidth3;
	int nSubMenuUnselWidth1;
	int nSubMenuUnselWidth2;
	int nSubMenuUnselWidth2Mode;
	int nSubMenuUnselWidth3;
	int nSubMenuSelWidth1;
	int nSubMenuSelWidth2;
	int nSubMenuSelWidth2Mode;
	int nSubMenuSelWidth3;
	int nSubMenuHeight;
	int nAnimationRate;
	int nAnimationSpeedupChaseDivider;
	int nAnimationChaseDivider;
	BOOL LoadBitmap(CBitmap &bmp, LPCTSTR str);
	CMenuItem* FindIndex(int nIndex);
	int m_nSelSubMenu;
	CMenuItem *pFirstMI;
	int m_nSelMenu;
	int m_nMenuCount;
	bool ThreadCanRun;
	static UINT Thread(LPVOID pParam);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUSTATIC_H__5074FA61_1AEA_11D4_B5FF_444553540000__INCLUDED_)
