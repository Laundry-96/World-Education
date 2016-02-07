#include "Continent.h"

using namespace std;

Continent::Continent(string name, vector<Country> countries)
{
	setName(name);
	countriesInContinent = countries;

}

ostream& operator<<(ostream& sout, const Continent& r)
{
  sout << "Hello world" << endl;
  
  return sout;
}