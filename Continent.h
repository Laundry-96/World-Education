/*
 * Continent.h
 * Project 0
 * Austin DeLauney
 * 02/07/16
 * Section 03
 * adelau1@umbc.edu
 * This is the header for Continent.cpp. Necessary things for the class.
 */


#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"
#include <vector>

using namespace std;

class Continent : public Country
{
	public:

		Continent(string name, vector<Country> countries);

		vector<Country> getCountriesInContinent() 	const {return countriesInContinent;}
		Country 		getHighestPopulation()		const {return highestPopulation;}
		Country			getHighestGDPSpent()		const {return highestGDPSpent;}
		Country			getHighestLiteracyRate()	const {return highestLiteracyRate;}

		friend ostream& operator<<(ostream& sout, const Continent& r);

	private:

		vector<Country> countriesInContinent;
		Country highestPopulation;
		Country highestGDPSpent;
		Country highestLiteracyRate;
};

#endif