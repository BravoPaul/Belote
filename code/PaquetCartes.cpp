
#include "PaquetCartes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>

PaquetCartes::PaquetCartes(void)
{
	for(int i = 0;i<8;i++)
	{
		Valeur val;
		Couleur coul;
		switch(i+1)
		{
			case 1:
				val = AS;
				break;
			case 2:
				val = DAME;
				break;
			case 3:
				val = DIX;
				break;
			case 4:
				val = HUIT;
				break;
			case 5:
				val = NEUF;
				break;
			case 6:
				val = ROI;
				break;
			case 7:
				val = SEPT;
				break;
			case 8:
				val = VALET;
				break;

		}
		for(int j = 0;j<4;j++)
		{
			switch(j+1)
			{
				case 1:
					coul = CARREAU ;
					break;
				case 2:
					coul = COEUR;
					break;
				case 3:
					coul = PIQUE;
					break;
				case 4:
					coul = TREFLE;
					break;
			}
			paquet.push_back(Carte(val,coul));
		}
	}
	std::random_shuffle(paquet.begin(),paquet.end());
}

std::vector<Carte> PaquetCartes:: getPaquet()
{
	return paquet;
}

PaquetCartes::~PaquetCartes(void)
{
}
