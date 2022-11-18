/*
 * Streckenende.cpp
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#include "Streckenende.h"

Streckenende::Streckenende(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w)
{
}

Streckenende::~Streckenende()
{
}


void Streckenende::vBearbeiten()
{
	cout << "Exception Streckenende von:" << endl;
	Fahrzeug::vKopf();
	cout << fzgException << endl;
	Weg::vKopf();
	cout << wayException << endl;

	wayException.pAbgabe(fzgException);
}
