// Specification B1 - Phrase Validation
// FAMOUS PERSON and 2 WORD OCCUPATION require a word phrase. This assignment assumes this is just two words separated with a space. The input validation for this is to just check to see if the string has a space in it.

// Specification B4 – Simple Menu
// Create a simple menu 1 - Explain Mad Libs, 2 - Start Mad Libs, 3 -Quit. Only allow valid choices.

// Specification A1 - Main Game Loop
// Use a DO - WHILE to run the game until the client decides to quit. Just prompt at the end of the game if the human want’s to play again (y/n).

// Specification A3 - Smallest Word
// Prompt the client for 2 words. Select the smallest and use that for VERB3.

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

class Madlib
{
	private:
		string timespan,
			adjective[2],
			noun[7],
			verb[6],
			occupation,
			person;
		int integer;
		float floatingNum;
		char noun7[13],
			letter;
	public:
		void getWords();
		void printStory();
};

string noun0();
string noun1();
string verb1();
string verb5();
float roomNum();

int main()
{
	srand(time(0));
	Madlib story;

	story.getWords();
	story.printStory();

	return 0;
}

void Madlib::getWords()
{
	cout << "Give me a timespan. ";
	cin >> timespan;

	cout << "Give me a noun, no longer than 15 letters. ";
	noun[0] = noun0();

	cout << "Give me a verb. ";
	cin >> verb[0];

	verb[1] = verb1();

	noun[1] = noun1();

	cout << "Give me a noun. ";
	cin >> noun[2];

	cout << "Give me a verb ending in \"ing\" (eg: running, walking). ";
	cin >> verb[2];

	cout << "Give me a two-word occupation. ";
	cin.ignore();
	getline(cin, occupation);

	cout << "Give me a noun. ";
	cin >> noun[3];

	cout << "Give me a noun. ";
	cin >> noun[4];

	cout << "Give me a famous person (first and last name). ";
	cin.ignore();
	getline(cin, person);

	cout << "Give me an adjective. ";
	cin >> adjective[0];

	cout << "Give me a verb. ";
	cin >> verb[3];

	cout << "Give me a noun. ";
	cin >> noun[5];

	cout << "Give me a noun (plural). ";
	cin >> noun[6];

	cout << "Give me an adjective. ";
	cin >> adjective[1];

	cout << "Give me a noun (plural). ";
	// Specification A2 - C Style String
	cin.ignore();
	cin.getline(noun7, 13);

	cout << "Give me a verb with preposition (eg: wait for, hang with). ";
	getline(cin, verb[4]);

	cout << "Give me an integer. (eg: 1, 20, 100) ";
	cin >> integer;

	cout << "Give me a verb. ";
	verb[5] = verb5();

	floatingNum = roomNum();

	cout << "Give me a single letter. ";
	cin >> letter;
	letter = toupper(letter);
}

//Specification B2 - Maximum Word Size Validation
string noun0()
{
	string noun;
	int size;

	do {
		cin >> noun;
		size = noun.length();
		if (size > 15)
			cout << "\nThat word is too long. Try again.\n";

	// loop while the word is longer than 15 characters
	} while(size > 15);

	return noun;
}

// Specification C3 - Word Menu
string noun1()
{
	char menu;
	string noun;

	do {
		cout << "Pick from the following: (b)reakfast, (f)ishes, (c)opper coins. ";
		cin >> menu;
		switch(menu)
		{
			case 'b':
			case 'B': noun = "breakfast";
			break;
			case 'f':
			case 'F': noun = "fishes";
			break;
			case 'c':
			case 'C': noun = "copper coins";
			break;
			default: cout << "\nNot a valid entry. Try again.\n";
		}
	} while((toupper(menu) != 'B') && (toupper(menu) != 'F') && (toupper(menu) != 'C'));

	return noun;
}

// Specification C1 - Random Word
string verb1()
{
	string str;
	int theFlip = (rand() % 3);
	if (theFlip == 0)
		str = "comb";
	else if (theFlip == 1)
		str = "paint";
	else
		str = "remove";
	return str;
}

// Specification B3 - Range Validation
string verb5()
{
	string verb;
	int size;

	do {
		cin >> verb;
		size = verb.length();
		if (size < 4 || size > 20)
			cout << "\nThe word must be between 4 and 20 characters. Try again.\n";

	// loop while the word is not between 4 and 20 characters
	} while(size < 4 || size > 20);

	return verb;
}

// Specification C2 - Random Float
float roomNum()
{
	float i = (rand() % 141) + 10;
	i = i / 10;
	return i;
}

void Madlib::printStory()
{
	cout << "  A Day In The Life Of a College Student\n";
    cout << "  ======================================\n\n";
    cout << "Every " << timespan << ", I wake up and get off my " << noun[0] << ". I don't\n";
    cout << "always have time to " << verb[0] << " a shower, but I always make sure\n";
    cout << "to " << verb[1] << " my hair. Once that‘s done I get some " << noun[1] << ",\n";
    cout << "and then it‘s off to my first " << noun[2] << ". I often\n";
    cout << "get caught " << verb[2] << " in class. No one likes it\n";
    cout << "when the " << occupation << " gives a surprise " << noun[3] << ". My second\n";
    cout << "class is " << noun[4] << " Theory. Dr. " << person << " is incredibly\n";
    cout << adjective[0] << ", but I never " << verb[3] << " her because of her thick " << noun[5] << ".\n";
    cout << "Her " << noun[6] << ", however, are really " << adjective[1] << ". After\n";
    cout << "lunch, I have no more " << noun7 << " and I‘m free to " << verb[4] << "\n";
    cout << "my friends. This is right around " << integer << " O’clock.\n";
    cout << "Before I go to bed I " << verb[5] << " a little bit, in my room, " << floatingNum << " " << letter << ".\n";
}
