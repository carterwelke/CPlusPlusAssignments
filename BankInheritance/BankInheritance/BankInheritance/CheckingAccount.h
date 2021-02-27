#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double bal, double fee);
	void credit(double amount);
	void debit(double amount);
private:
	double fee;
};

