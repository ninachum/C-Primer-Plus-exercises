#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <iterator>

void printList(std::ostream& os, const std::vector<std::string>& list) {
	using std::cout;
	os << "contents of the lists are...\n";
	for (auto str : list)
		os << str << '\n';
}
int main() {
	std::ifstream input1("mat.txt");
	std::vector<std::string> list1;

	if (!input1.is_open())
		exit(EXIT_FAILURE);

	std::string buffer;
	while (!input1.eof()) {
		std::getline(input1, buffer);
		list1.push_back(buffer);
	}
	std::sort(list1.begin(), list1.end());
	printList(std::cout, list1);

	std::ifstream input2("pat.txt");
	std::vector<std::string> list2;

	if (!input2.is_open())
		exit(EXIT_FAILURE);

	while (!input2.eof()) {
		std::getline(input2, buffer);
		list2.push_back(buffer);
	}
	std::sort(list2.begin(), list2.end());
	printList(std::cout, list2);

	std::vector<std::string> list3;
	std::merge(list1.begin(), list1.end(), list2.begin(), list2.end(),
		std::insert_iterator<std::vector<std::string>>(list3, list3.begin()));
	auto last = std::unique(list3.begin(), list3.end());
	list3.erase(last, list3.end());
	printList(std::cout, list3);

	std::ofstream output("matpat.txt");
	for (auto x : list3)
	{
		output << x << '\n';
	}

	return 0;
}