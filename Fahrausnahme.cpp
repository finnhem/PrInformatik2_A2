/*
 * Fahrausnahme.cpp
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#include "Fahrausnahme.h"

Fahrausnahme::Fahrausnahme(Fahrzeug& f, Weg& w) : fzgException(f), wayException(w)
{
}

Fahrausnahme::~Fahrausnahme()
{
}

