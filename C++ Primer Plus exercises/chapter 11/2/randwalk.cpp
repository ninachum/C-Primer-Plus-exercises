#include <iostream>
#include "vect1.h"
#include <cstdlib>
#include <ctime>

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

	cout << "목표 거리는? (q to exit) : ";
	while (cin >> target) {
		cout << "보폭은? : ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << steps << " 걸음을 걸은 후 위치 : \n";
		cout << result << endl;
		result.polar_mode();
		cout << " 또는\n" << result << endl;
		cout << "걸음당 기둥에서 벗어난 평균 거리 = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "목표 거리는? (q to exit) : ";
	}
	cout << "종료중...\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}