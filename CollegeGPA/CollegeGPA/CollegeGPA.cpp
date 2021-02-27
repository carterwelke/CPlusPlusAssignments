// CollegeGPA.cpp

//Carter Welke CIST 004A

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
using namespace std;

int main()
{
	cout << "Carter Welke\t\tCIST 004A\n\n";

	cout << "This program will calculate your GPA. For each course, enter a letter grade in upper" << endl
		<< "or lower case with an optional + or - then a ,[comma] followed by the number" << endl
		<< "of units for that course, then [Return] key. After all grades have been entered, input a \"z\"" << endl
		<< "and then [Return] to calculate your final GPA." << endl << endl;

	//initialize Variables
	string input, unitString;
	int courseNum{1}, commaIndex, units;
	char letter;
	float finalGPA, gpa, totalUnits{0}, totalScore{0};

	regex reg("[[:blank:]]*[ABCDFabcdf][[:blank:]]*[+-]?[[:blank:]]*,[[:blank:]]*([1-9]{1}|[1-3]{1}[0-9]|4[0-5]{1})");
	
	do
	{
		cout << "Enter a letter grade, Unit Count for course number " << courseNum << ": ";
		cin >> input;

		//check if input is in correct format
		if (regex_match(input, reg))
		{
			//get letter grade and convert to uppercase
			letter = input.at(0);
			letter = toupper(letter);

			//Assign GPA depending on Letter Grade
			switch (letter)
			{
			case 'A':
				gpa = 4.0;
				break;
			case 'B':
				gpa = 3.0;
				break;
			case 'C':
				gpa = 2.0;
				break;
			case 'D':
				gpa = 1.0;
				break;
			case 'F':
				gpa = 0.0;
			}
			
			//Check for + or -, change GPA unless grade is 'A+' or 'F-'
			if (input.at(1) == '+')
			{
				if (letter == 'A')
				{
					cout << "Great job, but the highest possible GPA is 4.000" << endl;
				}
				else
				{
					gpa += 0.3;
				}
			}
			if (input.at(1) == '-')
			{
				if (letter == 'F')
				{
					cout << "That's too bad, but the lowest GPA possible is 0.000" << endl;
				}
				else
				{
					gpa -= 0.3;
				}
			}

			//Locate comma and create a substring of everything after
			commaIndex = input.find(',');
			unitString = input.substr(commaIndex+1);
			//Convert to integer
			units = stoi(unitString);

			//Add up units and score
			totalUnits += units;
			totalScore += (gpa * units);

			//Increment Course Number
			courseNum++;
		}
		else if (input == "z")
		{
			cout << "Calulating GPA..." << endl;
		}
		else
		{
			cout << "Not a valid input, please reread the instructions provided above" << endl;
		}
	} while (input != "z");
	
	courseNum--;
	finalGPA = totalScore / totalUnits;

	cout << fixed << setprecision(3) << "Your GPA for the " << courseNum << " valid courses entered is: " << finalGPA << endl;

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
