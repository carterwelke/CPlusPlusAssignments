// DiceRoll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

void printDots(vector<int>);

int main()
{
    cout << "Carter Welke CIST 004A\n"; 

	unsigned int seed{0}; //Seed
	srand(seed);

	int numDice{3}, numSides{6}, numRolls{100}, rollValue{0};
	vector<int> rollsVector;

	do
	{
		cout << "Enter number of rolls(1-1,000,000): ";
		cin >> numRolls;

		cout << "Enter number of dice(1-5): ";
		cin >> numDice;

		cout << "Enter number of sides on each dice(4-20): ";
		cin >> numSides;

		if ((numRolls <= 0 || numRolls > 1000000) || (numDice <= 0 || numDice > 5) || (numSides < 4 || numSides > 20))
		{
			cout << "Incorrect Input, please double check ranges and input a valid input." << endl;
		}

	} while ((numRolls <= 0 || numRolls > 1000000) || (numDice <= 0 || numDice > 5) || (numSides < 4 || numSides > 20));
	
	rollsVector.assign(numDice*numSides,0);

	for (int i = 0; i < numRolls; i++)
	{
		for (int d = 1; d <= numDice; d++)
		{
			rollValue += (1 + rand() % numSides);
		}
		rollsVector[rollValue-1] += 1;

		rollValue = 0;
	}

	printDots(rollsVector);
}


void printDots(vector<int> n)
{
	double percent;
	int outOfForty;

	int max = n[0];
	for (unsigned int i{ 1 }; i < n.size() - 1; i++)
	{
		if (max < n[i])
		{
			max = n[i];
		}
	}

	for (unsigned int i{0}; i < n.size(); ++i)
	{
		cout << "Rolled " << setw(3) << i + 1 << " (" << setw(5) << n[i] << " times): ";

		percent = n[i] / static_cast<double>(max);
		outOfForty = percent * 40;
		
		for (int stars{0}; stars < outOfForty; ++stars)
		{
			cout << '*';
		}
		
		cout << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
