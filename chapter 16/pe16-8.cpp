#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

void callFriends(std::set<std::string> & list);
void printFriends(std::set<std::string> & list);

int main()
{
	using std::set;
	using std::string;
	using std::merge;
	set<string> Mat;
	callFriends(Mat);
	printFriends(Mat);
	set<string> Pat;
	callFriends(Pat);
	printFriends(Pat);
	set<string> MatPat;
	set<string> MatPat_2;
	// merge is not a member function - use insert_iterator<set<string>> for automatic resizing
	// and, set.begin() iterator is constant iterator(cannot change contents of *this).
	merge(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator<set<string>>(MatPat, MatPat.begin()));
	printFriends(MatPat);
	std::set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), std::insert_iterator<set<string>>(MatPat_2, MatPat_2.begin()));
	printFriends(MatPat_2);
	std::cin.get();
	std::cin.get();
	return 0;
}

void callFriends(std::set<std::string> & list)
{
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	string temp;
	cout << "a friend to call? (\"quit\" to quit) : ";
	while (cin >> temp && temp != "quit")
	{
		list.insert(temp);
		cout << "a friend to call? (\"quit\" to quit) : ";
	}
}

void printFriends(std::set<std::string> & list)
{
	using std::string;
	using std::cout;
	using std::endl;
	for (auto x : list)
		cout << x << ' ';
	cout << endl;
}



