#if !defined(AFX_ICQCLANSOCKET_H__8D55C933_0355_11D4_A414_444553540000__INCLUDED_)
#define AFX_ICQCLANSOCKET_H__8D55C933_0355_11D4_A414_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ICQClanSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CICQClanSocket command target

class CICQClanSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CICQClanSocket(LPVOID pParam, int n);
	virtual ~CICQClanSocket();

// Overrides
public:
	int Send(CString str);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CICQClanSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CICQClanSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	CDialog *pdlg;
	int nDlg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICQCLANSOCKET_H__8D55C933_0355_11D4_A414_444553540000__INCLUDED_)
