#include <iostream>
#include "stonewt2.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
	stone = (int)lbs / LBS_PER_STN;
	pds_left = (int)lbs % LBS_PER_STN + lbs - (int)lbs;
	pounds = lbs;
	mode = STONE;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * LBS_PER_STN + lbs;
	mode = STONE;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode = STONE; // default mode : STONE + POUND
}

void Stonewt::setMode(Mode md)
{
	mode = md;
}

Stonewt::~Stonewt()
{

}

Stonewt::operator int() const
{
	return int(pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}

std::ostream & operator<<(std::ostream & os, Stonewt & s)
{
	if (s.mode == Stonewt::STONE)
		cout << s.stone << "stone, " << s.pds_left << " pound\n";
	else if (s.mode == Stonewt::POUND_FLOAT)
		cout << s.pounds << " pound\n";
	else
		cout << "Invalid Stonewt mode has been called.\n";
	return os;
}

Stonewt operator+(Stonewt & s1, Stonewt & s2)
{
	double total = s1.pounds + s2.pounds;
	return Stonewt(total);
}

Stonewt operator-(Stonewt & s1, Stonewt & s2)
{
	double diff = s1.pounds - s2.pounds;
	return Stonewt(diff);
}

Stonewt operator*(Stonewt & s1, Stonewt & s2)
{
	double mult = s1.pounds * s2.pounds;
	return Stonewt(mult);
}