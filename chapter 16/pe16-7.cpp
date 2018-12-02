#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> lotto(int upperLimit, int count);
void printIt(int x);

int main()
{
	using std::vector;
	using std::cout;
	using std::endl;
	using std::for_each;
	vector<int> winners;
	winners = lotto(51, 6);
	for_each(winners.begin(), winners.end(), printIt);
	cout << endl;
	std::cin.get();
	return 0;
}

std::vector<int> lotto(int upperLimit, int count)
{
	using std::vector;
	vector<int> result;
	for (int i = 1; i <= upperLimit; ++i)
		result.push_back(i);
	std::random_shuffle(result.begin(), result.end());
	return vector<int>(result.begin(), result.begin() + 6);
}

void printIt(int x)
{
	std::cout << x << ' ';
}