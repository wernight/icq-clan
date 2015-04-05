// OptionsSkinPP.cpp : implementation file
//

#include "stdafx.h"
#include "ICQ Clan.h"
#include "OptionsSkinPP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsSkinPP property page

IMPLEMENT_DYNCREATE(COptionsSkinPP, CPropertyPage)

COptionsSkinPP::COptionsSkinPP() : CPropertyPage(COptionsSkinPP::IDD)
{
	//{{AFX_DATA_INIT(COptionsSkinPP)
	m_strAutor = _T("");
	m_strName = _T("");
	m_strNfo = _T("");
	//}}AFX_DATA_INIT
}

COptionsSkinPP::~COptionsSkinPP()
{
}

void COptionsSkinPP::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsSkinPP)
	DDX_Text(pDX, IDC_AUTOR_EDIT, m_strAutor);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_NFO_EDIT, m_strNfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsSkinPP, CPropertyPage)
	//{{AFX_MSG_MAP(COptionsSkinPP)
	ON_BN_CLICKED(IDC_SKIN_BUTTON, OnSkinButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsSkinPP message handlers

void COptionsSkinPP::OnOK() 
{
	// Enregistre ini
	UpdateData(TRUE);
	AfxGetApp()->WriteProfileString("Options", "Skin", strSkinFile);
	
	CPropertyPage::OnOK();

	CancelToClose();
}

BOOL COptionsSkinPP::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// Charge ini
	strSkinFile = AfxGetApp()->GetProfileString("Options", "Skin", "");
	UpdateSkinInfo();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// Donne les infos du skin
void COptionsSkinPP::UpdateSkinInfo()
{
	m_strName.ReleaseBuffer( ::GetPrivateProfileString("Skin informations", "Name", "", m_strName.GetBuffer(40), 40, strSkinFile+"skin.ini") );
	m_strAutor.ReleaseBuffer( ::GetPrivateProfileString("Skin informations", "Autor", "", m_strAutor.GetBuffer(40), 40, strSkinFile+"skin.ini") );
	m_strNfo.ReleaseBuffer( ::GetPrivateProfileString("Skin informations", "Informations", "", m_strNfo.GetBuffer(1024), 1024, strSkinFile+"skin.ini") );
	m_strNfo.Replace("\\n", "\r\n");
	UpdateData(FALSE);
}

void COptionsSkinPP::OnSkinButton() 
{
	char FileName[500];
	char FileTitle[100];
	CString strPath;

	UpdateData(TRUE);

	// Chemin en cours
	strPath.ReleaseBuffer( GetCurrentDirectory(500, strPath.GetBuffer(500)) );
	if (strPath.Right(1) != "\\")
		strPath += "\\";
	strPath += "Skins";

	// Demande le fichier
	OPENFILENAME ofn;
	memset(&ofn, 0, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrInitialDir = strPath;
	ofn.lpstrFile = FileName;
	ofn.nMaxFile = 500;
	ofn.lpstrFileTitle = FileTitle;
	ofn.nMaxFileTitle = 99;
	ofn.lpstrFilter = TEXT("ICQ Clan Skin (Skin.ini)\0Skin.ini\0\0");
	ofn.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;

	FileName[0] = '\0';
	
	GetOpenFileName(&ofn);

	if (FileName[0] == '\0')
		return;

	// Check et confirme
	strSkinFile = FileName;
	if (strSkinFile.Right(8).CompareNoCase("skin.ini") == 0)
		strSkinFile = strSkinFile.Left(strSkinFile.GetLength()-8);
	if (strSkinFile.Right(1) != "\\" && strSkinFile.Right(1) != "/")
		strSkinFile += "\\";

	// Affiche les infos du skin
	UpdateSkinInfo();

	SetModified(TRUE);
}
