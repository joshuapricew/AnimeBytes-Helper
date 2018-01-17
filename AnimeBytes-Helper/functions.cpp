#include "stdafx.h"
#include <iostream>
#include <string>
#include "constants.h"

void end()
{
	std::cout << '\n' << "Press enter to continue . . . "; std::cin.clear(); std::cin.ignore(32767, '\n'); std::cin.get();
}

float getValueFromUser() 
{
	float gigabytes{};
	std::cin >> gigabytes;
	return gigabytes;
}

int calcSeedTime(float gigabytes)
{
	// If torrent is under 10GB the minimum seed time is always 72 hours.
	if (gigabytes <= 10.0f)
		return constants::baseSeedHours;
	else
	{
		int seedTime{};
		gigabytes -= constants::baseGigabytes;
		gigabytes *= constants::hoursPerGigabyte;
		return (int)gigabytes + constants::baseSeedHours;
	}
}

// Correctly pluralises and omits strings
std::string days(int d, short h)
{
	std::string days{ std::to_string(d) };
	std::string hours{ std::to_string(h) };
	if (hours == "0")
		return days + " days";
	else if (hours == "1")
		return days + " days and " + hours + " hour";
	else
		return days + " days and " + hours + " hours";
}

void formatAndPrintSeedTime(int seedTime)
{
	int seedDays{ seedTime / constants::hoursInADay };
	short seedHours{ seedTime % constants::hoursInADay };
	std::cout << "Minimum seed time: " << days(seedDays, seedHours) << " or: " << seedTime << " hours" << '\n';
}

void formatAndPrintGracePeriod(int gracePeriod)
{
	int graceDays = gracePeriod / constants::hoursInADay;
	short graceHours = gracePeriod % constants::hoursInADay;
	std::cout << "Grace period: " << days(graceDays, graceHours) << " or: " << gracePeriod << " hours" << '\n';
}

// --- AnimeBytes Helper Functions ---

// void seedingTimeCalculator() {}
