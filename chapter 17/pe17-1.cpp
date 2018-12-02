#include <iostream>
#include <fstream>

int main()
{
	using std::ifstream;
	int count = 0;
	char tempChar = 0;

	ifstream istr("aa.txt");
	while (istr.get(tempChar))	// istream & get(char &) 
	{
		if (tempChar != '$')
			++count;
		else
			break;
	}

	std::cout << "result : " << count << '\n';
	return 0;


	
}