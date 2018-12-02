#include <iostream>
#include "stonewt2.h"

int main()
{
	using std::cout;
	using std::endl;
	Stonewt pig(34.55);
	Stonewt mulc(1, 34);
	Stonewt air;
	pig.setMode(Stonewt::Mode::POUND_FLOAT);
	cout << pig;
	pig.setMode(Stonewt::Mode::STONE);
	cout << pig;
	air = pig + mulc;
	cout << air << endl;
	air = pig - mulc;
	cout << air << endl;
	air = pig * mulc;
	cout << air << endl;
	std::cin.get();


	return 0;
}
