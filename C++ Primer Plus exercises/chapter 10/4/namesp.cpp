#include <iostream>
#include "namesp.h"

namespace SALES
{
	Sales::Sales(const double ar[], int n)
	{
		if (n == 0)
			return;

		int limit = (QUARTERS < n) ? QUARTERS : n;
		for (int i = 0; i < limit; i++)
			this->sales[i] = ar[i];
		for (int i = limit; i < QUARTERS; i++)
			this->sales[i] = 0.0;

		this->max = this->sales[0];
		this->min = this->sales[0];
		this->average = this->sales[0];
		for (int i = 1; i < limit; i++) {
			if (this->max < this->sales[i])
				this->max = this->sales[i];
			if (this->min > this->sales[i])
				this->min = this->sales[i];
			this->average += this->sales[i];
		}
		this->average /= limit;

	}

	Sales::Sales()
	{
		using std::cout;
		using std::cin;
		for (int i = 0; i < QUARTERS; i++) {
			cout << "quarter " << i + 1 << " sales? : ";
			cin >> this->sales[i];
		}
		cin.get();

		this->max = this->sales[0];
		this->min = this->sales[0];
		this->average = this->sales[0];
		for (int i = 1; i < QUARTERS; i++) {
			if (this->max < this->sales[i])
				this->max = this->sales[i];
			if (this->min > this->sales[i])
				this->min = this->sales[i];
			this->average += this->sales[i];
		}
		this->average /= QUARTERS;
	}

	void Sales::showSales() const
	{
		using std::cout;
		cout << "sales (for quarters) :" << std::endl;
		cout << this->sales[0] << " " << this->sales[1] << " " << this->sales[2] << " " << this->sales[3] << std::endl;
		cout << "maximum : " << this->max << ", minimum : " << this->min << ", average : " << this->average << std::endl;
	}
}