#include "pch.h"
#include "OverDraftCheckingAccount.h"
#include <iostream>

OverDraftCheckingAccount::OverDraftCheckingAccount(double bal, double fee, double odFee, Account *savingsAccount)
	: CheckingAccount{ bal, fee }, ODFee{ odFee }, ODSavings{savingsAccount}
{
}

bool OverDraftCheckingAccount::debit(double amount)
{
	if (CheckingAccount::debit(amount))
	{
		return true;
	}
	if (ODSavings == nullptr)
	{
		return false;
	}
	if (getBalance() + ODSavings->getBalance() > amount + getFee() + ODFee)
	{
		std::cout << "Using overdraft protection that's probably legal" << std::endl;
		ODSavings->debit(amount + ODFee + getFee() - getBalance());
		CheckingAccount::debit(getBalance()-getFee());

		std::cout  << "$" << ODFee << " Overdraft transaction fee charged" << std::endl;
		std::cout << "Updated Overdraft Savings Account balance: $" << ODSavings->getBalance() << std::endl;
		return true;
	}
	std::cout << "OVERDRAFT ERROR" << std::endl;
	return false;


}



