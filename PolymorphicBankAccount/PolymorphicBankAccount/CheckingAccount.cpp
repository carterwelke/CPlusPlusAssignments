#include "pch.h"
#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double bal, double feeCost)
	: Account{ bal }, fee{ feeCost }
{}

void CheckingAccount::credit(double amount)
{
	Account::credit(amount);
	Account::debit(fee);
	std::cout << "$" << fee << " transaction fee charged." << std::endl;
}

bool CheckingAccount::debit(double amount)
{
	if (amount == 0)
	{
		return true;
	}
	if (Account::debit(amount + fee))
	{
		std::cout << "$" << fee << " fee charged." << std::endl;
		return true;
	}
	return false;
}

double CheckingAccount::getFee()
{
	return fee;
}
