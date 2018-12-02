#include <iostream>
#include <fstream>
#include "vect.h"
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
	using std::ofstream;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	ofstream outfile;
	outfile.open("randwalk.txt");

	cout << "��ǥ �Ÿ���? (q to exit) : ";
	while (cin >> target) {
		cout << "������? : ";
		if (!(cin >> dstep))
			break;
		outfile << "��ǥ �Ÿ�: " << target << ", " << "���� : " << dstep << endl;
		outfile << steps << ": " << result << endl;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			step.rect_mode();
			outfile << steps << ": " << result << endl;
		}
		outfile << steps << " ������ ���� �� ��ġ : \n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " �Ǵ�\n" << result << endl;
		outfile << "������ ��տ��� ��� ��� �Ÿ� = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �Ÿ���? (q to exit) : ";
	}
	cout << "������...\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	outfile.close();
	return 0;
}