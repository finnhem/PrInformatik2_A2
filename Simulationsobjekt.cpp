/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 11.11.2022
 *      Author: root
 */

#include "Simulationsobjekt.h"

Simulationsobjekt::Simulationsobjekt() : p_sName("")
{
}


Simulationsobjekt::Simulationsobjekt(const string sName) : p_sName(sName)
{
}


Simulationsobjekt::~Simulationsobjekt()
{
	cout << "Das Objekt #"<< p_iID << " mit dem Namen "
			<< p_sName << " wurde dekonstruiert." << endl;
}


ostream& operator<<(ostream& o, const Simulationsobjekt& simulationsobjekt)
{
	simulationsobjekt.vAusgeben(o);
	return o;
}




void Simulationsobjekt::vAusgeben(ostream& o) const
{
	o << resetiosflags(ios::left) << resetiosflags(ios::right)
			<< setprecision(2) << fixed ;

	o << setiosflags(ios::right) << setw(3) << p_iID
			<< setw(3) << " : "
			<< resetiosflags(ios::right)

			<< setiosflags(ios::left) << setw(30) << p_sName
			<< setw(3) << " : "
			<< resetiosflags(ios::left);
}


void Simulationsobjekt::operator =(const Simulationsobjekt& simulationsobjekt)
{
	this->p_sName = simulationsobjekt.p_sName;
}


bool Simulationsobjekt::operator ==(const Simulationsobjekt& simulationsobjekt)
{
	return this->p_iID == simulationsobjekt.p_iID;
}
