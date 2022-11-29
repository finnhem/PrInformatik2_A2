/*
 * main.cpp
 *
 *  Created on: 15.10.2022
 *      Author: root
 */

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahrrad.h"
#include "PKW.h"
#include <memory>
#include <vector>
#include <cmath>

#include "SimuClient.h"

#include "vertagt_liste.h"
#include <random>

//Probe test
#include <iomanip>
double dEpsilon = 0.001;


using namespace std;

double dGlobaleZeit;


void vAufgabe_1()
{
	static Fahrzeug auto1("AMG");
	Fahrzeug* auto2 = new Fahrzeug;

	delete auto2;

	static Fahrzeug auto3("BMW");

	unique_ptr<Fahrzeug> upAuto1 = make_unique<Fahrzeug>("urus");
	unique_ptr<Fahrzeug> upAuto2 = make_unique<Fahrzeug>("urus2");

	shared_ptr<Fahrzeug> spAuto1 = make_shared<Fahrzeug>();
	shared_ptr<Fahrzeug> spAuto2 = make_shared<Fahrzeug>();


	cout << spAuto2.use_count()<< endl;
	shared_ptr<Fahrzeug> spAuto3 = spAuto1;
	shared_ptr<Fahrzeug> spAuto4 = spAuto1;
	cout << spAuto2.use_count()<< endl;

//	Die Klasse unique_ptr besitzt keine Funktion use_count
//	cout << upAuto2.use_count() << endl;
//	unique_ptr<Fahrzeug> upAuto3 = upAuto2;
//	cout << upAuto2.use_count() << endl;

	vector<unique_ptr<Fahrzeug>> v1;
	v1.push_back(move(upAuto1));
	v1.push_back(move(upAuto2));		//Was macht move?
	v1.clear();							//Wann werden die Objekte gelöscht?


	spAuto1.use_count();
	vector<shared_ptr<Fahrzeug>> v2;
	cout << spAuto1.use_count() << endl;
	v2.push_back(move(spAuto1));
	cout << spAuto1.use_count() << endl;	//move setzt die Referenz auf 0
	cout << spAuto2.use_count() << endl;
	v2.push_back(spAuto2);
	cout << spAuto2.use_count() << endl;	//ohne move Referenz++
	v2.clear();

	static Fahrzeug auto7("Test", -300);
}

void vAufgabe_1a()
{
	unique_ptr<Fahrzeug> a1aAuto1 = make_unique<Fahrzeug>("Audi", 230);
	unique_ptr<Fahrzeug> a1aAuto2 = make_unique<Fahrzeug>("Dacia", 50);
	unique_ptr<Fahrzeug> a1aAuto3 = make_unique<Fahrzeug>("Opel", 130);

	vector<unique_ptr<Fahrzeug>> a1aVector;
	a1aVector.push_back(move(a1aAuto1));
	a1aVector.push_back(move(a1aAuto2));
	a1aVector.push_back(move(a1aAuto3));

	for (double dTakt = 0.25; dGlobaleZeit<=2; dGlobaleZeit += dTakt)
	{
		Fahrzeug::vKopf();

		for (int i = 0; i<3; i++)
		{
			a1aVector[i]->vSimulieren();
			a1aVector[i]->vAusgeben(cout);
		}
	}
}


void test()
{
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;

	{
		cout << "**Anfang Test Ausgabe**" << endl << endl;

		unique_ptr<Fahrzeug> upAutoTest0 = make_unique<Fahrzeug>("Test Fahrzeug0 Ausgabe");
		unique_ptr<Fahrzeug> upAutoTest1 = make_unique<Fahrzeug>("Test Fahrzeug1 Ausgabe");
		unique_ptr<Fahrzeug> upAutoTest2 = make_unique<Fahrzeug>("Kurz");
		cout << endl << endl;

		Fahrzeug::vKopf();
		upAutoTest0->vAusgeben(cout);
		upAutoTest1->vAusgeben(cout);
		upAutoTest2->vAusgeben(cout);
		cout << endl << "**Ende Test Ausgabe**" << endl << endl;
	}



	{
		cout << "**Angang Test PKW Ausgabe**" << endl;

		PKW pkw1 = PKW ("VM", 180, 5, 10);
		Fahrzeug::vKopf();
		pkw1.vAusgeben(cout);

		for (double dTakt = 0.25; dGlobaleZeit<=2; dGlobaleZeit += dTakt)
		{
			pkw1.vSimulieren();
			pkw1.vSimulieren();
			pkw1.vAusgeben(cout);
		}

		cout << "**Ende Test PKW Ausgabe**" << endl;
	}

	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;

}



void vAufgabe_2()
{
	//Warum sollten sie keine Fahrzeugobjekte speichern?

	//Warum können sie PKWs und Fahrräder in einen Vektor speichern?
	//Weil sie beide Unterklassen von Fahrzeug sind

	vector<unique_ptr<Fahrzeug>> vecA2;

	int iPKW;
	int iFahrrad;
	cout << "Wie viele PKWs wollen sie?" << endl;
	cin >> iPKW;
	cout << "Wie viele Fahrraeder wollen sie?" << endl;
	cin >> iFahrrad;


	//Hinzufuegen der Fahrzeug Daten fuer PKWs und Fahrraeder
	for (int i = 1; i <= iPKW; i++)
	{
		string sName;
		double dVMax;
		double dVerbrauch;
		double dTankvolumen;

		cout << "Eingaben fuer PKW #" << i << endl;
		cout << "Wie soll das Fahrzeug heißen?" << endl;
		cin >> sName;
		cout << "Was ist die Maximalgeschwindigkeit ihres Fahrzeugs?" << endl;
		cin >> dVMax;
		cout << "Welchen Verbrauch hat ihr Fahrzeug?" << endl;
		cin >> dVerbrauch;
		cout << "Wie viel Liter fasst der Tank des Fahrzeugs?" << endl;
		cin >> dTankvolumen;
		vecA2.push_back(make_unique<PKW>(sName, dVMax, dVerbrauch, dTankvolumen));
		cout << "Eingabe von PKW #" << i << " erfolgreich." << endl << endl;
	}

	for (int i = 1; i <= iFahrrad; i++)
	{
		string sName;
		double dVMax;

		cout << "Eingabe fuer Fahrrad #" << i << endl;
		cout << "Wie soll das Fahrrad heißen?" << endl;
		cin >> sName;
		cout << "Was ist die Maximalgeschwindigkeit?" << endl;
		cin >> dVMax;
		vecA2.push_back(make_unique<Fahrrad>(sName, dVMax));
		cout << "Eingabe von Fahrrad #" << i << " erfolgreich." << endl << endl;
	}

	Fahrzeug::vKopf();
	bool bGetankt = false;
	for (double dTakt = 0.09; dGlobaleZeit <= 4; dGlobaleZeit += dTakt)
	{
		if (fabs(dGlobaleZeit - 3)<0.2 && bGetankt == false)
		{
			cout << "#### 3h um, Zeit zu Tanken ####\tt=" << dGlobaleZeit << endl;
			for (int i = 0; i < iPKW; i++)
			{
				vecA2[i]->dTanken();
				cout << "Auto #" << vecA2[i]->getID() << " mit der Bezeichnung \"" << vecA2[i]->getName() << "\" wurde getankt." << endl;
			}
			bGetankt = true;
		}
		for (auto it = vecA2.begin(); it != vecA2.end(); ++it)
		{
			(*it)->vSimulieren();
			(*it)->vAusgeben(cout);
		}
	}
}


void vAufgabe_Probe() {
    Fahrzeug* pF1 = new PKW("Audi", 150, 8);
    dGlobaleZeit = 0.0;
    Fahrzeug::vKopf();
    dGlobaleZeit = 3.0;
    cout << endl << "Globalezeit = " << dGlobaleZeit << endl;
    pF1->vSimulieren();
    std::cout << *pF1 << endl;
    delete pF1;
    char c;
    std::cin >> c;
}


void vAufgabe_3()
{

	vector<unique_ptr<Fahrzeug>> vec3;

	vec3.push_back(move(make_unique<Fahrrad>("vA3_Fahrrad0", 30)));
	vec3.push_back(move(make_unique<Fahrrad>("vA3_Fahrrad1_langsam", 20)));
	vec3.push_back(move(make_unique<Fahrrad>("vA3_Fahrrad2_schnell", 40)));


	vec3.push_back(move(make_unique<PKW>("vA3_PKW0", 150, 5, 60)));
	vec3.push_back(move(make_unique<PKW>("vA3_PKW1_langsam", 100, 4, 50)));
	vec3.push_back(move(make_unique<PKW>("vA3_PKW2_schnell", 200, 8, 70)));



//	cout << "Ausgabe Test" << endl;
//	for (int i = 0; i < 6; i++)
//	{
//		cout << *vec3[i];
//	}
//	cout << "Ausgabe erfolgreich" << endl;


	//Ausgabe
	for (double dTakt = 0.5; dGlobaleZeit < 10.1; dGlobaleZeit += dTakt)
	{
		Fahrzeug::vKopf();
		for (int i = 0; i < 6; i++)
		{
			vec3[i]->vSimulieren();
			cout << *vec3[i];
		}
	}

	//Vergleichs Operator
	if (*vec3[3] < *vec3[4]) {
		cout << "aPKW ist weniger gefahren als lPKW." << endl;
	} else {
		cout << "Die Aussage ist falsch. aPKW ist weiter gefahren als lPKW." << endl;
	}

	if (*vec3[3] < *vec3[5]) {
		cout << "aPKW ist weniger gefahren als sPKW." << endl;
	} else {
		cout << "Die Aussage ist falsch. aPKW ist weiter gefahren als sPKW." << endl;
	}
	cout << endl << endl;


	//Kopieren von Stammdaten
	cout << "Vor dem Kopieren:";
	Fahrzeug::vKopf();
	cout << "aPKW:" << endl << *vec3[3];
	cout << "lPKW:" << endl << *vec3[4];
	cout << "sPKW:" << endl << *vec3[5];
	cout << endl << endl;


	*vec3[4] = *vec3[3];
	*vec3[5] = *vec3[3];

	cout << "Nach dem Kopieren:";
	Fahrzeug::vKopf();
	cout << "aPKW:" << endl << *vec3[3];
	cout << "lPKW:" << endl << *vec3[4];
	cout << "sPKW:" << endl << *vec3[5];
	cout << endl << endl;
}

//Test fuer Klasse Weg
void vAufgabe_4()
{
	Weg lousbergstr("Lousbergstr", 0.8, innerorts);
	Weg::vKopf();
	cout << lousbergstr << endl;



	for (double dTakt = 0.25; dGlobaleZeit<2.2; dGlobaleZeit += dTakt)
	{
		lousbergstr.vSimulieren();
	}

}


void vAufgabe_5()
{
	//Weg
	Weg mondallee("Mondallee", 15, landstraße);

	//Fahrzeuge auf dem Weg annehmen
	mondallee.vAnnahme(make_unique<PKW>("BMW", 190, 5, 70));
	mondallee.vAnnahme(make_unique<PKW>("Corsa", 130, 5, 70));
	mondallee.vAnnahme(make_unique<Fahrrad>("Rose", 28));

	//Ausgabe und Simulation
	Weg::vKopf();
	for(double dTakt = 0.25; dGlobaleZeit < 2.01; dGlobaleZeit += dTakt)
	{
		mondallee.vSimulieren();
		cout << mondallee;
	}
}


void vAufgabe_6()
{
	bInitialisiereGrafik(800, 500);		//Ausgabefenster

	Weg hinWeg("Hinweg", 500, landstraße);
	Weg rueckWeg("Rueckweg", 500, landstraße);

	int iKoordinaten[4] { 700, 250, 100, 250 };

	bZeichneStrasse(hinWeg.getName(), rueckWeg.getName(), 500, 2, iKoordinaten);

	hinWeg.vAnnahme(make_unique<PKW>("BMW", 190, 5, 70), 1);
	hinWeg.vAnnahme(make_unique<PKW>("Corsa", 130, 5, 70));
	hinWeg.vAnnahme(make_unique<Fahrrad>("Rose", 28));

	rueckWeg.vAnnahme(make_unique<PKW>("Audi", 200, 5, 70));
	rueckWeg.vAnnahme(make_unique<PKW>("Mercedes", 170, 5, 70), 2);
	rueckWeg.vAnnahme(make_unique<Fahrrad>("BMX", 18));



	for (double dTakt = 0.25; dGlobaleZeit < 8.1; dGlobaleZeit += dTakt)
	{
		hinWeg.vSimulieren();
		rueckWeg.vSimulieren();
		vSleep(300);
	}
}



void vAufgabe_6a()
{
	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);

	vertagt::VListe<int> vListe_iTest = vertagt::VListe<int>();

	for (int i = 0; i<10; ++i)
	{
		vListe_iTest.push_back(dist(device));
	}

	vListe_iTest.vAktualisieren();
	vListe_iTest.vlAusgeben();

	//Loeschen aller Elemente > 5
	for (auto it = vListe_iTest.begin(); it != vListe_iTest.end(); ++it)
	{
		if ((*it) > 5)
		{
			vListe_iTest.erase(it);
		}
	}

	//Liste wieder ausgeben
	vListe_iTest.vlAusgeben();		//gleiche Ausgabe, denn noch nicht aktualisiert

	vListe_iTest.vAktualisieren();

	vListe_iTest.vlAusgeben();		//neue Ausgabe

	//Elemente vorne und hinten einfuegen
	vListe_iTest.push_front(-1);
	vListe_iTest.push_back(11);
	vListe_iTest.vAktualisieren();
	vListe_iTest.vlAusgeben();
}



int main()
{
	dGlobaleZeit = 0.0;

	/*
	PKW a1 = PKW("GTI", 250, 5, 60);
	a1.vKopf();
	cout << a1;


	vAufgabe_1a();

	test();

	vAufgabe_2();

	vAufgabe_Probe();

	*/

	//vAufgabe_3();

	//vAufgabe_4();

	//Schlecht implementiert
	//vAufgabe_5();


	//vAufgabe_6();

	vAufgabe_6a();

	return 0;
}
