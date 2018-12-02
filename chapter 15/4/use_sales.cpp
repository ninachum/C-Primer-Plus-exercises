#include <iostream>
#include "sales.h"
#include <exception>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "first try block : \n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; i++)	// array-out-of-bound exception here
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "end of try block 1.\n";
	}	
	catch (Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "Bad Index: " << bad.bi_val() << endl;
		LabeledSales::nbad_index * np;
		if (np = dynamic_cast<LabeledSales::nbad_index *>(&bad))
		{
			cout << "Company: " << np->label_val() << endl;
		}
	}
	cout << "\nnext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;	// out of bound exception
		cout << "end of try block 2.\n";
	}
	catch (Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "Bad Index: " << bad.bi_val() << endl;
		LabeledSales::nbad_index * np;
		if (np = dynamic_cast<LabeledSales::nbad_index *>(&bad))
		{
			cout << "Company: " << np->label_val() << endl;
		}
	}
	cout << "Terminating...\n";
	cin.get();

	return 0;
}