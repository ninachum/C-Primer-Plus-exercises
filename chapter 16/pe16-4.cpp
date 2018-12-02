#include <algorithm>

int reduce(long ar[], int n);

int main()
{
	long a[7] = { 30, 29, 39, 388, 4, 4, 490 };
	int x = reduce(a, 7);
	return 0;
}

int reduce(long ar[], int n)
{
	std::sort(ar, ar + n);
	int before = int(ar) + n * sizeof(long);
	int after = int(std::unique(ar, ar + n));
	return (before - after) / sizeof(long);

}