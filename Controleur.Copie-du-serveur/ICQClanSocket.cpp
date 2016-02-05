// ICQClanSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ICQClanSocket.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CICQClanSocket

CICQClanSocket::CICQClanSocket(LPVOID pParam, DWORD dwId)
{
	pdlg = (CServerDlg*) pParam;
	dwSocketid = dwId;
}

CICQClanSocket::~CICQClanSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CICQClanSocket, CSocket)
	//{{AFX_MSG_MAP(CICQClanSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CICQClanSocket member functions

void CICQClanSocket::OnAccept(int nErrorCode) 
{
	((CServerDlg*) pdlg)->OnAccept();
	
	CSocket::OnAccept(nErrorCode);
}

void CICQClanSocket::OnReceive(int nErrorCode) 
{
	((CServerDlg*) pdlg)->OnReceive(dwSocketid);
	
	CSocket::OnReceive(nErrorCode);
}

int CICQClanSocket::Send(CString str)
{
	str += "\n";
	return CSocket::Send(str, str.GetLength());
}
