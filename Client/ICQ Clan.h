// ICQ Clan.h : main header file for the ICQ CLAN application
//

#if !defined(AFX_ICQCLAN_H__8D55C925_0355_11D4_A414_444553540000__INCLUDED_)
#define AFX_ICQCLAN_H__8D55C925_0355_11D4_A414_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "RegWelcomePP.h"
#include "RegNewPP.h"
#include "RegOldPP.h"

/////////////////////////////////////////////////////////////////////////////
// CICQClanApp:
// See ICQ Clan.cpp for the implementation of this class
//

class CICQClanApp : public CWinApp
{
public:
	CPropertySheet *pPSWizard;
	CICQClanApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICQClanApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CICQClanApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICQCLAN_H__8D55C925_0355_11D4_A414_444553540000__INCLUDED_)
