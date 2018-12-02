#pragma once

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	// constructor and other methods
	String(const char * s);
	String(const String & s);
	String();
	~String();
	int length() const { return len; }
	void stringlow();
	void stringup();
	unsigned int has(char c) const;
	// operator overloadings
	String & operator=(const String & s);
	String & operator=(const char *s);
	String operator+(const char * s) const;
	char & operator[](int i);
	const char & operator[](int i) const;
	// friend operator overloadings
	friend bool operator<(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
	friend String operator+(const char * s1, const String & s2);
	friend String operator+(const String & s1, const String & s2);
	// static function
	static int HowMany();
};