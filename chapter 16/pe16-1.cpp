#include <iostream>
#include <string>


bool isPalin(std::string & str);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	
	bool temp;
	string x;
	cout << "type a word : ";
	cin >> x;
	while (x != "quit")
	{
		temp = isPalin(x);
		if (temp)
			cout << "it's palindrome.\n";
		else
			cout << "nope.\n";
		cout << "type a word : ";
		cin >> x;
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