#include "stack1.h"
#include <iostream>

int main()
{
	Item mom = 10;
	Item dad = 30;
	double totalRev = 0;
	Stack s;
	s.push(mom);
	s.push(dad);
	Item pophere;
	s.pop(pophere);
	totalRev += pophere;
	s.pop(pophere);
	totalRev += pophere;
	std::cout << "total rev : " << totalRev << std::endl;
	Stack z = s;
	Stack x;
	x = s;
	std::cin.get();
	return 0;
}