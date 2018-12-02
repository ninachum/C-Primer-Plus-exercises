#include <iostream>

template <typename T>
T max5(T a[]);

int main(void)
{
	using namespace std;
	int test1[5] = { 3, 4, 5, 2, -1 };
	double test2[5] = { 23.423, 234.34, 345345.344, 22, 0 };

	cout << max5(test1) << endl;
	cout << max5(test2) << endl;
	cin.get();
	return 0;
}

template <typename T>
T max5(T a[])
{
	T result = a[0];
	for (int i = 1; i < 5; i++) {
		if (result < a[i])
			result = a[i];
	}
	return result;
}