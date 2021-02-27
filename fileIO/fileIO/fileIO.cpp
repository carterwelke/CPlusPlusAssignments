// fileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Carter Welke CIST 04A\n\n";

	string fName, line;
	char yesno;
	do
	{
		yesno = 'Y';
		cout << "Enter a file name: ";
		cin >> fName;

		//add .txt extension
		fName += ".txt";

		ifstream testFile{ fName };
		if (testFile)
		{
			cout << "\"" << fName << "\" already exists!" << endl;
			testFile.close();

			do
			{
				cout << "Would you like to overwrite file named \"" << fName << "\"? (Y/N): ";
				cin >> yesno;
			} while (yesno != 'Y' && yesno != 'N');
			if (yesno == 'Y')
			{
				cout << "Attempting to delete \"" << fName << "\"." << endl;
			}
		}
	} while (yesno == 'N');

	//Create or Overwrite file
	ofstream oFile{fName,ios::out};
	cout << "\"" << fName << "\" succesfully created!" << endl << endl;

	//Have user input lines to print to the file
	int lineCount{ 0 };
	cout << "Enter lines of text to add to the file. Hit <return> to end." << endl;
	cin.ignore();
	do
	{
		cout << "Enter text for line " << ++lineCount << ": ";
		getline(cin, line);
		if(line != "")
		{
			oFile << line << endl;
		}
	} while(line != "");
	cout << "The file was written." << endl << endl;

	ifstream iFile{ fName,ios::in };
	streampos endF, beginF;

	//get file size in bytes
	beginF = iFile.tellg(); 
	iFile.seekg(0, ios::end);
	endF = iFile.tellg();
	cout << "The file \"" << fName << "\" is " << (endF - beginF) << " bytes long." << endl << endl;
	
	//write another line to file
	cout << "Enter final line of text to add to file: ";
	getline(cin, line);
	cout << "Writing \"" << line << "\" to the file." << endl << endl;
	oFile << line << endl;

	//get new file size in bytes
	iFile.seekg(0, ios::beg);
	beginF = iFile.tellg();
	iFile.seekg(0, ios::end);
	endF = iFile.tellg();
	cout << "The file \"" << fName << "\" is now " << (endF - beginF) << " bytes long."<< endl << endl;
	
	//Print file
	iFile.seekg(0, ios::beg);
	char c;
	cout << "The file \"" << fName << "\" contains: " << endl;
	while (!iFile.eof()) 
	{
		iFile.get(c);
		cout << c;
	}

	oFile.close();
	iFile.close();
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
