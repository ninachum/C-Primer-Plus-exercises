#include <iostream>
#include <string>

void strcount(std::string & str);

int main()
{
	using std::string;
	using std::cout;
	using std::cin;
	string input;
	char next;

	cout << "type a line in English : \n";
	std::getline(std::cin, input); // most important
	while (input != "") {
		strcount(input);
		cout << "input next line (empty line to quit) : \n";
		std::getline(std::cin, input);

	}
	/*
	const int ArSize = 10;
	cin.get(input, ArSize);
	while (cin) {
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "input next line (empty line to quit) : \n";
		cin.get(input, ArSize);
	}
	*/
	cout << "terminating..\n";
	return 0;
}

void strcount(std::string & str)
{
	using std::cout;
	static int total = 0;
	int count = str.size();
	cout << "at \"" << str << "\"";
	/*
	while (*(str++))
		count++;
	*/

	total += count;
	cout << "there is " << count << " characters.\n";
	cout << "so far, you did input " << total << " characters.\n";
}