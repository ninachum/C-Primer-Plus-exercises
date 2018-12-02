#include "complex0.h"
#include <iostream>

Complex::Complex()
{
	real = imag = 0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}

Complex Complex::operator+(const Complex & c) const
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex & c) const
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex & c) const
{
	return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator*(double mult) const
{
	return Complex(real * mult, imag * mult);
}

Complex operator*(double mult, const Complex & c)
{
	return Complex(mult * c.real, mult * c.imag);
}

Complex Complex::operator~() const
{
	return Complex(real, -imag);
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << "(" << c.real << ", " << c.imag << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
	using std::cout;
	using std::cin;
	cout << "실수부: ";
	cin >> c.real;
	cout << "허수부: ";
	cin >> c.imag;
	return is;
}