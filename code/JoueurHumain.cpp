#include "JoueurHumain.h"

#include "Belote.h"



JoueurHumain:: JoueurHumain(int numero):Joueur()
{
    m_nom = "Humain";
    m_numero = numero;
    point = 0;
    pointGagne = 0;
    contra = false;
}

Carte JoueurHumain:: demandeContra(int contraPoint)
{
    Carte carte;
    std::cout<<"est ce que vous voulez encherer? si, tapez 1. sinon tapez 2 \n";
    int encherePas;
    std::cin>>encherePas;
    if(encherePas==1)
    {
        std::cout<<"Choisir le couleur : 1 COEUR 2 PIQUE 3 CARREAU 4 TREFFLE\n";
        int couleurInt;
        cin>>couleurInt;
        if(couleurInt==1)
        {
            carte.setCouleur(COEUR);
            carte.setValeur(HUIT);
        }
        else if(couleurInt==2)
        {
            carte.setCouleur(PIQUE);
            carte.setValeur(HUIT);
        }
        else if(couleurInt==3)
        {
            carte.setCouleur(CARREAU);
            carte.setValeur(HUIT);
        }
        else if(couleurInt==4)
        {
            carte.setCouleur(TREFLE);
            carte.setValeur(HUIT);
        }
        else
            {
                std::cout<<"error couleur";
                carte.setCouleur(COEUR);
                carte.setValeur(SEPT);
            }
    }
    else
    {
        carte.setCouleur(COEUR);
        carte.setValeur(SEPT);
    }
    return carte;
}

Carte JoueurHumain:: sortirCarte(std::vector<Carte> carteAvant,Couleur atout)
{
	Carte sortCarte;
	std::vector<Carte> carteConvient = convient(carteAvant,atout);
	std::cout<<"Les cartes que vous avez sont:\n ";
	for(int i=0;i<m_main.size();i++)
    {
        std::cout<<m_main[i].toString()<<"  ";
    }
	std::cout<<"Les cartes que vous pouvez sortir sont:\n ";
	for(int i=0;i<carteConvient.size();i++)
    {
        std::cout<<carteConvient[i].toString()<<"  ";
    }

    std::cout<<"Choisissez un carte a sortir:\n ";

    while(true)
    {
        int sortnum;
        cin>>sortnum;
        if(sortnum<=carteConvient.size())
        {
            sortCarte = carteConvient[sortnum-1];
            break;
        }
        else
        {
            std::cout<<"error input";
        }

    }
   // std::cout<<this->m_nom<<"sort"<<carteConvient[0].toString()<<"\n";
    std::cout<<this->m_nom<<" sort "<<sortCarte.toString()<<"\n";
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

	return sortCarte;

}
