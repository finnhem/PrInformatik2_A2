/*
 * Weg.cpp
 *
 *  Created on: 11.11.2022
 *      Author: root
 */

#include "Weg.h"


Weg::Weg() : Simulationsobjekt(), p_dLaenge(0.0), p_eTempolimit(autobahn)
{
}

Weg::Weg(string sName, double dLaenge, Tempolimit tempolimit) :
		Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(tempolimit)
{

}

Weg::~Weg() {
	cout << "Weg #" << this->p_iID << " mit dem Namen " << this->p_sName << " wurde dekonstruiert." << endl;
}

double Weg::getTempolimit()
{
	return (double) p_eTempolimit;
}


void Weg::vSimulieren()
{
	for (auto &listElement : p_pFahrzeuge)
	{
		listElement->vSimulieren();
	}
}


void Weg::vKopf()
{
	cout << endl << endl << "Zeit: " << dGlobaleZeit << endl;
	cout << resetiosflags(ios::left) << resetiosflags(ios::right);

	cout << setiosflags(ios::left) << setw(3) << "ID"
			<< setw(3) << " | "
			<< resetiosflags(ios::right)

			<< setiosflags(ios::left) << setw(30) << "Name"
			<< setw(3) << " | "

			<< setw(9) << " Laenge"
			<< setw(3) << " | "

			<< setw(21) << "Fahrzeuge" << endl;
	cout << setw(100) << "----------------------------------------------------------------------------"<< endl;
}


void Weg::vAusgeben(ostream& o) const
{
	Simulationsobjekt::vAusgeben(o);

	o << setiosflags(ios::right) << setw(9) << p_dLaenge
			<< setw(3) << " : ";

	//list Ausgabe
	if (p_pFahrzeuge.empty())
	{
		o << "( )" << endl;
	}
	else	//es befinden sich Fahrzeuge auf dem Weg
	{
		string sListe = "(";
		//for (list<unique_ptr<Fahrzeug>>::const_iterator it = p_pFahrzeuge.cbegin(); it != --p_pFahrzeuge.cend(); ++it)
		for (auto &n : p_pFahrzeuge)
		{
			sListe += " " + n->getName();
		}
		sListe += " )";

		o << sListe << endl;
	}
}


double Weg::getLaenge() const
{
	return this->p_dLaenge;
}


void Weg::vAnnahme(unique_ptr<Fahrzeug> pFzg)
{
	//Signal an pFzg neue Strecke
	pFzg->vNeueStrecke(*this);

	//Fahrzeug zur Liste hinzufuegen
	p_pFahrzeuge.push_back(move(pFzg));

}
