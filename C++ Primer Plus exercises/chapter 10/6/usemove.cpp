#include "move.h"
#include <iostream>

int main(void)
{
	Move before;
	Move after(3, 4);
	before.reset(6, 5);
	before.showmove();
	after.reset(0, 0);
	after.showmove();
	
	std::cin.get();
	return 0;
}