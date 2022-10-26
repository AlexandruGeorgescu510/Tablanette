#include <iostream>
#include <string>
#include "Tabinet.h"

int main()
{
	int nr;
	auto ok = false;
	std::cout << "TABLANETTE SIMPLE IMPLEMENTATION" << std::endl;
	std::cout << std::endl;
	std::cout << "Input the number of players (2/3/4): ";
	std::cin >> nr;
	if (nr == 2 || nr == 3 || nr == 4)
	{
		ok = true;
	}
	while (!ok)
	{
		std::cout << "Wrong input, type a number betweeen 2 and 4." << std::endl;
		std::cin >> nr;
		if (nr == 2 || nr == 3 || nr == 4)
		{
			ok = true;
		}
	}

	Tabinet T(nr);
	T.run();



}