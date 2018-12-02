#include <fstream>
#include <string>

int main() {
	std::ifstream input1("input1.txt");
	std::ifstream input2("input2.txt");
	std::ofstream output("output.txt");

	std::string buffer1;
	std::string buffer2;

	while (!input1.eof() && !input2.eof()) 
	{
		std::getline(input1, buffer1);
		output << buffer1;
		output << ' ';
		std::getline(input2, buffer2);
		output << buffer2;
		output << '\n';
	}

	if (input1.eof() && !input2.eof())
	{
		while (std::getline(input2, buffer2))
			output << buffer2 << '\n';
	}
	else if (!input1.eof() && input2.eof()) 
	{
		while (std::getline(input1, buffer1))
			output << buffer1 << '\n';
	}

	return 0;
}