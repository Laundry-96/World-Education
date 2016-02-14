#include "Continent.h"

using namespace std;

Continent::Continent(string name, vector<Country> countries)
{
	setName(name);
	countriesInContinent = countries;

	long totalPop = 0;

	for(int i = 0; i < getCountriesInContinent().size(); i++)
	{
		totalPop += getCountriesInContinent().at(i).getPopulation();
	}

	setPopulation(totalPop);

}

ostream& operator<< (ostream& sout, const Continent& r)
{
	sout << r.getName() << " " << r.getPopulation() << endl ;

	for(int i = 0; i < r.getCountriesInContinent().size(); i++)
	{
		sout << r.getCountriesInContinent().at(i).getName() << " " <<  r.getCountriesInContinent().at(i).getPopulation() << endl;
	}
	return sout;
}