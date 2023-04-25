/*
 * Verhalten.h
 *
 *  Created on: 14.11.2022
 *      Author: root
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

class Weg;
class Fahrzeug;
extern double dGlobaleZeit;

class Verhalten {
public:
	Verhalten(Weg& weg);
	virtual ~Verhalten();

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
	virtual double getStartzeit() const;

	Weg& getWeg();

protected:
	Weg& currentWay;
};

#endif /* VERHALTEN_H_ */
