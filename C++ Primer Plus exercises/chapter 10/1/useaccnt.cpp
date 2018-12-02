#include <iostream>
#include "account.h"


int main()
{
	using std::string;
	using std::cin;
	using std::cout;

	string user;
	string accntNo;
	double amount;

	cout << "your name? : ";
	std::getline(cin, user);
	cout << "account number? : ";
	std::getline(cin, accntNo);
	cout << "initial balance? : ";
	cin >> amount;
	cin.get(); // for deleting new-line char in input stream.

	BankAccount goblin(user, accntNo, amount);
	goblin.show();
	goblin.deposit(300.0);
	goblin.show();
	goblin.withdraw(30000000.0);
	goblin.show();
	goblin.withdraw(200000.0);
	goblin.show();
	cin.get();
	return 0;
}