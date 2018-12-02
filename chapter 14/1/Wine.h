#pragma once

#include <iostream>
#include <string>
#include <valarray>
#include "Pair.h"

using std::string;

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	string label;
	int years;
	PairArray pa;

public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	const string & Label() const;
	int sum() const;
	void Show() const;
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
	: pa(ArrayInt(yr, y), ArrayInt(bot, y))
{
	label = l;
	years = y;
}

Wine::Wine(const char * l, int y)
	: pa(ArrayInt(y), ArrayInt(y))
{
	label = l;
	years = y;
}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "input data of " << years << " years : " << endl;
	for (int i = 0; i < years; i++)
	{
		cout << "enter year " << i + 1 << " : ";
		cin >> pa.first()[i];
		cout << "enter bottles of year " << i + 1 << " : ";
		cin >> pa.second()[i];
	}

	while (cin.get() != '\n')
		continue;
}

const string & Wine::Label() const
{
	return label;
}

int Wine::sum() const
{
	return pa.second().sum();  // not efficient : makes a copy of an ArrayInt (valarray<int>) object, then calculates its sum.
}

void Wine::Show() const
{
	using std::cout;
	using std::endl;

	cout << "years and bottles" << endl;
	for (int i = 0; i < years; i++)
	{
		cout << pa.first()[i] << " and " << pa.second()[i] << endl;
	}
}