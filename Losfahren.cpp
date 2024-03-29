/*
 * Losfahren.cpp
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#include "Losfahren.h"
#include "Weg.h"

Losfahren::Losfahren(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w)
{
}


Losfahren::~Losfahren()
{
}


void Losfahren::vBearbeiten()
{
	cout << "Exception Losfahren von:" << endl;
	Fahrzeug::vKopf();
	cout << fzgException << endl;
	Weg::vKopf();
	cout << wayException << endl;

	wayException.vAnnahme(wayException.pAbgabe(fzgException));
}
