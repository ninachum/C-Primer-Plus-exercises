#include "stack.h"
#include <iostream>

int main()
{
	customer mom = { "nanoboost", 500.0 };
	customer dad = { "nannytorso", 3000.0 };
	double totalRev = 0;
	customer pophere;
	Stack s;
	s.push(mom);
	s.push(dad);
	s.pop(pophere);
	totalRev += pophere.payment;
	s.pop(pophere);
	totalRev += pophere.payment;
	std::cout << "total rev : " << totalRev << std::endl;
	std::cin.get();
	return 0;
}