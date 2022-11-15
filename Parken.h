/*
 * Parken.h
 *
 *  Created on: 15.11.2022
 *      Author: Hemsteg
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"
#include "Fahren.h"

class Parken : public Verhalten
{
public:
	Parken(Weg&, double startzeit);
	virtual ~Parken();

	double dStrecke(Fahrzeug&, double startzeit) override;
	double getStartzeit();

private:
	double p_dStartzeit;
};

#endif /* PARKEN_H_ */
