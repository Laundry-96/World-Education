#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	vector<Continent> world;
	ifstream countriesFile;
	ifstream dataFile;

	countriesFile.open("CountriesContinents.txt");
	dataFile.open("2013WorldBankEducationCensusData.txt");

	string line = "";

	vector<string> countryData;
	string countryDataLine;

	while(getline(dataFile, countryDataLine))
	{
		countryData.push_back(countryDataLine);
	}

	while (getline(countriesFile, line))
	{
		if(line.find("--") != std::string::npos)
		{
			istringstream isis(line);
			string continent, filler;
			int countriesAmount;
			isis >> continent >> filler >> countriesAmount;
			vector<Country> countries;

			for (int i = 0; i < countriesAmount; i++)
			{
				string countryName;
				getline(countriesFile, countryName);

				//cout << "Trying to find " << countryName << endl;


				for (int i = 0; i < countryData.size(); i++)
				{
					if (countryData.at(i).find(countryName) != std::string::npos)
					{
						countries.push_back(Country(countryData.at(i)));
						//cout << countryData.at(i) << endl;
					}

				}
				//countries.push_back(Country("Test", -1, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0));
			}

			world.push_back(Continent(continent, countries));
		}
	}

	for (int i = 0; i < world.size(); i++)
	{
		cout << world.at(i) << endl;
		
	}
}