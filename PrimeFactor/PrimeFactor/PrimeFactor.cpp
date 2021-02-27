// PrimeFactor.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Carter Welke CIST 004A


#include "pch.h"
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;

void primeFactor(unsigned int,unsigned int = 2);

int main() 
{

	cout << "Carter Welke CIST 004A\n\n";

	unsigned int number;

	cout << "Enter a number to factor(negative number to end): ";
	cin >> number;
	cout << "The prime factors are: ";

	//start time
	high_resolution_clock::time_point start = high_resolution_clock::now();

	primeFactor(number);

	//stop time
	high_resolution_clock::time_point stop = high_resolution_clock::now();
	
	//calculate execution time
	auto duration = duration_cast<microseconds>(stop - start).count();

	cout << fixed << setprecision(4) << endl << "This took " << duration / 1000.0 << " milliseconds" << endl;

	return 0;
}

void primeFactor(unsigned int num, unsigned int div)
{
	if (num == div) { // It's Prime
		cout << div << ". ";
		return;
	}
	if (num % div == 0) { // div is a factor
		cout << div << ", ";
		primeFactor(num / div, div);
	}
	else 
	{ //div is not a factor or the number
		primeFactor(num, div+1);
	}
	return;
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
