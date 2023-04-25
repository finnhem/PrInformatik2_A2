/*
 * Losfahren.h
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {
public:
	Losfahren(Fahrzeug&, Weg&);
	virtual ~Losfahren();
	void vBearbeiten() override;
};

#endif /* LOSFAHREN_H_ */
