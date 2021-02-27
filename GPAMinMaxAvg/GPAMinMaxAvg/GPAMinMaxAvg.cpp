// GPAMinMaxAvg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

//Carter Welke CIST 004A

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Carter Welke\t\tCIST 004A\n\n";

	int numStudents;
	float gpa{ 0.0 }, min{ 5.0 }, max{ -1.0 }, sum{ 0.0 }, avg;

	cout << "How many students? ";
	cin >> numStudents;

	for (int i = 1; i <= numStudents; i++)
	{
		do
		{
			cout << "Enter a valid GPA for student " << (i) << " (between 0.0 and 4.0): ";
			cin >> gpa;

			if (gpa < 0.0 || gpa > 4.0)
			{
				cout << "Error: GPA invalid.\n";
			}

		} while (gpa < 0.0 || gpa > 4.0);

		if (gpa < min)
		{
			min = gpa;
		}
		if (gpa > max)
		{
			max = gpa;
		}
		sum += gpa;
	}

	avg = sum/static_cast<float>(numStudents);

	cout << fixed << setprecision(3);
	cout << "The highest GPA is " << max << endl;
	cout << "The lowest GPA is " << min << endl;
	cout << "The Average GPA is " << avg << endl;

}