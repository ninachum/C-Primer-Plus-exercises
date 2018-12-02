#include <fstream>
#include <iostream>
#include <memory>
#include "emp.h"
#include <cstdlib>

const int MAX = 10;
int cur = 0;
std::unique_ptr<abstr_emp> pc[MAX];

void consumeLine()
{
	using std::cin;
	while (cin.get() != '\n')
		continue;
}

void readIn()
{
	using std::ifstream;
	using std::make_unique;
	using std::cout;

	ifstream input("emplist.txt");
	if (input.is_open())
	{
		int classtype;
		while (input >> classtype)
		{
			while (input.get() != '\n')
				continue;

			switch (classtype)
			{
			case Employee:
				pc[cur] = make_unique<employee>();
				pc[cur++]->GetAll(input);
				break;
			case Manager:
				pc[cur] = make_unique<manager>();
				pc[cur++]->GetAll(input);
				break;
			case Fink:
				pc[cur] = make_unique<fink>();
				pc[cur++]->GetAll(input);
				break;
			case Highfink:
				pc[cur] = make_unique<highfink>();
				pc[cur++]->GetAll(input);
				break;
			default:
				std::cerr << "read error : abort.\n";
				exit(EXIT_FAILURE);
			}
		}
		cout << "contents are : \n";
		for (int i = 0; i < cur; ++i)
			pc[i]->ShowAll();
		input.close();
	}
	else
		cout << "couldn't read emplist.txt.... new emplist will be created.\n";

}

void takeInput()
{
	using std::cout;
	using std::cin;
	using std::make_unique;

	if (cur == MAX)
	{
		cout << "list is full. skip input sequence.\n";
		return;
	}

	char choice;
	while (cur < MAX)
	{
		cout << "choose one (" << cur + 1 << " of " << MAX << ")\n"
			<< "1 : employee // 2 : manager // 3 : fink // 4 : highfink // 5 to exit\n"
			<< "choice : ";
		choice = cin.get();
		consumeLine();
		switch (choice)
		{
		case '1':
			pc[cur] = make_unique<employee>();
			pc[cur++]->SetAll();
			break;
		case '2':
			pc[cur] = make_unique<manager>();
			pc[cur++]->SetAll();
			break;
		case '3':
			pc[cur] = make_unique<fink>();
			pc[cur++]->SetAll();
			break;
		case '4':
			pc[cur] = make_unique<highfink>();
			pc[cur++]->SetAll();
			break;
		case '5':
			break;
		default:
			cout << "1, 2, 3, 4, 5....: \n";
			break;
		}
		if (choice == '5')
			break;

	}

}

void showContent()
{
	std::cout << "contents are : \n";
	for (int i = 0; i < cur; ++i)
		pc[i]->ShowAll();
}

void writeOut()
{
	std::cout << "writing the file...\n";
	using std::ofstream;
	using std::ios_base;
	ofstream output("emplist.txt");

	for (int i = 0; i < cur; ++i)
		pc[i]->WriteAll(output);
}

int main()
{
	readIn();
	showContent();
	takeInput();
	showContent();
	writeOut();

	std::cout << "press enter to exit.\n";
	std::cin.get();
	return 0;
}