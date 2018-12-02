#include "stonewt3.h"
#include <iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	Stonewt x[6] = { {34.3}, {22.3}, {3, 34.3} };
	double pounds;

	for (int i = 3; i < 6; i++) {
		cin >> pounds;
		x[i] = Stonewt(pounds);
	}
	cin.get();

	Stonewt compared(11, 0);
	int count = 0;
	Stonewt *min = &x[0];
	Stonewt *max = &x[0];
	for (int i = 0; i < 6; i++) {
		if (x[i] >= compared)
			count++;
		if (x[i] > *max)
			max = &x[i];
		if (x[i] < *min)
			min = &x[i];
	}

	cout << "max = " << *max << endl;
	cout << "min = " << *min << endl;
	cout << "count = " << count << endl;

	cin.get();
}