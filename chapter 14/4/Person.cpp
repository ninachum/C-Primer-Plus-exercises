#include "Person.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::getline;
using std::cin;

void Person::Show() const
{
	Data();
}

void Person::Data()	const
{
	cout << "name : " << last << ", " << first << endl;
}

void Person::Get()
{
	cout << "first name : ";
	getline(cin, first);
	cout << "last name : ";
	getline(cin, last);
}

void Person::Set()
{
	Person::Get();
}

void Gunslinger::Show() const
{
	Person::Data();
	Data();
}

void Gunslinger::Data() const
{
	cout << "Pulling time : " << Draw() << endl;
	cout << "notch : " << notch << endl;
}

double Gunslinger::Draw() const
{
	return pullingTime;
}

void Gunslinger::Get()
{
	cout << "pulling time ? ";
	cin >> pullingTime;
	cout << "notch ? ";
	cin >> notch;
	while (cin.get() != '\n')
		continue;
}

void Gunslinger::Set()
{
	Person::Get();
	Get();
}

int PokerPlayer::Draw() const
{
	return (rand() % 52) + 1;
}

void PokerPlayer::Show() const
{
	Person::Data();
	Data();
}

void PokerPlayer::Data() const
{
	cout << "did draw card " << Draw() << "." << endl;
}

void PokerPlayer::Get()
{
	// does nothing...
}

void PokerPlayer::Set()
{
	Person::Get();
	//Get();
}

double BadDude::Gdraw() const
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
	return PokerPlayer::Draw();
}

void BadDude::Show() const
{
	Person::Data();
	Gunslinger::Data();
	PokerPlayer::Data();
	//Data();
}

void BadDude::Data() const
{
	// does nothing...
}

void BadDude::Get()
{
	// does nothing...
}

void BadDude::Set()
{
	Person::Get();
	Gunslinger::Get();
	PokerPlayer::Get();
	//Get();
}