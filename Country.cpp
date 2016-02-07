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

	isis >> this->name;
	isis >> this->population;
	isis >> this->literacyRate;
	isis >> this->primaryCompletionFemale;
	isis >> this->primaryCompletionMale;
	isis >> this->primaryCompletionTotal;
	isis >> this->educationGDPSpent;
	isis >> this->youthLitRateFem;
	isis >> this->youthLitRateMale;
}