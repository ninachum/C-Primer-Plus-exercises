#include <iostream>
#include <initializer_list>

template <typename T>
double average_list(const std::initializer_list<T> && list)
{
	double result = 0;
	for (auto x : list)
	{
		result += x;
	}
	return result;
}

int main()
{
	using namespace std;
	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << '\n';

	cout << average_list({ 20, 30, 19, 16, 45, 38 }) << '\n';

	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << '\n';

	return 0;
}