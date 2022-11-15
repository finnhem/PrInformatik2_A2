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

class Verhalten {
public:
	Verhalten(Weg&);
	virtual ~Verhalten();

	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall);

private:
	Weg& currentWay;
};

#endif /* VERHALTEN_H_ */
