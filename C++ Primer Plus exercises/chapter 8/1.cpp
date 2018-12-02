#include <iostream>

int times = 0;

void printLine(const char *p, const int n = 0);

int main()
{
	using namespace std;
	printLine("hellow");
	printLine("hellow");
	printLine("hellow");
	printLine("hellow");
	printLine("hellow", 1);
	cin.get();
	return 0;
}

void printLine(const char *p, int n)
{
	using namespace std;
	if (n == 0)
		cout << p << endl;
	else
		for (int i = 0; i < times; i++)
			cout << p << endl;
	times++;
}