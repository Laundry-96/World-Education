#include "Country.h"

Country::Country()
{
	
}

Country::Country(string name, long population, float literacyRate, float educationGDPSpent, float primaryCompletionTotal, float primaryCompletionMale, float primaryCompletionFemale, float youthLitRateFem, float youthLitRateMale)
{
	this->name 						= name;
	this->population 				= population;
	this->literacyRate 				= literacyRate;
	this->educationGDPSpent 		= educationGDPSpent;
	this->primaryCompletionFemale 	= primaryCompletionFemale;
	this->primaryCompletionMale 	= primaryCompletionMale;
	this->primaryCompletionTotal 	= primaryCompletionTotal;
	this->youthLitRateFem 			= youthLitRateFem;
	this->youthLitRateMale 			= youthLitRateMale;
}

Country::Country(string country_data)
{
	istringstream isis(country_data);

	//These two variables will always be filled with correct values no matter what
	isis >> this->name;
	//cout << name << endl;
	isis >> this->population;

	//Don't know if proper data is in these
	string nextVar = "";

	//literacyRate
	isis >> nextVar;
	setVar(this -> literacyRate, nextVar);

	//educationalGDPSpent
	isis >> nextVar;
	setVar(this -> educationGDPSpent, nextVar);

	//primaryCompletionTotal
	isis >> nextVar;
	setVar(this -> primaryCompletionTotal, nextVar);

	//primaryCompletionMale
	isis >> nextVar;
	setVar(this -> primaryCompletionMale, nextVar);

	//primaryCompletionFemale
	isis >> nextVar;
	setVar(this -> primaryCompletionFemale, nextVar);

	//youthLitRateFem
	isis >> nextVar;
	setVar(this -> youthLitRateFem, nextVar);

	//youthLitRateMale
	isis >> nextVar;
	setVar(this -> youthLitRateMale, nextVar);
}

void Country::setVar(float& fl, string& val)
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

string Country::toString() const
{
	//Turn populaton into a string
	ostringstream osisPop;
	osisPop << getPopulation();
	string population = osisPop.str();

	//Turn lit rate into a string
	ostringstream osisLit;
	osisLit << getLiteracyRate();
	string lit = osisLit.str();

	return getName() + " with a population of " + population + " and a literacy rate of " + lit;
}