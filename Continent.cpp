/*
 * Continent.cpp
 * Project 0
 * Austin DeLauney
 * 02/07/16
 * Section 03
 * adelau1@umbc.edu
 * When the constructor is called, it sets the name of the continent,
 * accumulates population, and sets the highest countries
 */


#include "Continent.h"

using namespace std;

Continent::Continent(string name, vector<Country> countries)
{
	//Set name of continent
	setName(name);

	//Set countries that are in the continent
	countriesInContinent = countries;

	//Variables for continent
	long totalPop = 0;
	int indexOfHighestPop = 0, indexOfHighestLitRate = 0, indexOfHighestGDPSpent = 0;

	//Set highest GDP, Population and Literacy rate
	for(int i = 0; i < getCountriesInContinent().size(); i++)
	{
		//Variables for finding the top pop, gdp, and lit
		long tempPop = getCountriesInContinent().at(i).getPopulation();
		float tempGDP = getCountriesInContinent().at(i).getEducationGDPSpent();
		float tempLit = getCountriesInContinent().at(i).getLiteracyRate();

		//Add so we get population for the continent
		totalPop += tempPop;

		if(tempPop > getCountriesInContinent().at(indexOfHighestPop).getPopulation())
			{ indexOfHighestPop = i; }

		if(tempGDP > getCountriesInContinent().at(indexOfHighestGDPSpent).getEducationGDPSpent())
			{ indexOfHighestGDPSpent = i; }

		if(tempLit > getCountriesInContinent().at(indexOfHighestLitRate).getLiteracyRate())
			{ indexOfHighestLitRate = i; }
	}

	setPopulation(totalPop);

	highestPopulation 	= getCountriesInContinent().at(indexOfHighestPop);
	highestGDPSpent 	= getCountriesInContinent().at(indexOfHighestGDPSpent);
	highestLiteracyRate = getCountriesInContinent().at(indexOfHighestLitRate);

}

ostream& operator<< (ostream& sout, const Continent& r)
{
	sout << r.getName() << endl;

	sout << " Population: " << r.getPopulation() << endl;
	sout << " Country with the highest literacy rate: " << r.getHighestLiteracyRate().toString() << endl;
	sout << " Country with the highest GDP spendature on education: " << r.getHighestGDPSpent().toString() << endl;
	sout << " Country with the highest population: " << r.getHighestPopulation().toString() << endl;
	
	return sout;
}