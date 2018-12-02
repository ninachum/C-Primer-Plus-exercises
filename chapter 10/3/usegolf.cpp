#include <iostream>
#include "golf.h"

int main(void)
{
	using std::cout;
	using std::cin;
	Golf ann("Ann Birdfree", 24);
	
	Golf nina;
	ann.showgolf();
	nina.showgolf();
		
	cin.get();
	return 0;
}