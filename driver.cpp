#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Country parseData(string data);
void	setVar(float& fl, string& val);

int main()
{
	vector<Continent> world;
	ifstream countriesFile;
	ifstream dataFile;

	countriesFile.open("CountriesContinents.txt");
	dataFile.open("2013WorldBankEducationCensusData.txt");

	string line = "";

	vector<Country> countryData;
	string countryDataLine = "";
	string waste = "";

	getline(dataFile, waste);

	while(getline(dataFile, countryDataLine))
	{
		cout << countryDataLine << endl;
		countryData.push_back(parseData(countryDataLine));
	}

	cout << countryData.size() << endl;

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
				//cout << i << endl;
				string countryName;
				getline(countriesFile, countryName);

				for (int j = 0; j < countryData.size(); j++)
				{
					//cout << countryData.size() << endl;
					//cout << j << endl;
					if (!countryData.at(j).getName().compare(countryName))
					{
						countries.push_back(countryData.at(j));
					}

				}
			}
			cout << "WElP" << endl;
			world.push_back(Continent(continent, countries));
		}
	}

	for (int i = 0; i < world.size(); i++)
	{
		cout << world.at(i) << endl;
		
	}
}

Country parseData(string country_data)
{
	string name;
	long population;
	float literacyRate;
	float educationGDPSpent;
	float primaryCompletionTotal;
	float primaryCompletionMale;
	float primaryCompletionFemale;
	float youthLitRateFem;
	float youthLitRateMale;

	istringstream isis(country_data);

	//These two variables will always be filled with correct values no matter what
	isis >> name;
	//cout << name << endl;
	isis >> population;

	//Don't know if proper data is in these
	string nextVar = "";

	//literacyRate
	isis >> nextVar;
	setVar(literacyRate, nextVar);

	//educationalGDPSpent
	isis >> nextVar;
	setVar(educationGDPSpent, nextVar);

	//primaryCompletionTotal
	isis >> nextVar;
	setVar(primaryCompletionTotal, nextVar);

	//primaryCompletionMale
	isis >> nextVar;
	setVar(primaryCompletionMale, nextVar);

	//primaryCompletionFemale
	isis >> nextVar;
	setVar(primaryCompletionFemale, nextVar);

	//youthLitRateFem
	isis >> nextVar;
	setVar(youthLitRateFem, nextVar);

	//youthLitRateMale
	isis >> nextVar;
	setVar(youthLitRateMale, nextVar);

	return Country(name, population, literacyRate, educationGDPSpent, primaryCompletionTotal, primaryCompletionMale, primaryCompletionFemale, youthLitRateFem, youthLitRateMale);
}

void setVar(float& fl, string& val)
{
	//If the string is "N/A", set it to -1.0
	if (!val.compare("N/A"))
		fl = float(-1.0);

	//Has a valid value, set the value
	else
	{
		istringstream temp(val);
		temp >> fl;
	}
}
