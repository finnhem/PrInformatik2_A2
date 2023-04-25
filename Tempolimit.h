/*
 * Tempolimit.h
 *
 *  Created on: 11.11.2022
 *      Author: root
 */

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

enum Tempolimit
{
	innerorts = 50,			//	[km/h]
	landstraße = 100,
	autobahn = std::numeric_limits<int>::max()		//max int Wert
};



#endif /* TEMPOLIMIT_H_ */
