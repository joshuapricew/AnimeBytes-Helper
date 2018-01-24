// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"
#include "functions.h"

int main()
{
	std::cout << "##~~ AnimeBytes Helper ~~##\n"
		<< '\n'
		<< "Seeding Time Calculator\n"
		<< "How many gigabytes is the torrent?\n";
	double gigabytes{ getValueFromUser() };
	std::cout << '\n';
	
	int seedTime{ calcSeedTime(gigabytes) };
	formatAndPrintSeedTime(seedTime);

	int gracePeriod{ seedTime * constants::gracePeriodMultiplier };
	formatAndPrintGracePeriod(gracePeriod);

	end();
	return 0;
}
