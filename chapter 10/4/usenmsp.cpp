#include "namesp.h"
#include <iostream>
int main(void)
{
	using SALES::Sales;

	const double sales[3] = { 35.33, 23.23, 76.23 };
	Sales x(sales, 3);
	Sales y;
	x.showSales();
	y.showSales();

	std::cin.get();
	return 0;

}