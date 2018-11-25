// madlibs.cpp
// Erroll Abrahamian, CISP 360
// 11-25-2018

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// class delcaration
class Madlib
{
	private:
		string timespan,
			adjective[2],
			noun[7],
			verb[6],
			verb2choice1,
			verb2choice2,
			occupation,
			person;
		int integer;
		float floatingNum;
		char noun7[13],
			letter;
	public:
		void sayHi();
		void gameMenu();
		void printRules();
		void getWords();
		void printStory();
		bool playAgain();
};

// function prototypes
string noun0();
string noun1();
string verb1();
string verb2();
string getOccupation();
string getPerson();
string verb5();
float roomNum();

int main()
{
// randomize the random number for later
	srand(time(0));

// class objects
	Madlib story;

// program greeting
	story.sayHi();

// the main menu
	story.gameMenu();

	return 0;
}

void Madlib::sayHi()
{
	cout << "\nWelcome to Madlibs!\n\n";
}

void Madlib::gameMenu()
{
	int menu;
	bool again;

// Specification B4 – Simple Menu
	do {
		cout << "\n1. Need to know how to play?\n";
		cout << "2. Play Mad Libs!\n";
		cout << "3. Quit.\n";

		cin >> menu;

		if (menu == 1)
			printRules();
		else if (menu == 2)
		{
			do {
				getWords();
				printStory();
// Specification A1 - Main Game Loop
				again = playAgain();
			} while(again);
		}
		else if (menu == 3)
			cout << "\nBye!\n\n";
	} while(menu != 3);
}

void Madlib::printRules()
{
	cout << "\nYou will be asked for different categories of words.\n";
	cout << "These categories will include nouns, verbs, adjectives, a timespan (such as\n";
	cout << "a day or year), an occupation, a number, a letter, even a person!\n";
}

void Madlib::getWords()
{
	cout << "\nGive me a timespan. ";
	cin >> timespan;

	cout << "Give me a noun, no longer than 15 letters. ";
// run the noun0 function to check the length of the noun
	noun[0] = noun0();

	cout << "Give me a verb. ";
	cin >> verb[0];

// run the verb1 function to generate the random word
	verb[1] = verb1();

// run the noun1 function to let user pick from a menu of words
	noun[1] = noun1();

	cout << "Give me a noun. ";
	cin >> noun[2];

// run the verb2 function to check for the smaller verb
	verb[2] = verb2();

// run the getOccupation function to check for a space in the occupation
	occupation = getOccupation();

	cout << "Give me a noun. ";
	cin >> noun[3];

	cout << "Give me a noun. ";
	cin >> noun[4];

// run the getPerson function to check for a space in the name
	person = getPerson();

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
	cin.ignore();

// Specification A2 - C Style String
	cin.getline(noun7, 13);

	cout << "Give me a verb with preposition (eg: wait for, hang with). ";
	getline(cin, verb[4]);

	cout << "Give me an integer. (eg: 1, 20, 100) ";
	cin >> integer;

	cout << "Give me a verb. ";

// run the verb5 function to validate the size of the verb
	verb[5] = verb5();

// run the roomNum function to generate a random room number
	floatingNum = roomNum();

	cout << "Give me a single letter. ";
	cin >> letter;
	letter = toupper(letter);
}

bool Madlib::playAgain()
{
	char menu;
	bool again;

	cout << "Would you like to play again? (y/n)\n";

	do {
		cin >> menu;
		if (toupper(menu) == 'Y')
			again = true;
		else if (toupper(menu) == 'N')
			again = false;
		else
			cout << "\nTry again! (y/n)\n";

	// loop while the wrong letter is entered
	} while((toupper(menu) != 'N') && (toupper(menu) != 'Y'));

	return again;
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

	// loop as long as the wrong letter is entered
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

// Specification A3 - Smallest Word
string verb2()
{
	string verb2,
		verb2choice1,
		verb2choice2;
	int size1,
		size2;

	cout << "Give me a verb ending in \"ing\" (eg: running, walking). ";
	cin >> verb2choice1;

	cout << "Give me another verb ending in \"ing\" ";
	cin >> verb2choice2;

	size1 = verb2choice1.length();
	size2 = verb2choice2.length();

	if (size1 < size2)
		verb2 = verb2choice1;
	else

		// just use the second choice, even if they're the same size
		verb2 = verb2choice2;

	return verb2;
}

// Specification B1 - Phrase Validation
string getPerson()
{
	string person;
	int count = 0,
		i;

	cout << "Give me a famous person (first and last name). ";
	cin.ignore();
	do {
		getline(cin, person);

		for (i = 0; i < static_cast<int>(person.length()); i++)
			if (person[i] == ' ')
				count++;

		if (count != 1)
		{
			cout << "\nThat doesn't seem right. Shouldn't there only be one space?\n";
			cout << "What's their first and last name? ";
		}

	// loop while there is not exactly one space in the name
	} while(count != 1);

	return person;
}

string getOccupation()
{
	string occupation;
	int count = 0,
		i;

	cout << "Give me a two-word occupation. ";
	cin.ignore();
	do {
		getline(cin, occupation);

		for (i = 0; i < static_cast<int>(occupation.length()); i++)
			if (occupation[i] == ' ')
				count++;

		if (count != 1)
		{
			cout << "\nThat doesn't seem like a two-word occupation, does it?\n";
			cout << "What do they do? ";
		}

	// loop while there is not exactly one space in the occupation
	} while(count != 1);

	return occupation;
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
	// generate between 0 and 140, then add 10 to make the range 10 to 150
	float i = (rand() % 141) + 10;

	// divide by 10 to get our desired decimal
	i = i / 10;

	return i;
}

// tell a story!
void Madlib::printStory()
{
	cout << "\n  A Day In The Life Of a College Student\n";
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
