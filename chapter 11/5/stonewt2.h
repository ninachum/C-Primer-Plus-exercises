#pragma once

class Stonewt
{
public:
	enum Mode { STONE, POUND_FLOAT };
private:
	static const int LBS_PER_STN = 14;
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	void setMode(Mode md);
	~Stonewt();
	// conversion functions
	operator int() const;
	operator double() const;
	// operator overloadings
	friend std::ostream & operator<<(std::ostream & os, Stonewt & s);
	friend Stonewt operator+(Stonewt & s1, Stonewt & s2);
	friend Stonewt operator-(Stonewt & s1, Stonewt & s2);
	friend Stonewt operator*(Stonewt & s1, Stonewt & s2);
};