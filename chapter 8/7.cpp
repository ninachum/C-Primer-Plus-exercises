#include <iostream>

struct debts
{
	char name[50];
	double amount;
};

template <typename T>
T SumArray(T arr[], int n);

double SumArray(debts arr[], int n);

int main()
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};

	int equitySum = SumArray(things, 6);
	double liabilitySum = SumArray(mr_E, 3);
	cout << "Mr. E's equity: " << equitySum << endl;
	cout << "Mr. E's liability: " << liabilitySum << endl;
	cin.get();
	return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
	T result = 0;
	for (int i = 0; i < n; i++)
		result += arr[i];
	return result;
}

double SumArray(debts arr[], int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
		result += arr[i].amount;
	return result;
}