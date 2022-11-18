/*
 * Parken.cpp
 *
 *  Created on: 15.11.2022
 *      Author: Hemsteg
 */

#include "Parken.h"
#include "Losfahren.h"

//extern double dGlobaleZeit;

Parken::Parken(Weg& weg, double startzeit) : Verhalten(weg), p_dStartzeit(startzeit)
{
	// TODO Auto-generated constructor stub

}

Parken::~Parken()
{
	// TODO Auto-generated destructor stub
}


double Parken::getStartzeit() const
{
	return this->p_dStartzeit;
}


double Parken::dStrecke(Fahrzeug &aFzg, double startzeit)
{
	if (dGlobaleZeit - this->p_dStartzeit < 0.1)
	{
		return 0.0;
	} else {
		throw Losfahren(aFzg, currentWay);
	}
	cout << "Startzeit wurde erreicht." << endl;

	/*double dZeitIntervall = dGlobaleZeit - this->p_dStartzeit;
	double dMoeglich = aFzg.dGeschwindigkeit()*(dZeitIntervall);

	//Weg ist laenger als Strecke im Zeitintervall
	if(aFzg.getAbschnittStrecke() + dMoeglich < currentWay.getLaenge())
	{
		return dMoeglich;
	} else if (aFzg.getAbschnittStrecke()==this->currentWay.getLaenge()){

		cout << "Fahrzeug #" << aFzg.getID() << " bereits am Weg ende." << endl;
		return 0;
	}else {		//sonst Reststrecke
	return this->currentWay.getLaenge() - aFzg.getAbschnittStrecke();
	}*/
}
