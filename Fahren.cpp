/*
 * Fahren.cpp
 *
 *  Created on: 15.11.2022
 *      Author: Hemsteg
 */

#include "Fahren.h"
#include "Streckenende.h"

Fahren::Fahren(Weg& weg) : Verhalten(weg)
{
}


Fahren::~Fahren()
{
}


//Returns gefahrene Strecke
double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	double dMoeglich = aFzg.dGeschwindigkeit()*dZeitIntervall;	//Moegliche Strecke

	//Weg ist laenger als moegliche Strecke im Zeitintervall
	if(aFzg.getAbschnittStrecke() + dMoeglich < currentWay.getLaenge())
	{
		return dMoeglich;
	} else if (aFzg.getAbschnittStrecke()==this->currentWay.getLaenge()){

		cout << "Fahrzeug #" << aFzg.getID() << " bereits am Weg ende." << endl;
		throw Streckenende(aFzg, currentWay);	//Throw Exception
		return 0;
	}
	//sonst Reststrecke
	return this->currentWay.getLaenge() - aFzg.getAbschnittStrecke();
}
