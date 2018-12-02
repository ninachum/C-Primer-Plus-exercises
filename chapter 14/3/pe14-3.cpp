#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	QueueTp<Worker *> qtp;
	Worker * temp1 = nullptr;
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "직종은? : \n"
			<< "w : waiter	s : singer	"
			<< "t : singingwaiter	q : quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q : ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': qtp.enqueue(temp1 = new Waiter);
			break;
		case 's': qtp.enqueue(temp1 = new Singer);
			break;
		case 't': qtp.enqueue(temp1 = new SingingWaiter);
			break;
		}
		cin.get();
		temp1->Set();
	}

	cout << "\n사원 현황:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		qtp.dequeue(temp1);
		temp1->Show();
		delete temp1;
	}

	cout << "terminating...\n";
	cin.get();
	cin.get();

	return 0;
}