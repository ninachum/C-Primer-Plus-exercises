#include <iostream>

struct CandyBar
{
	const char *brand;
	double weight;
	int cal;
};

void makeCandy(CandyBar & x, const char *newBrand = "Millenium Munch", const double newWeight = 2.85, const int newCal = 350);
void printCandy(CandyBar & x);

int main()
{
	CandyBar c;
	makeCandy(c, "ninachum", 3.33);
	printCandy(c);
	return 0;
}

void makeCandy(CandyBar & x, const char *newBrand, const double newWeight, const int newCal)
{
	x.brand = newBrand;
	x.weight = newWeight;
	x.cal = newCal;
}

void printCandy(CandyBar & x)
{
	using namespace std;
	cout << "brand : " << x.brand << endl;
	cout << "weight : " << x.weight << endl;
	cout << "calories : " << x.cal << endl;
}