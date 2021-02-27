#pragma once
#include "CheckingAccount.h"
class OverDraftCheckingAccount :
	public CheckingAccount
{
public:
	OverDraftCheckingAccount(double bal, double fee, double odFee, Account *savingsAccount);
	bool debit(double);

private:
	double ODFee;
	Account * ODSavings;
};
