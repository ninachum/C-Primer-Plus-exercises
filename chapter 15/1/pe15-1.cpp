#include <iostream>
#include "tvnew.h"

int main()
{
	using std::cout;
	Tv s65;
	Remote curve;

	curve.onoff(s65); // TV turned on
	curve.print_mod();
	s65.change_mod(curve);
	curve.print_mod();

	std::cin.get();
	return 0;
}