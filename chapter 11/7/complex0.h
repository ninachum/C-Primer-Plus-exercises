#pragma once

#include <iostream>

class Complex
{
private:
	double real;
	double imag;

public:
	// constructors
	Complex();
	Complex(double r, double i);

	// operator overloadings
	Complex operator+(const Complex & c) const;
	Complex operator-(const Complex & c) const;
	Complex operator*(const Complex & c) const;
	Complex operator*(double mult) const;
	friend Complex operator*(double mult, const Complex & c);
	Complex operator~() const;
	friend std::ostream & operator<<(std::ostream & os, const Complex & c);
	friend std::istream & operator>>(std::istream & is, Complex & c);
};