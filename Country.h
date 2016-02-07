#ifndef COUNTRY_H
#define	COUNTRY_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Country
{
	public:
		/* Country default constructor */
		Country();
		Country(string name, long population, float literacyRate, float primaryCompletionFemale, float primaryCompletionMale, float primaryCompletionTotal, float educationGDPSpent, float youthLitRateFem, float youthLitRateMale);
		Country(string EAT_SHIT);
		/* Getters */
		string getName();
		long getPopulation() 								{return population;}
		float getLiteracyRate() 							{return literacyRate;}
		float getPrimaryCompletionFemale() 					{return primaryCompletionFemale;}
		float getPrimaryCompletionMale() 					{return primaryCompletionMale;}
		float getPrimaryCompletionTotal() 					{return primaryCompletionTotal;}
		float getEducationGDPSpent() 						{return educationGDPSpent;}
		float getYouthLitRateFem() 							{return youthLitRateFem;}
		float getYouthLitRateMale() 						{return youthLitRateMale;}

		/* Setters */
		void setName(string newName) 						{name = newName;}
		void setPopulation(long pop) 						{population = pop;}
		void setLiteracyRate(float litRate) 				{literacyRate = litRate;}
		void setPrimaryCompletionFemale(float PrimComplFem) {primaryCompletionFemale = PrimComplFem;}
		void setPrimaryCompletionMale(float PrimComplMale) 	{primaryCompletionMale = PrimComplMale;}
		void setPrimaryCompletionTotal(float PrimComplTot) 	{primaryCompletionTotal = PrimComplTot;}
		void setEducationGDPSpent(float edGDPSpent) 		{educationGDPSpent = edGDPSpent;}
		void setYouthLitRateFem(float youLitRateFem) 		{youthLitRateFem = youLitRateFem;}
		void setYouthLitRateMale(float youLitRateMale) 		{youthLitRateMale = youLitRateMale;}

	private:
		/* Variables */
		string name;
		long population;
		float literacyRate;
		float primaryCompletionFemale;
		float primaryCompletionMale;
		float primaryCompletionTotal;
		float educationGDPSpent;
		float youthLitRateFem;
		float youthLitRateMale;
};

#endif