/*
 * Verhalten.cpp
 *
 *  Created on: 14.11.2022
 *      Author: root
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"


Verhalten::Verhalten(Weg& weg) : currentWay(weg)
{
}


Verhalten::~Verhalten() {
	cout << "Verhalten wurde dekonstruiert######################" << endl;
}




double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall)
{
	double dMoeglich = aFzg.dGeschwindigkeit()*dZeitIntervall;

	//Weg ist laenger als Strecke im Zeitintervall
	if(aFzg.getAbschnittStrecke() + dMoeglich < currentWay.getLaenge())
	{
		return dMoeglich;
	} else if (aFzg.getAbschnittStrecke()==this->currentWay.getLaenge()){
		cout << "Fahrzeug bereits am Weg ende." << endl;
		return 0;
	}else {		//sonst Reststrecke
		return this->currentWay.getLaenge() - aFzg.getAbschnittStrecke();
	}
}
