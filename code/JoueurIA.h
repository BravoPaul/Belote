/*
 * JoueurIA.h
 *
 *  Created on: 2016Äê2ÔÂ2ÈÕ
 *      Author: paul
 */

#ifndef JOUEURIA_H_
#define JOUEURIA_H_
#include "Joueur.h"

class JoueurIA :public Joueur
{

public:
	JoueurIA(int nu);
	JoueurIA();
	Carte demandeContra(int contraPoint);
	Carte sortirCarte(std::vector<Carte> carteAvant,Couleur atout);
	Carte sss();
};

#endif /* JOUEURIA_H_ */
