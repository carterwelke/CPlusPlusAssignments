#pragma once
class Account
{
public:
	Account(double bal);
	void credit(double amount);
	bool debit(double amount);
	double getBalance();
private:
	double balance;
};

