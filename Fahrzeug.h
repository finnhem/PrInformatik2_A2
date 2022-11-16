/*
 * Fahrzeug.h
 *
 *  Created on: 15.10.2022
 *      Author: root
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

extern double dGlobaleZeit; //Gibt an wie viele Stunden Fahrzeuge simuliert werden muessen

#include "Simulationsobjekt.h"
#include "Verhalten.h"
class Weg;

class Fahrzeug : public Simulationsobjekt {
public:
	Fahrzeug();
	Fahrzeug(const string sName);
	Fahrzeug(const string sName, const double dMaxV);
	Fahrzeug(const Fahrzeug&) = delete;
	static void vKopf();
	virtual void vAusgeben(ostream&) const override;
	virtual ~Fahrzeug();

	virtual void vSimulieren() override;

	virtual double dTanken();
	virtual double dTanken(double dMenge);

	virtual double dGeschwindigkeit() const;

	int getID();
	string getName();

	bool operator<(const Fahrzeug& fahrzeug) const;

	virtual void operator=(const Fahrzeug& fahrzeug);

	void vNeueStrecke(Weg&);
	void vNeueStrecke(Weg&, double);

	double getAbschnittStrecke() const;

	virtual void vZeichnen(const Weg&) const;

protected:
	double p_dMaxGeschwindigkeit = 0;
	double p_dGesamtStrecke = 0;
	double p_dGesamtFahrZeit = 0;
	unique_ptr<Verhalten> p_pVerhalten = nullptr;

private:
	double p_dAbschnittStrecke = 0.0;
};


#endif /* FAHRZEUG_H_ */
