#include "plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char * s)
{
	using std::cout;
	if (strlen(s) > LEN - 1) {
		cout << "plorg name too long. it is trimmed to initial 19 chars.\n";
	}
	strncpy(name, s, LEN - 1);
	name[LEN - 1] = '\0';

	CI = 50;
}

void Plorg::show() const
{
	using std::cout;
	cout << "name is : " << name << '\n' << "CI is : " << CI << '\n';
}
