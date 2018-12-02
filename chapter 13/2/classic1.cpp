#include "classic1.h"
#include <cstring>
#include <iostream>

Cd::Cd(const char * s1, const char * s2, int n, double x)
{
	using std::strlen;
	using std::strcpy;
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & c)
{
	using std::strlen;
	using std::strcpy;
	performers = new char[strlen(c.performers) + 1];
	strcpy(performers, c.performers);
	label = new char[strlen(c.label) + 1];
	strcpy(label, c.label);
	selections = c.selections;
	playtime = c.playtime;

}

Cd::Cd()
{
	performers = new char[1];
	performers[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
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

	delete[] performers;
	delete[] label;

	using std::strlen;
	using std::strcpy;

	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char * songname, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	using std::strlen;
	using std::strcpy;
	title = new char[strlen(songname) + 1];
	strcpy(title, songname);
}

Classic::Classic(const Classic & c)
	: Cd(c)
{
	using std::strlen;
	using std::strcpy;
	title = new char[strlen(c.title) + 1];
	strcpy(title, c.title);
}

Classic::Classic()
	: Cd()
{
	title = new char[1];
	title[0] = '\0';
}

Classic::~Classic()
{
	delete[] title;
}

void Classic::Report() const
{
	Cd::Report();
	using std::cout;
	using std::endl;

	cout << "title song : " << title << endl;
}

Classic & Classic::operator=(const Classic & c)
{
	if (this == &c)
		return *this;

	Cd::operator=(c);
	delete[] title;

	using std::strlen;
	using std::strcpy;

	title = new char[strlen(c.title) + 1];
	strcpy(title, c.title);

	return *this;
}
