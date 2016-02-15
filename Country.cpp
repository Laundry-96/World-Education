#include "Country.h"

Country::Country()
{
	
}

Country::Country(string name, long population, float literacyRate, float primaryCompletionFemale, float primaryCompletionMale, float primaryCompletionTotal, float educationGDPSpent, float youthLitRateFem, float youthLitRateMale)
{
	this->name 						= name;
	this->population 				= population;
	this->literacyRate 				= literacyRate;
	this->primaryCompletionFemale 	= primaryCompletionFemale;
	this->primaryCompletionMale 	= primaryCompletionMale;
	this->primaryCompletionTotal 	= primaryCompletionTotal;
	this->educationGDPSpent 		= educationGDPSpent;
	this->youthLitRateFem 			= youthLitRateFem;
	this->youthLitRateMale 			= youthLitRateMale;
}

Country::Country(string EAT_SHIT)
{
	istringstream isis(EAT_SHIT);

	//These two variables will always be filled with correct values no matter what
	isis >> this->name;
	isis >> this->population;

	//Don't know if proper data is in these
	string nextVar = "";

	//literacyRate
	isis >> nextVar;
	setVar(this -> literacyRate, nextVar);

	//primaryCompletionFemale
	isis >> nextVar;
	setVar(this -> primaryCompletionFemale, nextVar);

	//primaryCompletionMale
	isis >> nextVar;
	setVar(this -> primaryCompletionMale, nextVar);

	//primaryCompletionTotal
	isis >> nextVar;
	setVar(this -> primaryCompletionTotal, nextVar);

	//educationalGDPSpent
	isis >> nextVar;
	setVar(this -> educationGDPSpent, nextVar);
	
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
		fl = stof(val);
}

string Country::toString() const
{
	ostringstream osisPop;
	osisPop << getPopulation();
	string population = osisPop.str();

	ostringstream osisLit;
	osisLit << getLiteracyRate();
	string lit = osisLit.str();

	return getName() + " with a population of " + population + " and a literacy rate of " + lit;
}