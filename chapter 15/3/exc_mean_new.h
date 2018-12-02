#pragma once

#include <stdexcept>
#include <iostream>	

using std::logic_error;
using std::cout;
using std::endl;

class mean_error : public logic_error
{
private:
	double v1;
	double v2;

public:
	mean_error(double a, double b, const char * c) : logic_error(c), v1(a), v2(b) { }
	virtual void report() const;
};

void mean_error::report() const
{
	cout << "error value1 : " << v1 << endl;
	cout << "error value2 : " << v2 << endl;
	cout << "function name : " << logic_error::what() << endl;
}

class bad_hmean : public mean_error
{
public:
	bad_hmean(double a, double b, const char * c)
		: mean_error(a, b, c) { }
	virtual void report() const;
};

void bad_hmean::report() const
{
	cout << "bad_hmean exception!" << endl;
	mean_error::report();
}

class bad_gmean : public mean_error
{
public:
	bad_gmean(double a, double b, const char * c)
		: mean_error(a, b, c) { }
	virtual void report() const;
};

void bad_gmean::report() const
{
	cout << "bad_gmean exception!" << endl;
	mean_error::report();
}