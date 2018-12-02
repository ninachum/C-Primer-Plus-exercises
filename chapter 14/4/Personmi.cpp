#include <iostream>
#include <cstring>
#include "Person.h"
#include <ctime>

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	srand(time(NULL));
	Person * lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "타입은? : \n"
			<< "p : person		g : gunslinger	"
			<< "o : pokerplayer		b : baddude		q : quit\n";
		cin >> choice;
		while (strchr("pgobq", choice) == NULL)
		{
			cout << "p, g, o, b, q : ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'p': lolas[ct] = new Person;
			break;
		case 'g': lolas[ct] = new Gunslinger;
			break;
		case 'o': lolas[ct] = new PokerPlayer;
			break;
		case 'b': lolas[ct] = new BadDude;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\n전체 현황:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << "terminating...\n";
	cin.get();
	cin.get();
	return 0;
}