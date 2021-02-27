#include "pch.h"
#include "Account.h"
#include <iostream>

Account::Account(double bal)
	:balance{ bal }
{
	if (balance < 0.0)
	{
		std::cout << "ERROR: invalid initial balance" << std::endl;
		balance = 0.0;
	}
}

void Account::credit(double amount)
{
	balance += amount;
}

bool Account::debit(double amount)
{
	if (amount > balance)
	{
		std::cout << "ERROR:Debit of $" << amount << " exceeds balance $" << balance << std::endl;
		return false;
	}
	else
	{
		balance -= amount;
		return true;
	}
}

double Account::getBalance()
{
	return balance;
}



