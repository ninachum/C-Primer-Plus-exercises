#include <iostream>
#include "4-1.h"

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		if (n == 0)
			return;

		int limit = (QUARTERS < n) ? QUARTERS : n;
		for (int i = 0; i < limit; i++)
			s.sales[i] = ar[i];
		for (int i = limit; i < QUARTERS; i++)
			s.sales[i] = 0.0;

		s.max = s.sales[0];
		s.min = s.sales[0];
		s.average = s.sales[0];
		for (int i = 1; i < limit; i++) {
			if (s.max < s.sales[i])
				s.max = s.sales[i];
			if (s.min > s.sales[i])
				s.min = s.sales[i];
			s.average += s.sales[i];
		}
		s.average /= limit;

	}
	void setSales(Sales & s)
	{
		using std::cout;
		using std::cin;
		for (int i = 0; i < QUARTERS; i++) {
			cout << "quarter " << i + 1 << " sales? : ";
			cin >> s.sales[i];
		}
		cin.get();

		s.max = s.sales[0];
		s.min = s.sales[0];
		s.average = s.sales[0];
		for (int i = 1; i < QUARTERS; i++) {
			if (s.max < s.sales[i])
				s.max = s.sales[i];
			if (s.min > s.sales[i])
				s.min = s.sales[i];
			s.average += s.sales[i];
		}
		s.average /= QUARTERS;
	}
	void showSales(const Sales & s)
	{
		using std::cout;
		cout << "sales (for quarters) :" << std::endl;
		cout << s.sales[0] << " " << s.sales[1] << " " << s.sales[2] << " " << s.sales[3] << std::endl;
		cout << "maximum : " << s.max << ", minimum : " << s.min << ", average : " << s.average << std::endl;
	}
}