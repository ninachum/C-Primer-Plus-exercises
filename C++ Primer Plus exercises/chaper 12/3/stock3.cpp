#include "stock3.h"
#include <iostream>
#include <cstring>


Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	len = 0;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
	company = new char[std::strlen(co) + 1];
	len = std::strlen(company);
	std::strcpy(company, co);
	if (n < 0) {
		std::cout << "negative stocks : " << company << " ... share is set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock &s)
{
	company = new char[std::strlen(s.company) + 1];
	len = std::strlen(company);
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}

Stock::~Stock()
{
	delete[] company;
}

Stock & Stock::operator=(const Stock & s)
{
	if (this == &s)
		return *this;
	delete[] company;
	company = new char[std::strlen(s.company) + 1];
	len = std::strlen(company);
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	return *this;
}

void Stock::buy(long num, double price)
{
	if (num < 0) {
		std::cout << "you cannot buy negative shares. deal aborted.\n" << std::endl;
	}
	else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0) {
		cout << "you cannot buy negative shares. deal aborted.\n";
	}
	else if (num > shares) {
		cout << "you cannot sell more than you have. deal aborted.\n";
	}
	else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
	using std::cout;
	using std::ios_base;

	// set format to #.###
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	std::cout << "Company name : " << s.company << '\n'
		<< "shares : " << s.shares << '\n'
		<< "price : " << s.share_val << '\n';
	// set format to #.##
	cout.precision(2);
	cout << "total value : $" << s.total_val << '\n';

	// restore original format
	cout.setf(orig);
	cout.precision(prec);
	return os;
}