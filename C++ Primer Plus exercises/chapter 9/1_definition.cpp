#include <iostream>
#include "1_def_header.h"

void setgolf(golf & g, const char * name, int hc)
{
	int i;
	for (i = 0; i < LEN - 1 && *name != '\0'; i++, name++)
		g.fullname[i] = *name;
	g.fullname[i] = '\0';
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cin;
	using std::cout;
	cout << "fullname? (empty line to quit) : ";
	cin.get(g.fullname, LEN);

	if (cin) {
		cout << "handicap? : ";
		cin >> g.handicap;
		cin.get();
		return 1;
	}
	else
		return 0;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
	return;
}
void showgolf(const golf & g)
{
	using std::cout;
	cout << "name : " << g.fullname << ", handicap : " << g.handicap << std::endl;
}