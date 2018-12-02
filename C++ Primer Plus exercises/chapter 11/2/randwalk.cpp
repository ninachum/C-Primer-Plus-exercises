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

	cout << "��ǥ �Ÿ���? (q to exit) : ";
	while (cin >> target) {
		cout << "������? : ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << steps << " ������ ���� �� ��ġ : \n";
		cout << result << endl;
		result.polar_mode();
		cout << " �Ǵ�\n" << result << endl;
		cout << "������ ��տ��� ��� ��� �Ÿ� = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �Ÿ���? (q to exit) : ";
	}
	cout << "������...\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}