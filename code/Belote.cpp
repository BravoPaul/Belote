
#include <iostream>
#include "Belote.h"
#include "Couleur.h"
#include "Valeur.h"
#include "PaquetCartes.h"
#include <random>
#include <string>
#include <time.h>
#include <stdio.h>
#include <sstream>


Belote:: Belote (): xmlBelote("Game")
{
    contraPoint = 80;
}

void Belote:: addJoueur(int mode)
{
	if(mode==1)
	{
		for(int i = 0;i<4;i++)
		{
		    Joueur *joueur = new JoueurIA(i+1);
			joueurs.push_back(joueur);
		}
	}
	if(mode==2)
	{
		for(int i = 0;i<3;i++)
		{
		    Joueur *joueur = new JoueurIA(i+1);
			joueurs.push_back(joueur);
		}
		Joueur *joueur = new JoueurHumain(4);
        joueurs.push_back(joueur);
	}

    std::cout<<"**************************\n";
	std::cout<<"Les joueursIA a ete ajoute\n";
    //std::cout<<joueurs.size();

    // Another element, with attributes
    TiXmlElement team1 ( "Team" );
    team1.SetAttribute("name","NS");
    team1.SetAttribute("score",0);

    TiXmlElement team2 ( "Team" );
    team2.SetAttribute("name","EW");
    team2.SetAttribute("score",0);

    TiXmlElement player1 ( "Player" );
    player1.SetAttribute("name",const_cast<char*>(joueurs[0]->getNom().c_str()));
    // This is how you "attach" a (child) element to its (parent) element at its end
    team1.InsertEndChild( player1 );

    TiXmlElement player2 ( "Player" );
    player2.SetAttribute("name",const_cast<char*>(joueurs[1]->getNom().c_str()));
    team1.InsertEndChild( player2 );

    TiXmlElement player3 ( "Player" );
    player3.SetAttribute("name",const_cast<char*>(joueurs[2]->getNom().c_str()));
    team2.InsertEndChild( player3 );

    TiXmlElement player4 ( "Player" );
    player4.SetAttribute("name",const_cast<char*>(joueurs[3]->getNom().c_str()));
    team2.InsertEndChild( player4 );

    // Insert the teams now that they are complete
    xmlBelote.InsertEndChild( team1 );
    xmlBelote.InsertEndChild( team2 );


}

TiXmlElement Belote:: start(int mode)
{
	//4 AI joue au jeu
	addJoueur(mode);
	jouer();
    return xmlBelote;
}

void Belote::jouer()
{
    std::vector<TiXmlElement*> hands;
    int num = 0;
	while(1)
	{

		if(joueurs[0]->getPointGagne()+joueurs[2]->getPointGagne()>1000)
		{
			std::cout<<joueurs[0]->getNom()+" et "+joueurs[2]->getNom()+"ont gagne !"+"\n"+"ils ont obtenue";
			int point =  joueurs[0]->getPointGagne()+joueurs[2]->getPointGagne();
			cout<<point;
			break;
		}
		else if(joueurs[1]->getPointGagne()+joueurs[3]->getPointGagne()>1000)
		{
			std::cout<<joueurs[1]->getNom()+" et "+joueurs[3]->getNom()+" ont gagne !"+"\n"+"ils ont obtenue";
			int point = joueurs[1]->getPointGagne()+joueurs[3]->getPointGagne();
			cout<<point;
			break;
		}
		else
		{
            std::cout<<"**********************************\n";
		    std::cout<<"ils vont jouer une partie\n";
		    TiXmlElement *hand  = new TiXmlElement( "Hand");
            hand->SetAttribute("num",num+1);
            hand->SetAttribute("dealer",const_cast<char*>(joueurs[0]->getNom().c_str()));
            hand->SetAttribute("currentTrick",0);
            hand->SetAttribute("nextPlayer",const_cast<char*>(joueurs[1]->getNom().c_str()));
			distribuerCarte();
			enchere(hand);
			Carte carteTTT(VALET,atout);
			hand->SetAttribute("trump",carteTTT.getCouleur2());
            hands.push_back(hand);
			for(int i = 0;i<8;i++)
			{
                std::cout<<"*******************************\n";
			    std::cout<<"le piece commence\n";
				jouerUnePartie(hand);

			}
            changePoint();
		}
		num++;
	}
	for(int i = 0;i<hands.size();i++)
    {
        xmlBelote.InsertEndChild(*hands[i]);
    }
}

void Belote:: changePoint()
{
    for(int i = 0;i<joueurs.size();i++)
    {
        if(joueurs[i]->isContra())
        {

            if(joueurs[i]->getPoint()+joueurs[(i+2)%4]->getPoint()>contraPoint)
            {
                joueurs[i]->setPointGagne(joueurs[i]->getPointGagne()+contraPoint);
                //std::cout<<joueurs[i]->getNom()<<"xiao zu point"<<joueurs[i]->getPointGagne();
                break;
            }
            else
            {
                joueurs[i+1]->setPointGagne(joueurs[i+1]->getPointGagne()+contraPoint);
                break;
            }
        }
    }
    for(int i = 0;i<joueurs.size();i++)
    {
        joueurs[i]->setPoint(0);
        joueurs[i]->setContra(true);
    }
}

void Belote::jouerUnePartie(TiXmlElement* hand)
{
    std::vector<TiXmlElement> sorxml;
	for(int i = sortirNum;i<4+sortirNum;i++)
	{
	    std::cin.get();
	    Carte carte = joueurs[i%4]->sortirCarte(carteEnTable,atout);
		carteEnTable.push_back(carte);
		table.push_back(joueurs[i%4]);
        TiXmlElement card1 ( "Card" );
        card1.SetAttribute("id",carte.toString2());
        card1.SetAttribute("player",const_cast<char*>(joueurs[i%4]->getNom().c_str()));
        card1.SetAttribute("status","played");
        sorxml.push_back(card1);
        //card1.SetAttribute("winner","");
        //hand->InsertEndChild( card1 );
	}
	gagneJoueur();
	for(int j = 0;j<sorxml.size();j++)
    {
        sorxml[j].SetAttribute("winner",const_cast<char*>(joueurs[(sortirNum+3)%4]->getNom().c_str()));
        hand->InsertEndChild(sorxml[j]);
    }
}



void Belote::gagneJoueur()
{
	Carte carteSordiMax = carteEnTable[0];
	Carte premierCarte = carteEnTable[0];
	int total  =  carteEnTable.size();
	for(int i = 0;i<total;i++)
	{
		Carte carte = carteEnTable[i];
		if(!carteSordiMax.isSuperieur(carte,atout,premierCarte.getCouleur()))
		{
			carteSordiMax = carte;
		}
	}
	int point = 0;
	for(int i = 0;i<total;i++)
	{
		Carte carte = carteEnTable[i];
		point = carte.getOrdre(atout)+point;
	}
	for(int i = 0;i<4;i++)
    {
        if(carteEnTable[i].equals(carteSordiMax))
        {
            int pointTotal = table[i]->getPoint()+point;
            table[i]->setPoint(pointTotal);
            std::cout<<table[i]->getNom()<<"a gagne ce piece\n";
            std::cout<<"il a gagne "<<table[i]->getPoint()<<"piont\n";
            sortirNum = table[i]->getNumero()-1;
            break;
        }
    }
	table.clear();
	carteEnTable.clear();
}


void Belote::enchere(TiXmlElement *hand)
{
	std::cout << " team 1 a point: " <<joueurs[0]->getPointGagne()+joueurs[2]->getPointGagne()<<endl;
	std::cout << " team 2 a point: " <<joueurs[0]->getPointGagne()+joueurs[2]->getPointGagne()<<endl;
    srand((unsigned)time(0));
	int haha = rand()%4;
	Couleur couleur;
	switch(haha)
	{
	case 0:
		couleur = CARREAU;
		break;
	case 1:
		couleur = COEUR;
		break;

	case 2:
		couleur = PIQUE;
		break;
	case 3:
		couleur = TREFLE;
		break;

	}
	Carte carte(VALET,couleur);
	atout = couleur;
	std::cout<<"Le couleur atout est "<<carte.toString() <<"\n"<<endl;
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<8;j++)
		{
			if(joueurs[i]->getCarteEnMain()[j].equals(carte))
			{
				atout = couleur;
				joueurs[i]->setContra(true);
				joueurs[(i+2)%4]->setContra(true);
				sortirNum = (i+1)%4;
				std::cout<<joueurs[i]->getNom()<<"demande enchere\n";
				break;
			}
		}
	}
	TiXmlElement bid1( "Bid" );
    bid1.SetAttribute("num",1);
    bid1.SetAttribute("player",const_cast<char*>(joueurs[(sortirNum+3)%4]->getNom().c_str()));
    bid1.SetAttribute("value",80);
    Carte carteT(VALET,atout);
    bid1.SetAttribute("suit",carteT.getCouleur2());
    hand->InsertEndChild( bid1 );
	int flag = 0;
	int num = 1;
	while(true)
    {
        for(int i = 0;i<3;i++)
        {
            num++;
            std::cin.get();
            Carte carte = joueurs[(sortirNum+i)%4]->demandeContra(contraPoint);
            if(carte.getValeur()==HUIT)
            {
                flag =1;
                atout = carte.getCouleur();
                for(int j = 0;j<joueurs.size();j++)
                {
                    joueurs[(sortirNum+j)%4]->setContra(false);
                }
                joueurs[(sortirNum+i)%4]->setContra(true);
                joueurs[(sortirNum+2+i)%4]->setContra(true);
                sortirNum = (sortirNum+i+1)%4;
                contraPoint = contraPoint+10;
                std::cout<<joueurs[(sortirNum+3)%4]->getNom()<<" enchere\n";
                std::cout<<joueurs[(sortirNum+i)%4]->getNom()<<"demande enchere\n"<<" "<< contraPoint<<endl;
                TiXmlElement bid1 ( "Bid" );
                bid1.SetAttribute("num",num);
                bid1.SetAttribute("player",const_cast<char*>(joueurs[(sortirNum+3)%4]->getNom().c_str()));
                bid1.SetAttribute("value",contraPoint);
                Carte carteT2(VALET,atout);
                bid1.SetAttribute("suit",carteT2.getCouleur2());
                hand->InsertEndChild( bid1 );
                break;
            }
            else
            {
                TiXmlElement bid1 ( "Bid" );
                bid1.SetAttribute("num",num);
                bid1.SetAttribute("player",const_cast<char*>(joueurs[(sortirNum+i)%4]->getNom().c_str()));
                bid1.SetAttribute("value",0);
                bid1.SetAttribute("suit","C");
                hand->InsertEndChild( bid1 );
            }
        }
        if(flag==0)
            break;
        flag = 0;
    }

    std::cout<<"Le ContraPoint est: "<<contraPoint<<"\n";
}



void Belote:: distribuerCarte()
{

	for(int j = 0;j<8;j++)
	{
		joueurs[0]->inniCarteEnmain(paquet.getPaquet()[j]);
	}
	for(int j = 8;j<16;j++)
	{
		joueurs[1]->inniCarteEnmain(paquet.getPaquet()[j]);
	}
	for(int j = 16;j<24;j++)
	{
		joueurs[2]->inniCarteEnmain(paquet.getPaquet()[j]);
	}
	for(int j = 24;j<32;j++)
	{
		joueurs[3]->inniCarteEnmain(paquet.getPaquet()[j]);
	}

	std::cout<<"Les cartes a ete distritue\n";
	for(int j = 0;j<4;j++)
    {
        std::cout<< joueurs[j]->getNom()<<endl;
        for(int i = 0;i<8;i++)
        {
        std::cout<<"ses cartes:  "<<joueurs[j]->getCarteEnMain()[i].toString()<<"\n";
        }


    }

}

	/**
	 * Fait un tour de table pour demander a chaque joueur de mettre
	 * une carte, en commencant par le joueur indique en parametre
	 */
