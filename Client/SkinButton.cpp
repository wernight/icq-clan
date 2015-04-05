// SkinButton.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "SkinButton.h"

// Bouton ICQ Clan
#define	BTC_ICQ_X		0	// Postition de départ en x
#define	BTC_ICQ_Y		0	// Postition de départ en y
#define	BTC_ICQ_HEIGHT	20	// Hauteur
#define	BTC_ICQ_WIDTH	53	// Largeur

// Bouton Add
#define	BTC_X		0	// Postition de départ en x
#define	BTC_Y		0	// Postition de départ en y
#define	BTC_HEIGHT	23	// Hauteur
#define	BTC_WIDTH1	nButtonWidth1	// Largeur (départ)
#define	BTC_WIDTH2	nButtonWidth2	// Largeur (milieu)
#define	BTC_WIDTH3	nButtonWidth3	// Largeur (fin)
#define	BTC_WIDTH	(BTC_WIDTH1 + BTC_WIDTH2 + BTC_WIDTH3)	// Largeur (totale)
// Sprite
#define	BTC_SPRITE_X		0					// Postition de départ en x
#define	BTC_SPRITE_Y		BTC_HEIGHT		// Postition de départ en y
#define	BTC_SPRITE_HEIGHT	20					// Hauteur
#define	BTC_SPRITE_WIDTH	nButtonSpriteWidth	// Largeur
// Sprite - alpha
#define	BTC_SPRITE_A_X		(BTC_SPRITE_X+BTC_SPRITE_WIDTH)	// Postition de départ en x
#define	BTC_SPRITE_A_Y		BTC_SPRITE_Y					// Postition de départ en y
#define	BTC_SPRITE_A_HEIGHT	BTC_SPRITE_HEIGHT				// Hauteur
#define	BTC_SPRITE_A_WIDTH	BTC_SPRITE_WIDTH				// Largeur

// Bouton Close
#define	BTC_X_WIDTH	13	// Largeur
#define	BTC_X_HEIGHT	11	// Hauteur

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkinButton

CSkinButton::CSkinButton()
{
	bIni = TRUE;
}

CSkinButton::~CSkinButton()
{
}


BEGIN_MESSAGE_MAP(CSkinButton, CButton)
	//{{AFX_MSG_MAP(CSkinButton)
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkinButton message handlers

void CSkinButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// Donne le focus
	CButton::SetFocus();
	
	CButton::OnMouseMove(nFlags, point);
}

void CSkinButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	ASSERT(lpDrawItemStruct != NULL);

	CDC		*pDC,
			dcmem,
			dcSkin;
	CBitmap bmpMem,
			*pOldbmpMem,
			*pOldbmpSkin;
	CString str,
			str2,
			strSkinPath,
			strFile;
	CRect	rect,
			rect2(0,0,1,1);
	UINT	nState,
			nXStart,
			nSpriteYStart,
			nDownDecal;
	register int	i;

	if (bIni)
	{
		bIni = FALSE;

		// Donne caption
		GetWindowText(m_strCaption.GetBuffer(20), 20);

		// Charge le skin / options
		if (m_strCaption == "ICQ Clan")
			str = "ButtonICQClanImages";
		else if (m_strCaption == "Add clan")
			str = "ButtonAdduserImages";
		else if (m_strCaption == "System")
			str = "ButtonSysmessageImages";
		else if (m_strCaption == "x")
			str = "ButtonCloseImages";
		strSkinPath = AfxGetApp()->GetProfileString("Options", "Skin", "");
		strFile.ReleaseBuffer( ::GetPrivateProfileString("Buttons", str, "", strFile.GetBuffer(255), 255, strSkinPath+"Skin.ini") );
		pBmpSkin = NULL;
		if (strFile != "")
		{
			HBITMAP hBitmap = NULL; 
			hBitmap = (HBITMAP)LoadImage(NULL, strSkinPath+strFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
			pBmpSkin = new CBitmap;
			if (hBitmap == NULL || pBmpSkin->Attach(hBitmap) == 0)
			{
				delete pBmpSkin;
				pBmpSkin = NULL;
			}
		}

		// Add
		if (m_strCaption == "Add clan")
			str = "Adduser";
		// Sys
		else if (m_strCaption == "System")
			str = "Sysmessage";
		if (m_strCaption == "Add clan" || m_strCaption == "System")
		{
			nButtonWidth1 = ::GetPrivateProfileInt("Buttons", "Button"+str+"LeftFixWidth", 4, strSkinPath+"skin.ini");
			nButtonWidth2 = ::GetPrivateProfileInt("Buttons", "Button"+str+"MidleWidth", 45, strSkinPath+"skin.ini");
			str2.ReleaseBuffer( ::GetPrivateProfileString("Buttons", "Button"+str+"MidleMode", "Stretch", str2.GetBuffer(20), 20, strSkinPath+"skin.ini") );
			str2.MakeUpper();
			nButtonWidth2Mode = str2 == "STRETCH" ? 0 : 1;
			nButtonWidth3 = ::GetPrivateProfileInt("Buttons", "Button"+str+"RightFixWidth", 4, strSkinPath+"skin.ini");
			nButtonSpriteWidth = ::GetPrivateProfileInt("Buttons", "Button"+str+"SpriteWidth", 99, strSkinPath+"skin.ini");
		}
	}

	if (pBmpSkin == NULL)
	{
		SetButtonStyle( GetButtonStyle() & ~BS_OWNERDRAW, TRUE);
		return;
	}

	GetWindowRect(rect);
	nState = lpDrawItemStruct->itemState;
	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

	// Créé un dc mem
	dcmem.CreateCompatibleDC(pDC);
	bmpMem.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldbmpMem = dcmem.SelectObject(&bmpMem);
	
	// Créé un dc mem avec le skin
	dcSkin.CreateCompatibleDC(pDC);
	pOldbmpSkin = dcSkin.SelectObject(pBmpSkin);

	// Place le skin ds le dcmem (1/2)
	// ICQ Clan
	if (m_strCaption == "ICQ Clan")
	{
		// Selon l'état
		if (nState & ODS_SELECTED)		// Down
			nXStart = BTC_ICQ_X + 2*BTC_ICQ_WIDTH;
		else if (nState & ODS_FOCUS)	// Focus
			nXStart = BTC_ICQ_X + BTC_ICQ_WIDTH;
		else							// Normal
			nXStart = BTC_ICQ_X;
		dcmem.BitBlt(0,0, BTC_ICQ_WIDTH, BTC_ICQ_HEIGHT, &dcSkin, nXStart+BTC_ICQ_X, BTC_ICQ_Y, SRCCOPY);
	}
	// Add / Sys
	else if (m_strCaption == "Add clan" || m_strCaption == "System")
	{
		// Selon l'état
		if (nState & ODS_SELECTED)		// Down
		{
			nXStart = BTC_X + 2*BTC_WIDTH;
			nSpriteYStart = BTC_SPRITE_Y + 2*BTC_SPRITE_HEIGHT;
		}
		else if (nState & ODS_FOCUS)	// Focus
		{
			nXStart = BTC_X + BTC_WIDTH;
			nSpriteYStart = BTC_SPRITE_Y + BTC_SPRITE_HEIGHT;
		}
		else if (nState & ODS_DISABLED)	// Disabled
		{
			nXStart = BTC_X + 3*BTC_WIDTH;
			nSpriteYStart = BTC_SPRITE_Y + 3*BTC_SPRITE_HEIGHT;
		}
		else							// Normal
		{
			nXStart = BTC_X;
			nSpriteYStart = BTC_SPRITE_Y;
		}
		// En mode répété ou étiré
		if (nButtonWidth2Mode == 0)
			dcmem.StretchBlt(BTC_WIDTH1,0, rect.Width()-BTC_WIDTH1-BTC_WIDTH3, BTC_HEIGHT, &dcSkin, nXStart+BTC_X+BTC_WIDTH1, BTC_Y, BTC_WIDTH2, BTC_HEIGHT, SRCCOPY);
		else
			for (i=BTC_WIDTH1; i<rect.Width()-BTC_WIDTH1-BTC_WIDTH3; i+=BTC_WIDTH2)
				dcmem.BitBlt(i,0, rect.Width()-BTC_WIDTH1-BTC_WIDTH3, BTC_HEIGHT, &dcSkin, nXStart+BTC_X+BTC_WIDTH1, BTC_Y, SRCCOPY);
	}
	// Close
	else if (m_strCaption == "x")
	{
		// Selon l'état
		if (nState & ODS_SELECTED)		// Down
			nXStart = 2*BTC_X_WIDTH;
		else if (nState & ODS_FOCUS)	// Focus
			nXStart = BTC_X_WIDTH;
		else							// Normal
			nXStart = 0;
		dcmem.BitBlt(0, 0, BTC_X_WIDTH, BTC_X_HEIGHT, &dcSkin, nXStart, 0, SRCCOPY);
	}

	// Place le sprite
	if (m_strCaption == "Add clan" || m_strCaption == "System")
	{
		// Down ?
		if (nState & ODS_SELECTED)
			nDownDecal=1;
		else
			nDownDecal=0;

		GetWindowText(str);										// Txt à afficher
		// Prépare l'affichage
		rect2 = CRect(BTC_WIDTH1, 0, rect.Width()-BTC_WIDTH3, rect.Height());		// Zone de texte
		// Applique l'image en tenant compte de la couche alpha
		dcmem.BitBlt(rect.Width()/2-BTC_SPRITE_WIDTH/2+nDownDecal, nDownDecal, BTC_SPRITE_WIDTH, BTC_SPRITE_HEIGHT, &dcSkin, BTC_SPRITE_A_X, nSpriteYStart, SRCPAINT);
		dcmem.BitBlt(rect.Width()/2-BTC_SPRITE_WIDTH/2+nDownDecal, nDownDecal, BTC_SPRITE_WIDTH, BTC_SPRITE_HEIGHT, &dcSkin, BTC_SPRITE_A_X, nSpriteYStart, SRCINVERT);
		dcSkin.BitBlt(BTC_SPRITE_X, nSpriteYStart, BTC_SPRITE_WIDTH, BTC_SPRITE_HEIGHT, &dcSkin, BTC_SPRITE_A_X, nSpriteYStart, SRCAND);
		dcmem.BitBlt(rect.Width()/2-BTC_SPRITE_WIDTH/2+nDownDecal, nDownDecal, BTC_SPRITE_WIDTH, BTC_SPRITE_HEIGHT, &dcSkin, BTC_SPRITE_X, nSpriteYStart, SRCPAINT);
	}

	// Place le skin ds le dcmem (2/2)
	// Add / Sys
	if (m_strCaption == "Add clan" || m_strCaption == "System")
	{
		dcmem.BitBlt(0,0, BTC_WIDTH1, BTC_HEIGHT, &dcSkin, nXStart+BTC_X, BTC_Y, SRCCOPY);
		dcmem.BitBlt(rect.Width()-BTC_WIDTH3,0, BTC_WIDTH3, BTC_HEIGHT, &dcSkin, nXStart+BTC_X+BTC_WIDTH1+BTC_WIDTH2, 0, SRCCOPY);
	}

	// Affiche à l'écran
	pDC->BitBlt(0,0, rect.Width(), rect.Height(), &dcmem, 0,0, SRCCOPY);

	// Clear la memoire
	dcmem.SelectObject(pOldbmpMem);
	dcmem.DeleteDC();
	dcSkin.SelectObject(pOldbmpSkin);
	dcSkin.DeleteDC();
}

void CSkinButton::OnDestroy() 
{
	CButton::OnDestroy();
	
	if (pBmpSkin != NULL)
		delete pBmpSkin;
}
