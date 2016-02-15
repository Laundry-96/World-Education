
/*
 * Country.cpp
 * Project 0
 * Austin DeLauney
 * 02/07/16
 * Section 03
 * adelau1@umbc.edu
 * This is the implemention for Country.h. Mostly getters and setters.
 */
 
#ifndef COUNTRY_H
#define	COUNTRY_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Country
{
	public:
		/* Country constructors */
		Country();
		Country(string name, long population, float literacyRate, float educationGDPSpent, float primaryCompletionTotal, float primaryCompletionMale, float primaryCompletionFemale, float youthLitRateFem, float youthLitRateMale);


		/* Getters */
		string 	getName()										const	{return name;}
		string 	toString() 										const;
		long  	getPopulation() 								const	{return population;}
		float 	getLiteracyRate() 								const	{return literacyRate;}
		float 	getPrimaryCompletionFemale() 					const	{return primaryCompletionFemale;}
		float 	getPrimaryCompletionMale() 						const	{return primaryCompletionMale;}
		float  	getPrimaryCompletionTotal() 					const	{return primaryCompletionTotal;}
		float  	getEducationGDPSpent() 							const	{return educationGDPSpent;}
		float  	getYouthLitRateFem() 							const	{return youthLitRateFem;}
		float  	getYouthLitRateMale() 							const	{return youthLitRateMale;}


		/* Setters */
		void 	setName(string newName) 								{name = newName;}
		void 	setPopulation(long pop) 								{population = pop;}
		void 	setLiteracyRate(float litRate) 							{literacyRate = litRate;}
		void 	setPrimaryCompletionFemale(float PrimComplFem) 			{primaryCompletionFemale = PrimComplFem;}
		void 	setPrimaryCompletionMale(float PrimComplMale) 			{primaryCompletionMale = PrimComplMale;}
		void 	setPrimaryCompletionTotal(float PrimComplTot) 			{primaryCompletionTotal = PrimComplTot;}
		void 	setEducationGDPSpent(float edGDPSpent) 					{educationGDPSpent = edGDPSpent;}
		void 	setYouthLitRateFem(float youLitRateFem) 				{youthLitRateFem = youLitRateFem;}
		void 	setYouthLitRateMale(float youLitRateMale) 				{youthLitRateMale = youLitRateMale;}
		void	setVar(float& fl, string& val);

	private:
		/* Variables */
		string 	name;
		long	population;
		float 	literacyRate;
		float 	primaryCompletionFemale;
		float 	primaryCompletionMale;
		float 	primaryCompletionTotal;
		float 	educationGDPSpent;
		float 	youthLitRateFem;
		float 	youthLitRateMale;
};

#endif