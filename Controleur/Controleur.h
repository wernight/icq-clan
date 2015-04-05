// Controleur.h : main header file for the CONTROLEUR application
//

#if !defined(AFX_CONTROLEUR_H__4B739573_2839_11D4_B5FF_B69A92510653__INCLUDED_)
#define AFX_CONTROLEUR_H__4B739573_2839_11D4_B5FF_B69A92510653__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CControleurApp:
// See Controleur.cpp for the implementation of this class
//

class CControleurApp : public CWinApp
{
public:
	CControleurApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControleurApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CControleurApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLEUR_H__4B739573_2839_11D4_B5FF_B69A92510653__INCLUDED_)
