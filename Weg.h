/*
 * Weg.h
 *
 *  Created on: 11.11.2022
 *      Author: root
 */

#ifndef WEG_H_
#define WEG_H_

#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Fahrzeug.h"

#include <list>

#include "vertagt_liste.h"

class Fahrzeug;


class Weg : public Simulationsobjekt {

public:
	Weg();
	Weg(string sName, double dLaenge, Tempolimit tempolimit = autobahn);
	virtual ~Weg();
	double getTempolimit();

	void vSimulieren() override;

	static void vKopf();
	void vAusgeben(ostream&) const override;

	double getLaenge() const;
	void vAnnahme(unique_ptr<Fahrzeug>);
	void vAnnahme(unique_ptr<Fahrzeug>, double);

	string getName() const;

	unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug&);

private:
	double p_dLaenge = 0.0;
	Tempolimit p_eTempolimit;
	//list<unique_ptr<Fahrzeug> > p_pFahrzeuge;
	vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;
};

#endif /* WEG_H_ */
