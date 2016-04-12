
#include "JoueurIA.h"
#include "Belote.h"
#include <random>
#include <time.h>

JoueurIA:: JoueurIA(int numero):Joueur()
{
    if(numero==1)
    {
        m_nom = "ROBOT1";
    }
    else if(numero==2)
    {
        m_nom = "ROBOT2";
    }
    else if(numero==3)
    {
        m_nom = "ROBOT3";
    }
    else if(numero==4)
    {
        m_nom = "ROBOT4";
    }

    m_numero = numero;
    point = 0;
    pointGagne = 0;
    contra = false;
}


JoueurIA:: JoueurIA()
{


}

Carte JoueurIA:: demandeContra(int contraPoint)
{
    Carte cartee;
    srand((unsigned)time(0));
	int haha = rand()%161;
	if(haha>contraPoint)
    {
        Couleur couleuraa;
        int nombreCoeur = 0;
        int nombrePique = 0;
        int nombreTreffle = 0;
        int nombreCarreua = 0;
        int nombre = 0;
        for(int i=0;i<m_main.size();i++)
        {
            if(m_main[i].getCouleur()==COEUR)
                nombreCoeur++;
            else if(m_main[i].getCouleur()==CARREAU)
                nombreCarreua++;
            else if(m_main[i].getCouleur()==TREFLE)
                nombreTreffle++;
            else if(m_main[i].getCouleur()==PIQUE)
                nombrePique++;
            else
                std::cout<<"shen me diao pai";
            nombre = nombreCarreua;
            couleuraa = CARREAU;
            if(nombreCoeur>nombre)
            {
                nombre = nombreCoeur;
                couleuraa = COEUR;
            }

            if(nombreTreffle>nombre)
            {
                nombre = nombreTreffle;
                couleuraa = TREFLE;
            }

            if(nombrePique>nombre)
            {
                nombre = nombrePique;
                couleuraa = PIQUE;
            }

        }
        cartee.setValeur(HUIT);
        cartee.setCouleur(couleuraa);
    }
    else
    {
        cartee.setValeur(SEPT);
        cartee.setCouleur(COEUR);
    }
    return cartee;

}

Carte JoueurIA:: sortirCarte(std::vector<Carte> carteAvant,Couleur atout)
{
	Carte sortCarte;
	std::vector<Carte> carteConvient = convient(carteAvant,atout);

	for(int i = 0;i<carteConvient.size();i++)
    {
        std::cout<<"carte qui peut sortir: "<<carteConvient[i].toString()<<" \n";
    }

	if(carteAvant.size()!=0)
	{
		Carte carteSordiMax = carteConvient[0];
		Carte premierCarte = carteAvant[0];
		for(int i = 0;i<carteConvient.size();i++)
		{
			Carte carte = carteConvient[i];
			if(!carteSordiMax.isSuperieur(carte,atout,premierCarte.getCouleur()))
			{
				carteSordiMax = carte;
			}
		}
	
		Carte maxCarte = carteAvant[0];
		for(int i = 0;i<carteAvant.size();i++)
		{
			Carte carte = carteAvant[i];
			if(!maxCarte.isSuperieur(carte,atout,premierCarte.getCouleur()))
			{
				maxCarte = carte;
			}
		}
		if(carteAvant.size()>2)
        {
            if(!maxCarte.equals(carteAvant[carteAvant.size()-2])&&!carteSordiMax.isSuperieur(maxCarte,atout,premierCarte.getCouleur()))
            {
                Carte carteSordiMin = carteConvient[0];
                for(int i = 0;i<carteConvient.size();i++)
                {
                    Carte carte = carteConvient[i];
                    if(carteSordiMin.isSuperieur(carte,atout,premierCarte.getCouleur()))
                    {
                        carteSordiMin = carte;
                    }
                }
                sortCarte = carteSordiMin;
            }
            else
            {
                sortCarte = carteSordiMax;
            }

        }

		else
		{
			sortCarte = carteSordiMax;
		}
	}
	else
	{
		sortCarte = carteConvient[0];
	}
   // std::cout<<this->m_nom<<"sort"<<carteConvient[0].toString()<<"\n";
    std::cout<<this->m_nom<<" sort "<<sortCarte.toString()<<"\n";
    Carte carteVraiSort(sortCarte.getValeur(),sortCarte.getCouleur());
     for(vector<Carte>::iterator it=m_main.begin(); it!=m_main.end(); )
     {
        if((*it).equals(sortCarte) )
        {
            it = m_main.erase(it);
        }
        else
        {
            ++it;
        }
     }

	return carteVraiSort;

}

