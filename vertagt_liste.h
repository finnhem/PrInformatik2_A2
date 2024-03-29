#pragma once

#include "vertagt_aktion.h"

#include <list>
//Test
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = default; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}


		//Ausgabefunktion der vListe
		void vlAusgeben()
		{
			cout << endl;
			for (auto& pObjekt : p_objekte)
			{
				cout << pObjekt << endl;
			}
		}


		//leert die Fahrzeugliste
		void clear()
		{
			vAktualisieren();
			p_objekte.clear();
		}


		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			return p_objekte.end();
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end();
		}
		bool empty() const
		{
			return p_objekte.empty();		//list size == 0?
		}


		// Schreibfunktionen
		void push_back(T obj)
		{
			//Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushBack<T>>(p_objekte, std::move(obj)));

		}

		void push_front(T obj)
		{
			//Aktionselement für PushFront auf Liste erzeugen
			p_aktionen.push_front(std::make_unique<VPushFront<T>>(p_objekte, std::move(obj)));
		}


		void erase(iterator it)
		{
			// Aktionselement für Erase auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(std::make_unique<VErase<T>>(p_objekte, it));
			//Erst zu spaeterem Zeitpunkt in vAktualisieren erase anwenden
		}


		// Aenderungen auf Objektliste uebertragen
		void vAktualisieren()
		{
			// Aenderungen auf Objektliste uebertragen
			for (auto& pAktion : p_aktionen)
			{
				// Aktion ausführen
				pAktion->vAusfuehren();
			}
			// Aktionsliste löschen
			p_aktionen.clear();
		}
	};
} // namespace vertagt
