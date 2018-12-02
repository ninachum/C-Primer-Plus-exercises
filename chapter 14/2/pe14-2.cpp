#include <iostream>
#include "Pair.h"
#include "Wine.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "wine name? :";
	char label[50];
	cin.getline(label, 50);
	cout << "num of reap year? : ";
	int yrs;
	cin >> yrs;

	Wine holding(label, yrs);

	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << more.Label() << " 전체 수량" << ": " << more.sum() << endl;
	cout << "Terminating....\n";
	cin.get();
	return 0;
}