// Patcher.h : main header file for the PATCHER application
//

#if !defined(AFX_PATCHER_H__F806C966_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_)
#define AFX_PATCHER_H__F806C966_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPatcherApp:
// See Patcher.cpp for the implementation of this class
//

class CPatcherApp : public CWinApp
{
public:
	CPatcherApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPatcherApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPatcherApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATCHER_H__F806C966_4115_11D4_B5FF_9CCB3CC70A50__INCLUDED_)
