/*
 * Fahrausnahme.h
 *
 *  Created on: 15.11.2022
 *      Author: root
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_

#include <exception>
#include <stdexcept>
#include "Fahrzeug.h"
#include "Weg.h"

class Fahrausnahme : public exception {
public:
	Fahrausnahme(Fahrzeug&, Weg&);
	virtual ~Fahrausnahme();
	virtual void vBearbeiten() = 0;

protected:
	Fahrzeug& fzgException;
	Weg& wayException;
};

#endif /* FAHRAUSNAHME_H_ */
