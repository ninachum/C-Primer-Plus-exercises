#include <iostream>
#include <string>
#include "dmaabc.h"

const int ARRN = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	DMA * pointers[ARRN];
	string tempname;
	int temprating;
	string tempcolor;
	string tempstyle;
	int choice;

	for (int i = 0; i < ARRN; i++) {
		cout << "label? ";
		std::getline(cin, tempname);
		cout << "rating? ";
		cin >> temprating;
		cout << "1 for baseDMA, 2 for lacksDMA, 3 for hasDMA : ";
		while (cin >> choice && (choice != 1 && choice != 2 && choice != 3))
			cout << "1 for baseDMA, 2 for lacksDMA, 3 for hasDMA. enter again : ";
		if (choice == 1) {
			cin.get();
			pointers[i] = new baseDMA(tempname.data(), temprating);
		}
		else if (choice == 2) {
			cout << "color? ";
			cin.get(); // for '\n' left in stdin.
			getline(cin, tempcolor);
			pointers[i] = new lacksDMA(tempcolor.data(), tempname.data(), temprating);
		}
		else if (choice == 3) {
			cout << "style? ";
			cin.get(); // for '\n' left in stdin.
			getline(cin, tempstyle);
			pointers[i] = new hasDMA(tempstyle.data(), tempname.data(), temprating);
		}
	}

	cout << endl;

	for (int i = 0; i < ARRN; i++) {
		pointers[i]->view();
		cout << endl;
	}

	for (int i = 0; i < ARRN; i++) {
		delete pointers[i];
	}
	cout << "Terminating...\n";
	cin.get();
	cin.get();
	return 0;
}