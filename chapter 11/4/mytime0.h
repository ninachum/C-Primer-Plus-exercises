#pragma once
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	friend Time operator+(const Time & t1, const Time & t2);
	friend Time operator-(const Time & t1, const Time & t2);
	Time operator*(double n) const;
	friend Time operator*(double m, const Time & t)
		{ return t * m; }
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
	void show() const;
};