#include "Port.h"
#include <cstring>

// Port methods

void Port::SetStyle(const char * newst)
{
	std::strncpy(style, newst, 19);
	style[19] = '\0';
}

Port::Port(const char * br, const char * st, int b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;

	delete[] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;

	return *this;
}

Port & Port::operator-=(int b)
{
	if (bottles < b)
		std::cout << "you can't draw more bottles than you have.\n";
	else
		bottles -= b;
	return *this;
}

void Port::Show() const
{
	using std::cout;
	using std::endl;
	cout << "브랜드 : " << brand << endl;
	cout << "스타일 : " << style << endl;
	cout << "수량 : " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
	using std::cout;
	cout << p.brand << ", " << p.style << ", " << p.bottles;
}

// VintagePort methods
VintagePort::VintagePort()
	: Port()
{
	Port::SetStyle("vintage");
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
	: Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;

	delete[] nickname;
	Port::operator=(vp);
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	using std::cout;
	using std::endl;
	cout << "닉네임 : " << nickname << endl;
	cout << "빈티지 : " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	using std::cout;
	cout << (const Port &)vp;
	cout << ", " << vp.nickname << ", " << vp.year;
}