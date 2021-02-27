// PointersAndCstrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void countChar(char *cStrPtr)
{
	int count{0};
	for (; *cStrPtr;  cStrPtr++)
	{
		count++;
	}
	cout << "There are " << count << " characters in: ";

	return;
}

void countVowels(char *cStrPtr)
{
	int count{ 0 };
	for (; *cStrPtr; cStrPtr++)
	{
		//SWITCH
		switch (toupper(*cStrPtr))
		{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			count++;
		}
	}
	cout << "There are " << count << " vowel(s) in: ";

	return;
}

void upperFirstLetter(char *cStrPtr)
{
	//uppercase first letter
	*cStrPtr = toupper(*cStrPtr);
	cStrPtr++;
	for (; *cStrPtr;cStrPtr++)
	{
		//check for spaces and tabs and then uppercase
		if (*(cStrPtr - 1) == ' ' || *(cStrPtr - 1) == '\t')
		{
			*cStrPtr = toupper(*cStrPtr);
		}
	}

	cout << "Uppercase first letter of each word: ";

	return;
}

void upperEveryLetter(char *cStrPtr)
{
	for (; *cStrPtr; cStrPtr++)
	{
		*cStrPtr = toupper(*cStrPtr);
	}

	cout << "Upper case everything: ";

	return;
}

void removeExtraSpaces(char *cStrPtr)
{
	char *sPtr, *dPtr;
	sPtr = cStrPtr;
	dPtr = cStrPtr;
	
	while (*sPtr)
	{
		if (*sPtr == ' ' && *(sPtr+1) == ' ')
		{
			sPtr++;
		}
		if (*sPtr != ' ' || (*sPtr == ' ' && *(sPtr+1) != ' '))
		{
			*dPtr = *sPtr;
			dPtr++;
			sPtr++;
		}
	}
	*dPtr = '\0';

	cout << "Extra spaces removed: ";

	return;
}

int main()
{
    cout << "Carter Welke\tCIST 004A\n"; 

	char input[100];
	int operation;
	void (*functionsArr[])(char*) {countChar, countVowels, upperFirstLetter, upperEveryLetter, removeExtraSpaces};

	cout << "Enter a string: ";
	cin.getline(input, 100);

	do
	{
		cout << endl;
		cout << "Select an operation to perform on this string: " << endl;
		cout << "1  Count the characters in the string" << endl;
		cout << "2  Count the vowels in the string." << endl;
		cout << "3  Uppercase the first character of each word in the string." << endl;
		cout << "4  Uppercase the every character in the string." << endl;
		cout << "5  Remove extra spaces in the string." << endl;
		cout << "6  Enter a new String." << endl;
		cout << "0  Exit Program." << endl;
		cout << "Enter Operation: ";
		cin >> operation;
		cout << endl;

		//if one the 5 operations
		if(operation > 0 && operation < 6)
		{ 
			functionsArr[operation-1](input);

			cout << input << endl;
		}

		//if Enter a new String
		if (operation == 6)
		{
			cin.ignore();
			cout << "Enter a string: ";
			cin.getline(input, 100);
		}
		
	} while (operation != 0);
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
