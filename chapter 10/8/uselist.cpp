#include "list.h"
#include <iostream>
void printContent(Item & item);

int main()
{
	List x;
	x.add(342349);
	x.add(3429);
	x.add(3422349);
	x.add(342119);
	x.add(342229);
	x.add(333429);
	x.add(322429);
	x.doThis(printContent);
	std::cin.get();
	return 0;
}

void printContent(Item & item)
{
	using std::cout;
	cout << item << '\n';
}
