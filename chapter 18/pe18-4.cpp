#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>

template <class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t) : cutoff(t) { }
	bool operator()(const T & v) { return v > cutoff; }
};

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	std::function outint([](int n) { std::cout << n << " "; });

	cout << "원래의 리스트 : \n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if(std::function(TooBig(100)));
	etcetera.remove_if(std::function(TooBig(200)));
	cout << "정비된 리스트 : \n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	std::cin.get();
	return 0;
}