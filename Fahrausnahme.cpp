/*
 * Fahrausnahme.cpp
 *
 *  Created on: 15.11.2022
 *      Author: root
 *
 *      Oberklasse von Losfahren und Streckenende
 */

#include "Fahrausnahme.h"


Fahrausnahme::Fahrausnahme(Fahrzeug& f, Weg& w) : fzgException(f), wayException(w)
{
}


Fahrausnahme::~Fahrausnahme()
{
}

