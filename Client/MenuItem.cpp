// MenuItem.cpp: implementation of the CMenuItem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICQ Clan.h"
#include "MenuItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMenuItem::CMenuItem()
{
	m_strTitre = "";
	m_nStartPos = 0;
}

CMenuItem::CMenuItem(CString strTitre, UINT nStartPos)
{
	m_strTitre = strTitre;
	m_nStartPos = nStartPos;
}


CMenuItem::~CMenuItem()
{

}

CString CMenuItem::GetItem(int nIndex)
{
	return m_strListItem.GetAt( m_strListItem.FindIndex(nIndex) );
}

int CMenuItem::GetCount()
{
	return m_strListItem.GetCount();
}
