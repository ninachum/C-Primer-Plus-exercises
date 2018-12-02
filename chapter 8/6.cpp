#include <iostream>
#include <cstring>

template <typename T>
T maxn(T arr[], int len);

template <>
const char *maxn<const char *>(const char *arr[], int len);

int main()
{
	using namespace std;
	int test1[6] = { 4132, 1423, 1432, 14235, 4, 3 };
	double test2[4] = { 234.2341, 34.22, 543.56, 356.65 };
	const char *charArr[5] = { "Tom", "Jerry", "Optex", "Care", "Chooltaset" };

	int intMax = maxn(test1, 6);
	double doubleMax = maxn(test2, 4);
	const char *charMaxAddr = maxn(charArr, 5);

	cout << intMax << endl;
	cout << doubleMax << endl;
	cout << (int *)charMaxAddr << endl;
	cin.get();
	return 0;
}

template <typename T>
T maxn(T arr[], int len)
{
	T result = arr[0];
	for (int i = 1; i < len; i++) {
		if (result < arr[i])
			result = arr[i];
	}
	return result;
}

template <>
const char *maxn<const char *>(const char *arr[], int len)
{
	const char *result = arr[0];
	for (int i = 1; i < len; i++) {
		if (strlen(result) < strlen(arr[i]))
			result = arr[i];
	}
	return result;
}