/*
 * driver.cpp
 * Project 0
 * Austin DeLauney
 * 02/07/16
 * Section 03
 * adelau1@umbc.edu
 * Reads the files, and sorts the countries into according continent, then prints out data
 */

#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*  parseData(string data)
 *  preconditions:  data must have a valid line of data following convention
 *  postconditions: returns a country object that has all of the data in it
 */
Country parseData(string data);

/*  setVar(floay& fl, string& val)
 *  preconditions:  float is the variable you want to store the value
 					string is a numerical value, or "N/A"
 *  postconditions: the value of val is stored as a float in fl, -1 if string is "N/A"
 */
void setVar(float& fl, string& val);

int main()
{
	//Create the world, and file streams
	vector<Continent> world;
	ifstream countriesFile;
	ifstream dataFile;

	countriesFile.open("CountriesContinents.txt");
	dataFile.open("2013WorldBankEducationCensusData.txt");

	string line = "";

	vector<Country> countryData;
	string countryDataLine = "";
	string waste = "";

	//First line of the world bank is garbage and not needed
	getline(dataFile, waste);

	//Create a new country from each line of data
	while(getline(dataFile, countryDataLine))
		countryData.push_back(parseData(countryDataLine));

	while (getline(countriesFile, line))
	{
		//Get a line that has a continent in it
		if(line.find("--") != std::string::npos)
		{
			//Variables for parsing countries
			istringstream iss(line);
			string continent, filler;
			int countriesAmount;

			//Get the Continent name and amount
			iss >> continent >> filler >> countriesAmount;
			vector<Country> countries;

			//Puts all fo the countries into the continent
			for (int i = 0; i < countriesAmount; i++)
			{
				string countryName;
				getline(countriesFile, countryName);

				//Go through the country data and find the correct country, and add it to the continent
				for (int j = 0; j < countryData.size(); j++)
				{
					if (!countryData.at(j).getName().compare(countryName))
					{
						countries.push_back(countryData.at(j));
					}
				}
			}

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

	istringstream iss(country_data);

	//These two variables will always be filled with correct values no matter what
	iss >> name;
	//cout << name << endl;
	iss >> population;

	//Don't know if proper data is in these
	string nextVar = "";

	//literacyRate
	iss >> nextVar;
	setVar(literacyRate, nextVar);

	//educationalGDPSpent
	iss >> nextVar;
	setVar(educationGDPSpent, nextVar);

	//primaryCompletionTotal
	iss >> nextVar;
	setVar(primaryCompletionTotal, nextVar);

	//primaryCompletionMale
	iss >> nextVar;
	setVar(primaryCompletionMale, nextVar);

	//primaryCompletionFemale
	iss >> nextVar;
	setVar(primaryCompletionFemale, nextVar);

	//youthLitRateFem
	iss >> nextVar;
	setVar(youthLitRateFem, nextVar);

	//youthLitRateMale
	iss >> nextVar;
	setVar(youthLitRateMale, nextVar);

	return Country(name, population, literacyRate, educationGDPSpent, primaryCompletionTotal, primaryCompletionMale, primaryCompletionFemale, youthLitRateFem, youthLitRateMale);
}

void setVar(float& fl, string& val)
{
	//If the string is "N/A", set it to -1.0
	if (!val.compare("N/A"))
		{ fl = float(-1.0); }

	//Has a valid value, set the value
	else
	{
		istringstream temp(val);
		temp >> fl;
	}
}
