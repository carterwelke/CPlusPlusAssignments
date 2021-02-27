#pragma once
#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount(double bal, double fee);
	void credit(double amount);
	bool debit(double amount);
	double getFee();
private:
	double fee;
};