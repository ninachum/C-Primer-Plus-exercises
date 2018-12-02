#include "cow.h"
#include <iostream>

int main()
{
	Cow hey("jude", "dealing", 49.9);
	Cow dude = hey;
	Cow nani;
	nani = dude;
	hey.ShowCow();
	dude.ShowCow();
	nani.ShowCow();

	std::cin.get();
	return 0;
}