/*
 * PaquetCartes.h
 *
 *  Created on: 2016Äê2ÔÂ2ÈÕ
 *      Author: paul
 */
#include "Carte.h"
#include <stdio.h>
#include<stdlib.h>
#include<vector>
#ifndef PAQUETCARTES_H_
#define PAQUETCARTES_H_

class PaquetCartes
{
private:
	 std::vector<Carte> paquet;

public:
	PaquetCartes(void);
    std::vector<Carte> getPaquet();
	~PaquetCartes(void);
};

#endif /* PAQUETCARTES_H_ */
