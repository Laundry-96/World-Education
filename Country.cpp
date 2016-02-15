/*
 * Country.cpp
 * Project 0
 * Austin DeLauney
 * 02/07/16
 * Section 03
 * adelau1@umbc.edu
 * This is the implemention for Country.cpp. toString method and constructor.
 */

#include "Country.h"

Country::Country()
{
	
}

Country::Country(string name, long population, float literacyRate, float educationGDPSpent, float primaryCompletionTotal, float primaryCompletionMale, float primaryCompletionFemale, float youthLitRateFem, float youthLitRateMale)
{
	this -> name 						= name;
	this -> population 					= population;
	this -> literacyRate 				= literacyRate;
	this -> educationGDPSpent 			= educationGDPSpent;
	this -> primaryCompletionFemale 	= primaryCompletionFemale;
	this -> primaryCompletionMale 		= primaryCompletionMale;
	this -> primaryCompletionTotal 		= primaryCompletionTotal;
	this -> youthLitRateFem 			= youthLitRateFem;
	this -> youthLitRateMale 			= youthLitRateMale;
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