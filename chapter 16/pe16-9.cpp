/*
(assuming debug mode)
MAX ELEMENTS? : 1000000
elapsed time for sorting vector<int> of size 1000000 : 3
elapsed time for sorting list<int> of size 1000000 : 78
elapsed time for copying from list to vector and sorting of size 1000000 : 4
*/

#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iterator>
#include <algorithm>
int main()
{
	using std::cout;
	using std::endl;
	srand(time(0));
	int ELEMENTS = 0;
	cout << "MAX ELEMENTS? : ";
	std::cin >> ELEMENTS;

	std::vector<int> vi0;
	for (int i = 0; i < ELEMENTS; ++i)
	{
		vi0.push_back(i);
	}
	// shuffle original container
	std::random_shuffle(vi0.begin(), vi0.end());

	// copy the contents into vector and list, each.
	std::vector<int> vi = vi0;
	std::list<int> li;
	std::copy(vi0.begin(), vi0.end(), std::insert_iterator<std::list<int>>(li, li.end()));

	// benchmark sort() for vector
	clock_t start = clock();
	std::sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout << "elapsed time for sorting vector<int> of size " << vi.size()
		<< " : " << (double)((end - start) / CLOCKS_PER_SEC) << endl;

	// benchmark sort() for list
	start = clock();
	li.sort();
	end = clock();
	cout << "elapsed time for sorting list<int> of size " << li.size()
		<< " : " << (double)((end - start) / CLOCKS_PER_SEC) << endl;

	// reset list
	std::copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	std::copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	std::copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << "elapsed time for copying from list to vector and sorting of size " << li.size()
		<< " : " << (double)((end - start) / CLOCKS_PER_SEC) << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}