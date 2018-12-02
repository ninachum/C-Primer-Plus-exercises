#include "account.h"
#include <iostream>

BankAccount::BankAccount(std::string & client, std::string num, double bal)
{
	name = client;
	acctnum = num;
	balance = bal;
}

void BankAccount::show() const
{
	using std::cout;
	using std::endl;
	cout << "Client name : " << name << endl
		<< "Account number : " << acctnum << endl
		<< "Balance : " << balance << endl;
}

void BankAccount::deposit(double cash)
{
	using std::cout;
	if (cash <= 0) {
		cout << "you cannot deposit 0 or less than 0 amount.\n";
		return;
	}
	else {
		balance += cash;
	}
}

void BankAccount::withdraw(double cash)
{
	using std::cout;
	if (balance < cash) {
		cout << "you cannot withdraw more than you have.\n";
		return;
	}
	else {
		balance -= cash;
	}

}