// sumSquareDiff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;



int main()
{
    cout << "Hello World!\n"; 

	int sum1{ 0 }, sum2{0}, diff;

	for (int i = 1; i <= 100; i++)
	{
		sum1 += i*i;
		sum2 += i;
	}
	sum2 *= sum2;

	diff = sum2 - sum1;
	cout << diff;

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
