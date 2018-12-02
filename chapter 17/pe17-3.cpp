#include <fstream>
#include <iostream>
#include <cstdlib>

void notifyCannotOpenThenAbort()
{
	using std::cout;
	cout << "cannot open the file(s). abort..\n";
	exit(EXIT_FAILURE);
}

void notifyUsageThenAbort()
{
	using std::cout;
	cout << "usage : main sourcefile destfile\n";
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		notifyUsageThenAbort();

	std::ifstream source(argv[1]);
	std::ofstream dest(argv[2]);

	if (!source.is_open() || !dest.is_open())
		notifyCannotOpenThenAbort();

	char tempChar = 0;
	while (source.get(tempChar))
	{
		dest.write(&tempChar, 1);
	}

	return 0;
}