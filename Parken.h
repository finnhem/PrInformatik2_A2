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
	Parken(Weg&, double startzeit = 0);
	virtual ~Parken();

	double dStrecke(Fahrzeug&, double startzeit) override;
	double getStartzeit() const override;

private:
	double p_dStartzeit;
};

#endif /* PARKEN_H_ */
