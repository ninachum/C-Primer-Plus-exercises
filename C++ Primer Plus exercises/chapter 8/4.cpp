#include <iostream>
#include <string>

struct stringy
{
	char * str;
	int ct;
};

void set(stringy &stry, const char *p);
void show(stringy &stry, int n = 1);
void show(const char *p, int n = 1);

void set(stringy &stry, const char *p)
{
	stry.str = new char[strlen(p) + 1];
	strcpy(stry.str, p);
}

void show(stringy &stry, int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << stry.str << endl;
}

void show(const char *p, int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << p << endl;
}

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	std::cin.get();
	return 0;
}
