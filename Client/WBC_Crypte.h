// WBC_Crypte.h
//

#if !defined(WBC_CRYPTE_H__5F67EFC6_1832_12D4_B5FF_8CE870713053__INCLUDED_)
#define WBC_CRYPTE_H__5F67EFC6_1832_12D4_B5FF_8CE870713053__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWBC_Crypte
{
public:
	CString Crypter(LPCTSTR str, unsigned long lCle);
	CString Decrypter(LPCTSTR str, unsigned long lCle);
private:
	CString Translate(LPCTSTR str, int nSens, unsigned long lCle);
};

#endif // !defined(AFX_MAINFRAME_H__5F66EFC6_1832_11D4_B5FF_8CE770713053__INCLUDED_)