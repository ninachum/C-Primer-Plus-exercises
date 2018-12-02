#include "stock3.h"
#include <iostream>

const int STKS = 4;

int main(void)
{
	using std::cout;
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};


	cout << "list of stocks : \n";
	for (int i = 0; i < STKS; i++) {
		cout << stocks[i];
	}

	const Stock *top = &stocks[0];
	for (int i = 1; i < STKS; i++) {
		top = &(top->topval(stocks[i]));
	}

	std::cout << "\nstock that has the highest value : \n";
	cout << *top;
	std::cin.get();
	return 0;

}