
#include "Carte.h"
#include <vector>
#ifndef JOUEUR_H_
#define JOUEUR_H_


class Joueur
{
protected:
	int m_numero;
	std::string m_nom;
	bool contra;
	int point;
    std::vector<Carte> m_main;
    int pointGagne;

public:
	Joueur(std::string nom, int numero);
	Joueur();
	int getNumero();
	std::string getNom();
	std::vector<Carte> getCartesGagnees();
	std::vector<Carte> getCarteEnMain();
	bool possedeCouleurEnMain(Couleur couleur);
    virtual Carte sortirCarte(std::vector<Carte> carteAvant,Couleur atout)=0;
    virtual Carte demandeContra(int contraPoint)=0;
	std::vector<Carte> convient(std::vector<Carte> carteAvant,Couleur atout);
	void inniCarteEnmain(Carte carte);
	bool isContra() const;
	void setContra(bool contra);
	Carte getCarteSortie();


    void setPointGagne(int num);
    int getPointGagne();


	int getPoint();

	void setPoint(int point);
};

#endif /* JOUEUR_H_ */
