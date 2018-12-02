#include <iostream>
#include <cmath>
#include "exc_mean_new.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	double x, y, z;

	cout << "두 수? : ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << x << ", " << y << "의 조화평균은 " << z << "입니다.\n";
			cout << x << ", " << y << "의 기하평균은 " << gmean(x, y) << "입니다.\n";
			cout << "다른 두 수 (q to quit) : ";
		}
		catch (mean_error & bg)
		{
			bg.report();
			break;
		}
	}
	cout << "Terminating...\n";
	cin.get();
	cin.get();
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b, "hmean exception : a == -b");
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b, "gmean exception : a < 0 || b < 0");
	return std::sqrt(a * b);
}