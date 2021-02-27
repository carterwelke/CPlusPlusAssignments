#include "pch.h"
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(double bal, double iRate)
	: Account(bal) ,interest{iRate}
{}

double SavingsAccount::calculateInterest()
{
	double adding = interest * this->getBalance();
	return adding;
}
