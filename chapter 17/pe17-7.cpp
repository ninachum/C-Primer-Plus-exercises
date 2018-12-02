#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>


class Store 
{
private:
	std::ofstream& output;

public:
	Store(std::ofstream& i) : output(i) { }
	void operator()(const std::string& str)
	{
		size_t strsize = str.size();
		output.write(reinterpret_cast<char *> (&strsize), sizeof(size_t));
		output.write(str.data(), strsize);
	}
};

void ShowStr(const std::string & str)
{
	std::cout << str << '\n';
}

void GetStrs(std::ifstream & ifs, std::vector<std::string> & vi)
{
	size_t tempsize;
	std::string tempstring;
	char tempbyte;
	while (ifs.peek() != EOF)
	{
		ifs.read(reinterpret_cast<char*>(&tempsize), sizeof(size_t));
		for (size_t i = 0; i < tempsize; ++i)
		{
			ifs.read(&tempbyte, 1);
			tempstring.append(1, tempbyte);
		}
		vi.push_back(tempstring);
		tempstring = "";
	}

}

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;

	cout << "enter string (empty line to quit) : \n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "your input : \n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "cannot open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "contents are : \n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	cin.get();
	cin.get();
	return 0;
}