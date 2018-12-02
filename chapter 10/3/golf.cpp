#include <iostream>
#include "golf.h"

Golf::Golf(const char * name, int hc)
{
	int i;
	for (i = 0; i < LEN - 1 && *name != '\0'; i++, name++)
		this->fullname[i] = *name;
	this->fullname[i] = '\0';
	this->handicap = hc;
}

Golf::Golf()
{
	using std::cin;
	using std::cout;
	cout << "fullname? (empty line to quit) : ";
	cin.get(this->fullname, LEN);
	
	char temp;
	cin.get(temp);
	while (temp != '\n')
		cin.get(temp);

	cout << "handicap? : ";
	cin >> this->handicap;
	cin.get();
}

void Golf::sethandicap(int hc)
{
	this->handicap = hc;
	return;
}
void Golf::showgolf() const
{
	using std::cout;
	cout << "name : " << this->fullname << ", handicap : " << this->handicap << std::endl;
}