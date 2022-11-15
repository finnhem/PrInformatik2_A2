/*
 * Simulationsobjekt.h
 *
 *  Created on: 11.11.2022
 *      Author: root
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <list>

using namespace std;

extern double dGlobaleZeit;


class Simulationsobjekt {
private:
	static inline int p_iMaxID = 0;

protected:
	string p_sName = "";
	const int p_iID = p_iMaxID++;	//Aendert sich nicht mehr nach Konstruktion
	double p_dZeit = 0;

public:
	Simulationsobjekt();
	Simulationsobjekt(const string sName);
	Simulationsobjekt(const Simulationsobjekt&) = delete;
	virtual ~Simulationsobjekt();
	virtual void vAusgeben(ostream& o) const;
	virtual void vSimulieren() = 0;

	virtual void operator = (const Simulationsobjekt&);
	virtual bool operator == (const Simulationsobjekt&);



};

ostream& operator<<(ostream& o, const Simulationsobjekt& simulationsobjekt);
//Warum außerhalb der Klasse?
//damit der Outputstream global fuer Fahrzeuge ueberladen wird.

//Warum reicht die eine Definition fuer alle abgeleiteten Klassen aus?
//


#endif /* SIMULATIONSOBJEKT_H_ */
