// largestProductInSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>;
#include <cstdlib>
#include <array>;
using namespace std;

int main()
{
	//vector<vector<int>> arrays;
	array<int, 13> thirteen{0,0,0,0,0,0,0,0,0,0,0,0,0};
	char n;
	int num;
	long long product{1};
	long long max{1};

	ifstream inFile{ "numbers.txt",ios::in };
	if (inFile)
	{
		while (!inFile.eof())
		{
			inFile.get(n);
			num = n - 48;
			if(num >= 0)
			{
				//cout << num;
				for (int i = 0; i < 13; ++i)
				{
					thirteen[i] = num;
					for (int j = 0; j < 13; ++j)
					{
						product *= thirteen[j];
						if (product > max)
						{

						}
					}
				}



			}
			
		}
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
