#include "pch.h"
#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double bal, double feeCost)
	: Account{ bal }, fee{feeCost}
{}

void CheckingAccount::credit(double amount)
{
	Account::credit(amount);
	Account::debit(fee);
	std::cout << "$" << fee << " fee charged." << std::endl;
}

void CheckingAccount::debit(double amount)
{
	if (Account::debit(amount+fee))
	{
		std::cout << "$" << fee << " fee charged." << std::endl;
	}
}
