/*
 * Fahrzeug.cpp
 *
 *  Created on: 15.10.2022
 *      Author: root
 */

#include "Fahrzeug.h"


Fahrzeug::Fahrzeug() :
		Simulationsobjekt()
{
	cout << "Das Fahrzeug #"<< p_iID << " mit dem Namen "
			<< p_sName << " wurde konstruiert." << endl;
}

Fahrzeug::Fahrzeug(const string sName) :
		Simulationsobjekt(sName)
{
	cout << "Das Fahrzeug #"<< p_iID << " mit dem Namen "
			<< p_sName << " wurde konstruiert." << endl;
}

Fahrzeug::Fahrzeug(const string sName, const double dMaxV) :
		Simulationsobjekt(sName),
		p_dMaxGeschwindigkeit((dMaxV >0) ? dMaxV : abs(dMaxV))

{
	cout << "Das Fahrzeug #"<< p_iID << " mit dem Namen "
			<< p_sName << " und der maximal Geschwindigkeit "
			<< p_dMaxGeschwindigkeit << " wurde konstruiert." << endl;
}

Fahrzeug::~Fahrzeug()
{
}

void Fahrzeug::vKopf()
{
	cout << endl << endl << endl;
	cout << resetiosflags(ios::left);

	cout << setiosflags(ios::left) << setw(3) << "ID"
			<< setw(3) << " | "
			<< resetiosflags(ios::right)

			<< setiosflags(ios::left) << setw(30) << "Name"
			<< setw(3) << " | "
			<< resetiosflags(ios::left)

			<< setiosflags(ios::right) << setw(18) << "MaxGeschwindigkeit"
			<< setw(3) << " | "

			<< setw(13) << "Gesamtstrecke"
			<< setw(3) << " | "

			<< setw(14) << "Abschnitt [km]"
			<< setw(3) << " | "

			<< setw(15) << "Geschwindigkeit"
			<< setw(3) << " | "
			<< setw(15) << "Gesamtverbrauch"
			<< setw(3) << " | "
			<< setw(10) << "Tankinhalt" << setw(6)
			<< setprecision(2) << fixed  << dGlobaleZeit << endl;
	cout << setw(100) << "-------------------------------------------------------------------------------------------------------------------------------------------"<< endl;
}

void Fahrzeug::vAusgeben(ostream& o) const
{
	Simulationsobjekt::vAusgeben(o);

	o <<  setiosflags(ios::right) << setw(18)
			<< p_dMaxGeschwindigkeit
			<< setw(3) << " : "

			<< setw(13) << p_dGesamtStrecke
			<< setw(3) << " : "
			<< setw(14) << p_dAbschnittStrecke
			<< setw(3) << " : ";
	//o << endl;
}

void Fahrzeug::vSimulieren()
{
	if (fabs(p_dZeit - dGlobaleZeit) > 0.1 || p_dZeit == 0)	//Nur einmal simuliert pro Zeitschritt
	{
		double dZeitIntervall = dGlobaleZeit - p_dZeit;	//Fahrtzeit wird erhoeht
		//p_dGesamtStrecke = p_dGesamtFahrZeit * p_dMaxGeschwindigkeit;	//Zeit * MaxGesch.
		double p_dNeueStrecke = p_pVerhalten->dStrecke(*this, dZeitIntervall);
		p_dAbschnittStrecke += p_dNeueStrecke;
		p_dGesamtStrecke += p_dNeueStrecke;
		p_dZeit = dGlobaleZeit;
		p_dGesamtFahrZeit +=dZeitIntervall;
	}
}

double Fahrzeug::dTanken()
{
	return 0;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

int Fahrzeug::getID()
{
	return p_iID;
}


string Fahrzeug::getName()
{
	return p_sName;
}


bool Fahrzeug::operator <(const Fahrzeug& fahrzeug) const
{
	return this->p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke;
}


//Unsere Kopie soll eine eigene ID haben, damit jedes Fahrzeug seine eigene hat.
//Deswegen setzen wir den Copyconstructor = delete, damit nicht auch die ID kopiert wird.
void Fahrzeug::operator =(const Fahrzeug& fahrzeug)
{
	Simulationsobjekt::operator =(fahrzeug);
	this->p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
}


void Fahrzeug::vNeueStrecke(Weg& weg)
{
	p_pVerhalten = make_unique<Verhalten>(weg);
	p_dAbschnittStrecke = 0;
}


double Fahrzeug::getAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}










