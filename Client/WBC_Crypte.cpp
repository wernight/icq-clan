// WBC_Crypte.cpp
//

#include "stdafx.h"
#include "WBC_Crypte.h"

CString CWBC_Crypte::Translate(LPCTSTR str, int nSens, unsigned long lCle)
{
	CString	strResult = "";		// Résultat
	const int nbrChar = 62;		// nbr de carac. d'un table
	char tables[2][nbrChar];	// table (cryptage et décryptage)
	int nXSens;					// sens (création de la table)
	int rndFait[nbrChar];		// nbr aléatoire traités (création de la table)
	int rnd;					// nombre aléatoire (création de la table)
	register int lettre = -1;	// lettre en cours
	register unsigned int i;	// pour les boucles

	// change lCle
	srand(lCle);
	lCle = rand();

	// (dé)cripte
	while (str[++lettre] != '\0')
	{
		// crée une table (cryptage et décryptage)
		srand(lCle + lettre);
		for (nXSens=0; nXSens<=1; nXSens++)
		{
			// ini. rndFait[] = 0
			for (i=0; i<nbrChar; i++)
				rndFait[i] = FALSE;

			// créé un ligne de la table (1/2 table)
			for (i=0; i<nbrChar; i++)
			{
				// nbr non-fait aléatoire
				do
					rnd = (nbrChar) * rand() / RAND_MAX;
				while (rndFait[rnd]);
				rndFait[rnd] = TRUE;

				// nbr -> charactère
				if (rnd <= 9)
					tables[nXSens][i] = rnd + 48;
				else if (rnd <= 35)
					tables[nXSens][i] = rnd + 55;
				else
					tables[nXSens][i] = rnd + 61;
			}
		}

		// (dé)cripte une lettre
		for (i=0; i<nbrChar; i++)
			if (str[lettre] == tables[nSens][i])
			{
				strResult += tables[!nSens][i];
				break;
			}
	}

	return strResult;
}

CString CWBC_Crypte::Crypter(LPCTSTR str, unsigned long lCle)
{
	// Crypte
	CString	strCrypte = Translate(str, 0, lCle);
	CString	strResult = "";
	
	// Convertit en hexa
	for (int i=0; i<strCrypte.GetLength(); i++)
		strResult.Format(strResult + "%X", strCrypte[i]);
	
	// Revoi la valeur
	return strResult;
}

CString CWBC_Crypte::Decrypter(LPCTSTR str, unsigned long lCle)
{
	CString	strDeCrypte = str;
	CString	strResult = "";
    register TCHAR ch;
	register INT n = 0;

	// Convertit d'hexa en normal
	for (int i=0; i<strDeCrypte.GetLength(); i++)
	{
		// Hexa -> Int
		ch = strDeCrypte.GetAt(i);
		if (iswdigit(ch))
			ch -= '0';
		else if (ch >= 'A' && ch <= 'F')
			ch += (TCHAR)(10 - 'A');
		else if (ch >= 'a' && ch <= 'f')
			ch += (TCHAR)(10 - 'a');
		else
			ch = (TCHAR)0;
		n = 16 * n + ch;

		if (i%2)
		{
			// Int -> Ascii
			if (n != 0)
				strResult += (char) n;
			n = 0;
		}
	}
	
	// Revoi la valeur
	return Translate(strResult, 1, lCle);
}
