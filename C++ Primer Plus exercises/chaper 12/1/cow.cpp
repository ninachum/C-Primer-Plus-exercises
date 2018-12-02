#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	std::strncpy(name, nm, sizeof(name));
	name[19] = '\0'; // for safe
	hobby = new char[strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;
}

// copy constructor
Cow::Cow(const Cow & c)
{
	std::strcpy(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

// assignment operator (overloaded)
Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
		return *this;
	std::strcpy(name, c.name);
	delete[] hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	using std::cout;
	using std::endl;
	cout << "name : " << name << endl;
	cout << "hobby : " << hobby << endl;
	cout << "weight : " << weight << endl;
}