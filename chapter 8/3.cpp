#include <iostream>
#include <string>
#include <cctype>

void convert(std::string & s);
void printString(std::string &s);

int main()
{
	using namespace std;
	string str = "";
	char temp[50];
	cout << "input string (q to exit) : ";
	while (str != "Q") {
		cin.getline(temp, 50);
		str = temp;
		convert(str);
		printString(str);
		cout << "input string (q to exit) : ";
	}
	cout << "End." << endl;
	return 0;
}

void convert(std::string &s)
{
	for (int i = 0; i < s.size(); i++) {
		s[i] = toupper(s[i]);
	}
}

void printString(std::string &s)
{
	using namespace std;
	cout << s << endl;
}

