#include <cstring>
#include <cctype>
#include "string2.h"
using std::cout;
using std::cin;

// initialize static class member.
int String::num_strings = 0;

// static method
int String::HowMany()
{
	return num_strings;
}

// class methods
String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String & s)
{
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	num_strings++;
}

String::~String()
{
	num_strings--;
	delete[] str;
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
}

unsigned int String::has(char c) const
{
	unsigned int result = 0;
	for (int i = 0; i < len; i++)
		if (c == str[i])
			result++;
	return result;
}


// operator overloadings

	// assign String to String.
String & String::operator=(const String & s)
{
	if (this == &s)
		return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	return *this;
}

	// assign C string to string
String & String::operator=(const char *s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

	// combine two strings
String String::operator+(const char * s) const
{
	String result;
	delete[] result.str;

	result.len = len + std::strlen(s);
	if (result.len + 1 > String::CINLIM) // if total length needed (including terminating null-char) exceeds CINLIM, trim the rest.
		result.len = String::CINLIM - 1;
	result.str = new char[result.len + 1];
	std::strncpy(result.str, str, result.len);
	result.str[result.len] = '\0'; // for safe strncat() execution
	std::strncat(result.str, s, result.len - std::strlen(str));
	return result;
}

	// access to single non-const char character reference.
char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	return str[i];
}

// friend operator overloadings

bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) > 0);
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String operator+(const char * s1, const String & s2)
{
	String result;
	delete[] result.str;

	result.len = std::strlen(s1) + s2.len;
	if (result.len + 1 > String::CINLIM) // if total length needed (including terminating null-char) exceeds CINLIM, trim the rest.
		result.len = String::CINLIM - 1;
	result.str = new char[result.len + 1];
	std::strncpy(result.str, s1, result.len);
	result.str[result.len] = '\0'; // for safe strncat() execution
	std::strncat(result.str, s2.str, result.len - std::strlen(result.str)); // result.str[result.len] = '\0'; automatically done.
	return result;
}

String operator+(const String & s1, const String & s2)
{
	String result;
	delete[] result.str;

	result.len = s1.len + s2.len;
	if (result.len + 1 > String::CINLIM) // if total length needed (including terminating null-char) exceeds CINLIM, trim the rest.
		result.len = String::CINLIM - 1;
	result.str = new char[result.len + 1];
	std::strncpy(result.str, s1.str, result.len);
	result.str[result.len] = '\0'; // for safe strncat() execution
	std::strncat(result.str, s2.str, result.len - std::strlen(result.str));
	return result;
}