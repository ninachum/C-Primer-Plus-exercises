#include <iostream>
#include "vect1.h"
#include <cstdlib>
#include <ctime>
#include <limits.h>

int main()
{
	using std::cout;
	using std::endl;
	using std::srand;
	using std::time;
	using std::cin;
	using VECTOR::Vector;

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int trials;

	cout << "��ǥ �Ÿ���? (q to exit) : ";
	while (cin >> target) {
		cout << "������? : ";
		if (!(cin >> dstep))
			break;
		cout << "�� �� �õ�? : ";
		if (!(cin >> trials) || trials <= 0)
			break;

		unsigned int min = UINT_MAX;
		unsigned int max = 0;
		double avg = 0.0;
		for (int i = 0; i < trials; i++) {
			while (result.magval() < target) {
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			avg += steps;
			if (steps < min)
				min = steps;
			if (steps > max)
				max = steps;
			steps = 0;
			result.reset(0.0, 0.0);

		}
		avg = avg / trials;
		cout << "min = " << min << ", max = " << max << endl;
		cout << "avg = " << avg << endl;
		cout << "��ǥ �Ÿ���? (q to exit) : ";
	}
	cout << "������...\n";

	cin.get();
	return 0;
}