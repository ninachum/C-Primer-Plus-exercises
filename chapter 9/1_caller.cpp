#include <iostream>
#include "1_def_header.h"

int main(void)
{
	using std::cout;
	using std::cin;
	golf ann;
	setgolf(ann, "Ann BirdFree", 24);

	golf nina;
	if (!setgolf(nina))
		cout << "\naborted\n";
	else {
		showgolf(nina);
		showgolf(ann);
	}
		
	cin.get();
	return 0;
}