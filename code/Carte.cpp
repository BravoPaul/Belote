
#include "Carte.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>

Carte::Carte(Valeur val, Couleur coul)
{
	valeur = val;
	couleur = coul;
}

Carte::Carte()
{
}

void Carte:: setCouleur(Couleur couleur) {
		this->couleur = couleur;
	}

void Carte:: setValeur(Valeur valeur) {
	this->valeur = valeur;
}

Couleur Carte:: getCouleur()
{
	return couleur;
}

char* Carte:: getCouleur2()
{
	std::string stringss;


	switch (couleur)
	{
		case COEUR : stringss = "H";break;
		case CARREAU : stringss = "D";break;
		case PIQUE  : stringss = "S";break;
		case TREFLE : stringss = "C";break;
		default  : std::cout<<"K";break;
	}
	 char* c = new char[stringss.size() + 1];
	 std::copy(stringss.begin(), stringss.end(),c);
	 c[stringss.size()] = '\0';
	return c;	
}

	/**
	 * Retourne la valeur.
	 */
Valeur Carte:: getValeur()
{
    return valeur;
}

int Carte:: getValeur(Couleur atout)
{
	if (couleur==atout)
	{
		if (valeur==VALET) return 20;
		if (valeur==NEUF) return 14;
	}

	else if (valeur==VALET) return 2;

	if (valeur==AS) return 11;
	if (valeur==DIX) return 10;
	if (valeur==ROI) return 4;
	if (valeur==DAME) return 3;

	return 0;
}

int Carte:: getOrdre(Couleur atout)
	{
		if (couleur==atout)
		{
			switch (valeur)
			{
			case VALET : return 20;
			case NEUF  : return 14;
			case AS    : return 11;
			case DIX   : return 10;
			case ROI   : return 4;
			case DAME  : return 3;
			default  : return 0;
			}
		}
		else
		{
			switch (valeur)
			{
			case VALET : return 2;
			case AS    : return 11;
			case DIX   : return 10;
			case ROI   : return 4;
			case DAME  : return 2;
			default  : return 0;
			}
		}
	}

bool Carte:: isSuperieur(Carte carte, Couleur atout, Couleur couleurPli)
	{
		// si la carte n'est pas de la couleur de l'atout et que nous si
		if (couleur == atout &&carte.couleur != atout) return true;

		// inversement
		if (couleur != atout && carte.couleur == atout) return false;

		// si la carte n'est pas de la couleur du pli et que nous si
		if (couleur == couleurPli && carte.couleur != couleurPli) return true;

		// inversement
		if (couleur != couleurPli && carte.couleur == couleurPli) return false;

		// sinon on compare les ordres
		return (getOrdre(atout) > carte.getOrdre(atout));
	}

std::string Carte:: toString()
{
	std::string stringss = "";
	switch (valeur)
	{
		case VALET : stringss = stringss+"VALET"; break;
		case NEUF  : stringss =stringss+"NEUF"; break;
		case AS    : stringss = stringss+"AS";break;
		case DIX   : stringss = stringss+"DIX";break;
		case ROI   : stringss = stringss+"ROI";break;
		case DAME  : stringss = stringss+"DAME";break;
		case HUIT  : stringss = stringss+"HUIT";break;
		case SEPT  : stringss = stringss+"SETP";break;
		default  : std::cout<<"cuo wu de pai";break;
	}
	switch (couleur)
	{
		case COEUR : stringss = stringss+" DE COEUR";break;
		case CARREAU : stringss = stringss+" DE CARREAU";break;
		case PIQUE  : stringss = stringss+" DE PIQUE";break;
		case TREFLE : stringss = stringss+" DE TREFLE";break;
		default  : std::cout<<"error carte";break;
	}
	return stringss;
}



char* Carte:: toString2()
{
	char *stringss;
	stringss = new char[10];
	stringss[0] = ' ';
	switch (valeur)
	{
		case VALET : strcat(stringss,"J"); break;
		case NEUF  : strcat(stringss,"9"); break;
		case AS    : strcat(stringss,"1");break;
		case DIX   : strcat(stringss,"10");break;
		case ROI   : strcat(stringss,"K");break;
		case DAME  : strcat(stringss,"Q");break;
		case HUIT  : strcat(stringss,"8");break;
		case SEPT  : strcat(stringss,"7");break;
		default  : std::cout<<"error carte";break;
	}
	switch (couleur)
	{
		case COEUR : strcat(stringss,"H");break;
		case CARREAU : strcat(stringss,"D");break;
		case PIQUE  : strcat(stringss,"S");break;
		case TREFLE : strcat(stringss,"C");break;
		default  : std::cout<<"error carte";break;
	}
	return stringss;
}

bool Carte:: equals(Carte obj)
	{
		if (this == &obj) return true;
		if (couleur != obj.couleur) return false;
		if (valeur != obj.valeur) return false;
		return true;
	}

Carte::~Carte(void)
{
}
