#pragma once
#include "Account.h"


class SavingsAccount : public Account
{
public:
	SavingsAccount(double bal, double iRate);
	double calculateInterest();
private:
	double interest;
};

