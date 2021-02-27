#pragma once
class Account
{
public:
	Account(double bal);
	virtual void credit(double amount);
	virtual bool debit(double amount);
	double getBalance();
private:
	double balance;
};

