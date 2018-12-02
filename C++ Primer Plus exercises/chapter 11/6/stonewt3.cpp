#include <iostream>
#include "stonewt3.h"

using std::cout;

Stonewt::Stonewt(double lbs)
{
	stone = (int)lbs / LBS_PER_STN;
	pds_left = (int)lbs % LBS_PER_STN + lbs - (int)lbs;
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * LBS_PER_STN + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{

}

void Stonewt::show_stn() const
{
	cout << stone << "stone, " << pds_left << "pound\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << "pound\n";
}

Stonewt::operator int() const
{
	return int(pounds + 0.5);
}

Stonewt::operator double() const
{
	return pounds;
}

bool Stonewt::operator>(const Stonewt & s) const
{
	if (pounds > s.pounds)
		return true;
	else
		return false;

}
bool Stonewt::operator<(const Stonewt & s) const
{
	if (pounds < s.pounds)
		return true;
	else
		return false;
}
bool Stonewt::operator>=(const Stonewt & s) const
{
	if (pounds >= s.pounds)
		return true;
	else
		return false;
}
bool Stonewt::operator<=(const Stonewt & s) const
{
	if (pounds <= s.pounds)
		return true;
	else
		return false;
}
bool Stonewt::operator==(const Stonewt & s) const
{
	if (pounds == s.pounds)
		return true;
	else
		return false;
}
bool Stonewt::operator!=(const Stonewt & s) const
{
	if (pounds != s.pounds)
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & os, Stonewt & s)
{
	cout << s.stone << "stone, " << s.pds_left << " pound";
	return os;
}