/*
 * Fahrrad.h
 *
 *  Created on: 06.11.2022
 *      Author: root
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad: public Fahrzeug {
public:
	Fahrrad();
	Fahrrad(const string sName);
	Fahrrad(const string sName, const double dVMax);
	double dGeschwindigkeit() const override;


	void vAusgeben(ostream&) const override;

	void vZeichnen(const Weg&) const override;
};

#endif /* FAHRRAD_H_ */
