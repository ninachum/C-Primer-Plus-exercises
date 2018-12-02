#pragma once

#include <iostream>

class Stonewt
{
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
	// conversion functions
	operator int() const;
	operator double() const;
	// operator overloadings
	bool operator>(const Stonewt & s) const;
	bool operator<(const Stonewt & s) const;
	bool operator>=(const Stonewt & s) const;
	bool operator<=(const Stonewt & s) const;
	bool operator==(const Stonewt & s) const;
	bool operator!=(const Stonewt & s) const;
	// operator overloadings
	friend std::ostream & operator<<(std::ostream & os, Stonewt & s);
};