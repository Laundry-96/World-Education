#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"
#include <vector>

using namespace std;

class Continent : public Country
{
	public:
		Continent(string name, vector<Country> countries);

		vector<Country> getCountriesInContinent() 	{return countriesInContinent;}
		Country 		getHighestPopulation()		{return highestPopulation;}
		Country			getHighestGDPSpent()		{return hightestGDPSpent;}
		Country			getHighestLiteracyRate()	{return highestLiteracyRate;}

		friend ostream& operator<<(ostream& sout, const Continent& r);

	private:
		vector<Country> countriesInContinent;
		Country highestPopulation;
		Country hightestGDPSpent;
		Country highestLiteracyRate;
};

#endif