/*
 * PKW.cpp
 *
 *  Created on: 06.11.2022
 *      Author: root
 */

#include "PKW.h"


PKW::PKW() : Fahrzeug()
{

}


PKW::PKW(const string sName) : Fahrzeug(sName)
{

}


PKW::PKW(const string sName, const double dVMax, const double dVerbrauch, const double dTankvolumen) :
		Fahrzeug(sName, dVMax), p_dVerbrauch(dVerbrauch),
		p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen/2)
{
}

double PKW::dTanken() {
	double dGetankt = p_dTankvolumen - p_dTankinhalt;
	p_dTankinhalt = p_dTankvolumen;

	return dGetankt;
}

double PKW::dTanken(double dMenge)
{
	double dGetankt;

	if (p_dTankvolumen - p_dTankinhalt > dMenge)
	{
		dGetankt = dMenge;
		p_dTankinhalt += dMenge;
	} else {
		dGetankt = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
	}

	return dGetankt;
}


void PKW::vSimulieren()
{
	if (p_dTankinhalt > 0)
	{
		double dVerbrauch = p_dVerbrauch/100 *
				(dGlobaleZeit - p_dZeit) * p_dMaxGeschwindigkeit;


		p_dTankinhalt = (p_dTankinhalt-dVerbrauch<0) ? 0 :
				p_dTankinhalt - dVerbrauch;

		Fahrzeug::vSimulieren();
	}

	/*
	else
	{
		cout << "Tank von #" << p_iID
				<< " ist leer, und muss getankt werden." << endl;
	}
	*/


}


void PKW::vAusgeben(ostream& o) const
{
	Fahrzeug::vAusgeben(o);
	o << resetiosflags(ios::right);

	o << setw(15) << dGeschwindigkeit()
			<< setw(3) << " : "
			<< setw(15) << p_dVerbrauch/100 * p_dGesamtStrecke
			<< setw(3) << " : "
			<< setw(10) << p_dTankinhalt
			<< endl;
}


double PKW::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}


void PKW::operator=(const PKW& pkw)
{
	Fahrzeug::operator =(pkw);
	this->p_dTankvolumen = pkw.p_dTankvolumen;
	this->p_dVerbrauch = pkw.p_dVerbrauch;
}
