/*
 * Fahrrad.cpp
 *
 *  Created on: 06.11.2022
 *      Author: root
 */

#include "Fahrrad.h"

Fahrrad::Fahrrad() : Fahrzeug()
{
}


Fahrrad::Fahrrad(const string sName) :
		Fahrzeug(sName)
{
}


Fahrrad::Fahrrad(const string sName, const double dVMax) :
		Fahrzeug(sName, dVMax)
{
}


double Fahrrad::dGeschwindigkeit() const
{
	if (p_dGesamtStrecke < 20) {
		return p_dMaxGeschwindigkeit;
	}
	else
	{
		double dV = pow(0.9, (int)p_dGesamtStrecke/20) * p_dMaxGeschwindigkeit;

		if (dV < 12)
		{
			return 12;
		}
		else
		{
			return dV;
		}

	}
}


void Fahrrad::vAusgeben(ostream& o) const
{
	Fahrzeug::vAusgeben(o);
	o << resetiosflags(ios::right);
	o << setw(15) << dGeschwindigkeit()
					<< setw(3) << " : "
					<< setw(15) << "-"
					<< setw(3) << " : "
					<< setw(10) << "-"
					<< endl;
}
