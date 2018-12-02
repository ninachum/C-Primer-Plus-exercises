#include "classic0.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	using std::strncpy;
	strncpy(performers, s1, 49);
	performers[49] = '\0';
	strncpy(label, s2, 19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	// do nothing
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;

	cout << "performers : " << performers << endl;
	cout << "label : " << label << endl;
	cout << "selections : " << selections << endl;
	cout << "playtime : " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	
	using std::strncpy;
	strncpy(performers, d.performers, 49);
	performers[49] = '\0';
	strncpy(label, d.label, 19);
	label[19] = '\0';
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char * songname, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	strncpy(title, songname, 49);
	title[49] = '\0';
}

Classic::Classic()
	: Cd()
{

}

void Classic::Report() const
{
	Cd::Report();
	using std::cout;
	using std::endl;

	cout << "title song : " << title << endl;
}

