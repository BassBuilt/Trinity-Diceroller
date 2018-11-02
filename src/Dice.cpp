// Preprocessor Directives
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "Dice.h"
using namespace std; 

// Member Functions

Dice::Dice()
{
}

Dice::Dice(int num, int d, int advan)
{
	number = num;
	sides = d;
	advantage = advan;
	srand(time(NULL));

	for (int i = 0; i < (number + abs(advantage)); i++)
	{
		values[i] = rand() % sides + 1;

	}

	int n = sizeof(values) / sizeof(values[0]);

	sort(values, values+n, greater<int>());

	if (advantage >= 0)
	{
		for (int i = 0; i < number; i++)
		{
			if (values[i] == 1)
			{
				fumble++;
			}

			if (values[i] == sides)
			{
				crit++;
			}

			total += values[i];
		}
	}
	else 
	{
		for (int i = abs(advantage); i < (number + abs(advantage)); i++)
		{
			if (values[i] == 1)
			{
				fumble++;
			}

			if (values[i] == sides)
			{
				crit++;
			}

			total += values[i];
		}
	}	
}

Dice::~Dice()
{
}

int Dice::getNumber()
{
	return number;
}

int Dice::getTotal()
{
	return total;
}

int Dice::getCrit()
{
	return crit;
}

int Dice::getFumble()
{
	return fumble;
}
