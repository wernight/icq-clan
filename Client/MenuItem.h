// MenuItem.h: interface for the CMenuItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUITEM_H__9F984841_1BA8_11D4_B5FF_947E0C440953__INCLUDED_)
#define AFX_MENUITEM_H__9F984841_1BA8_11D4_B5FF_947E0C440953__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMenuItem  
{
public:
	CMenuItem *pNext;
	int GetCount();
	CString GetItem(int nIndex);
	CMenuItem();
	CMenuItem(CString strTitre, UINT nStartPos);
	virtual ~CMenuItem();
	CString m_strTitre;
	UINT m_nStartPos;
	CStringList	m_strListItem;
};

#endif // !defined(AFX_MENUITEM_H__9F984841_1BA8_11D4_B5FF_947E0C440953__INCLUDED_)
