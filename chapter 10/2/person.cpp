#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string & ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT - 1);
	fname[LIMIT - 1] = '\0';
}

void Person::Show() const
{
	using std::cout;
	using std::endl;
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
	using std::cout;
	using std::endl;
	cout << lname << ", " << fname << endl;
}