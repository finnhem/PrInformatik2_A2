/*
 * Fahren.h
 *
 *  Created on: 15.11.2022
 *      Author: Hemsteg
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

class Fahren : public Verhalten
{
public:
	Fahren(Weg&);
	virtual ~Fahren();
	double dStrecke(Fahrzeug&, double) override;
};

#endif /* FAHREN_H_ */
