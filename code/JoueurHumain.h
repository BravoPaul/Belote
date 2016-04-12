#ifndef JOUEURHUMAIN_H
#define JOUEURHUMAIN_H
#include "Joueur.h"


class JoueurHumain:public Joueur
{

public:
	JoueurHumain(int nu);
	JoueurHumain();
	Carte demandeContra(int contraPoint);
	Carte sortirCarte(std::vector<Carte> carteAvant,Couleur atout);
};

#endif // JOUEURHUMAIN_H
