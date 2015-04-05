/************************************************************************************\
|                                                                                    |
|        II       CCCC      QQQ               _                                      |
|        II     CC         Q   Q            /    /|                                  |
|        II    C          Q     Q          |     |/   -i  /|/|                       |
|        II     CC         Q  QQ            \ __/ \__|_|_| | |_                      |
|        II       CCCC      QQQQ                       `                             |
|                               Q                                                    |
|                                                                                    |
|   ICQ Clan                                                                         |
|   Copyright (c) 2000 Werner BEROUX (known as WBC or Wernight)                      |
|   All rights reserved                                                              |
|                                                                                    |
|   Web site:     www.alc-wbc.com                                                    |
|   E-Mail:       wbc@alc-wbc.com                                                    |
|   ICQ UIN:      14542366                                                           |
|   ICQ Clan UIN: 0                                                                  |
|                                                                                    |
\************************************************************************************/
// MenuStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "MenuStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuStatic

CMenuStatic::CMenuStatic()
{
	CMenuItem	*pInvisbleMI;
	CString		strPath,
				str;
	int			t;

	ThreadCanRun = TRUE;

	// Item invisible de fin
	pInvisbleMI = new CMenuItem("", 0);
	pInvisbleMI->pNext = NULL;
	pFirstMI = pInvisbleMI;
	m_nMenuCount = 0;
	m_nSelMenu = -1;

	// Répertoire du skin
	strPath = AfxGetApp()->GetProfileString("Options", "Skin", "");

	// Menu: Img de fond
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu", "BackgroundImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	pBmpBkground = NULL;
	if (str != "")
	{
		pBmpBkground = new CBitmap;
		LoadBitmap(*pBmpBkground, strPath + str);
	}

	// Menu: Img de fond Mode
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu", "BackgroundImageMode", "Stretch", str.GetBuffer(20), 20, strPath+"skin.ini") );
	str.MakeUpper();
	nBkgroundMode = str == "STRETCH" ? 0 : 1;

	// Menu: Couleur de fond
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu", "BackgroundColor", "192,192,192", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorBkground = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu: Animation: déplacement
	nAnimationChaseDivider = AfxGetApp()->GetProfileInt("Options", "Menu Speed1", 3);

	// Menu: Animation: déplacement
	nAnimationSpeedupChaseDivider = AfxGetApp()->GetProfileInt("Options", "Menu Speed2", 7);

	// Menu: Animation: wait time
	nAnimationRate = AfxGetApp()->GetProfileInt("Options", "Menu Rate", 40);

	// Menu: Close on exit
	bCloseOnMenuExit = AfxGetApp()->GetProfileInt("Options", "Menu CloseOnExit", 0) != 0;

	// Menu item: Unsel img
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "UnselectedMenuImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	pBmpUnselMenu = NULL;
	if (str != "")
	{
		pBmpUnselMenu = new CBitmap;
		LoadBitmap(*pBmpUnselMenu, strPath + str);
	}

	// Menu item: Left fix
	nMenuUnselWidth1 = ::GetPrivateProfileInt("Menu items", "UnselectedMenuLeftFixWidth", 17, strPath+"skin.ini");

	// Menu item: Midle fix
	nMenuUnselWidth2 = ::GetPrivateProfileInt("Menu items", "UnselectedMenuMidleWidth", 84, strPath+"skin.ini");

	// Menu item: Midle fix Mode
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "SelectedMenuMidleMode", "Stretch", str.GetBuffer(20), 20, strPath+"skin.ini") );
	str.MakeUpper();
	nMenuUnselWidth2Mode = str == "STRETCH" ? 0 : 1;

	// Menu item: Right fix
	nMenuUnselWidth3 = ::GetPrivateProfileInt("Menu items", "UnselectedMenuRightFixWidth", 5, strPath+"skin.ini");

	// Menu item: Sel img
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "SelectedMenuImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	pBmpSelMenu = NULL;
	if (str != "")
	{
		pBmpSelMenu = new CBitmap;
		LoadBitmap(*pBmpSelMenu, strPath + str);
	}

	// Menu item: Left fix
	nMenuSelWidth1 = ::GetPrivateProfileInt("Menu items", "SelectedMenuLeftFixWidth", 17, strPath+"skin.ini");

	// Menu item: Midle fix
	nMenuSelWidth2 = ::GetPrivateProfileInt("Menu items", "SelectedMenuMidleWidth", 84, strPath+"skin.ini");

	// Menu item: Midle fix Mode
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "SelectedMenuMidleMode", "Stretch", str.GetBuffer(20), 20, strPath+"skin.ini") );
	str.MakeUpper();
	nMenuSelWidth2Mode = str == "STRETCH" ? 0 : 1;

	// Menu item: Right fix
	nMenuSelWidth3 = ::GetPrivateProfileInt("Menu items", "SelectedMenuRightFixWidth", 5, strPath+"skin.ini");

	// Menu item: Menu height
	nMenuHeight = ::GetPrivateProfileInt("Menu items", "MenuHeight", 15, strPath+"skin.ini");

	// Menu item: Font
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "MenuFont", "MS Sans Serif", str.GetBuffer(255), 255, strPath+"skin.ini") );
	t = ::GetPrivateProfileInt("Menu items", "MenuFontSize", 12, strPath+"skin.ini");
	fontMenu.CreateFont(-t, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
						ANSI_CHARSET, OUT_DEVICE_PRECIS, CLIP_CHARACTER_PRECIS,
						DEFAULT_QUALITY, FF_SWISS, str);

	// Menu item: Unsel menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "MenuUnselectedColor", "000,000,000", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorMenuUnsel = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu item: Sel menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "MenuSelectedColor", "051,025,000", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorMenuSel = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu item: Unsel shadow menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "MenuUnselectedShadowColor", "204,204,204", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorMenuUnselShadow = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu item: Sel shadow menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu items", "MenuSelectedShadowColor", "214,200,100", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorMenuSelShadow = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu subitem: Unsel img
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "UnselectedMenuItemImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	pBmpUnselSubMenu = NULL;
	if (str != "")
	{
		pBmpUnselSubMenu = new CBitmap;
		LoadBitmap(*pBmpUnselSubMenu, strPath + str);
	}

	// Menu subitem: Left fix
	nSubMenuUnselWidth1 = ::GetPrivateProfileInt("Menu subitems", "UnselectedMenuItemLeftFixWidth", 17, strPath+"skin.ini");

	// Menu subitem: Midle fix
	nSubMenuUnselWidth2 = ::GetPrivateProfileInt("Menu subitems", "UnselectedMenuItemMidleWidth", 84, strPath+"skin.ini");

	// Menu subitem: Midle fix Mode
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "UnselectedMenuMidleMode", "Stretch", str.GetBuffer(20), 20, strPath+"skin.ini") );
	str.MakeUpper();
	nSubMenuUnselWidth2Mode = str == "STRETCH" ? 0 : 1;

	// Menu subitem: Right fix
	nSubMenuUnselWidth3 = ::GetPrivateProfileInt("Menu subitems", "UnselectedMenuItemRightFixWidth", 5, strPath+"skin.ini");

	// Menu subitem: Sel img
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "SelectedMenuItemImage", "", str.GetBuffer(255), 255, strPath+"skin.ini") );
	pBmpSelSubMenu = NULL;
	if (str != "")
	{
		pBmpSelSubMenu = new CBitmap;
		LoadBitmap(*pBmpSelSubMenu, strPath + str);
	}

	// Menu subitem: Left fix
	nSubMenuSelWidth1 = ::GetPrivateProfileInt("Menu subitems", "SelectedMenuItemLeftFixWidth", 17, strPath+"skin.ini");

	// Menu subitem: Midle fix
	nSubMenuSelWidth2 = ::GetPrivateProfileInt("Menu subitems", "SelectedMenuItemMidleWidth", 84, strPath+"skin.ini");

	// Menu subitem: Midle fix Mode
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "SelectedMenuMidleMode", "Stretch", str.GetBuffer(20), 20, strPath+"skin.ini") );
	str.MakeUpper();
	nSubMenuSelWidth2Mode = str == "STRETCH" ? 0 : 1;

	// Menu subitem: Right fix
	nSubMenuSelWidth3 = ::GetPrivateProfileInt("Menu subitems", "SelectedMenuItemRightFixWidth", 5, strPath+"skin.ini");

	// Menu subitem: Menu height
	nSubMenuHeight = ::GetPrivateProfileInt("Menu subitems", "MenuItemHeight", 14, strPath+"skin.ini");

	// Menu subitem: Font
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "MenuItemFont", "MS Sans Serif", str.GetBuffer(255), 255, strPath+"skin.ini") );
	t = ::GetPrivateProfileInt("Menu subitems", "MenuItemFontSize", 12, strPath+"skin.ini");
	fontSubMenu.CreateFont(-t, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
						   ANSI_CHARSET, OUT_DEVICE_PRECIS, CLIP_CHARACTER_PRECIS,
						   DEFAULT_QUALITY, FF_SWISS, str);

	// Menu subitem: Unsel menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "MenuItemUnselectedColor", "181,200,208", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorSubMenuUnsel = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu subitem: Sel menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "MenuItemSelectedColor", "214,200,100", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorSubMenuSel = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu subitem: Unsel shadow menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "MenuItemUnselectedShadowColor", "000,000,000", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorSubMenuUnselShadow = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));

	// Menu subitem: Sel shadow menu color
	str.ReleaseBuffer( ::GetPrivateProfileString("Menu subitems", "MenuItemSelectedShadowColor", "000,000,000", str.GetBuffer(255), 255, strPath+"skin.ini") );
	if (str.GetLength() == 11)
		colorSubMenuSelShadow = RGB(atoi(str.Mid(0,3)), atoi(str.Mid(4,3)), atoi(str.Mid(8,3)));
}

CMenuStatic::~CMenuStatic()
{
}


BEGIN_MESSAGE_MAP(CMenuStatic, CStatic)
	//{{AFX_MSG_MAP(CMenuStatic)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuStatic message handlers

void CMenuStatic::OnPaint() 
{
	CClientDC	dc(this); // device context for painting
	CRect		rectTxt,
				rectDc;
	CFont		font;
	CBitmap		bmpMem,
				*pOldbmpMem,
				*pOldbmp;
	BITMAP		bm;
	CBrush		brush;
	CDC			dcmem,
				dcbmp;
	CMenuItem	*pMi;
	CPoint		point;
	int			nWidth1 = 17,
				nWidth2 = 84,
				nWidth3 = 5;
	int			nWidth2Mode;
	bool		bCanDraw;
	register int i, j, x;

	GetWindowRect(&rectDc);

	// Donne les éléments sélectionnés
	GetCursorPos(&point);
	ScreenToClient(&point);
	m_nSelMenu = -1;
	if (point.x > 1 && point.x < rectDc.Width())
		for (i=0, pMi=pFirstMI; pMi->pNext != NULL; i++, pMi=pMi->pNext)
		{
			// Sél un Item
			if (point.y >= (int) pMi->m_nStartPos && point.y <= (int) pMi->m_nStartPos + nMenuHeight)
			{
				// Le menu sél.
				m_nSelMenu = i;
				m_nSelSubMenu = -1;
				break;
			}
			// Sél un Sous-item
			if (point.y >= (int) pMi->m_nStartPos + nMenuHeight && point.y <= (int) pMi->pNext->m_nStartPos)
			{
				// Le sous menu sél. (-1 si c le menu principal)
				m_nSelMenu = i;
				m_nSelSubMenu = (point.y - (int) pMi->m_nStartPos - nMenuHeight) / nSubMenuHeight;
				break;
			}
		}

	// Créé un dc mem
	dcmem.CreateCompatibleDC(&dc);
	rectDc = CRect(0,0, rectDc.Width()-4, rectDc.Height()-4);
	bmpMem.CreateCompatibleBitmap(&dc, rectDc.Width(), rectDc.Height());
	pOldbmpMem = dcmem.SelectObject(&bmpMem);

	// Créé un dc avec bmp de fond
	dcbmp.CreateCompatibleDC(&dc);

	// Donne le bmp ori
	pOldbmp = NULL;
	if (pBmpSelMenu != NULL)
		pOldbmp = dcbmp.SelectObject(pBmpSelMenu);
	else if (pBmpUnselMenu != NULL)
		pOldbmp = dcbmp.SelectObject(pBmpUnselMenu);
	else if (pBmpBkground != NULL)
		pOldbmp = dcbmp.SelectObject(pBmpBkground);

	// Place le fond
	if (pBmpBkground != NULL)
	{
		if (nBkgroundMode == 0)
		{
			pBmpBkground->GetBitmap( &bm );
			dcbmp.SelectObject(pBmpBkground);
			dcmem.StretchBlt(rectDc.left, rectDc.top, rectDc.Width(), rectDc.Height(), &dcbmp, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
		}
		else
		{
			brush.CreatePatternBrush(pBmpBkground);
			dcmem.FillRect(&rectDc, &brush);
		}
	}
	else
		dcmem.FillSolidRect(0,0, rectDc.Width(), rectDc.Height(), colorBkground);

	// Place le menu
	dcmem.SetBkMode(TRANSPARENT);
	for (i=0, pMi=pFirstMI; pMi->pNext != NULL; i++, pMi = pMi->pNext)
	{
		// Affiche les sous-items d'un item
		if (pMi->GetCount() != 0)
		{
			dcmem.SelectObject(&fontSubMenu);
			for (j=0; (int)j<pMi->GetCount() && pMi->m_nStartPos+(j+1)*nMenuHeight<FindIndex(i+1)->m_nStartPos; j++)
			{
				// Selon si le menu est sélectionné
				bCanDraw = FALSE;
				if (m_nSelMenu == i && m_nSelSubMenu == j)
				{
					if (pBmpSelSubMenu != NULL)
					{
						dcbmp.SelectObject(pBmpSelSubMenu);
						nWidth1 = nSubMenuSelWidth1;
						nWidth2 = nSubMenuSelWidth2;
						nWidth2Mode = nSubMenuSelWidth2Mode;
						nWidth3 = nSubMenuSelWidth3;
						bCanDraw = TRUE;
					}
				}
				else
				{
					if (pBmpUnselSubMenu != NULL)
					{
						dcbmp.SelectObject(pBmpUnselSubMenu);
						nWidth1 = nSubMenuUnselWidth1;
						nWidth2 = nSubMenuUnselWidth2;
						nWidth2Mode = nSubMenuUnselWidth2Mode;
						nWidth3 = nSubMenuUnselWidth3;
						bCanDraw = TRUE;
					}
				}

				// Place les img du menus
				if (bCanDraw)
				{
					dcmem.BitBlt(	0,
									pMi->m_nStartPos+nMenuHeight+j*nSubMenuHeight, 
									nWidth1, 
									nSubMenuHeight, 
									&dcbmp, 
									0, 
									0, 
									SRCCOPY);
					// Stretch
					if (nWidth2Mode == 0)
						dcmem.StretchBlt(	nWidth1,
											pMi->m_nStartPos+nMenuHeight+j*nSubMenuHeight, 
											rectDc.Width()-nWidth1-nWidth3, 
											nSubMenuHeight, 
											&dcbmp, 
											nWidth1, 
											0, 
											nWidth3, 
											nSubMenuHeight, 
											SRCCOPY);
					// Repeat
					else
						for (x=nWidth1; x<rectDc.Width()-nWidth3; x+=nWidth3)
							dcmem.BitBlt(x,pMi->m_nStartPos+nMenuHeight+j*nSubMenuHeight, nWidth3, nSubMenuHeight, &dcbmp, nWidth1, 0, SRCCOPY);
					dcmem.BitBlt(	rectDc.Width()-nWidth3,
									pMi->m_nStartPos+nMenuHeight+j*nSubMenuHeight,
									nWidth3,
									nSubMenuHeight,
									&dcbmp,
									nWidth1+nWidth2,
									0,
									SRCCOPY);
				}

				// Place les textes du sous-menu
				// Affiche 1/2 (ombre)
				rectTxt = CRect(24, 1+pMi->m_nStartPos+nMenuHeight+j*nSubMenuHeight, rectDc.Width(), 1+pMi->m_nStartPos+nMenuHeight+(j+1)*nSubMenuHeight);
				// Si le sous-menu est sélectionné
				if (m_nSelMenu == i && m_nSelSubMenu == j)
					dcmem.SetTextColor( colorSubMenuSelShadow );
				else
					dcmem.SetTextColor( colorSubMenuUnselShadow );
				dcmem.DrawText(pMi->GetItem(j), rectTxt, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

				// Affiche 2/2
				rectTxt.OffsetRect(-1,-1);										// Déplace le rect pr faire un relief
				// Si le sous-menu est sélectionné
				if (m_nSelMenu == i && m_nSelSubMenu == j)
					dcmem.SetTextColor( colorSubMenuSel );
				else
					dcmem.SetTextColor( colorSubMenuUnsel );
				dcmem.DrawText(pMi->GetItem(j), rectTxt, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			}
		}

		// Selon si le menu est sélectionné
		bCanDraw = FALSE;
		if (m_nSelMenu == i && m_nSelSubMenu == -1)
		{
			if (pBmpSelMenu != NULL)
			{
				dcbmp.SelectObject(pBmpSelMenu);
				nWidth1 = nMenuSelWidth1;
				nWidth2 = nMenuSelWidth2;
				nWidth2Mode = nMenuSelWidth2Mode;
				nWidth3 = nMenuSelWidth3;
				bCanDraw = TRUE;
			}
		}
		else
		{
			if (pBmpUnselMenu != NULL)
			{
				dcbmp.SelectObject(pBmpUnselMenu);
				nWidth1 = nMenuUnselWidth1;
				nWidth2 = nMenuUnselWidth2;
				nWidth2Mode = nMenuUnselWidth2Mode;
				nWidth3 = nMenuUnselWidth3;
				bCanDraw = TRUE;
			}
		}

		// Place les img du menus
		if (bCanDraw)
		{
			dcmem.BitBlt(	0,
							pMi->m_nStartPos, 
							nWidth1, 
							nMenuHeight, 
							&dcbmp, 
							0, 
							0, 
							SRCCOPY);
			// Stretch
			if (nWidth2Mode == 0)
				dcmem.StretchBlt(	nWidth1,
									pMi->m_nStartPos, 
									rectDc.Width()-nWidth1-nWidth3, 
									nMenuHeight, 
									&dcbmp, 
									nWidth1, 
									0, 
									nWidth3, 
									nMenuHeight, 
									SRCCOPY);
			// Repeat
			else
				for (x=nWidth1; x<rectDc.Width()-nWidth3; x+=nWidth3)
					dcmem.BitBlt(x,pMi->m_nStartPos, nWidth3, nMenuHeight, &dcbmp, nWidth1, 0, SRCCOPY);
			dcmem.BitBlt(	rectDc.Width()-nWidth3,
							pMi->m_nStartPos,
							nWidth3,
							nMenuHeight,
							&dcbmp,
							nWidth1+nWidth2,
							0,
							SRCCOPY);
		}
		// Place un fond si y'en a pas
		else
		{
			rectTxt = CRect(0, pMi->m_nStartPos, rectDc.Width(), pMi->m_nStartPos + nMenuHeight);
			dcmem.FillSolidRect(rectTxt, colorBkground);
		}

		// Place les textes du menu
		dcmem.SelectObject(&fontMenu);
		// Affiche 1/2 (ombre)
		rectTxt = CRect(nWidth1 + 4, pMi->m_nStartPos, rectDc.Width()-nWidth3, pMi->m_nStartPos + nMenuHeight);
		if (m_nSelMenu == i && m_nSelSubMenu == -1)
			dcmem.SetTextColor( colorMenuSelShadow );
		else
			dcmem.SetTextColor( colorMenuUnselShadow );
		dcmem.DrawText(pMi->m_strTitre, rectTxt, DT_LEFT | DT_VCENTER | DT_SINGLELINE);	// ...

		// Affiche 2/2
		rectTxt.OffsetRect(-1,-1);										// Déplace le rect pr faire un relief
		if (m_nSelMenu == i && m_nSelSubMenu == -1)
			dcmem.SetTextColor( colorMenuSel );
		else
			dcmem.SetTextColor( colorMenuUnsel );
		dcmem.DrawText(pMi->m_strTitre, rectTxt, DT_LEFT | DT_VCENTER | DT_SINGLELINE);	// ...
	}

	// Affiche
	dc.BitBlt(0,0, rectDc.Width(), rectDc.Height(), &dcmem, 0,0, SRCCOPY);

	// Clean mem
	dcmem.SelectObject(pOldbmpMem);
	dcmem.DeleteDC();
	if (pOldbmp)
		dcbmp.SelectObject(pOldbmp);
	dcbmp.DeleteDC();

	// Valide la zone
	ValidateRect(rectDc);

	// Do not call CStatic::OnPaint() for painting messages
}

// Lance l'animation en cas de besoins
void CMenuStatic::OnMouseMove(UINT nFlags, CPoint point) 
{
	CMenuItem		*pMI;
	CRect			rect;

	this->GetWindowRect(&rect);

	// Donne le dernier élément.
	for (pMI=pFirstMI; pMI->pNext != NULL; pMI=pMI->pNext)
	{ }

	// Si le curseur est dans le menu
	if (point.x > 1 && point.x < rect.Width() &&
		point.y > 1 && point.y <= (int) pMI->m_nStartPos + nMenuHeight &&
		ThreadCanRun)
	{
		// Si le déplacement n'est pas lancé le lance
		ThreadCanRun = FALSE;
		AfxBeginThread(Thread, this);
	}

	Invalidate(FALSE);
	
	CStatic::OnMouseMove(nFlags, point);
}

// Thread qui déplace les menu pour afficher les éléments
UINT CMenuStatic::Thread(LPVOID pParam)
{
	CMenuStatic	*pdlg = (CMenuStatic*) pParam;
	int		*nStartPos,
			i, j,
			nSelMenuHeight,
			nSlowMoveMenu,
			nCalled;
	bool	bEnd;

	// Donne la position de départ
	nSlowMoveMenu = pdlg->m_nSelMenu;
	nStartPos = new int[pdlg->m_nMenuCount+1];
	for (i=0; i<(int)pdlg->m_nMenuCount+1; i++)
		nStartPos[i] = i * pdlg->nMenuHeight;

	// Affiche la trensition (1/2: Monte)
	nCalled = 1;
	do
	{
		bEnd = TRUE;

		// Calcul la nouvelle postion de items
		for (j=0; j<=pdlg->m_nSelMenu; j++)
		{
			// Déplace
			if (j == nSlowMoveMenu)
				pdlg->FindIndex(j)->m_nStartPos -= 	pdlg->nAnimationChaseDivider;
			else
				pdlg->FindIndex(j)->m_nStartPos -= pdlg->nAnimationSpeedupChaseDivider;

			// Si le déplacement de l'élément est terminé (premier élément)
			if (j==0)
			{
				// Test si le déplacement est terminé
				// (test un peu spécial car m_nStartPos est UIN donc y'a pas de val <0
				if (pdlg->FindIndex(j)->m_nStartPos >= pdlg->FindIndex(j)->m_nStartPos+pdlg->nAnimationSpeedupChaseDivider)
				{
					pdlg->FindIndex(j)->m_nStartPos = 0;
					nSlowMoveMenu = j+1;
				}
				else
					bEnd = FALSE;
			}
			// Si le déplacement de l'élément est terminé
			else if (pdlg->FindIndex(j)->m_nStartPos <= pdlg->FindIndex(j-1)->m_nStartPos+pdlg->nMenuHeight)
				pdlg->FindIndex(j)->m_nStartPos = pdlg->FindIndex(j-1)->m_nStartPos + pdlg->nMenuHeight;
			// Sinon
			else
				bEnd = FALSE;
		}

		// Affiche et attend
		pdlg->Invalidate(FALSE);
		::Sleep(pdlg->nAnimationRate);
	} while (!bEnd);

	// Affiche la trensition (2/2: Descend)
	nSelMenuHeight = pdlg->FindIndex(pdlg->m_nSelMenu)->GetCount() * pdlg->nMenuHeight;
	nCalled = 2;
	do
	{
		bEnd = TRUE;

		// Calcul la nouvelle postion de items
		for (j=pdlg->m_nMenuCount; j>pdlg->m_nSelMenu; j--)
		{
			// Si c pas dernier élément invisible ou s'il n'est pas à la bonne position
			if (j != (int)pdlg->m_nMenuCount || pdlg->FindIndex(pdlg->m_nMenuCount)->m_nStartPos < nStartPos[pdlg->m_nMenuCount] + (UINT)nSelMenuHeight)
			{
				//  Se c le dernier élément
				if (j == (int)pdlg->m_nMenuCount)
					bEnd = FALSE;

				// Déplace
				if (j == nSlowMoveMenu)
					pdlg->FindIndex(j)->m_nStartPos += pdlg->nAnimationChaseDivider;
				else
					pdlg->FindIndex(j)->m_nStartPos += pdlg->nAnimationSpeedupChaseDivider;
			}
			// Sinon donne la position finale exact du dernier élément invisible
			else
			{
				pdlg->FindIndex(j)->m_nStartPos = nStartPos[j] + nSelMenuHeight;
				nSlowMoveMenu = j-1;
			}

			// Si le déplacement de l'élément est terminé
			if (j != (int)pdlg->m_nMenuCount)
			{
				if (pdlg->FindIndex(j)->m_nStartPos+pdlg->nMenuHeight >= pdlg->FindIndex(j+1)->m_nStartPos)
				{
					pdlg->FindIndex(j)->m_nStartPos = pdlg->FindIndex(j+1)->m_nStartPos - pdlg->nMenuHeight;
					nSlowMoveMenu = j-1;
				}
				// Sinon
				else
					bEnd = FALSE;
			}
		}

		// Affiche et attend
		pdlg->Invalidate(FALSE);
		::Sleep(pdlg->nAnimationRate);
	} while (!bEnd);


	// Clean mem
	delete [] nStartPos;
	pdlg->ThreadCanRun = TRUE;
	return 0;
}

void CMenuStatic::OnDestroy() 
{
	CStatic::OnDestroy();

	// Bmp
	if (pBmpBkground != NULL)
		delete pBmpBkground;
	if (pBmpUnselMenu != NULL)
		delete pBmpUnselMenu;
	if (pBmpSelMenu != NULL)
		delete pBmpSelMenu;
	if (pBmpSelSubMenu != NULL)
		delete pBmpSelSubMenu;
	if (pBmpUnselSubMenu != NULL)
		delete pBmpUnselSubMenu;

	RemoveAll();
	delete pFirstMI;
}

// Ajoute un item à la fin de la liste
BOOL CMenuStatic::AddItem(CString str)
{
	return InsertAfter(str, m_nMenuCount-1);
}

BOOL CMenuStatic::InsertAfter(CString str, int nIndex)
{
	int i;
	CMenuItem *pNewMI,
			  *pMI;

	// Créé un mi
	pMI = FindIndex(nIndex+1);
	pNewMI = new CMenuItem(str, pMI->m_nStartPos);

	// Change la chaine des mi (pNext)
	pNewMI->pNext = pMI;
	if (nIndex == -1)
		pFirstMI = pNewMI;
	else
		FindIndex(nIndex)->pNext = pNewMI;

	m_nMenuCount++;

	// Décalle les m_nStartPos
	for (i=0, pMI=pFirstMI; pMI!=NULL; i++, pMI=pMI->pNext)
		if (i>nIndex+1)
			pMI->m_nStartPos += nMenuHeight;

	return TRUE;
}

void CMenuStatic::RemoveItem(int nIndex)
{
	ASSERT(nIndex >= 0);
	ASSERT(nIndex < m_nMenuCount);

	CMenuItem	*pMI;

	pMI = FindIndex(nIndex);

	// Change la chaise
	if (nIndex == 0)
		pFirstMI = pMI->pNext;
	else
		FindIndex(nIndex-1)->pNext = pMI->pNext;

	// Efface de la mem
	delete pMI;

	m_nMenuCount--;
}

void CMenuStatic::RemoveAll()
{
	int i;
	CMenuItem *pInvisibleMI;

	// Vire tout sauf l'invisible
	pInvisibleMI = FindIndex(m_nMenuCount);
	for (i=m_nMenuCount; i>0; i--)
		delete FindIndex(i-1);

	// Le 1er = l'invisible
	pFirstMI = pInvisibleMI;

	m_nMenuCount = 0;
}

void CMenuStatic::AddSubItem(CString str, int nIndex)
{
	InsertSubAfter(str, nIndex, FindIndex(nIndex)->GetCount());
}

void CMenuStatic::InsertSubAfter(CString str, int nIndex, int nSub)
{
	FindIndex(nIndex)->m_strListItem.InsertAfter( FindIndex(nIndex)->m_strListItem.FindIndex(nSub), str);
}

void CMenuStatic::RemoveAllSub(int nIndex)
{
	FindIndex(nIndex)->m_strListItem.RemoveAll();
}

void CMenuStatic::RemoveSubAt(int nIndex, int nSub)
{
	FindIndex(nIndex)->m_strListItem.RemoveAt( FindIndex(nIndex)->m_strListItem.FindIndex(nSub) );
}

int CMenuStatic::GetSubItemCount(int nIndex)
{
	return FindIndex(nIndex)->GetCount();

}

CString CMenuStatic::GetSubItem(int nIndex, int nSub)
{
	return FindIndex(nIndex)->GetItem(nSub);
}

// Renvoi un pointeur vers l'élement demandé
CMenuItem* CMenuStatic::FindIndex(int nIndex)
{
	ASSERT(nIndex >= 0);
	ASSERT(nIndex <= m_nMenuCount);

	int i;
	CMenuItem *pNext;

	// Cherche l'adresse
	for (i=0, pNext=pFirstMI; i<nIndex && pNext->pNext != NULL; i++, pNext=pNext->pNext) { }

	return pNext;
}

BOOL CMenuStatic::LoadBitmap(CBitmap &bmp, LPCTSTR str)
{
	ASSERT( str );

	HBITMAP hBitmap = NULL; 
	hBitmap = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION | LR_DEFAULTSIZE);
	return bmp.Attach(hBitmap);
}
