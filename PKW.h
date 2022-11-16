/*
 * PKW.h
 *
 *  Created on: 06.11.2022
 *      Author: root
 */

#ifndef PKW_H_
#define PKW_H_

extern double dGlobalzeit;

#include "Fahrzeug.h"

class PKW : public Fahrzeug {
private:
	double p_dVerbrauch = 0.0;	//liter/100km
	double p_dTankvolumen = 0.0;
	double p_dTankinhalt = 0.0;	//liter

public:
	PKW();
	PKW(const string sName);
	PKW(const string sName, const double dVMax,
		const double dVerbrauch, const double dTankvolumen = 55);

	double dTanken() override;
	double dTanken(double dMenge) override;

	void vSimulieren() override;

	void vAusgeben(ostream&) const override;

	double dGeschwindigkeit() const override;

	void operator=(const PKW& pkw);

	void vZeichnen(const Weg&) const override;
};

#endif /* PKW_H_ */
