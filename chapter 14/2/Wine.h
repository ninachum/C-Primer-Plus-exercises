#pragma once

#include <iostream>
#include <string>
#include <valarray>
#include "Pair.h"

using std::string;
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private string, private PairArray
{
private:
	int years;

public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	const string & Label() const;
	int sum() const;
	void Show() const;
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), string(l), years(y) { }

Wine::Wine(const char * l, int y)
	: PairArray(ArrayInt(y), ArrayInt(y)), string(l), years(y) { }

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "input data of " << years << " years : " << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "enter year " << i + 1 << " : ";
		cin >> PairArray::first()[i];
		cout << "enter bottles of year " << i + 1 << " : ";
		cin >> PairArray::second()[i];
	}

	while (cin.get() != '\n')
		continue;
}

const string & Wine::Label() const
{
	return (const string &) *this;
}

int Wine::sum() const
{
	return PairArray::second().sum();  // not efficient : makes a copy of an ArrayInt (valarray<int>) object, then calculates its sum.
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "years and bottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << PairArray::first()[i] << " and " << PairArray::second()[i] << endl;
	}
}