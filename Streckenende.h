/*
 * Streckenende.h
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende :public Fahrausnahme {
public:
	Streckenende(Fahrzeug&, Weg&);
	virtual ~Streckenende();

	void vBearbeiten() override;
};

#endif /* STRECKENENDE_H_ */
