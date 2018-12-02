#include "dmaabc.h"
#include <cstring>

// DMA methods
DMA::DMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

DMA::DMA(const DMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

DMA::~DMA()
{
	delete[] label;
}

DMA & DMA::operator=(const DMA & rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

void DMA::view() const
{
	std::cout << *this;
}

std::ostream & operator<<(std::ostream & os, const DMA & rs)
{
	os << "상표: " << rs.label << std::endl;
	os << "등급: " << rs.rating << std::endl;
	return os;
}

// baseDMA methods

baseDMA::baseDMA(const char * l, int r)
	: DMA(l ,r)
{

}

void baseDMA::view() const
{
	std::cout << *this;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: DMA(l, r)
{
	// copy COL_LEN - 1(maximum) chars. padded with zero if less than COL-LEN - 1 chars were copied.
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & rs)
	: DMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	os << (const DMA &)ls;
	os << "색상: " << ls.color << std::endl;
	return os;
}

void lacksDMA::view() const
{
	std::cout << *this;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
	: DMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & rs)
	: DMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
	: DMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	DMA::operator=(hs);
	delete[] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

void hasDMA::view() const
{
	std::cout << *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	// same as operator<<(os, (const DMA &)hs);
	os << (const DMA &)hs;
	os << "스타일: " << hs.style << std::endl;
	return os;
}