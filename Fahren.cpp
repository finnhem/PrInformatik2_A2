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
	// TODO Auto-generated constructor stub

}

Fahren::~Fahren()
{
	// TODO Auto-generated destructor stub
}


double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	double dMoeglich = aFzg.dGeschwindigkeit()*dZeitIntervall;

	//Weg ist laenger als Strecke im Zeitintervall
	if(aFzg.getAbschnittStrecke() + dMoeglich < currentWay.getLaenge())
	{
		return dMoeglich;
	} else if (aFzg.getAbschnittStrecke()==this->currentWay.getLaenge()){

		cout << "Fahrzeug #" << aFzg.getID() << " bereits am Weg ende." << endl;
		throw Streckenende(aFzg, currentWay);
		return 0;
	}
	//sonst Reststrecke
	return this->currentWay.getLaenge() - aFzg.getAbschnittStrecke();
}
