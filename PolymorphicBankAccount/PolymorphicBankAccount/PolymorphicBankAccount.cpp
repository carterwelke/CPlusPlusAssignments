// PolymorphicBankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include "Account.h";
#include "SavingsAccount.h";
#include "CheckingAccount.h";
#include "OverDraftCheckingAccount.h"

using namespace std;

int main()
{
    cout << "Carter Welke CIST 04A\n\n" << fixed << setprecision(2); 

	vector<Account *> accounts{};
	accounts.emplace_back(new SavingsAccount{ 25,0.03 });
	accounts.emplace_back(new CheckingAccount{ 80, 1 });
	accounts.emplace_back(new SavingsAccount{ 200,0.01497 });
	accounts.emplace_back(new OverDraftCheckingAccount{ 400, 0.5, 10, accounts[2]});

	double input;
	SavingsAccount* savingsCastPtr;

	for (int i{ 0 }; i < accounts.size(); i++)
	{

		cout << "Account " << i+1 << " balance: $" << accounts[i]->getBalance() << endl;

		do
		{
			cout << "Enter a non-negative amount to withdraw from Account " << i+1 << ": ";
			cin >> input;
		} while (input < 0);
		accounts[i]->debit(input);

		do
		{
			cout << "Enter a non-negative amount to deposit into Account " << i+1 << ": ";
			cin >> input;
		} while (input < 0);
		accounts[i]->credit(input);

		savingsCastPtr = dynamic_cast<SavingsAccount*>(accounts[i]);
		if (savingsCastPtr != nullptr)
		{
			cout << "Adding $" << savingsCastPtr->calculateInterest() << " interest to Account " << i+1 << " (savings account) " << endl;
			savingsCastPtr->credit(savingsCastPtr->calculateInterest());
		}

		cout << "Updated Account " << i+1 << " balance: $" << accounts[i]->getBalance() << endl << endl;

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
