#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	cout << "Hello" << endl;
	vector<Continent> world;
	ifstream countriesFile;
	ifstream dataFile;

	countriesFile.open("CountriesContinents.txt");
	dataFile.open("2013WorldBankEducationCensusData.txt");

	string line = "";

	stringstream test("Hello What Is Up?");
	cout << test << endl;
	test.str("HHHH");
	cout << "HELLLOOOOOOOOOOO";
	cout << endl;

	while (getline(countriesFile, line))
	{
		if(line.find("--") != std::string::npos)
		{
			cout << "Found -- in " << line << endl;
			istringstream isis(line);
			string continent, filler;
			int countriesAmount;
			isis >> continent >> filler >> countriesAmount;
			//cout << continent << filler << countriesAmount << endl;
			vector<Country> countries;
			for (int i = 0; i < countriesAmount; i++)
			{
				string temp_line;
				getline(countriesFile, temp_line);
				//isis.str(getline(countriesFile, temp_line));
				istringstream temp_isis(temp_line);
				cout << temp_line << endl;
				countries.push_back(Country("Test", -1, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0));
			}
			//cout << countries;
			world.push_back(Continent(continent, countries));
		}

		else
			cout << "ERROR ERROR ERROR" << endl;
	}
}