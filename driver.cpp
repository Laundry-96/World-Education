#include "Country.h"
#include "Continent.h"
#include <iostream>
#include <fstream>
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
	while (getline(countriesFile, line))
	{
		if(line.find("--") != std::string::npos)
			cout << "Found -- in " << line << endl;
	}
}