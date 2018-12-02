#include "4-1.h"
#include <iostream>
int main(void)
{
	using SALES::QUARTERS;
	using SALES::Sales;
	using SALES::setSales;
	using SALES::showSales;

	const double sales[3] = { 35.33, 23.23, 76.23 };
	Sales x;
	Sales y;
	setSales(x, sales, 3);
	setSales(y);
	showSales(x);
	showSales(y);

	std::cin.get();
	return 0;

}