// BankInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
    cout << "Carter Welke CIST 004A\n\n"; 
	
	Account account1{50.0};
	SavingsAccount account2{25,0.03};
	CheckingAccount account3{80,1};

	cout << fixed << setprecision(2) << "(Regular) account1 balance is: $" <<  account1.getBalance() << endl;
	cout << "(savings) account2 balance is: $" << account2.getBalance() << endl;
	cout << "(checking) account3 balance is: $" << account3.getBalance() << endl;

	cout << endl << "attempting to debit $25.00 from account1" << endl;
	account1.debit(25);
	
	cout << endl << "attempting to debit $30.00 from account2" << endl;
	account2.debit(30);

	cout << endl << "attempting to debit $40.00 from account3" << endl;
	account3.debit(40);

	cout << endl << "account1 (regular) balance is: $" << account1.getBalance() << endl;
	cout << "account2 (savings) balance is: $" << account2.getBalance() << endl;
	cout << "account3 (checking) balance is: $" << account3.getBalance() << endl;

	cout << endl << "crediting $40.00 to account1" << endl;
	account1.credit(40);

	cout << endl << "crediting $65.00 to account2" << endl;
	account2.credit(65);

	cout << endl << "crediting $20.00 to account3" << endl;
	account3.credit(20);

	cout << endl << "account1 (regular) balance is: $" << account1.getBalance() << endl;
	cout << "account2 (savings) balance is: $" << account2.getBalance() << endl;
	cout << "account3 (checking) balance is: $" << account3.getBalance() << endl;

	cout << endl << "Adding " << account2.calculateInterest() << " interest to account2." << endl;

	cout << "New account2 balance: $" << account2.getBalance() << endl;

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
