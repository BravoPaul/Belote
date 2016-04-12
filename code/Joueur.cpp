
#include "Joueur.h"
#include "JoueurIA.h"
#include <typeinfo>
#include <iostream>

Joueur::Joueur(){}


void Joueur:: inniCarteEnmain(Carte carte)
{
	m_main.push_back(carte);
}

std::string Joueur:: getNom()
{
    return m_nom;
}


int Joueur:: getNumero()
{
    return m_numero;
}

std::vector<Carte> Joueur:: getCarteEnMain()
{
	return m_main;
}

bool Joueur:: isContra() const
{
	return contra;
}

void Joueur:: setContra(bool contra)
{
	this->contra = contra;
}

void Joueur:: setPoint(int num)
{
    point = num;
}

int Joueur:: getPoint()
{
    return point;
}

void Joueur:: setPointGagne(int num)
{
    pointGagne = num;
}

int Joueur:: getPointGagne()
{
    return pointGagne;
}



std::vector<Carte> Joueur:: convient(std::vector<Carte>avantCarte,Couleur atout)
{
	std::vector<Carte> cartesordi;
	if(avantCarte.size()==0)
		cartesordi = m_main;
	else
	{
	Carte cartePremier = avantCarte[0];
	if(cartePremier.getCouleur()==atout)
		{
			int flag1 = 0;
			for(int i = 0;i<m_main.size();i++)
			{
				Carte carte = m_main[i];
				int flag2 = 1;
				for(int j = 0;j<avantCarte.size();j++)
				{
					Carte carteavant = avantCarte[j];
					if(!carte.isSuperieur(carteavant,atout,atout))
					{
						flag2 = 0;
						break;
					}
				}
				if(flag2==1)
				{
					cartesordi.push_back(carte);
					flag1=1;
				}

			}
			if(flag1==0)
			{
				cartesordi = m_main;
			}
		}

		else if(cartePremier.getCouleur()!=atout)
		{
			int flag1 = 0;
			for(int i = 0;i<m_main.size();i++)
			{
				Carte carte = m_main[i];
				if(carte.getCouleur()==cartePremier.getCouleur())
				{
					cartesordi.push_back(carte);
					flag1 = 1;
				}
			}
			if(flag1==0)
			{
				cartesordi=m_main;
			}
		}
	}
	return cartesordi;
}

