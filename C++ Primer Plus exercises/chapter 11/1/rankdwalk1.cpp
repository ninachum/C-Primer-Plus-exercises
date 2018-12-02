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

	cout << "목표 거리는? (q to exit) : ";
	while (cin >> target) {
		cout << "보폭은? : ";
		if (!(cin >> dstep))
			break;
		outfile << "목표 거리: " << target << ", " << "보폭 : " << dstep << endl;
		outfile << steps << ": " << result << endl;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			step.rect_mode();
			outfile << steps << ": " << result << endl;
		}
		outfile << steps << " 걸음을 걸은 후 위치 : \n";
		outfile << result << endl;
		result.polar_mode();
		outfile << " 또는\n" << result << endl;
		outfile << "걸음당 기둥에서 벗어난 평균 거리 = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "목표 거리는? (q to exit) : ";
	}
	cout << "종료중...\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	outfile.close();
	return 0;
}