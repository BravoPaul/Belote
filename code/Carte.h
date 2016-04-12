
#ifndef CARTE_H_
#define CARTE_H_
#include "Couleur.h"
#include "Valeur.h"
#include <string>

class Carte
{
private:
	Couleur couleur;
	Valeur valeur;
public:
	Couleur getCouleur();
	Valeur getValeur();
	int getValeur(Couleur atout);
	int getOrdre(Couleur atout);
	bool isSuperieur(Carte carte, Couleur atout, Couleur couleurPli);
	std::string toString();
	bool equals(Carte obj);
	char* toString2();
	char* getCouleur2();
	Carte(Valeur val,Couleur coul);
	Carte();
	void setCouleur(Couleur couleur);
	void setValeur(Valeur valeur);
	~Carte(void);
};

#endif /* CARTE_H_ */
