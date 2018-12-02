#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>

using std::string;
using std::vector;

void initialize(vector<string> & list);

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	vector<string> wordlist;
	initialize(wordlist);
	std::srand(std::time(0));
	char play;
	cout << "wanna play game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % wordlist.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Let's guess the magic word. of length "
			<< length << ".\n"
			<< "guess a letter at a time.\n"
			<< "chances left : " << guesses << "\n";
		cout << "your word :  " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "you've already guessed the letter. try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "WRONG!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "RIGHT!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);	// check for same letter that comes after.
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "your guess : " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "wrong guesses : " << badchars << endl;
				cout << "chances left : " << guesses << endl;
			}
		}
		if (guesses > 0)
			cout << "that's the word.\n";
		else
			cout << "the word was " << target << ".\n";
		cout << "play again? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Terminating...\n";

	return 0;
}

void initialize(vector<string> & list)
{
	using std::ifstream;
	ifstream input;
	input.open("C:\\Users\\±èÇö¹Î´Ô\\Desktop\\choo.txt");

	string x;
	while (input >> x)
		list.push_back(x);
}