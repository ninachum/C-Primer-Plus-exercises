#include <fstream>
#include <iostream>
#include <cstdlib>
#include <Windows.h>


int main(int argc, char *argv[])
{
	using std::cout;
	using std::cin;
	using std::ofstream;
	using std::ios_base;

	ofstream fout(argv[1], ios_base::out | ios_base::app);	// append to file, if not exists, create one.
	if (!fout.is_open())
	{
		cout << "failed to open the file.\n";
		exit(EXIT_FAILURE);
	}

	char tempChar = 0;
	while (cin.get(tempChar))
	{
		fout << tempChar;
	}
		
	if (!cin.eof()) {
		cout << "error occurred during writing the file.\n";
		exit(EXIT_FAILURE);
	}

	return 0;
}