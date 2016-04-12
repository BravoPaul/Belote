

#ifndef BELOTE_H_
#define BELOTE_H_

#include "Couleur.h"
#include "Valeur.h"
#include "Carte.h"
#include "PaquetCartes.h"
#include "Joueur.h"
#include "JoueurIA.h"
#include "JoueurHumain.h"
#include <vector>
#include <map>
#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

class Belote
{
public:
	std::vector<Joueur*> joueurs;
    PaquetCartes paquet;
	Couleur atout;
	Couleur couleurPli;
	std::vector<Carte> carteEnTable;
	std::vector<Joueur*> table;
	int sortirNum;
	int contraPoint;
   // std::vector<int> point;
    TiXmlElement xmlBelote;

public:


	void addJoueur(int mode);
	void enchere(TiXmlElement *hand);
    void distribuerCarte();
	TiXmlElement start(int mode);
	void gagneJoueur();
	void jouerUnePartie(TiXmlElement *hand);
	void jouer();
    void changePoint();
	Belote(void);
};

#endif /* BELOTE_H_ */
