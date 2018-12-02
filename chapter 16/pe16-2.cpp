#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>

bool isPalin(std::string & str);
std::string convert(std::string & str);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	using std::getline;

	bool temp;
	string x;
	cout << "type a word : ";
	getline(cin, x);
	x = convert(x);
	while (x != "quit")
	{
		temp = isPalin(x);
		if (temp)
			cout << "it's palindrome.\n";
		else
			cout << "nope.\n";
		cout << "type a word : ";
		getline(cin, x);
		x = convert(x);
	}
	cout << "terminating...\n";
	cin.get();
	cin.get();
	return 0;
}

bool isPalin(std::string & str)
{
	using std::string;
	for (auto x = str.begin(), y = str.end(); x < y;  )
	{
		if (*x++ != *--y)
			return false;
	}
	return true;
}

std::string convert(std::string & str)
{
	using std::string;
	auto x = str.begin();
	auto y = str.end();
	string result;
	while (x != y)
	{
		if (islower(*x))
			result.push_back(*x);
		else if (isupper(*x))
			result.push_back(tolower(*x));
		++x;
	}
	return result;
}
