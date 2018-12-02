#include <algorithm>
#include <string>
#include <iostream>

template <class T>
int reduce(T ar[], int n);

int main()
{
	long a[7] = { 30, 29, 39, 388, 4, 4, 490 };
	std::string sa[10] = { "�ȳ�", "����fnfnfnffnfnfnfnfn", "īī����", "īī����", "�µ���", "Ű����", "Ű����", "���콺", "��ġ�е�" };
	int x = reduce(a, 7);
	int y = reduce(sa, 10);
	std::cout << x << ", " << y << std::endl;
	std::cin.get();
	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	std::sort(ar, ar + n);
	int before = int(ar) + n * sizeof(T);
	int after = int(std::unique(ar, ar + n));
	return (before - after) / sizeof(T);

}